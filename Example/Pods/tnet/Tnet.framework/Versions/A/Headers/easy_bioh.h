#include "easy_port.h"
#ifdef HAVE_LIBSLIGHTSSL
#ifndef EASY_L7_H_
#define EASY_L7_H_

#include "slight_ssl.h"
#include "easy_define.h"
#include "easy_io_struct.h"

EASY_CPP_START
#define L7_HTTP_CRLF    "\r\n"
#define L7_MAX_RSP_HEADER_SIZE      1024
#define L7_HTTP_POST_HEADER    "POST /L7/ HTTP/1.1"L7_HTTP_CRLF   \
                                "Host: cipher.m.taobao.com"L7_HTTP_CRLF    \
                                "Connection: Keep-Alive"L7_HTTP_CRLF   \
                                "Content-Length: %d"L7_HTTP_CRLF   \
                                "Content-Type: application/octet-stream"L7_HTTP_CRLF   \
                                L7_HTTP_CRLF

#define L7_MAX_SEND_SIZE        (1024*64)

//#define ENABLE_TEST_CODE
#if defined(ENABLE_TEST_CODE)
typedef ssize_t (writev_func)(int fd, const struct iovec *iov, int iovcnt);
extern writev_func *test_writev;
typedef ssize_t (recv_func)(int sockfd, void *buf, size_t len, int flags);
extern recv_func *test_recv;
#endif

enum{
    L7_SEND_INIT,
    L7_SEND_DONE,
    L7_SEND_HEADER,
    L7_SEND_BODY,

    L7_RECV_DONE,
    L7_RECV_HEADER,
    L7_RECV_BODY,
};
struct easy_bio_ctx_s{
    uint16_t    send_state; //发送阶段
    uint16_t    recv_state; //接收阶段
    uint16_t    send_header_size;
    uint16_t    send_header_sent_size;
    uint32_t    send_body_size;
    uint32_t    send_body_sent_size;

    uint16_t    recv_header_size;
    uint16_t    recv_header_body;
    uint32_t    recv_body_total_size;
    uint32_t    recv_body_recv_size;

    char        send_header[2*sizeof(L7_HTTP_POST_HEADER) + 10]; //add max int size
    char        recv_header[L7_MAX_RSP_HEADER_SIZE];
};

//typedef struct easy_bio_ctx_s easy_bio_ctx_t;

/*
 * 替换ssl里面的read/write函数
 * 其中method指向的内存空间需要调用方来管理, 确保生命周期比ssl对象长
 * read/write为空则不替换对应函数
 */
int easy_bioh_init(easy_connection_t *c);

void easy_bioh_destroy(easy_connection_t *c);

EASY_CPP_END
#endif
#endif
