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

#ifndef __NAL_SESSION_H__
#define __NAL_SESSION_H__

//pre defines
#ifndef HAVE_LIBSLIGHTSSL
 #define HAVE_LIBSLIGHTSSL 1
#endif

#include "NAL_tools.h"
#include "NAL_request.h"
#include "easy_log.h"

typedef struct url_t {
    char *protocol;
    char *host;
    char *username;
    char *passwd;
    char *path;
    char *filename;
    char *param;
    char *path_file;
    int port;
} url_t;

typedef struct NAL_session_handler {
    void (*NAL_session_error)(int error, int syserrorno, void* att);
    int  (*NAL_session_ping)(void* att, int index, bool flags);
    /*
     * It will be called when TCP connection disconnects, for whatever reason.
     */
    void (*NAL_session_disconnect)(void *att, int error, int syserrorno);
    
    
    /*
     * connect failed
     */
    void (*NAL_session_connfail)(void *att, int retry, int error, int syserrorno);
    
    
    /*
     * connected
     */
    void (*NAL_session_connect)(void *att, NAL_connection_count_t *count_ptr);
    
    /*
     * for slight ssl plus
     */
    void (*NAL_session_SSL_shakedone)(void*att, NAL_connection_count_t* count_ptr);
    
    /*
     * for constorm_frame
     */
    void (*NAL_session_custom_frame)(void*att, uint16_t type, uint8_t flags, int32_t length, char *data);
    
    /*
     * many times no read/write event on tcp connection.
     */
    int (*NAL_session_idle)(void *att);
    
    /*
     * Get session idle timeout
     */
    int (*NAL_session_get_idle_timeout)(void *att);
    
    void (*NAL_session_on_writable)(void *att, int size);
    
    /*
     * Put session ticket into blackbox
     */
    int (*NAL_session_putSSLMeta)(void *att, char* ssl_meta, int len);
    
    
    /*
     * Get session ticket into blackbox
     */
    int (*NAL_session_getSSLMeta)(void *att, char* ssl_meta, int* len);
    
    /*
     * bio ping callback
     */
    void (*NAL_session_bio_ping)(void *att, uint32_t ping_id);
} NAL_session_handler;

typedef struct NAL_session_meta {
    NAL_context context;
    NAL_session_handler handler;
    unsigned int    closed:1;
} NAL_session_meta;

// Session refers to a connection in libeasy.
typedef struct NAL_session_t {
    NAL_addr_t addr;
    volatile int customBufferSize;  //the size can be sent before write to socket per connection for custom proto
    uint16_t protocol;
    uint16_t pubkey_seqnum; //slight ssl pubkey seqnum
    NAL_session_meta meta;
} NAL_session_t;

NAL_session_t* NAL_session_Create(char *host, unsigned int port, uint32_t cidx);
void NAL_session_Destory(NAL_session_t* session);


/*
 * do connect
 */
int NAL_session_do_connect(NAL_session_t* session, uint32_t timeout, int retrys);

/*
 * set protocol
 */
int NAL_session_SetProtocol(NAL_session_t* session, NAL_protocol protocol);

/*
 * set slight ssl pubkey
 */
int NAL_session_SetPubkeySeq(NAL_session_t* session, int pubkey_seqnum);

/*
 * Submit a new request.
 * session: Refers to the connection info.
 * request: Request info(url, head, option, etc.).
 */
int NAL_session_SubmitRequest(NAL_session_t* session, NAL_request_t* request);

/*
 * Close a connection.
 * session: Refers to the connection info.
 */
int NAL_session_Close(NAL_session_t* session);

/*
 * Set Socket option for a connection.
 * session: Refers to the connection info.
 * option: The option need to be enabled.
 */
int NAL_session_SetOption(NAL_session_t* session, NAL_option* option);
int NAL_session_SetContext(NAL_session_t* session, void* context);
int NAL_session_SetHandler(NAL_session_t* session, NAL_session_handler handler);

int NAL_session_SetProxy(NAL_session_t* session, const char *proxy_ip, uint16_t proxy_port);

/*
 * Submit a Ping packet.
 * session: Refers to the connection info.
 */
int NAL_session_Ping(NAL_session_t* session, int timeout);


/*
 * Send Bio Ping
 */
int NAL_session_SendBioPing(NAL_session_t *session);;

/*
 * Start TNET module.
 */
int NAL_start_Tnet();


/*
 * Submit a head packet(SPDY).
 * session: Refers to the connection info.
 * head: The head content need to be sent to the peer.
 */
int NAL_session_SendHead(NAL_session_t* session, NAL_head* head);

/*
 * Submit body packets(POST).
 * session: Refers to the connection info.
 * request: Refers to the data body.
 */
int NAL_session_SendData(NAL_session_t* session, NAL_request_t* request);
int NAL_set_thread_callback(void (*on_begin)(void*), void (*on_end)(void*), void* user_data);


/*
 * send constorm frame
 */
int NAL_session_SendFrame(NAL_session_t *session, uint16_t type, uint8_t flags, int32_t length, char *data, int32_t ssl_idx);


/*
 * Initialize TNET module.
 */
int NAL_init_Tnet();


/*
 * Destroy TNET module.
 */
int NAL_destroy_Tnet();

//#ifdef DEBUG_LOG_FILE
/*
 * Init Log config
 */
int NAL_config_log_file(const char *path, int fileSize, int fileNum, int bufferSize);
/*
 * Flush log file
 */
void NAL_log_file_flush();
/*
 * Close log file
 */
void NAL_log_file_close();
//#endif

#ifdef HAVE_LIBSLIGHTSSL
/**
 * @param seqnum    pubkey seqnum
 * @param in        encryped pubkey buffer
 * @param in_len    encryped pubkey size
 * @param out       the space to store decrpted pubkey
 * @param out_len   out buffer size, the out_len should be set after write to out,
 * return   0 for success, and -1 for error
 */
typedef int (*slightssl_get_publicKey_cb)(int seqnum, const char *in, int in_len, char *out, int *out_len);
void NAL_set_slightssl_get_publicKey_cb(slightssl_get_publicKey_cb get_pubkey_cb);
#define TNET_PUBKEY_SG_KEY  "tnet_pksg_key"
#endif

typedef void (*NAL_log_print_pt)(int level, const char *message);
extern void NAL_log_set_print(NAL_log_print_pt p);

int NAL_config_ip_stack_mode(int mode);

/*
 * local DNS reslove
 */
int NAL_resolve_host(NAL_ip_addr_t *ip, const char *host, int port);
#endif
