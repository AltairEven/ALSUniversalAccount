
#ifndef ___SSL_H__
#define ___SSL_H__


#include "ssl_locl.h"
#include "slight_ssl_method.h"
#include "slight_err.h"

#define SLIGHT_SSL_PROJECT_VERSION "2.2.11"


/*Used in SSL_set_shutdown()/SSL_get_shutdown();*/
/**
 * send data shutdown
 */
#define SSSL_SENT_SHUTDOWN      0x01
/**
 * receive data shutdown
 */
#define SSSL_RECEIVED_SHUTDOWN  0x02


/**
 * create SSL object,represent a secure channel
 * @param [ctx] ssl_context
 * @retrun SSL-object-pointer
 */
SLIGHT_SSL* SLIGHT_SSL_new(SLIGHT_SSL_CTX *ctx);

/**
 * free SSL object
 * @param [ssl] SSL-object-pointer
 */
void SLIGHT_SSL_free(SLIGHT_SSL *ssl);

/**
 * client use to start a connection.
 * @param [ssl]  SSL-object-pointer
 * @return error code
 */
int SLIGHT_SSL_connect(SLIGHT_SSL *ssl);

/**
 * read data from secure channel.
 * @param [ssl]  SSL-object-pointer
 * @param [buf]  data cache address
 * @param [num]  data cache size
 * @return >0: the number of data has been read
 * @return <=0: error code . @see slight_err.h
 * OK is success , < OK is error > OK is data read.
 */
int SLIGHT_SSL_read(SLIGHT_SSL *ssl, void *buf, int num);

/**
 * write data to secure channel.
 * @param [ssl]  SSL-object-pointer
 * @param [buf]  data cache address
 * @param [num]  data cache size
 * @return >0: the number of data has been written
 * @return <=0: error code . @see slight_err.h
 * OK is success , < OK is error > OK is data sent.
 */
int SLIGHT_SSL_write(SLIGHT_SSL *ssl, const void *buf, int num);

/**
 * write a vector of data
 * @param [ssl]   SSL-object-pointer
 * @param [iovec] the vector of data
 * @param [count] the count of blocks in the vector
 * @return >0: the number of data has been written
 * @return <=0: error code
 */
int SLIGHT_SSL_writev(SLIGHT_SSL *ssl, const struct iovec *vector, int count);

/**
 * write cipher text or plaintext for SPDY,
 * it will check a bit of flag in syn_stream to choose whether it should encrypt.
 * @param [ssl]  SSL-object-pointer
 * @param [buf]  data cache address
 * @param [num]  data cache size
 * @return >=0: the number of data has been written
 * @return <0:  error code
 */
int SLIGHT_SSL_write_spdy(SLIGHT_SSL *ssl, const void *buf, int num);

/**
 * check read/write buffer in ssl structure,
 * and return whether there are any data to be read/wrote.
 * @param [ssl]  SSL-object-pointer
 * @return
 *     not 0    - want read/write;
 *     0        - want nothing
 */
uint32_t SLIGHT_SSL_want_read(SLIGHT_SSL *ssl);
uint32_t SLIGHT_SSL_want_write(SLIGHT_SSL *ssl);

/**
 * shutdown secure channel
 * @param [ssl] SSL-object-pointer
 * @return OK.
 */
int SLIGHT_SSL_shutdown(SLIGHT_SSL *ssl);

/**
 * set socket file descriptor,so secure channel can send or receive data.
 * @param [ssl] SSL-object-pointer
 * @param [fd]  socket file descriptor
 * @return OK
 */
int SLIGHT_SSL_set_fd(SLIGHT_SSL *ssl, int fd);

/**
 * get secure channel version string.
 * @param [ssl] SSL-object-pointer
 * @return string
 */
const char *SLIGHT_SSL_get_version_string(const SLIGHT_SSL *ssl);

/**
 * get secure channel version.
 * @param [ssl] SSL-object-pointer
 * @return sslversion
 */
int SLIGHT_SSL_version(const SLIGHT_SSL *ssl);

/**
 * set user context which will be returned in callback functions.
 * @param [ssl] SSL-object-pointer
 * @param [context] user context
 */
void SLIGHT_SSL_set_usercontext(SLIGHT_SSL* ssl, void* context);

/**
 * set/get secure channel mode.
 * @see sslmod
 * @param [ssl] SSL-object-pointer
 * @param [mode] mode
 */
static inline void SLIGHT_SSL_set_mode(SLIGHT_SSL *ssl, SLIGHT_SSL_MOD mode)
{
    ssl->mod = mode;
}
static inline SLIGHT_SSL_MOD SLIGHT_SSL_get_mode(const SLIGHT_SSL *ssl)
{
    return ssl->mod;
}

/**
 * set pubkey seqnum
 */
int SLIGHT_SSL_set_pubkey_seqnum(SLIGHT_SSL* ssl, int seqnum);

/**
 * set the max count of 0-RTT request packets before receiving a response.
 * default: 10
 */
static inline void SLIGHT_SSL_set_request_num(SLIGHT_SSL *ssl, int num)
{
    ssl->request_max = num;
}

/**
 * get performance data of slight ssl
 */
static inline SLIGHT_SSL_PERFORMANCE_DATA* SLIGHT_SSL_get_performance_data(SLIGHT_SSL* ssl)
{
    return &ssl->performance_data;
}

/**
 * obtain number of readable bytes buffered in an SSL object
 */
int SLIGHT_SSL_pending(const SLIGHT_SSL *ssl);

/**
 * check whether slight ssl writting is block
 * retrun 1 may block , 0 write normally
 */
int SLIGHT_SSL_is_write_block(const SLIGHT_SSL *ssl);

/**
 * whether slight ssl is in init
 */
