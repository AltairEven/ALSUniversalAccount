
#ifndef  _SSL_FRAME_H__
#define  _SSL_FRAME_H__


#include "slight_ssl.h"
#include "endian.h"
#include "errno.h"
#include "ssl_locl.h"
#include "sys/socket.h"
#include "ssl_log.h"
#include "time.h"
#include "sys/types.h"
#include "cipher.h"
#include "sha256.h"
#include "ecdh.h"
#include "ssl_cycle_buffer.h"
#include "ssl_tool.h"


#define REQUEST_HAND                0x01
#define REQUEST_CIPHER_TEXT         0x02
#define REQUEST_TEXT                0x03
#define REQUEST_HAND_CIPHER_TEXT    0x04
#define REQUEST_SESSION_TICKET_HAND 0x05


#define RESPONCE_CERT_TYPE          0x01  //deprecated type
#define RESPONCE_KEY_INVALID_TYPE   0x02
#define RESPONCE_HAND               0x03
#define RESPONCE_CIPHER_DATA        0x04
#define RESPONCE_DATA               0x05
#define RESPONCE_RST                0x06


int ssl_read_frame_text(SLIGHT_SSL *ssl, uint8_t *buf, int num);
int ssl_write_frame_text(SLIGHT_SSL *ssl, const uint8_t *buf, int num, int type);


static inline int ssl_write_frame_head(data_ctx* ctx, uint8_t *buf)
{
    uint8_t version = ctx->whbit.version;
    uint8_t type = ctx->whbit.type;
    uint32_t length = ctx->whbit.length;
    length = htonl(length);
    uint8_t* ptr = (uint8_t*)&length;
    buf[0] = type | (version << 3);
    buf[1] = ptr[1];
    buf[2] = ptr[2];
    buf[3] = ptr[3];

    return sizeof(uint32_t);
}

static inline int ssl_write_frame_int(uint8_t *buf, uint32_t data)
{
    uint32_t temp = htonl(data);
    uint8_t* ptr = (uint8_t *)&temp;
    buf[0] = ptr[0];
    buf[1] = ptr[1];
    buf[2] = ptr[2];
    buf[3] = ptr[3];
    return sizeof(uint32_t);
}

static inline int ssl_write_frame_int16(uint8_t *buf, uint16_t data)
{
    uint16_t temp = htons(data);
    uint8_t* ptr = (uint8_t *)&temp;
    buf[0] = ptr[0];
    buf[1] = ptr[1];
    return sizeof(uint16_t);
}

static inline int ssl_check_rst_frame(data_ctx* data, rst_code_value* rcv)
{
    if (data->rhbit.type != RESPONCE_RST)
        return 0;

    rcv->code = (uint8_t)((data->rhbit.length >> 16) & 0xFF);
    rcv->value = (uint16_t)(data->rhbit.length & 0xFFFF);
    return 1;
}

static inline int ssl_read_frame_length_judge(data_ctx* ctx)
{
    int err = OK;
    int block = cipher_get_blocksize();
    int mod = 0;

    switch(ctx->rhbit.type){
        case RESPONCE_KEY_INVALID_TYPE:
        case RESPONCE_DATA:
            break;
        case RESPONCE_HAND:
            mod = (ctx->rhbit.length - ctx->rcount) % block;
            break;
        case RESPONCE_CIPHER_DATA:
            mod = (ctx->rhbit.length - ctx->rcount) % block;
            break;
        default:
            /*error Type : error is fatal*/
            err = ERR_INVALID_RESP_TYPE;
    }
    if(mod){
        err = ERR_FRAME_LENGTH_ERR;
    }
    return err;
}


#define RESPONCE_FIXED                      32
#define RECV_BUF_WRITE_POINT(ctx)           BBuffer_get_write_point(&ctx->read)
#define RECV_BUF_READ_POINT(ctx)            BBuffer_get_read_point(&ctx->read)
#define RECV_BUF_SPACE(ctx)                 BBuffer_get_space_size(&ctx->read)
#define RECV_BUF_DATA_LEN(ctx)              BBuffer_get_data_len(&ctx->read)
#define RECV_BUF_WRITE_COUNT(ctx,count)     BBuffer_add_write_point(&ctx->read,count)
#define RECV_BUF_READ_COUNT(ctx,count)      BBuffer_add_read_point(&ctx->read,count)
#define RECV_BUF_RESET(ctx)                 BBuffer_reset(&ctx->read)
#define RECV_BUF_SET_WRITE_COUNT(ctx,count) BBuffer_set_write_point(&ctx->read,count)
#define RECV_BUF_SET_READ_COUNT(ctx,count)  BBuffer_set_read_point(&ctx->read,count)
#define RECV_BUF(ctx)                       BBuffer_get_buffer(&ctx->read)
#define RECV_BUF_SIZE(ctx)                  BBuffer_get_size(&ctx->read)


#define REQUEST_FIXED                       (40 + 128) //Effective data of at least one block
#define SEND_BUF_WRITE_POINT(ctx)           BBuffer_get_write_point(&ctx->write)
#define SEND_BUF_READ_POINT(ctx)            BBuffer_get_read_point(&ctx->write)
#define SEND_BUF_SPACE(ctx)                 BBuffer_get_space_size(&ctx->write)
#define SEND_BUF_DATA_LEN(ctx)              BBuffer_get_data_len(&ctx->write)
#define SEND_BUF_WRITE_COUNT(ctx,count)     BBuffer_add_write_point(&ctx->write,count)
#define SEND_BUF_READ_COUNT(ctx,count)      BBuffer_add_read_point(&ctx->write,count)
#define SEND_BUF_RESET(ctx)                 BBuffer_reset(&ctx->write)
#define SEND_BUF(ctx)                       BBuffer_get_buffer(&ctx->write)
#define SEND_BUF_SIZE(ctx)                  BBuffer_get_size(&ctx->write)


#endif/*<_SSL_FRAME_H__>*/

