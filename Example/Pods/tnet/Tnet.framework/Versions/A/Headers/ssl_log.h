
#ifndef  __SSL_LOG_H__
#define  __SSL_LOG_H__

#include "stdio.h"

#if DEBUG_LOG
static const char*  hexdata = "0123456789abcdef";

#if defined(USE_EASY_LOG)
    // call easy log interface
    #include "extern_easy_log.h"
    #define sssl_log_printf(msg, arg...) easy_info_log("(%s): "msg, __FUNCTION__, ##arg)
#elif defined(NET_OS_ANDROID)
    #include "android/log.h"
    #define ANDROID_DEBUG 3
    #define sssl_log_printf(msg, arg...) __android_log_print\
        (ANDROID_DEBUG, __FUNCTION__, "(%s): "msg, __FUNCTION__, ##arg)
#else
    #define sssl_log_printf(msg, arg...)   fprintf(stderr, "(%s:%d): "msg"\n", __FILE__,  __LINE__, ##arg)
#endif

/* Change bytes stream data into hex text data, and output as log  */
#define sssl_log_print_buffer(msg, buf, len) sssl_log_print_buffer_def(__FUNCTION__, msg, buf, len)
static inline void sssl_log_print_buffer_def(const char* tag,
        const char* msg, const uint8_t* buf, uint32_t len)
{
    if (!buf || len <= 0) {
        return ;
    }
    if (!tag || !msg) {
        return ;
    }

    uint8_t* temp = (uint8_t*)malloc(len*2 +1);
    if (!temp) {
        return ;
    }
    int i = 0;
    uint8_t data = 0;
    for (i = 0; i < len ; i ++) {
        data = (buf[i] >> 4) & 0x0F;
        temp[i * 2] = hexdata[data];
        data = (buf[i]) & 0x0F;
        temp[i*2 + 1] = hexdata[data];
    }
    temp[len*2] = 0;
    sssl_log_printf("(%s): [%s][data=%s]", tag, msg, temp);
    free(temp);
}

#else

#define sssl_log_printf(msg,...)
#define sssl_log_print_buffer(msg, buf, len)

#endif/*DEBUG_LOG*/

#endif/*__SSL_LOG_H__*/

