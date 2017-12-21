#ifndef EASY_MESSAGE_H_
#define EASY_MESSAGE_H_

#include "easy_define.h"
#include "easy_io_struct.h"

/**
 * 接收message
 */

EASY_CPP_START

easy_message_t *easy_message_create(easy_connection_t *c);
easy_message_t *easy_message_create_nlist(easy_connection_t *c);
int easy_message_destroy(easy_message_t *m, int del);
int easy_session_process(easy_session_t *s, int stop);
int easy_session_async(easy_session_t *s, easy_message_t *m);

void easy_task_set_cleanup(easy_task_t *r, easy_buf_t *buf);
void easy_task_destroy(easy_task_t *t);

extern easy_io_process_pt *default_process;
static inline void easy_set_default_process(easy_io_process_pt *process){
    default_process = process;
}
EASY_CPP_END

#endif
