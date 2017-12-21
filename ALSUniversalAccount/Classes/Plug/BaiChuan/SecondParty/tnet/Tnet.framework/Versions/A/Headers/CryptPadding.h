
#ifndef  __CRYPT_PADDING_H__

#define  __CRYPT_PADDING_H__

#include  "stdint.h"
#include  "string.h"

typedef enum pad_mode{

	ENCODE_NONE_PADDING = 0,
	ENCODE_ZERO_PADDING,
	ENCODE_PKCS7_5_PADDING,
	ENCODE_ANSIX923_PADDING,
	ENCODE_ISO10126_PADDING

}pad_mode;


#define  GET_PAD_NUM(len,bs)  (bs - len % bs)

#define  GET_NUM_WITH_PAD(len,bs)  (len + GET_PAD_NUM(len,bs))


void SSSL_EncryptPadding(const uint8_t * input ,uint32_t  len , int bs,pad_mode mode,uint8_t * out ,uint32_t* outlen);
void SSSL_DecryptPadding(const uint8_t * input ,uint32_t* len , int bs,pad_mode mode);


#endif
