#include "easy_port.h"
#ifndef EASY_SLIGHTSSL_V2_H_
#define EASY_SLIGHTSSL_V2_H_

#include "easy_io.h"
#ifdef HAVE_LIBSLIGHTSSL
/*
 * 初始化、释放slightssl资源
 */
int easy_slightssl_init_v2(easy_io_t *eio);
int easy_slightssl_cleanup_v2(easy_io_t *eio);

/*
 * 关闭slightssl连接
 */
int easy_slightssl_connection_destroy_v2(easy_connection_t *c);

/*
 * slightssl握手回调
 */
void easy_slightssl_client_handshake_cb_v2(struct ev_loop *loop, ev_io *w, int revents);

/*
 * 直接slightssl握手
 */
void easy_slightssl_client_handshake_v2(easy_connection_t *c);

#endif
#endif
