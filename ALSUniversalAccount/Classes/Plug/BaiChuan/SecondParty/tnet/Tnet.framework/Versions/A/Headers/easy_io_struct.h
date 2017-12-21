#ifndef EASY_IO_STRUCT_H_
#define EASY_IO_STRUCT_H_

#include "easy_define.h"
#ifdef HAVE_LIBSSL
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/conf.h>
#include <openssl/engine.h>
#include <openssl/evp.h>
#include "easy_bio.h"
#endif
#ifdef HAVE_LIBSLIGHTSSL
#include "slight_ssl.h"
#endif
#include <zlib.h>
#include <pthread.h>
/**
 * IO结构定义
 */

EASY_CPP_START

#define EV_STANDALONE    1
#define EV_USE_MONOTONIC 0
#include "ev.h"
#include "easy_pool.h"
#include "easy_buf.h"
#include "easy_list.h"
#include "easy_atomic.h"
#include "easy_hash.h"
#include "easy_hashx.h"
#include "easy_inet.h"
#include "easy_array.h"

///// define
#define EASY_MAX_THREAD_CNT         64
#define EASY_IOTH_DOING_REQ_CNT     8192
#define EASY_CONN_DOING_REQ_CNT     1024
#define EASY_WARN_LOG_INTERVAL      100
#define EASY_MSS                    1024
#ifndef EASY_MAX_CLIENT_CNT
#define EASY_MAX_CLIENT_CNT         1024
#endif

#define EASY_EVENT_READ             1
#define EASY_EVENT_WRITE            2
#define EASY_EVENT_TIMEOUT          4

#define EASY_TYPE_CLIENT            1

#define EASY_TYPE_MESSAGE           1
#define EASY_TYPE_SESSION           2
#define EASY_TYPE_TASK              3

//通道已经建立，可以发送实际数据
#define EASY_CONN_OK                0
//通道建立中
#define EASY_CONN_CONNECTING        1
#define EASY_CONN_AUTO_CONN         2
#define EASY_CONN_CLOSE             3

#define EASY_CLIENT_DEFAULT_TIMEOUT 4000
#define EASY_IO_BUFFER_SIZE         8192
#define EASY_UDP_BUFFER_SIZE        1500
#define EASY_MESG_READ_AGAIN        1
#define EASY_MESG_WRITE_AGAIN       2
#define EASY_MESG_DESTROY           3
#define EASY_REQUEST_DONE           1
#define EASY_REQUEST_DOING          2

#define EASY_IOV_MAX                256
#define EASY_IOV_SIZE               262144

#define EASY_FILE_READ              1
#define EASY_FILE_WRITE             2
#define EASY_FILE_SENDFILE          3
#define EASY_FILE_WILLNEED          4

#define EASY_DISCONNECT_DIRECT      0x0a
#define EASY_DISCONNECT_ADDR        0x02
#define EASY_DISCONNECT_ALL         0x06
#define EASY_CONNECT_ADDR           0x03
#define EASY_CONNECT_SEND           0x05

// if (? & 0b10) then find stream
#define EASY_TASK_CONNECTION        1
#define EASY_TASK_SEND_DATA         2
#define EASY_TASK_SEND_RST          3

//连接模式
#define EASY_CONNECT_AUTOCONN       0x01
#define EASY_CONNECT_SSL            0x02
//#define EASY_CONNECT_SLIGHTSSL      0x04
#define EASY_CONNECT_MULTISSL       0x08
#define EASY_CONNECT_SLIGHTSSLV2    0x10
//#define EASY_CONNECT_BIO            0x20   //deprecated
//各种连接模式的mode设置。低16位为各种连接模式，高16位为各连接模式的flag
//#define EASY_CONNECT_PROTO_MASK     0xFFFF
//#define EASY_CONNECT_ATT_MASK       (0xFFFF << 16)

