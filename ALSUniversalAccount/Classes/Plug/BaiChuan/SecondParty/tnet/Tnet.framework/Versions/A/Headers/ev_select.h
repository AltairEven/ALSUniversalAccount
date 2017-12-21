/*
 * libev select fd activity backend
 *
 * Copyright (c) 2007,2008,2009,2010 Marc Alexander Lehmann <libev@schmorp.de>
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
 *
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
#include "easy_port.h"

#include <sys/select.h>
#include <inttypes.h>
#define NFDBYTES (NFDBITS / 8)

#include <string.h>

#ifndef PLATFORM_PC
// For Android platform
typedef long fd_mask;
#endif

static void
select_modify (struct ev_loop *loop, int fd, int oev, int nev)
{
    if (oev == nev)
        return;

    {
        int                     word = fd / NFDBITS;
        fd_mask                 mask = 1UL << (fd % NFDBITS);

        if (expect_false (loop->vec_max <= word)) {
            int                     new_max = word + 1;

            loop->vec_ri = ev_realloc (loop->vec_ri, new_max * NFDBYTES);
            loop->vec_ro = ev_realloc (loop->vec_ro, new_max * NFDBYTES); /* could free/malloc */
            loop->vec_wi = ev_realloc (loop->vec_wi, new_max * NFDBYTES);
            loop->vec_wo = ev_realloc (loop->vec_wo, new_max * NFDBYTES); /* could free/malloc */

            for (; loop->vec_max < new_max; ++loop->vec_max)
                ((fd_mask *)loop->vec_ri) [loop->vec_max] =
                    ((fd_mask *)loop->vec_wi) [loop->vec_max] = 0;
        }

        ((fd_mask *)loop->vec_ri) [word] |= mask;

        if (!(nev & EV_READ))
            ((fd_mask *)loop->vec_ri) [word] &= ~mask;

        ((fd_mask *)loop->vec_wi) [word] |= mask;

        if (!(nev & EV_WRITE))
            ((fd_mask *)loop->vec_wi) [word] &= ~mask;
    }
}

#define easy_syserr(reason, info, args...) do{((void (*)(void *,...))reason)((void *)info, args);abort();}while(0)

static void
select_poll (struct ev_loop *loop, ev_tstamp timeout)
{
    struct timeval          tv;
    int                     res;
    int                     fd_setsize;

    EV_RELEASE_CB;
    EV_TV_SET (tv, timeout);

    fd_setsize = loop->vec_max * NFDBYTES;

    memcpy (loop->vec_ro, loop->vec_ri, fd_setsize);
    memcpy (loop->vec_wo, loop->vec_wi, fd_setsize);

    res = select (loop->vec_max * NFDBITS, (fd_set *)loop->vec_ro, (fd_set *)loop->vec_wo, 0, &tv);
    EV_ACQUIRE_CB;

    if (expect_false (res < 0)) {
        if (errno == EBADF)
            fd_ebadf (loop);
        else if (errno == ENOMEM && !syserr_cb)
            fd_enomem (loop);
        else if (errno != EINTR)
            ev_syserr ("(libev) select");
        return;
    }

    {
        int                     word, bit;

        for (word = loop->vec_max; word--; ) {
            fd_mask                 word_r = ((fd_mask *)loop->vec_ro) [word];
            fd_mask                 word_w = ((fd_mask *)loop->vec_wo) [word];

            if (word_r || word_w)
                for (bit = NFDBITS; bit--; ) {
                    fd_mask                 mask = 1UL << bit;
                    int                     events = 0;

                    events |= word_r & mask ? EV_READ  : 0;
                    events |= word_w & mask ? EV_WRITE : 0;

                    if (expect_true (events))
                        fd_event (loop, word * NFDBITS + bit, events);
                }
        }
    }
}

#undef easy_syserr

int inline_size
select_init (struct ev_loop *loop, int flags)
{
    loop->backend_modify = select_modify;
    loop->backend_poll   = select_poll;

    loop->vec_max = 0;
    loop->vec_ri  = 0;
    loop->vec_ro  = 0;
    loop->vec_wi  = 0;
    loop->vec_wo  = 0;

    return EVBACKEND_SELECT;
}

void inline_size
select_destroy (struct ev_loop *loop)
{
    ev_free (loop->vec_ri);
    ev_free (loop->vec_ro);
    ev_free (loop->vec_wi);
    ev_free (loop->vec_wo);
}


