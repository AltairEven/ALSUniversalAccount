/*
 * Network Apaptation Layer for Tnet Library.
 *
 * Copyright (c) Bin Yang <lingming.yb@alibaba-inc.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modifica-
 * tion, are permitted provided that the following conditions are met:
 *
 *   1.  Redistributions of source code must retain the above copyright notice,
 *       this list of conditions and the following disclaimer.
 *
 *   2.  Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MER-
 * CHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO
 * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPE-
 * CIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTH-
 * ERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * Alternatively, the contents of this file may be used under the terms of
 * the GNU General Public License ("GPL") version 2 or any later version,
 * in which case the provisions of the GPL are applicable instead of
 * the above. If you wish to allow the use of your version of this file
 * only under the terms of the GPL and not to allow others to use your
 * version of this file under the BSD license, indicate your decision
 * by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL. If you do not delete the
 * provisions above, a recipient may use your version of this file under
 * either the BSD or the GPL.
 */

#ifndef __NAL_TOOLS_H__
#define __NAL_TOOLS_H__ 
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "easy_io_struct.h"

#define NAL_OK 0
#define NAL_ERROR -1
#define NAL_FAILED -2

#define DEFAULT_TIMEOUT 5000

typedef enum NAL_OPTION 
{
    TIMEOUT = 0,
    TCP_NODELAY
} NAL_OPTION;

typedef struct NAL_option {
    NAL_OPTION *name;
    uint8_t *value;
    int len;
} NAL_option;


typedef struct NAL_data {
    char* data;
    size_t len;
    bool fin;
} NAL_data;
typedef void* NAL_context;

typedef struct NAL_ip_addr {
    uint16_t    family;
    union {
        uint32_t    addr;
        uint8_t     addr6[16];
    } u;
} NAL_ip_addr_t;

typedef struct NAL_addr_t {
    uint16_t family;
    uint16_t proxy_family;
    uint16_t port;
    uint16_t proxy_port;
    union {
        uint32_t addr;
        uint8_t addr6[16];
        char* host;
    } u;
    union {
        uint32_t addr;
        uint8_t addr6[16];
        char *host;
    } proxy;
    uint32_t cidx;
} NAL_addr_t;

#define SlightSSL_PUBKEY_SEQ_CDN   1 //EASY_CONNECT_SSSL_CDN_SEQNUM
#define SlightSSL_PUBKEY_PSEQ_CDN   1 //cdn去黑匣子使用相同的公钥
#define SlightSSL_PUBKEY_SEQ_ACCS  3 //EASY_CONNECT_SSSL_ACCS_SEQNUM
#define SlightSSL_PUBKEY_PSEQ_ACCS  4 //对应aserver明文公钥
#define SlightSSL_PUBKEY_SEQ_TEST  0 //EASY_CONNECT_SSSL_TEST_SEQNUM
#define SlightSSL_PUBKEY_SEQ_AE    5 //for AE
#define SlightSSL_PUBKEY_SEQ_ARUP  6 //for arup
#define SlightSSL_PUBKEY_PSEQ_ARUP  7 //for arup plaintext
#define SlightSSL_PUBKEY_SEQ_ADASH  8 //for adash
#define SlightSSL_PUBKEY_PSEQ_ADASH 9 //for adash plaintext
#define SlightSSL_PUBKEY_SEQ_OPEN 10 //for 第三方
#define SlightSSL_PUBKEY_PSEQ_OPEN 11 //for 第三方 plaintext
typedef enum NAL_protocol {
    NAL_HTTP = 0x0001,              //0
    NAL_SPDY = 0x0002,
    NAL_QUIC = 0x0004,
    NAL_HTTP2 = 0x0008,
    NAL_CustomProto = 0x0010,
    NAL_StandardSSL = 0x0020,
    //NAL_SlightSSL = 0x0040,
    NAL_SlightSSLV2 = 0x0080,
    //NAL_BIO = 0x0100,

    //下面为各协议的flag，放在高16位，不同的协议可以不一样
    NAL_SlightSSL_0_RTT = 0x1000,
    NAL_SlightSSL_1_RTT = 0x2000,
    NAL_SlightSSL_L7E = 0x4000, //slight ssl伪装成明文http请求传输
} NAL_protocol;
#define SSSL_0RTT_SPDY NAL_SlightSSLV2 | NAL_SlightSSL_0_RTT | NAL_SPDY
#define SSSL_1RTT_SPDY NAL_SlightSSLV2 | NAL_SlightSSL_1_RTT | NAL_SPDY
#define SSSL_0RTT_HTTP2 NAL_SlightSSLV2 | NAL_SlightSSL_0_RTT | NAL_HTTP2
#define SSSL_1RTT_HTTP2 NAL_SlightSSLV2 | NAL_SlightSSL_1_RTT | NAL_HTTP2
#define SSSL_0RTT_CUSTOM_PROTO NAL_SlightSSLV2 | NAL_SlightSSL_0_RTT | NAL_CustomProto
#define SSSL_1RTT_CUSTOM_PROTO NAL_SlightSSLV2 | NAL_SlightSSL_1_RTT | NAL_CustomProto
#define L7E_SSSL_0RTT_HTTP2 NAL_SlightSSL_L7E | SSSL_0RTT_HTTP2

enum {
    NAL_ipv4_to_ipv6_auto = 0,  //tnet自动判断，如果是ipv6 only环境，则会将ipv4转成ipv6地址连接
    NAL_ipv4_to_ipv6_on,        //将ipv4地址转成ipv6地址进行连接
    NAL_ipv4_to_ipv6_off        //对ipv4不转成ipv6
};

typedef struct NAL_request_count_t {
    uint64_t request_start;
    uint64_t request_send_start;
    uint64_t request_send_end;
    uint64_t response_start;
    uint64_t response_end;
    int    request_header_raw;
    int    request_header_deflated;
    int    response_header_raw;
    int    response_header_inflated;
    int    request_body;
    int    response_body;
    int    retry_times;
} NAL_request_count_t;

typedef struct NAL_connection_count_t {
    uint64_t conn_start;
    uint64_t conn_end;
    
    int  retry_times;
    uint32_t timeout;
    uint64_t handshake_start;
    uint64_t handshake_end;
    uint64_t handshake_caltime;
    int  session_ticket_reused;
    
    //slight-ssl time
    uint64_t requesttime;
} NAL_connection_count_t;

#define NAL_HTTP_PROTOCOL_ERROR -1000

#endif