//#define EASY_CONNECT_BIO            0x20
#define EASY_CONNECT_L7E            0x40  //将数据传输内容伪装成http请求
#define EASY_CONNECT_SLIGHTSSL_0RTT 0x1000
#define EASY_CONNECT_SLIGHTSSL_1RTT 0x2000
//各种连接模式的mode设置。低16位为各种连接模式，高16位为各slightssl对应的pubkey seqnum
#define EASY_CONNECT_MODE_BITS      16
#define EASY_CONNECT_SSSL_PUBKEY_MASK  (0xFF << EASY_CONNECT_MODE_BITS)
//由于cdn下0rtt初始可发送更多的报文，所以这里需要特殊判定。这里与上层偶合，需要将设置可发送报文数量由业务层控制。
#define EASY_CONNECT_SSSL_TEST_SEQNUM   0
#define EASY_CONNECT_SSSL_CDN_SEQNUM    1
#define EASY_CONNECT_SSSL_ACCS_SEQNUM   3

#define EASY_BIO_PING_SIZE          4
#define EASY_BIO_HDR_SIZE           2

#define EASY_EMPTY_BUFFER           ((void *)-1)

//内存创建 分配错误
#define EASY_REASON_MEM_ERROR                   (-2)
//tcp连接失败 s->errcode中有具体失败的errno
#define EASY_REASON_CONN_ERROR                  (-3)
//通道连接超时
#define EASY_REASON_CONN_TIMEOUT                (-4)
//链接不存在(只有s->status == 0时才会有)
#define EASY_REASON_CONN_NOT_EXISTS             (-5)
//请求超时
#define EASY_REASON_SESSION_TIMEOUT             (-6)
//对端关闭
#define EASY_REASON_SERVER_CLOSE                (-7)
//写数据失败 s->errcode中具体errno
#define EASY_REASON_WRITE_ERROR                 (-8)
//读数据失败 s->errcode中具体errno
#define EASY_REASON_READ_ERROR                  (-9)
//slightssl的读写错误， errcode将放置slightssl返回值
#define EASY_REASON_SLIGHTSSL_ERROR             (-10)
//应用主动disconnet
#define EASY_REASON_DISCONNECT                  (-11)
//spdy初始化失败
#define EASY_REASON_SPDYINIT_ERROR              (-12)
//io线程关闭状态
#define EASY_REASON_IO_STOPED                   (-13)
//session中有部分数据已经被发出去, 此时session被回调了
#define EASY_REASON_INVALID_DATA                (-14)
//上层取消stream
#define EASY_REASON_CANCEL                      (-15)
//16-29为spdy错误码
#define EASY_EAGAIN                             (-48)
//on_init失败
#define EASY_REASON_HTTP_PROXY_ERROR            (-49)
#define EASY_REASON_CB_INIT_ERROR               (-50)
//on_connect失败
#define EASY_REASON_CB_CONN_ERROR               (-51)
//on_decode
#define EASY_REASON_CB_DECODE_ERROR             (-52)
//on_encode
#define EASY_REASON_CB_ENCODE_ERROR             (-53)
//on_process
#define EASY_REASON_CB_PROCESS_ERROR            (-54)
//on_readidle
#define EASY_REASON_CB_READIDLE_ERROR           (-55)
#define EASY_REASON_HANDSHAKE_ERROR             (-56)
#define EASY_REASON_CB_PING_ERROR               (-57)
#define EASY_REASON_CB_IDLE_ERROR               (-58)
#define EASY_REASON_STREAM_NOT_EXIST            (-59)
//60-89为http2错误码

// async + spinlock
#define EASY_BASETH_DEFINE                          \
    easy_baseth_on_start_pt         *on_start;      \
    pthread_t                       tid;            \
    int                             idx, iot;       \
    struct ev_loop                  *loop;          \
    ev_async                        thread_watcher; \
    easy_spin_t                     thread_lock;    \
    easy_list_t                     user_list;      \
    ev_timer                        user_timer;     \
    easy_io_t                       *eio;

