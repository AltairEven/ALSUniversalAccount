
#ifndef __AES_H__

#define __AES_H__

#include  "crypto.h"


#define  AES_BLOCK_SIZE    16

typedef struct
{
	TBUInt32 erk[64];		/* encryption round keys */
	TBUInt32 drk[64];		/* decryption round keys */
	TBUInt32 nr;			/* number of rounds */
	unsigned char eiv[AES_BLOCK_SIZE];	/* encrypt initialized vector */
	unsigned char div[AES_BLOCK_SIZE];	/* decrypt initialized vector */
	int      mode;
} SSSL_AesContextT;

int  SSSL_AesSetKey(void * context,const TBUInt8 *aKey, int aKeylen);

int SSSL_AesSetEncryptIV(void * context, const unsigned char *iv, int ilen);

int SSSL_AesSetDecryptIV(void * context, const unsigned char *iv, int ilen);

void SSSL_AesEncryptBlock(void * context, TBUInt8 * output ,const TBUInt8 *input );

void SSSL_AesDecryptBlock(void * context, TBUInt8 * output ,const TBUInt8 *input );

#endif
