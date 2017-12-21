
#ifndef  __SSL_ERR_H__
#define  __SSL_ERR_H__

enum ErrCode{
    OK                          =   0,
    /*-1: remain to system call*/
    ERR_NO_MEMORY               =   -2,
    ERR_BUFFER_TOO_SMALL        =   -3,
    ERR_ECDH_FAILED             =   -4,
    ERR_STATE_ERROR             =   -5,
    ERR_NOT_SUPPORT             =   -6,
    ERR_R_AGAIN                 =   -7,
    ERR_W_AGAIN                 =   -8,
    ERR_READ_END                =   -9,
    ERR_WRITE_END               =   -10,
    ERR_MAGIC_NUM_WRONG         =   -11,
    ERR_INVALID_RESP_TYPE       =   -12,
    ERR_INVALID_PARAM           =   -13,
    ERR_CERT_TOO_LARGE          =   -14,
    ERR_FRAME_LENGTH_ERR        =   -15,
    ERR_FRAME_TOO_LARGE         =   -16,
    ERR_FRAME_TOO_SMALL         =   -17,
    ERR_RECEIVED_SHUTDOWN       =   -18,
    ERR_SEND_SHUTDOWN           =   -19,
    ERR_SHUTDOWN                =   -20,
    ERR_KEY_TIMEOUT             =   -21,
    ERR_SYS_CALL_TIMEOUT        =   -22,
    ERR_SPDY_FAILED             =   -23,
    ERR_INVALID_CIPHER_SEQNUM   =   -24,
    ERR_INVALID_MAC             =   -25,
    ERR_INVALID_STATE_READING   =   -26,
    ERR_UNINIT_SSL_MODE         =   -27,
    ERR_HANDSHAKE_ERROR         =   -28,
    ERR_STATE_ERROR_GET_CERT    =   -29,
    ERR_GET_PUBKEY              =   -30,

    // transform system-errno to slight ssl error code in the functions ssl_read
    // and ssl_write
    // errcode = ERR_SYSTEM_ERRNO_BASE - errno
    // errno (0 ~ 131) - errcode (-100 ~ -231)
    ERR_SYSTEM_ERRNO_BASE       =   -100,
};


#define SSL_ERROR_NONE          0
#define SSL_ERROR_SSL           1
#define SSL_ERROR_WANT_READ     2
#define SSL_ERROR_WANT_WRITE    3


#define get_last_socket_error() errno
#define clear_socket_error()    errno=0


static inline int SLIGHT_SSL_get_error(int r)
{
    int ret = SSL_ERROR_NONE;
    if (r == ERR_W_AGAIN) {
        ret = SSL_ERROR_WANT_WRITE;
    } else if (r == ERR_R_AGAIN) {
        ret = SSL_ERROR_WANT_READ;
    }
    return ret;
}

#endif/*<__SSL_ERR_H__>*/

