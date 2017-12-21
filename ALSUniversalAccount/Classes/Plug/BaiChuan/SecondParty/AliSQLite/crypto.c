/*
///////////////////////////////////////////////////////////////////////////////
// Name:        crypto.c
// Purpose:     
// Author:      Yanxian
// Modified by:
// Created:     2015-11-25
///////////////////////////////////////////////////////////////////////////////
*/
#include "sqlite3.c"
#include "aes.h"
#include "crypto.h"
#include <stdlib.h>
#include <string.h>

#ifdef SQLITE_HAS_CODEC

/*
** The database page the PENDING_BYTE occupies. This page is never used.
*/
#define PENDING_BYTE_PAGE_DEF(x) ((PENDING_BYTE/(x))+1)
#define KEY_PADDING '{'

/*
 ** Struct keep encrypt/decrypt key for encryption or decryption and status
 * */
typedef struct CryptoContext{
    int isEncrypted;
    int hasEncryptKey;      
    int hasDecryptKey;
    Btree* dbTree;
    aes_encrypt_ctx encryptKey;
    aes_decrypt_ctx decryptKey;
    unsigned char writeBuff[SQLITE_MAX_PAGE_SIZE]; /*write buffer, keep plaintext in buffer*/
}CryptoCtx;

/*
** Specify the key for an encrypted database.  This routine should be
** called right after sqlite3_open().
** The code to implement this API is not available in the public release
** of SQLite.
*/
SQLITE_API int 
sqlite3_key(
    sqlite3     *db,                /*!<in/out: Database handle> */
    const void  *pKey,              /*!<in: password> */
    int         nKey) 
{
    return sqlite3_key_v2(db, NULL, pKey, nKey);
}

SQLITE_API int 
sqlite3_key_v2(
    sqlite3     *db,                /*!<in/out: Database handle> */
    const char  *zDbName,           /*!<in: Name of the database> */
    const void  *pKey,              /*!<in: password> */
    int         nKey) 
{
    int rc = sqlite3CodecAttach(db, 0, pKey, nKey);
    return rc;
}

/*
** Change the key on an open database.  If the current database is not
** encrypted, this routine will encrypt it.  If pKey==0 or nKey==0, the
** database is decrypted.
*/
SQLITE_API int 
sqlite3_rekey(
    sqlite3     *db,                  /*!<in/out: Database to be rekeyed> */
    const void  *pKey,                /*!<in: password> */
    int         nKey) 
{
    return sqlite3_rekey_v2(db, NULL, pKey, nKey);
}

/*
** Specify the activation key for a SEE database.  Unless 
** activated, none of the SEE routines will work.
*/
SQLITE_API void sqlite3_activate_see(
    const char *zPassPhrase        /* Activation phrase */) 
{
    //do nothing
}

/*  
** The unencrypted password is not stored for security reasons
** therefore always return NULL
** If the main database is encrypted a key length of 1 is returned.
** In that case an attached database will get the same encryption key
** as the main database if no key was explicitly given for the attached database.
*/
void sqlite3CodecGetKey(
    sqlite3*    db, 
    int         nDb, 
    void**      pKey, 
    int*        keyLen)
{
    int keylength;

    Btree* pbt      = db->aDb[0].pBt;   
    Pager* pPager   = sqlite3BtreePager(pbt);
    CryptoCtx* ctx  = sqlite3PagerGetCodec(pPager);

    keylength = (ctx != NULL && ctx->isEncrypted) ? 1 : 0;
  
    *pKey   = NULL;
    *keyLen = keylength;
}


/*
**Generate fix len key for encryption/decryption
*/
void cryptoGenKey(
    unsigned char*  keyBuff, 
    const void*     pKey, 
    int             keyLen)
{
    int i = 0;

    if (keyLen >= KS_LENGTH) {
        memcpy(keyBuff, pKey, KS_LENGTH);
    } else {
        memcpy(keyBuff, pKey, keyLen);
        for(i = keyLen; i < KS_LENGTH; i++) {
            keyBuff[i] = KEY_PADDING;
        }
    }
}