static inline int SLIGHT_SSL_in_init(const SLIGHT_SSL *ssl)
{
    return ssl->mod == SSL_1_RTT && ssl->state <= SSL_REQUEST;
}

/**
 * set bio method and userdata
 */
void SLIGHT_SSL_set_bio(SLIGHT_SSL *ssl, SSSL_BIO_READ_METHOD bread,
                        SSSL_BIO_WRITE_METHOD bwrite, void* userdata);

/**
 * set session ticket
 */
static inline int SLIGHT_SSL_set_session_ticket(SLIGHT_SSL* ssl, void* ticket, int size)
{
    if (size != sizeof(ssl->ticket) || ticket == NULL) {
        return -1;
    }
    memcpy(&(ssl->ticket), ticket, size);
    ssl->use_ticket = 1;
    return OK;
}

/**
 * set session ticket callback
 */
static inline void SLIGHT_SSL_set_session_ticket_callback(SLIGHT_SSL* ssl, 
                                    SLIGHT_SSL_RECV_SESSION_TICKET_CB cb)
{
    ssl->on_recv_session_ticket_callback = cb;
}

/********************SSL_CTX****************************/

/**
 * Create SLIGHT_SSL_CTX object.
 * It is used to pass data to SLIGHT_SSL.
 * @param [meth] function hook version.
 * @see slight_method, slight_client_method
 */
SLIGHT_SSL_CTX *SLIGHT_SSL_CTX_new(const SLIGHT_SSL_METHOD *meth);

/**
 * Free SLIGHT_SSL_CTX
 * @param [ctx] SLIGHT_SSL_CTX pointer
 */
void SLIGHT_SSL_CTX_free(SLIGHT_SSL_CTX* ctx);

/**
 * set slight_ssl version.
 * now only one.
 */
static inline void SLIGHT_SSL_CTX_set_version(SLIGHT_SSL_CTX* ctx,
                                              SLIGHT_SSL_VERSION version){
    ctx->version = version;
}
/**
 * set slight_ssl version, should be called after SLIGHT_SSL_new
 * now only one.
 */
static inline void SLIGHT_SSL_set_version(SLIGHT_SSL* ssl,
                                              SLIGHT_SSL_VERSION version){
    ssl->version = version;
}

/**
 * Set slight_ssl performance callback.
 * It is called by slight_ssl ,pass performance data to application.
 */
static inline int SLIGHT_SSL_CTX_set_performance_cb(SLIGHT_SSL_CTX* ctx,
                                         SLIGHT_SSL_PERFORMANCE_CB perm){
    ctx->ssl_performance_cb = perm;
    return 0;
}

/**
 * Set slight_ssl get_pubkey callback.
 * the user should set the pubkey to slight ssl for slight ssl handshake
 */
static inline void SLIGHT_SSL_CTX_set_pubkey_cb(SLIGHT_SSL_CTX *ctx, SLIGHT_SSL_GET_PUBKEY_CB cb)
{
    ctx->get_pubkey_cb = cb;
}

/**
 * Set session expire time min.
 */
static inline void SLIGHT_SSL_GLOBAL_set_session_expire_time_min(int t)
{
    sssl_g_expire_time_min = t;
}


/**
 * get slight ssl method.
 * we only supply client method of slight ssl in this library.
 */
static inline const SLIGHT_SSL_METHOD* SLIGHT_SSL_method(void)
{
    return slight_ssl_get_method();
}

#define SLIGHT_SSL_client_method SLIGHT_SSL_method


//////////////////// Make interfaces compatible /////////////////////////////////
#if USE_STANDARD_SSL
//SSL
#define SSLv2_method        SLIGHT_SSL_method           /* SSLv2 */
#define SSLv2_server_method slight_server_method        /* SSLv2 */
#define SSLv2_client_method SLIGHT_SSL_client_method    /* SSLv2 */
#define SSLv3_method        SLIGHT_SSL_method           /* SSLv3 */
#define SSLv3_server_method slight_server_method        /* SSLv3 */
#define SSLv3_client_method SLIGHT_SSL_client_method    /* SSLv3 */
#define SSLv23_method       SLIGHT_SSL_method           /* SSLv3 but can rollback to v2 */
#define SSLv23_server_method    slight_server_method    /* SSLv3 but can rollback to v2 */
#define SSLv23_client_method    SLIGHT_SSL_client_method/* SSLv3 but can rollback to v2 */
//TLS
#define TLSv1_method        SLIGHT_SSL_method           /* TLSv1.0 */
#define TLSv1_server_method slight_server_method        /* TLSv1.0 */
#define TLSv1_client_method SLIGHT_SSL_client_method    /* TLSv1.0 */
#define TLSv1_1_method      SLIGHT_SSL_method           /* TLSv1.1 */
#define TLSv1_1_server_method   slight_server_method        /* TLSv1.1 */
#define TLSv1_1_client_method   SLIGHT_SSL_client_method    /* TLSv1.1 */
#define TLSv1_2_method          SLIGHT_SSL_method           /* TLSv1.2 */
#define TLSv1_2_server_method   slight_server_method        /* TLSv1.2 */
#define TLSv1_2_client_method   SLIGHT_SSL_client_method    /* TLSv1.2 */
#endif

#undef USE_STANDARD_SSL


/********************SSL_SPDY****************************/

/**
 * a helper function to set cipher flag in SYN_STREAM.
 * @param [buf]: a buffer of data which contain a SYN_STREAM.
 * @param [flag]: cipher flag, 0 - plaintext, 1 - cipher.
 * @return: error code.
 */
int SSSL_SPDY_set_cipher_flag(uint8_t *buf, int len, int flag);


#endif/*<___SSL_H__>*/

