
#ifndef  __SSL_LOCL_H__
#define  __SSL_LOCL_H__

#include "stdint.h"
#include "string.h"
#include "sys/types.h"
#include "ssl_cycle_buffer.h"
#include "ecdh.h"
#include "ssl_prefix.h"
#include "ssl_bitmap.h"
#include "cipher.h"
#include <sys/uio.h>


extern int sssl_g_expire_time_min;


#define SSL_REQUEST_PACKAGE_NUM     10
//Determine the cache memory size
#define READ_BUFFER_INIT_SIZE       (16 * 1024)
#define READ_FRAME_LENGTH_LIMIT     (4 * 1024)
#define WRITE_BUFFER_INIT_SIZE      (4 * 1024)
#define WRITEV_BUFFER_INIT_SIZE     8080
//Without considering the timeout
#define EXPIRE_TIME_INIT            0x0
#define EXPIRE_TIME_MIN             (5 * 60)    // 5 minutes
#define SESSION_KEY_LEN             32
#define SESSION_TICKET_LEN_LIMIT    128
#define SSSL_MAC_LEN                32
#define SSL_CERT_LENGTH_LIMIT       128


struct slight_ssl;
typedef struct slight_ssl SLIGHT_SSL;


typedef struct slight_ssl_method {
/// int (*ssl_accept)(SLIGHT_SSL *s);
    int (*ssl_connect)(SLIGHT_SSL *s);
    int (*ssl_read)(SLIGHT_SSL *s, uint8_t *buf, int len);
    int (*ssl_write)(SLIGHT_SSL *s, const uint8_t *buf, int len);
    int (*ssl_shutdown)(SLIGHT_SSL *s);
    int (*ssl_pending)(const SLIGHT_SSL *ssl);
    int (*ssl_write_block)(const SLIGHT_SSL *ssl);
    int (*ssl_write_spdy)(SLIGHT_SSL *s, const uint8_t *buf, int len);
    int (*ssl_writev)(SLIGHT_SSL *ssl, const struct iovec *vector, int count);
} SLIGHT_SSL_METHOD;


/* version */
/* Version -- total 5 bits. bit 0～2 indicates protocol (111-spdy，110-http2.0, 101-custom), bit 3～4 indicates slight ssl version (10 for slight ssl v2)
 ** so current version for slight ssl v2 include three versions: 11010B(0x1A), 11110B(0x1E), 10110(0x16)
 */
typedef enum ssl_version {
//  SLIGHT_VERSION_V1_HTTP =0x19,
//  SLIGHT_VERSION_V1_SPDY =0x1D,
    SLIGHT_VERSION_V2_SPDY =0x1E,
    SLIGHT_VERSION_V2_HTTP2 = 0x1A,
    SLIGHT_VERSION_V2_CUSTOM = 0x16,
} SLIGHT_SSL_VERSION;


/* performance data in ssl structure */
typedef struct ssl_performance_data {
    uint16_t requestnum;     // the number of handshake request has been sent
    uint16_t invalidkey;     // sessionKey invalid count:package is sent by server
    uint16_t keyrequest;     // Active request a new sessionKey
//  uint16_t reserved;       // reserved
    uint64_t requesttime;    // request RTT(include data process time of client and server.)
    uint64_t genrequest;     // the time spent by sending request package
} SLIGHT_SSL_PERFORMANCE_DATA;


/* callback functions type in ssl ctx */
typedef int (*SLIGHT_SSL_PERFORMANCE_CB)(const SLIGHT_SSL_PERFORMANCE_DATA* perm,void* ctx);

typedef int (*SLIGHT_SSL_GET_PUBKEY_CB)(int seqnum, char *buf, int *buf_len);

/* SSL CTX */
typedef struct ssl_ctx_internal {
    SLIGHT_SSL_PERFORMANCE_CB ssl_performance_cb;
    SLIGHT_SSL_GET_PUBKEY_CB get_pubkey_cb;
    SLIGHT_SSL_VERSION version;
    const SLIGHT_SSL_METHOD *method;
} SLIGHT_SSL_CTX;


/* header */
struct slight_header {
    uint32_t   type:3;
    uint32_t   version:5;
    uint32_t   length:24;
};

typedef union ssl_header {
    struct slight_header hbit;
    uint32_t horg;
} ssl_header;

typedef struct rst_code_value_pair {

// define reset code
#define RST_DOWN_GRADE 1
#define RST_SESSION_TICKET_ERROR 2

    uint8_t  code;
    uint16_t value;
    
} rst_code_value;


/* nonce magic code */
#define CLIENT_NONCE_MAGIC     0Xdb
#define SERVER_NONCE_MAGIC     0Xde


/*read status*/
enum {
    READ_INIT = 0,  //init status
    READ_HEAD,      //head receive ok
    READ_SUB_HEAD,  //subhead receive ok
};

/* data context */
typedef struct data_ctx {
    BBuffer     read;
    BBuffer     write;
    ssl_header  rhead;  //read head
    ssl_header  whead;  //write head
    int         rstate; //read state
    int         rcount; //The amount of data read by current Frame
    
#define  rhbit   rhead.hbit
#define  rhorg   rhead.horg
#define  whbit   whead.hbit
#define  whorg   whead.horg
} data_ctx;


/* slight ssl mod */
typedef enum ssl_mod {
    SSL_MOD_UNINIT = 0,// uninitialize value of ssl_mod
    SSL_0_RTT,         // Encrypted transmission of data with 0 RTT
    SSL_1_RTT,         // Encrypted transmission of data with 1 RTT
} SLIGHT_SSL_MOD;


