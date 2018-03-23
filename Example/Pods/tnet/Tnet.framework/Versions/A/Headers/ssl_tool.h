
#ifndef  __SSL_TOOL_H__
#define  __SSL_TOOL_H__

#include <sys/time.h>
#include <arpa/inet.h>


static inline int get_time(struct timeval *tv)
{
    return gettimeofday(tv, 0);
}

static inline uint64_t get_time64_ms()
{
    struct timeval tv;
    get_time(&tv);
    uint64_t sec = tv.tv_sec;
    return sec * 1000 + tv.tv_usec / 1000;
}

static inline uint64_t get_time64_us()
{
    struct timeval tv;
    get_time(&tv);
    uint64_t sec = tv.tv_sec;
    return sec * 1000000 + tv.tv_usec;
}


static inline void rand_buffer(uint8_t* buf, int len)
{
    int i;
    const int rmax = 255;

    for (i = 0; i < len; i++) {
        buf[i] = (rand() * 1.0 / RAND_MAX) * rmax;
    }
}


static inline uint32_t ssl_read_uint32(uint8_t* buf)
{
    uint32_t num = *(uint32_t*)buf;
    return ntohl(num);
}

static inline uint16_t ssl_read_uint16(uint8_t* buf)
{
    uint16_t num = *(uint16_t*)buf;
    return ntohs(num);
}

#endif/*__SSL_TOOL_H__*/

