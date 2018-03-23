
#ifndef SLIGHT_SSL_SPDY_H
#define SLIGHT_SSL_SPDY_H

#include "ssl_locl.h"

int slight_ssl_write_spdy(SLIGHT_SSL *s, const uint8_t *buf, int len);

int sssl_spdy_set_cipher_flag(uint8_t *buf, int len, int flag);

#endif