/* state of session */
#define SSL_UNINITILIZE     0   //Not initialized
#define SSL_INITILIZE       1   //Initialization is complete
#define SSL_REQUEST         2   //Have sent a handshake packet
//#define SSL_GET_CERT        3   //Get a certificate invalid package.
#define SSL_KEY_INVLID      4   //Get a sessionKey invalid packet
#define SSL_RESPONCE        5   //Get a response
#define SSL_ERROR           6   //error or invalid status


/* flag of respone frame */
#define SSL_FLAG_MAC        0x80    // whether use mac
#define SSL_FLAG_HMAC       0x40    // whether use hmac


/* spdy context */
typedef struct spdy_cntxt {
    sssl_bitmap* sid_flag;  // the flag for each stream-id to show whether it should encrypt.
                            // index is sid; content is flag: 0 - noencrypt, 1- encrypt
    int32_t frame_length;   // the length of the current frame.
    int     iscipher;       // cipher flag for current frame.
}spdy_context;


/* bio for slight ssl */
struct sssl_bio;
typedef struct sssl_bio SSSL_BIO;

typedef ssize_t (*SSSL_BIO_READ_METHOD)  (SSSL_BIO* bio, void* buf, size_t len, int flags);
typedef ssize_t (*SSSL_BIO_WRITE_METHOD) (SSSL_BIO* bio, const void* buf, size_t len, int flags);

struct sssl_bio {
    // members
    int fd;
    int err_code;
    void* userdata;
    // bio methods
    SSSL_BIO_READ_METHOD  bread;
    SSSL_BIO_WRITE_METHOD bwrite;
};


/* session ticket */
typedef struct sssl_session_ticket_t {
    time_t expire_time;             // expire time of ticket
    int len;                        // ticket length
    uint8_t ticket[SESSION_TICKET_LEN_LIMIT];   // ticket
    uint8_t key[SESSION_KEY_LEN];   // sessio key in ticket
} sssl_session_ticket;

typedef void (*SLIGHT_SSL_RECV_SESSION_TICKET_CB) 
    (SLIGHT_SSL* ssl, void* ticket, int size, void* usercontext);


/* slight ssl structure */
struct slight_ssl {

    data_ctx          data;     // write read Buffer
    BBuffer           readbuf;  // if user buffer size is less than READ_FRAME_LENGTH_LIMIT,
                                // then we will use this buffer to make sure that we can
                                // parse frames when using MAC or HMAC
//  int               fd;       // socket fd
    SSSL_BIO          bio;      // bio (use bio instead of fd)
    SLIGHT_SSL_METHOD method;   // a table of functions' pointers
    int               shutdown; // we have shut things down,0x01 sent,0x02 for received
    int               state;    // session state
    SLIGHT_SSL_CTX    *ctx;      // SSL Context

    //store nonce and key
    union {
        uint8_t nonce[SESSION_KEY_LEN]; // client nonce
        uint8_t key[SESSION_KEY_LEN];   // SessionKey
    } client;
    uint8_t nonce[SESSION_KEY_LEN];     // server nonce
    uint8_t oldkey[SESSION_KEY_LEN];    // old session key
    uint8_t oldnonce[SESSION_KEY_LEN];  // old server nonce (for cookies)

    // key pointers
    uint8_t* send_key;                  // point to the session key for sending
    uint8_t* recv_key;                  // point to the session key for receiving

    int use_ticket;                     // only use ticket at the first time
    sssl_session_ticket ticket;
    SLIGHT_SSL_RECV_SESSION_TICKET_CB on_recv_session_ticket_callback;

    SSSL_AesContextT    aes_ctx;        // aes ctx

    uint8_t             resp_flag;      // flag from the respone frame
    time_t              expire_time;    // expire time of sessionKey
    SLIGHT_SSL_VERSION  version;        // Slight SSL version
    SLIGHT_SSL_MOD      mod;            // SSL: The default mode

    // The handshake packet data transmission
    volatile uint16_t   request_num;    // the number of request can be sent
    uint16_t            request_max;    // Maximum number of handshake send

    void*               usercontext;

    uint32_t            client_cipher_seqnum;   // seqnum in cipher text from client(odd)
    uint32_t            server_cipher_seqnum;   // seqnum in cipher text from server(even)

    // peer key config pointers
    uint32_t            p_seqnum;       // the pointer of the server key serial number
    int                 p_nid;          // the pointer of ecdh nid
    const unsigned char*p_peerkey_ptr;// the pointer of peerkey
    size_t              p_peerkey_size; // the pointer of peerkey size

    EC_KEY*             ecdh_key;       // ecdh key
    EC_POINT*           ecdh_peerkey;   // ecdh peer key
    int                 update_cert;    // whether we updating peer key

    uint8_t             cache_pend[16];
    uint16_t            cache_size;
    uint16_t            cache_off;


    /* A temporary solution to fix 1 rtt bug:
     * if the server send data after connection established like first settings frame in http2,
     * the client will receive application data before sending application data and take is as an error.
     * So the soulution is:
     *      In slight_ssl_connect, if the client received same application data,  then it will save the data back
     * to the received_buf buffer,  and later fetch it in slight_ssl_read
     */
    uint8_t             received_buf[64];
    uint16_t            received_buf_size;

    // performance data of ssl early requests
    SLIGHT_SSL_PERFORMANCE_DATA performance_data;
    int                 send_frame_num[6];
    int                 recv_frame_num[7];

    spdy_context spdy_ctx;
};


#endif/*<__SSL_LOCL_H__>*/