///// typedef
typedef struct easy_io_thread_t easy_io_thread_t;
typedef struct easy_request_thread_t easy_request_thread_t;
typedef struct easy_message_t easy_message_t;
typedef struct easy_request_t easy_request_t;
typedef struct easy_connection_t easy_connection_t;
typedef struct easy_message_session_t easy_message_session_t;
typedef struct easy_session_t easy_session_t;
typedef struct easy_task_t easy_task_t;
typedef struct easy_client_t easy_client_t;
typedef struct easy_io_t easy_io_t;
typedef struct easy_io_handler_pt easy_io_handler_pt;
typedef struct easy_http_proxy_t easy_http_proxy_t;
typedef struct easy_io_stat_t easy_io_stat_t;
typedef struct easy_baseth_t easy_baseth_t;
typedef struct easy_thread_pool_t easy_thread_pool_t;
#ifdef HAVE_LIBSSL
typedef struct easy_ssl_t easy_ssl_t;
typedef struct easy_ssl_ctx_t easy_ssl_ctx_t;
typedef struct easy_ssl_connection_t easy_ssl_connection_t;
#endif

typedef int (easy_io_process_pt)(easy_request_t *r);
typedef int (easy_io_cleanup_pt)(easy_request_t *r, void *apacket);
typedef int (easy_request_process_pt)(easy_request_t *r, void *args);
typedef void (easy_io_stat_process_pt)(easy_io_stat_t *iostat);
typedef void *(easy_baseth_on_start_pt)(void *args);
typedef void (easy_baseth_on_process_pt)(easy_baseth_t *th);
typedef void (easy_baseth_on_wakeup_pt)(struct ev_loop *loop, ev_async *w, int revents);
typedef int (easy_read_pt)(easy_connection_t *c, char *buf, int size, int *pending);
typedef int (easy_write_pt)(easy_connection_t *c, easy_list_t *l);
typedef void (easy_ssl_schandler_pt)(easy_connection_t *c);
typedef void (easy_io_thread_cb_pt)(void *user_data);

struct easy_http_proxy_t {
    easy_addr_t             addr;
    easy_addr_t             dest_addr;
    char                    *basic_username;
    char                    *basic_password;
};

struct easy_io_handler_pt {
    void                    *(*decode)(easy_message_t *m);
    int                     (*encode)(easy_request_t *r, void *packet);
    easy_io_process_pt      *process;
    int                     (*spdy_process)(easy_request_t *r, char *data, int len);
    int                     (*spdy_ping_process)(easy_connection_t *c, int ping_id);
    void                    (*spdy_on_custom_frame)(easy_message_t *m, uint16_t type, uint8_t flags, int32_t length, char *data);
    int                     (*on_ping)(easy_connection_t *c, uint32_t ping_id);
    int                     (*do_response)(easy_message_t *m);
    easy_io_cleanup_pt      *spdy_cleanup;
    easy_io_cleanup_pt      *cleanup;
    uint64_t                (*get_packet_id)(easy_connection_t *c, void *packet, int is_outpacket);
    easy_session_t         *(*get_session)(easy_connection_t *c, void *packet, uint64_t packet_id);
    int                     (*on_init) (easy_connection_t *c);
    int                     (*on_connect_fail) (easy_connection_t *c);//通道建立失败
    int                     (*on_connect) (easy_connection_t *c);//通道建立成功
    int                     (*on_disconnect) (easy_connection_t *c);//已经建立的通道断开
    int                     (*on_put_ssl_session) (easy_connection_t *c, char *data, int len); //session持久化
    int                     (*on_get_ssl_session) (easy_connection_t *c, char *data, int *len); //取出session
    int                     (*set_data) (easy_request_t *r, const char *data, int len);
    int                     (*on_idle) (easy_connection_t *c);
    int                     (*on_read_idle) (easy_connection_t *c);
    void                    *user_data, *user_data2;
    int32_t                 window_size;
    int8_t                  is_ssl:1;
	int8_t                  is_udp:1;
	int8_t                  is_spdy:1;
	int8_t                  is_http2:1;
	int8_t                  is_custom_proto:1;
};

