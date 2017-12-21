/* crypto/ecdh/ecdh.h */
/* ====================================================================
 * Copyright 2002 Sun Microsystems, Inc. ALL RIGHTS RESERVED.
 */
/* ====================================================================
 * Copyright (c) 2000-2002 The OpenSSL Project.  All rights reserved.
 * ====================================================================
 *
 * This product includes cryptographic software written by Eric Young
 * (eay@cryptsoft.com).  This product includes software written by Tim
 * Hudson (tjh@cryptsoft.com).
 *
 */
#ifndef HEADER_ECDH_H
#define HEADER_ECDH_H

#include "opensslconf.h"

#ifdef OPENSSL_NO_ECDH
#error ECDH is disabled.
#endif

#include "ec.h"
#ifndef OPENSSL_NO_DEPRECATED
#include "bn.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

const ECDH_METHOD *sssl_ECDH_OpenSSL(void);

const ECDH_METHOD *sssl_ECDH_get_default_method(void);

int sssl_ECDH_compute_key(void *out, size_t outlen, const EC_POINT *pub_key, EC_KEY *ecdh,
                     void *(*KDF)(const void *in, size_t inlen, void *out, size_t *outlen));

#ifdef  __cplusplus
}
#endif
#endif
