#ifndef EASY_CONNECTION_H_
#define EASY_CONNECTION_H_

#include "easy_define.h"
#include "easy_io_struct.h"

/**
 * 连接主程序
 */

EASY_CPP_START

// fuction
void easy_connection_on_wakeup(struct ev_loop *loop, ev_async *w, int revents);
int easy_connection_write_socket(easy_connection_t *c);
int easy_connection_sendsocket(easy_connection_t *c);
uint64_t easy_connection_get_packet_id(easy_connection_t *c, void *packet, int flag);
easy_session_t *easy_connection_get_session(easy_connection_t *c, void *packet, uint64_t packet_id);

int easy_connection_send_session_list(easy_list_t *list);
int easy_connection_session_build(easy_session_t *s);
void easy_connection_wakeup_session(easy_connection_t *c);
void easy_connection_destroy(easy_connection_t *c);
int easy_connection_request_done(easy_request_t *c);
void easy_connection_on_readable(struct ev_loop *loop, ev_io *w, int revents);
void easy_connection_on_accs_readable(struct ev_loop *loop, ev_io *w, int revents);
void easy_connection_on_writable(struct ev_loop *loop, ev_io *w, int revents);
void easy_connection_on_udpread(struct ev_loop *loop, ev_io *w, int revents);

void easy_connection_on_udpreadable(struct ev_loop *loop, ev_io *w, int revents);
void easy_connection_on_udpwritable(struct ev_loop *loop, ev_io *w, int revents);

EASY_CPP_END

#endif

