
#ifndef  __SSL_CYCLE_BUFFER_H__
#define  __SSL_CYCLE_BUFFER_H__


#include "stdint.h"
#include "stdlib.h"
#include "slight_err.h"


typedef  struct BBuffer   BBuffer ,*pBBuffer;

struct BBuffer {
    uint8_t* buffer;//buffer
    uint32_t size;  //buffer max size
    uint32_t woff;  //buffer write offset
    uint32_t roff;  //buffer read offset
};


//pBBuffer BBuffer_new(uint32_t size);
//int BBuffer_free(pBBuffer bf);
int BBuffer_init(pBBuffer pb, uint32_t size);
int BBuffer_uninit(pBBuffer bf);


static inline int BBuffer_is_init(pBBuffer pb)
{
    return (pb->buffer != NULL);
}

static inline uint8_t* BBuffer_get_write_point(pBBuffer pb)
{
    return (uint8_t*)(pb->buffer + pb->woff);
}

static inline uint8_t* BBuffer_get_read_point(pBBuffer pb)
{
    return (uint8_t*)(pb->buffer + pb->roff);
}

static inline uint32_t BBuffer_get_space_size(pBBuffer pb)
{
    return pb->size - pb->woff ;
}

static inline uint32_t BBuffer_get_data_len(pBBuffer pb)
{
    return pb->woff - pb->roff;
}

static inline void BBuffer_add_write_point(pBBuffer pb, int count)
{
    pb->woff += count;
}

static inline void BBuffer_add_read_point(pBBuffer pb, int count)
{
    pb->roff += count;
}

static inline void BBuffer_reset(pBBuffer pb)
{
    pb->roff = 0;
    pb->woff = 0;
}

static inline void BBuffer_set_write_point(pBBuffer pb, int count)
{
    pb->woff = count;
}

static inline void BBuffer_set_read_point(pBBuffer pb, int count)
{
    pb->roff = count;
}

static inline uint8_t* BBuffer_get_buffer(pBBuffer pb)
{
    return pb->buffer;
}

static inline int BBuffer_get_size(pBBuffer pb)
{
    return pb->size;
}

#endif/*__SSL_CYCLE_BUFFER_H__*/