// 处理IO的线程
struct easy_io_thread_t {
    EASY_BASETH_DEFINE

    // queue
    easy_list_t             session_list;

    easy_io_thread_cb_pt    *on_begin;
    easy_io_thread_cb_pt    *on_end;
    void                    *user_data;

    // client list
    easy_hash_t             *client_list;
    easy_array_t            *client_array;

    // connected list
    easy_list_t             connected_list;
    easy_list_t             remain_list;
    easy_atomic32_t         doing_request_count;
    uint64_t                done_request_count;
};

// 处理任务的线程
struct easy_request_thread_t {
    EASY_BASETH_DEFINE

    // queue
    int                     task_list_count;
    easy_list_t             task_list;
    easy_list_t             session_list;

    easy_request_process_pt *process;
    void                    *args;
};

// 保存client
struct easy_client_t {
    easy_addr_t             addr;
    easy_connection_t       *c;
    easy_io_handler_pt      *handler;
#ifdef HAVE_LIBSSL
    SSL_SESSION             *ssl_session;
#endif
    easy_hash_list_t        client_list_node;
    void                    *user_data;
    int                     ref;
    uint32_t                timeout : 31;
    uint32_t                readidle_timeout;
    int                     retry_times;
    char                    *server_name;
    easy_http_proxy_t       *http_proxy;
    uint32_t                mode;   //连接模式
};

struct easy_bio_ctx_s;
typedef struct easy_bio_ctx_s easy_bio_ctx_t;

struct easy_connection_t {
    struct ev_loop          *loop;
    easy_pool_t             *pool;
    easy_io_thread_t        *ioth;
    easy_list_t             group_list_node;
    easy_list_t             conn_list_node;

    // file description
    uint32_t                default_msglen;
    uint32_t                first_msglen;
    uint32_t                timeout;
    int                     retry_times;
    int                     reconn_time, reconn_fail;
    int                     idle_time;
    int                     fd, seq;
    easy_addr_t             addr;

    ev_io                   read_watcher;
    ev_io                   write_watcher;
    ev_timer                timeout_watcher;
    ev_timer                readidle_watcher;
    easy_list_t             message_list;//非accs模式的message_list或者accs模式下，idx为0的message_list
    easy_list_t             output_ex; //accs模式下用来发8字节的list

    easy_list_t             output;
    easy_io_handler_pt      *handler;
    easy_read_pt            *read;
    easy_write_pt           *write;
    easy_client_t           *client;
    easy_list_t             session_list;
    easy_hash_t             *send_queue;
    void                    *user_data;

    easy_list_t             task_queue; //用于单向发送队列，不等待服务端的返回，仅用做发送失败时的回调处理

    uint32_t                status : 4;
    uint32_t                event_status : 4;
    uint32_t                type : 1;
    uint32_t                async_conn : 1;
    uint32_t                conn_has_error : 1;
    uint32_t                tcp_cork_flag : 1;
    uint32_t                wait_close : 1;
    uint32_t                read_eof : 1;       //可读的时候，是否已经把tcp里的数据读完标识
    uint32_t                auto_reconn : 1;
    uint32_t                reconn : 1;
    uint32_t                life_idle : 1;
    uint32_t                doing_request_count;
    uint32_t                done_request_count;