/*
**set status for having encryptkey or not
*/
void
cryptoSetHasEncryptKey(
    CryptoCtx*  ctx, 
    int         hasEncryptKey)
{
    ctx->hasEncryptKey = hasEncryptKey;
}

/*
**get status for having encryptkey
*/
int
cryptoGetHasEncryptKey(CryptoCtx* ctx)
{
    return ctx->hasEncryptKey;
}

/*
**set status for having decryptkey or not
*/
void
cryptoSetHasDecryptKey(
    CryptoCtx*  ctx, 
    int         hasDecryptKey)
{
    ctx->hasDecryptKey = hasDecryptKey;
}

/*
**get status for having decryptkey
*/
int
cryptoGetHasDecryptKey(CryptoCtx* ctx)
{
    return ctx->hasDecryptKey;
}

/*
**set status if database is encrypt or not
*/
void
cryptoSetIsEncrypted(
    CryptoCtx*  ctx, 
    int         isEncrypted)
{
    ctx->isEncrypted = isEncrypted;
}

/*
**get encrypt status for database
*/
int
cryptoGetIsEncrypted(CryptoCtx* ctx)
{
    return ctx->isEncrypted;
}

/*
**Generate Encrypt key.
**Normally, Encrypt key is same as Decrypt key. 
**But, when rekey, Encrypt key and Decrypt key is not same.
*/
void 
cryptoGenEncryptKey(
    CryptoCtx*  ctx, 
    const void* pKey, 
    int         keyLen)
{
    unsigned char keyBuff[KS_LENGTH];
    
    cryptoGenKey(keyBuff, pKey, keyLen);

    cryptoSetHasEncryptKey(ctx, 1);

    aes_encrypt_key128(keyBuff, &ctx->encryptKey);
}

/*
**Generate Decrypt key.
**Normally, Encrypt key is same as Decrypt key. 
**But, when rekey, Encrypt key and Decrypt key is not same.
*/
void 
cryptoGenDecryptKey(
    CryptoCtx*  ctx, 
    const void* pKey, 
    int         keyLen)
{
    unsigned char keyBuff[KS_LENGTH];
    
    cryptoGenKey(keyBuff, pKey, keyLen);

    cryptoSetHasDecryptKey(ctx, 1);

    aes_decrypt_key128(keyBuff, &ctx->decryptKey);
}

/*
**Encrypt a page.
**For page 1 has meta of pagesize,should deal with it especially
*/
void* 
cryptoEncrypt(
    CryptoCtx*      ctx, 
    Pgno            nPageNum, 
    unsigned char*  data, 
    int             pageSize)
{
    unsigned char dbHeader[8]; //store page size bytes
    int i = 0;
    int offset = 0;

    if (!cryptoGetHasEncryptKey(ctx)) {
        return data;
    }

    /*for 16,17 bytes in Pgno 1 store PageSize, should not encrypt */
    if (nPageNum == 1) {
        /* Save the header bytes remaining unencrypted */
        memcpy(dbHeader, data+16, 8); 
	    offset = 16;
	    aes_encrypt(data, data, &ctx->encryptKey);
    }

    for(i = offset; i < pageSize; i += AES_BLOCK_SIZE) {
        aes_encrypt(data + i, data + i, &ctx->encryptKey);
    }

    if (nPageNum == 1)
    {
        /* Move the encrypted header bytes 16..23 to a safe position */
        memcpy(data+8,  data+16,  8); 
        
        /* Restore the unencrypted header bytes 16..23 */
        memcpy(data+16, dbHeader, 8);             
    }

    return data;
}

