/* crypto/crypto.h */
/* ====================================================================
 * Copyright (c) 1998-2006 The OpenSSL Project.  All rights reserved.
 *
 * ====================================================================
 * Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)
 * All rights reserved.
 *
 * ====================================================================
 * Copyright 2002 Sun Microsystems, Inc. ALL RIGHTS RESERVED.
 * ECDH support in OpenSSL originally developed by 
 * SUN MICROSYSTEMS, INC., and contributed to the OpenSSL project.
 */

#ifndef HEADER_CRYPTO_H
#define HEADER_CRYPTO_H

#include <stdlib.h>
#include "e_os2.h"
#include <stdio.h>


#ifdef BIGNUM
#undef BIGNUM
#endif
typedef struct bignum_st BIGNUM;
typedef struct bignum_ctx BN_CTX;
typedef struct bn_mont_ctx_st BN_MONT_CTX;
typedef struct bn_recp_ctx_st BN_RECP_CTX;
typedef struct bn_gencb_st BN_GENCB;
typedef struct ecdh_method ECDH_METHOD;


/* Resolve problems on some operating systems with symbol names that clash
   one way or another */
//#include "symhacks.h"

#ifdef  __cplusplus
extern "C" {
#endif

#define CRYPTO_w_lock(a)
#define CRYPTO_w_unlock(a)
#define CRYPTO_r_lock(a)
#define CRYPTO_r_unlock(a)
#define CRYPTO_add(a,b,c)	((*(a))+=(b))

#define SSSL_malloc(num)	malloc(num)
#define SSSL_free(addr)		free(addr)

void SSSL_cleanse(void *ptr, size_t len);

#ifdef  __cplusplus
}
#endif
#endif