    ev_tstamp               wait_client_time, wcs;
    int64_t                 start_time;         //连接开始建立前, 微秒
    ev_tstamp               last_time;          //连接最后一次有'事件'的时间，事件包括可读、可写、连接关闭
    int64_t                 tcp_connected_time; //tcp建连成功的时间，微秒
    /*
     * 握手成功的时间，微秒
     * 只有accs、ssl、slightssl模式下才有效
     * 在proxy模式下，handshaked_time也是只有用了accs/ssl/slightssl才有效
     * 理论上，handshaked_time比on_connect回调被调用的时间更早，更精准
     */
    int64_t                 handshaked_time;    
    int64_t                 slightssl_do_handshake_time;
    int                     reused;

#ifdef HAVE_LIBSLIGHTSSL
    SLIGHT_SSL              *ss;
#endif
    easy_bio_ctx_t          *bio_ctx;

    int32_t                 reason;
    int32_t                 errcode;
    int32_t                 last_good_stream_id;
    int32_t                 last_recv_stream_id;
    int32_t                 last_send_stream_id;
    uint32_t                last_ping_id;
    uint32_t                next_ping_id;
    uint32_t                syn_stream_cnt;
    int32_t                 window_size;
    z_stream                *zst_in;
    z_stream                *zst_out;
    easy_buf_t              *nv;
    easy_hashx_t            *streams;
    void                    *evdata;
    void                    *s;    //the session of the connection related to
    easy_buf_t              *http_proxy_buf;
    uint32_t                mode;   //连接模式
    uint32_t                ping_id; //accs的ping id
};

// ipacket放进来的包, opacket及出去的包
struct easy_request_t {
    easy_message_session_t  *ms;

    easy_list_t             request_list_node;
    easy_list_t             all_node;
    int8_t                  retcode, status, waiting, alone;
    int                     reserved;
    ev_tstamp               start_time;
    void                    *ipacket;
    void                    *opacket;
    void                    *args;
    void                    *user_data;
    void                    *packet;
    void                    *index;
};

#define EASY_MESSAGE_SESSION_HEADER \
    easy_connection_t       *c;     \
    easy_pool_t             *pool;  \
    easy_http_proxy_t       *http_proxy; \
    easy_addr_t             addr;   \
    int8_t                  type;   \
    int8_t                  async;  \
    int8_t                  status; \
    int8_t                  error;  \
    int32_t                 reason; \
    int8_t                  ssl_idx;


struct easy_message_session_t {
    EASY_MESSAGE_SESSION_HEADER
};

// 用于接收, 一个或多个easy_request_t
struct easy_message_t {
    EASY_MESSAGE_SESSION_HEADER
    int                     recycle_cnt;

    easy_buf_t              *input;
    easy_list_t             message_list_node;
    int                     next_read_len;

    void                    *user_data;
};

// session打点数据
#define EASY_SESSION_TIME                       \
    double                  session_start;

// 用于发送, 只带一个easy_request_t
struct easy_session_t {
    EASY_MESSAGE_SESSION_HEADER;
    easy_list_t             session_list_node;
    ev_tstamp               timeout, now;
    uint32_t                readidle_timeout;
    uint32_t                conn_timeout;
    int                     retry_times;
    ev_timer                timeout_watcher;

    easy_hash_list_t        send_queue_hash;
    easy_list_t             send_queue_list;
    easy_io_handler_pt      *handler;
    easy_io_cleanup_pt      *cleanup;
    easy_list_t             *nextb;

    int32_t                 errcode;
    uint64_t                packet_id;
    void                    *thread_ptr;
    EASY_SESSION_TIME
    easy_request_t          r;
    char                    data[0];
};

struct easy_task_t {
    EASY_MESSAGE_SESSION_HEADER;
    easy_list_t             task_list_node;
    uint32_t                task_id;     //to identfy the task
    int32_t                 errcode;
    void                    *user_data;
    void                    *thread_ptr;
    int                     (*process)(easy_task_t *t, easy_connection_t *c);
    int                     (*on_task_fail)(easy_task_t *t, easy_connection_t *c);
    easy_request_t          r;
    easy_list_t             *nextb;
    easy_buf_t              *lastb;
    char                    data[0];
};