/*
** Decrypt a Page. 
** For page 1 has meta of pagesize,should deal with it especially.
*/
void* 
cryptoDecrypt(
    CryptoCtx*      ctx, 
    Pgno            nPageNum, 
    unsigned char*  data, 
    int             pageSize)
{
    unsigned char dbHeader[8];
    int dbPageSize;
    int offset = 0;
    int i;

    if (!cryptoGetHasDecryptKey(ctx)) {
        return data;
    }

    if (nPageNum == 1){
        /* Save (unencrypted) header bytes 16..23 */
        memcpy(dbHeader, data+16, 8);
        
        /* Determine page size */
        dbPageSize = (dbHeader[0] << 8) | (dbHeader[1] << 16);
        
        /* Check whether the database header is valid */
        /* If yes, the database follows the new encryption scheme, otherwise use the previous encryption scheme */
        if ((dbPageSize >= 512)   && (dbPageSize <= SQLITE_MAX_PAGE_SIZE) && (((dbPageSize-1) & dbPageSize) == 0) &&
           (dbHeader[5] == 0x40) && (dbHeader[6] == 0x20) && (dbHeader[7] == 0x20))
        {
            /* Restore encrypted bytes 16..23 */
            memcpy(data+16, data+8, 8);
            offset = 16;
        }
    }
    
    for (i = offset; i < pageSize; i += AES_BLOCK_SIZE){
        aes_decrypt(data + i, data + i, &ctx->decryptKey);
    }   
  
    if (nPageNum == 1 && offset == 16){
        /* Verify the database header */
        if (memcmp(dbHeader, data+16, 8) == 0){
            memcpy(data, SQLITE_FILE_HEADER, 16);
        }
    }
    
    return data;
}

/*
**Encrypt or Decrypt, called by pager
*/
void* 
cryptoCodec(
    void*   codecArg,          /*!<in/out: encrypt/decrypt control objects>*/
    void*   data,              /*!<in/out: page data buffer>*/
    Pgno    nPageNum,          /*!<in: pageno>*/
    int     nMode)             /*!<in: read or write page>*/
{
    int pageSize;
    
    CryptoCtx* ctx = codecArg;
    
    if (ctx == NULL){
        return data;
    }

    if (!cryptoGetIsEncrypted(ctx)){
        return data;
    }
    
    pageSize = sqlite3BtreeGetPageSize(ctx->dbTree);

    switch(nMode) {
    case 0: /* Undo a "case 7" journal file encryption */
    case 2: /* Reload a page */
    case 3: /* Load a page */
        assert(cryptoGetHasDecryptKey(ctx));
        
        data = cryptoDecrypt(ctx, nPageNum, (unsigned char*) data, pageSize);
        break;

    case 6: /* Encrypt a page for the main database file */
    case 7: /* Encrypt a page for the journal file */
        assert(cryptoGetHasEncryptKey(ctx));
        
        memcpy(ctx->writeBuff, data, pageSize);
        data = ctx->writeBuff;
        data = cryptoEncrypt(ctx, nPageNum, (unsigned char*) data, pageSize);
        break;
    }

    return data;
}

void 
cryptoCodecSizeChange(
    void    *pArg, 
    int     pageSize, 
    int     reservedSize
)
{
    //do nothing
}

/*
 ** free encrypt control struct
*/
void 
cryptoCodecFree(void *ctx)
{
    if (!ctx) {
        return;
    }

    sqlite3_free(ctx);
}

