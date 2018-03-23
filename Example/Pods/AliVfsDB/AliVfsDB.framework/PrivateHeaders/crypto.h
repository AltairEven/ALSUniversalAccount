/*
///////////////////////////////////////////////////////////////////////////////
// Name:        crypto.h
// Purpose:     
// Author:      Yanxian
// Modified by:
// Created:     2015-11-25
///////////////////////////////////////////////////////////////////////////////
*/

#ifndef _CRYPTO_H_
#define _CRYPTO_H_

#ifdef SQLITE_HAS_CODEC
int
sqlite3CodecAttach(
    sqlite3*    db,                 /*!<in/out: Database handle> */ 
    int         nDb,                /*!<in: index of database> */
    const void* pKey,               /*!<in: password> */
    int         keyLen);

SQLITE_API int sqlite3_key(
    sqlite3     *db,                /*!<in/out: Database handle> */
    const void  *pKey,              /*!<in: password> */
    int         nKey);

SQLITE_API int sqlite3_key_v2(
    sqlite3     *db,                 /*!<in/out:Database handle> */
    const char  *zDbName,            /*!<in: Name of the database> */
    const void  *pKey, 
    int         nKey);

SQLITE_API int sqlite3_rekey(
    sqlite3     *db,                  /*!<in/out: Database to be rekeyed> */
    const void  *pKey,                /*!<in: password> */
    int         nKey);
    
SQLITE_API int sqlite3_rekey_v2(
    sqlite3     *db,                 /*!<in/out: Database to be rekeyed> */
    const char  *zDbName,            /*!<in: Name of the database> */
    const void  *pKey, 
    int         nKey);

void sqlite3CodecGetKey(
    sqlite3*    db, 
    int         nDb, 
    void**      pKey, 
    int*        keyLen);

void cryptoGenKey(
    unsigned char*  keyBuff,         /*!<in/out: store fix format password> */ 
    const void*     pKey,            /*!<in: password user input> */
    int             keyLen);
    
#endif // SQLITE_HAS_CODEC

#endif // _CRYPTO_H_