// 用于统计处理速度
struct easy_io_stat_t {
    int64_t                 last_cnt;
    ev_tstamp               last_time;
    double                  last_speed;
    double                  total_speed;
    easy_io_stat_process_pt *process;
    easy_io_t               *eio;
};

// easy_io对象
struct easy_io_t {
    easy_pool_t             *pool;
    easy_list_t             eio_list_node;
    easy_spin_t             lock;

    int                     io_thread_count;
    easy_thread_pool_t      *io_thread_pool;
    void                    *user_data;

    // flags
    uint32_t                stoped : 1;
    uint32_t                started : 1;
    uint32_t                tcp_cork : 1;
    uint32_t                tcp_nodelay : 1;
    uint32_t                affinity_enable : 1;
    uint32_t                do_signal : 1;
    uint32_t                block_thread_signal : 1;
    uint32_t                no_delayack : 1;

    int32_t                 send_qlen;
    sigset_t                block_thread_sigset;

#ifdef HAVE_LIBSSL
    easy_ssl_t              *ssl;
#endif
#ifdef HAVE_LIBSLIGHTSSL
    SLIGHT_SSL_CTX          *ss_ctx;
#endif
};

// base thread
struct easy_baseth_t {
    EASY_BASETH_DEFINE
};

struct easy_thread_pool_t {
    int                     thread_count;
    int                     member_size;
    easy_atomic32_t         last_number;
    easy_thread_pool_t      *next;
    char                    *last;
    char                    data[0];
};

#ifdef HAVE_LIBSSL
struct easy_ssl_ctx_t {
    easy_pool_t             *pool;
    SSL_CTX                 *ctx;
    easy_list_t             list_node;
    int                     type;
    struct {
        char                    *file;
        int                     line;
        int                     prefer_server_ciphers;
        uint32_t                verify;
        uint32_t                verify_depth;
        int                     session_timeout;
        int                     session_cache;
        uint64_t                protocols;
        char                    *certificate;
        char                    *certificate_key;
        char                    *dhparam;
        char                    *client_certificate;
        char                    *crl;
        char                    *ciphers;
        char                    *server_name;
        char                    *pass_phrase_dialog;
        int                     session_reuse;
        char                    *next_proto;
    } conf;
};

struct easy_ssl_connection_t {
    SSL                     *connection;
    easy_ssl_schandler_pt   *handler;

    int                     last;
    uint32_t                handshaked : 1;
    uint32_t                renegotiation : 1;
    uint32_t                session_reuse : 1;
};

struct easy_ssl_t {
    easy_list_t             server_list;
    easy_pool_t             *pool;
    easy_hash_t             *server_map;
    easy_hash_t             *client_map;

    easy_ssl_ctx_t          *server_ctx;
    easy_ssl_ctx_t          *client_ctx;
};
#endif

typedef enum {
    EASY_SPDY_PROTOCOL_ERROR            = -0x11,
    EASY_SPDY_INVALID_STREAM            = -0x12,
    EASY_SPDY_REFUSED_STREAM            = -0x13,
    EASY_SPDY_UNSUPPORTED_VERSION       = -0x14,
    EASY_SPDY_CANCEL                    = -0x15,
    EASY_SPDY_INTERNAL_ERROR            = -0x16,
    EASY_SPDY_FLOW_CONTROL_ERROR        = -0x17,
    EASY_SPDY_STREAM_IN_USE             = -0x18,
    EASY_SPDY_STREAM_ALREADY_CLOSED     = -0x19,
    EASY_SPDY_INVALID_CREDENTIALS       = -0x1a,
    EASY_SPDY_FRAME_TOO_LARGE           = -0x1b,
    EASY_SPDY_SESSION_PROTOCOL_ERROR    = -0x1c,
    EASY_SPDY_SESSION_INTERNAL_ERROR    = -0x1d,
} easy_status_code;

EASY_CPP_END

#endif