/*
** Changes the encryption key for an existing database
*/
SQLITE_API int 
sqlite3_rekey_v2(
    sqlite3     *db,        /* Database to be rekeyed */
    const char  *zDbName,   /* Name of the database */
    const void  *pKey,      /* The new key */
    int         nKey)
{
    int rc = SQLITE_OK;
    aes_encrypt_ctx origEncryptKey;
    
    Btree* pbt      = db->aDb[0].pBt;
    Pager* pPager   = sqlite3BtreePager(pbt);
    CryptoCtx* ctx  = sqlite3PagerGetCodec(pPager);

    if ((pKey == NULL || nKey == 0) && 
        (ctx == NULL  || !cryptoGetIsEncrypted(ctx))) {
        /*
        // Database not encrypted and key not specified
        // therefore do nothing
        */
        return SQLITE_OK;
    }
    
    if (ctx == NULL || !cryptoGetIsEncrypted(ctx)) {
        /*
        // Database not encrypted, but key specified
        // therefore encrypt database
        */

        ctx  = sqlite3_malloc(sizeof(CryptoCtx));
        ctx->dbTree = pbt;
        cryptoSetIsEncrypted(ctx, 1);
        cryptoGenEncryptKey(ctx, pKey, nKey);

        sqlite3PagerSetCodec(sqlite3BtreePager(pbt), 
                             cryptoCodec, 
                             cryptoCodecSizeChange,
                             cryptoCodecFree,
                             ctx);

    } else if (pKey == NULL || nKey == 0) {
        /*
        // Database encrypted, but key not specified
        // therefore decrypt database
        // Keep decrypt key, drop encrypt key
        */
        memcpy(&origEncryptKey, &ctx->encryptKey, sizeof(origEncryptKey));
        cryptoSetHasEncryptKey(ctx, 0);

    } else  {
        /*
        // Database encrypted and key specified
        // therefore re-encrypt database with new key
        // Keep decrypt key, change encrypt key to new key
        */        
        memcpy(&origEncryptKey, &ctx->encryptKey, sizeof(origEncryptKey));
        cryptoSetHasEncryptKey(ctx, 1);
        cryptoGenEncryptKey(ctx, pKey, nKey);
    }
    
    sqlite3_mutex_enter(db->mutex);

    /* Start transaction */
    rc = sqlite3BtreeBeginTrans(pbt, 1);
    if (rc == SQLITE_OK) {
        /* Rewrite all pages using the new encryption key (if specified) */
        int pageSize;
        int nPageCount  = -1;
        int rc          = SQLITE_OK;
        
        sqlite3PagerPagecount(pPager, &nPageCount);
        Pgno nPage  = (Pgno) nPageCount;
        pageSize    = sqlite3BtreeGetPageSize(pbt);
        Pgno nSkip  = PENDING_BYTE_PAGE_DEF(pageSize);
        DbPage *pPage;
        Pgno n;
        
        for (n = 1; rc == SQLITE_OK && n <= nPage; n++) {
            if (n == nSkip) continue;
            rc = sqlite3PagerGet(pPager, n, &pPage);
            if (!rc) {
                rc = sqlite3PagerWrite(pPage);
                sqlite3PagerUnref(pPage);
            }
        }
    }

    if (rc == SQLITE_OK) {
        /* Commit transaction if all pages could be rewritten */
        rc = sqlite3BtreeCommit(pbt);
    }
  
    if (rc != SQLITE_OK) {
        /* Rollback in case of error */
        rc = sqlite3BtreeRollback(pbt, SQLITE_OK, 0);
    }

    sqlite3_mutex_leave(db->mutex);

    if (rc == SQLITE_OK){
        /* Set Encrypt key equal to Decrypt key if necessary */
        if (cryptoGetHasEncryptKey(ctx)){
            cryptoGenDecryptKey(ctx, pKey, nKey);
        } else {
            cryptoSetIsEncrypted(ctx, 0);
        }
    } 
    else{
        /* Restore Encrypt key if necessary */
        if (cryptoGetHasDecryptKey(ctx)) {          
            memcpy(&ctx->encryptKey, &origEncryptKey, sizeof(origEncryptKey));
            cryptoSetHasEncryptKey(ctx, 1);
        }
        else{
            cryptoSetIsEncrypted(ctx, 0);
        }
    }
  
    if (!cryptoGetIsEncrypted(ctx)) {
        sqlite3PagerSetCodec(pPager, NULL, NULL, NULL, NULL);
    }

    return rc;    
}

/*
 ** attach Encrypt/Decrypt function with sqlite
 */
int
sqlite3CodecAttach(
    sqlite3*        db,     /*!< in/out: db handle */
    int             nDb,    /*!<in: db index> */
    const void*     pKey,   /*!<in: password> */
    int             keyLen) /*!<in: password length> */
{    
    if (pKey == NULL || keyLen <= 0) {
        return SQLITE_OK;
    }
    
    CryptoCtx* ctx      = sqlite3_malloc(sizeof(CryptoCtx));
    ctx->dbTree         = db->aDb[nDb].pBt;
    
    cryptoSetIsEncrypted(ctx, 1);
    cryptoGenEncryptKey(ctx, pKey, keyLen);
    cryptoGenDecryptKey(ctx, pKey, keyLen);
    
    sqlite3PagerSetCodec(sqlite3BtreePager(db->aDb[nDb].pBt), 
                         cryptoCodec, 
                         cryptoCodecSizeChange,
                         cryptoCodecFree,
                         ctx);

    return SQLITE_OK;
}

#endif // SQLITE_HAS_CODEC


