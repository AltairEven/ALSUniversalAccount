
#ifndef  __CIPHER_H__

#define  __CIPHER_H__


#include  "Aes.h"
#include  "CryptPadding.h"
#include  "slight_err.h"


int cipher_encrypt (SSSL_AesContextT* ctx , uint8_t *outbuf, uint32_t* outbuflen,
		const uint8_t *inbuf, uint32_t inbuflen);

int cipher_decrypt (SSSL_AesContextT* ctx, uint8_t *outbuf, uint32_t* outbuflen,
                const uint8_t *inbuf,uint32_t inbuflen);

int cipher_setkey (SSSL_AesContextT* ctx, uint8_t *key,int keylen);

int cipher_seteiv(SSSL_AesContextT* ctx, const uint8_t *iv, int ilen);

int cipher_setdiv(SSSL_AesContextT* ctx, const uint8_t *iv, int ilen);

static inline int  cipher_get_blocksize(){
	return  AES_BLOCK_SIZE;
}

static inline int cipher_get_encrypt_size(uint32_t input){

	return (input/AES_BLOCK_SIZE + 1)*AES_BLOCK_SIZE;
}

static inline int cipher_set_pad_mode(SSSL_AesContextT* ctx,int mode){
	ctx->mode = mode;
	return 0;
}


#endif
