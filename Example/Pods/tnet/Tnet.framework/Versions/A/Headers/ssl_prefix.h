
#ifndef  __SSL_PREFIX_H__
#define  __SSL_PREFIX_H__


#ifdef  USE_STANDARD_SSL

#define SLIGHT_PREFIX_DATA

#define SLIGHT_PREFIX1(x,y)             x ## y
#define SLIGHT_PREFIX2(x,y)             SLIGHT_PREFIX1(x,y)

#define SLIGHT_PREFIX(x)                SLIGHT_PREFIX2(SLIGHT_PREFIX_DATA,x)

#define SLIGHT_SSL_new                  SLIGHT_PREFIX(SSL_new)
#define SLIGHT_SSL_free                 SLIGHT_PREFIX(SSL_free)
#define SLIGHT_SSL_connect              SLIGHT_PREFIX(SSL_connect)
#define SLIGHT_SSL_read                 SLIGHT_PREFIX(SSL_read)
#define SLIGHT_SSL_write                SLIGHT_PREFIX(SSL_write)
#define SLIGHT_SSL_shutdown             SLIGHT_PREFIX(SSL_shutdown)
#define SLIGHT_SSL_set_fd               SLIGHT_PREFIX(SSL_set_fd)
#define SLIGHT_SSL_get_version_sting    SLIGHT_PREFIX(SSL_get_version_string)
#define SLIGHT_SSL_version              SLIGHT_PREFIX(SSL_version)
#define SLIGHT_SSL_get_object           SLIGHT_PREFIX(SSL_get_object)
#define SLIGHT_SSL_set_usercontext      SLIGHT_PREFIX(SSL_set_usercontext)
#define SLIGHT_SSL_set_mode             SLIGHT_PREFIX(SSL_set_mode)
#define SLIGHT_SSL_get_mode             SLIGHT_PREFIX(SSL_get_mode)
#define SLIGHT_SSL_set_rsalimit         SLIGHT_PREFIX(SSL_set_rsalimit)
#define SLIGHT_SSL_set_request_num      SLIGHT_PREFIX(SSL_set_request_num)
#define SLIGHT_SSL_get_performance_data SLIGHT_PREFIX(SSL_get_performance_data)


#define SLIGHT_SSL_CTX_new              SLIGHT_PREFIX(SSL_CTX_new)
#define SLIGHT_SSL_CTX_free             SLIGHT_PREFIX(SSL_CTX_free)
#define SLIGHT_SSL_CTX_set_version      SLIGHT_PREFIX(SSL_CTX_set_version)
#define SLIGHT_SSL_CTX_set_pubkey_cb    SLIGHT_PREFIX(SSL_CTX_set_pubkey_cb)
#define SLIGHT_SSL_CTX_set_rsa_encrypt_cb   SLIGHT_PREFIX(SSL_CTX_set_rsa_encrypt_cb)
#define SLIGHT_SSL_CTX_set_performance_cb   SLIGHT_PREFIX(SSL_CTX_set_performance_cb)
#define SLIGHT_SSL_get_error            SLIGHT_PREFIX(SSL_get_error)
#define SLIGHT_SSL_pending              SLIGHT_PREFIX(SSL_pending)
#define SLIGHT_SSL_is_write_block       SLIGHT_PREFIX(SSL_is_write_block)


#define SLIGHT_SSL                      SLIGHT_PREFIX(SSL)
#define SLIGHT_SSL_CTX                  SLIGHT_PREFIX(SSL_CTX)
#define SLIGHT_SSL_METHOD               SLIGHT_PREFIX(SSL_METHOD)


#endif

#endif/*__SSL_PREFIX_H__*/

