
#ifndef  __SHA256_H__
#define  __SHA256_H__

#include "../crypto.h"

typedef struct SSSL_SHA256Context {
    TBUInt32 state[8];
    TBUInt32 total[2];
    TBUInt8 buffer[64];
} SSSL_SHA256Context;

extern void SSSL_SHA256Init(SSSL_SHA256Context *ctx);
extern void SSSL_SHA256Update(SSSL_SHA256Context *ctx,
	   			const TBUInt8 *input, TBUInt32 length);
extern void SSSL_SHA256Finish(SSSL_SHA256Context *ctx);

#endif/*<__SHA256_H__>*/

