/* crypto/bn/bn.h */
/* Copyright (C) 1995-1997 Eric Young (eay@cryptsoft.com)
 * All rights reserved.
 */
/* ====================================================================
 * Copyright (c) 1998-2006 The OpenSSL Project.  All rights reserved.
 * ====================================================================
 *
 * This product includes cryptographic software written by Eric Young
 * (eay@cryptsoft.com).  This product includes software written by Tim
 * Hudson (tjh@cryptsoft.com).
 *
 */
/* ====================================================================
 * Copyright 2002 Sun Microsystems, Inc. ALL RIGHTS RESERVED.
 */

#ifndef HEADER_BN_H
#define HEADER_BN_H

#include "e_os2.h"
#ifndef OPENSSL_NO_FP_API
#include <stdio.h> /* FILE */
#endif
#include "impl_crypto.h"

#ifdef  __cplusplus
extern "C" {
#endif

/* These preprocessor symbols control various aspects of the bignum headers and
 * library code. They're not defined by any "normal" configuration, as they are
 * intended for development and testing purposes. NB: defining all three can be
 * useful for debugging application code as well as openssl itself.
 *
 * BN_DEBUG - turn on various debugging alterations to the bignum code
 * BN_DEBUG_RAND - uses random poisoning of unused words to trip up
 * mismanagement of bignum internals. You must also define BN_DEBUG.
 */
/* #define BN_DEBUG */
/* #define BN_DEBUG_RAND */

#ifndef OPENSSL_SMALL_FOOTPRINT
#define BN_MUL_COMBA
#define BN_SQR_COMBA
#define BN_RECURSION
#endif

/* This next option uses the C libraries (2 word)/(1 word) function.
 * If it is not defined, I use my C version (which is slower).
 * The reason for this flag is that when the particular C compiler
 * library routine is used, and the library is linked with a different
 * compiler, the library is missing.  This mostly happens when the
 * library is built with gcc and then linked using normal cc.  This would
 * be a common occurrence because gcc normally produces code that is
 * 2 times faster than system compilers for the big number stuff.
 * For machines with only one compiler (or shared libraries), this should
 * be on.  Again this in only really a problem on machines
 * using "long long's", are 32bit, and are not using my assembler code. */
#if defined(OPENSSL_SYS_MSDOS) || defined(OPENSSL_SYS_WINDOWS) || \
    defined(OPENSSL_SYS_WIN32) || defined(linux)
# ifndef BN_DIV2W
#  define BN_DIV2W
# endif
#endif

/* assuming long is 64bit - this is the DEC Alpha
 * unsigned long long is only 64 bits :-(, don't define
 * BN_LLONG for the DEC Alpha */
#ifdef SIXTY_FOUR_BIT_LONG
#define BN_ULLONG	unsigned long long
#define BN_ULONG	unsigned long
#define BN_LONG		long
#define BN_BITS		128
#define BN_BYTES	8
#define BN_BITS2	64
#define BN_BITS4	32
#define BN_MASK		(0xffffffffffffffffffffffffffffffffLL)
#define BN_MASK2	(0xffffffffffffffffL)
#define BN_MASK2l	(0xffffffffL)
#define BN_MASK2h	(0xffffffff00000000L)
#define BN_MASK2h1	(0xffffffff80000000L)
#define BN_TBIT		(0x8000000000000000L)
#define BN_DEC_CONV	(10000000000000000000UL)
#define BN_DEC_FMT1	"%lu"
#define BN_DEC_FMT2	"%019lu"
#define BN_DEC_NUM	19
#define BN_HEX_FMT1	"%lX"
#define BN_HEX_FMT2	"%016lX"
#endif

/* This is where the long long data type is 64 bits, but long is 32.
 * For machines where there are 64bit registers, this is the mode to use.
 * IRIX, on R4000 and above should use this mode, along with the relevant
 * assembler code :-).  Do NOT define BN_LLONG.
 */
#ifdef SIXTY_FOUR_BIT
#undef BN_LLONG
#undef BN_ULLONG
#define BN_ULONG	unsigned long long
#define BN_LONG		long long
#define BN_BITS		128
#define BN_BYTES	8
#define BN_BITS2	64
#define BN_BITS4	32
#define BN_MASK2	(0xffffffffffffffffLL)
#define BN_MASK2l	(0xffffffffL)
#define BN_MASK2h	(0xffffffff00000000LL)
#define BN_MASK2h1	(0xffffffff80000000LL)
#define BN_TBIT		(0x8000000000000000LL)
#define BN_DEC_CONV	(10000000000000000000ULL)
#define BN_DEC_FMT1	"%llu"
#define BN_DEC_FMT2	"%019llu"
#define BN_DEC_NUM	19
#define BN_HEX_FMT1	"%llX"
#define BN_HEX_FMT2	"%016llX"
#endif

#ifdef THIRTY_TWO_BIT
#ifdef BN_LLONG
# if defined(_WIN32) && !defined(__GNUC__)
#  define BN_ULLONG	unsigned __int64
#  define BN_MASK	(0xffffffffffffffffI64)
# else
#  define BN_ULLONG	unsigned long long
#  define BN_MASK	(0xffffffffffffffffLL)
# endif
#endif
#define BN_ULONG	unsigned int
#define BN_LONG		int
#define BN_BITS		64
#define BN_BYTES	4
#define BN_BITS2	32
#define BN_BITS4	16
#define BN_MASK2	(0xffffffffL)
#define BN_MASK2l	(0xffff)
#define BN_MASK2h1	(0xffff8000L)
#define BN_MASK2h	(0xffff0000L)
#define BN_TBIT		(0x80000000L)
#define BN_DEC_CONV	(1000000000L)
#define BN_DEC_FMT1	"%u"
#define BN_DEC_FMT2	"%09u"
#define BN_DEC_NUM	9
#define BN_HEX_FMT1	"%X"
#define BN_HEX_FMT2	"%08X"
#endif

/* 2011-02-22 SMS.
 * In various places, a size_t variable or a type cast to size_t was
 * used to perform integer-only operations on pointers.  This failed on
 * VMS with 64-bit pointers (CC /POINTER_SIZE = 64) because size_t is
 * still only 32 bits.  What's needed in these cases is an integer type
 * with the same size as a pointer, which size_t is not certain to be. 
 * The only fix here is VMS-specific.
 */
#if defined(OPENSSL_SYS_VMS)
# if __INITIAL_POINTER_SIZE == 64
#  define PTR_SIZE_INT long long
# else /* __INITIAL_POINTER_SIZE == 64 */
#  define PTR_SIZE_INT int
# endif /* __INITIAL_POINTER_SIZE == 64 [else] */
#else /* defined(OPENSSL_SYS_VMS) */
# define PTR_SIZE_INT size_t
#endif /* defined(OPENSSL_SYS_VMS) [else] */

#define BN_DEFAULT_BITS	1280

#define BN_FLG_MALLOCED		0x01
#define BN_FLG_STATIC_DATA	0x02
#define BN_FLG_CONSTTIME	0x04 /* avoid leaking exponent information through timing,
                                      * sssl_BN_mod_exp_mont() will call sssl_BN_mod_exp_mont_consttime,
                                      * sssl_BN_div() will call BN_div_no_branch,
                                      * sssl_BN_mod_inverse() will call BN_mod_inverse_no_branch.
                                      */

#ifndef OPENSSL_NO_DEPRECATED
#define BN_FLG_EXP_CONSTTIME BN_FLG_CONSTTIME /* deprecated name for the flag */
                                      /* avoid leaking exponent information through timings
                                      * (sssl_BN_mod_exp_mont() will call sssl_BN_mod_exp_mont_consttime) */
#endif

#ifndef OPENSSL_NO_DEPRECATED
#define BN_FLG_FREE		0x8000	/* used for debuging */
#endif
#define BN_set_flags(b,n)	((b)->flags|=(n))
#define BN_get_flags(b,n)	((b)->flags&(n))

/* get a clone of a BIGNUM with changed flags, for *temporary* use only
 * (the two BIGNUMs cannot not be used in parallel!) */
#define BN_with_flags(dest,b,n)  ((dest)->d=(b)->d, \
                                  (dest)->top=(b)->top, \
                                  (dest)->dmax=(b)->dmax, \
                                  (dest)->neg=(b)->neg, \
                                  (dest)->flags=(((dest)->flags & BN_FLG_MALLOCED) \
                                                 |  ((b)->flags & ~BN_FLG_MALLOCED) \
                                                 |  BN_FLG_STATIC_DATA \
                                                 |  (n)))


struct bignum_st
	{
	BN_ULONG *d;	/* Pointer to an array of 'BN_BITS2' bit chunks. */
	int top;	/* Index of last used d +1. */
	/* The next are internal book keeping for bn_expand. */
	int dmax;	/* Size of the d array. */
	int neg;	/* one if the number is negative */
	int flags;
	};

/* Used for montgomery multiplication */
struct bn_mont_ctx_st
	{
	int ri;        /* number of bits in R */
	BIGNUM RR;     /* used to convert to montgomery form */
	BIGNUM N;      /* The modulus */
	BIGNUM Ni;     /* R*(1/R mod N) - N*Ni = 1
	                * (Ni is only stored for bignum algorithm) */
	BN_ULONG n0[2];/* least significant word(s) of Ni;
	                  (type changed with 0.9.9, was "BN_ULONG n0;" before) */
	int flags;
	};

/* Used for reciprocal division/mod functions
 * It cannot be shared between threads
 */
struct bn_recp_ctx_st
	{
	BIGNUM N;	/* the divisor */
	BIGNUM Nr;	/* the reciprocal */
	int num_bits;
	int shift;
	int flags;
	};

/* Used for slow "generation" functions. */
struct bn_gencb_st
	{
	unsigned int ver;	/* To handle binary (in)compatibility */
	void *arg;		/* callback-specific data */
	union
		{
		/* if(ver==1) - handles old style callbacks */
		void (*cb_1)(int, int, void *);
		/* if(ver==2) - new callback style */
		int (*cb_2)(int, int, BN_GENCB *);
		} cb;
	};

/* Macro to populate a BN_GENCB structure with an "old"-style callback */
#define BN_GENCB_set_old(gencb, callback, cb_arg) { \
		BN_GENCB *tmp_gencb = (gencb); \
		tmp_gencb->ver = 1; \
		tmp_gencb->arg = (cb_arg); \
		tmp_gencb->cb.cb_1 = (callback); }
/* Macro to populate a BN_GENCB structure with a "new"-style callback */
#define BN_GENCB_set(gencb, callback, cb_arg) { \
		BN_GENCB *tmp_gencb = (gencb); \
		tmp_gencb->ver = 2; \
		tmp_gencb->arg = (cb_arg); \
		tmp_gencb->cb.cb_2 = (callback); }

#define BN_prime_checks 0 /* default: select number of iterations
			     based on the size of the number */

/* number of Miller-Rabin iterations for an error rate  of less than 2^-80
 * for random 'b'-bit input, b >= 100 (taken from table 4.4 in the Handbook
 * of Applied Cryptography [Menezes, van Oorschot, Vanstone; CRC Press 1996];
 * original paper: Damgaard, Landrock, Pomerance: Average case error estimates
 * for the strong probable prime test. -- Math. Comp. 61 (1993) 177-194) */
#define BN_prime_checks_for_size(b) ((b) >= 1300 ?  2 : \
                                (b) >=  850 ?  3 : \
                                (b) >=  650 ?  4 : \
                                (b) >=  550 ?  5 : \
                                (b) >=  450 ?  6 : \
                                (b) >=  400 ?  7 : \
                                (b) >=  350 ?  8 : \
                                (b) >=  300 ?  9 : \
                                (b) >=  250 ? 12 : \
                                (b) >=  200 ? 15 : \
                                (b) >=  150 ? 18 : \
                                /* b >= 100 */ 27)

#define BN_num_bytes(a)	((sssl_BN_num_bits(a)+7)/8)

/* Note that BN_abs_is_word didn't work reliably for w == 0 until 0.9.8 */
#define BN_abs_is_word(a,w) ((((a)->top == 1) && ((a)->d[0] == (BN_ULONG)(w))) || \
				(((w) == 0) && ((a)->top == 0)))
#define BN_is_zero(a)       ((a)->top == 0)
#define BN_is_one(a)        (BN_abs_is_word((a),1) && !(a)->neg)
#define BN_is_word(a,w)     (BN_abs_is_word((a),(w)) && (!(w) || !(a)->neg))
#define BN_is_odd(a)	    (((a)->top > 0) && ((a)->d[0] & 1))

#define BN_one(a)	(sssl_BN_set_word((a),1))
#define BN_zero_ex(a) \
	do { \
		BIGNUM *_tmp_bn = (a); \
		_tmp_bn->top = 0; \
		_tmp_bn->neg = 0; \
	} while(0)
#ifdef OPENSSL_NO_DEPRECATED
#define BN_zero(a)	BN_zero_ex(a)
#else
#define BN_zero(a)	(sssl_BN_set_word((a),0))
#endif

const BIGNUM *sssl_BN_value_one(void);
BN_CTX *sssl_BN_CTX_new(void);
void	sssl_BN_CTX_free(BN_CTX *c);
void	sssl_BN_CTX_start(BN_CTX *ctx);
BIGNUM *sssl_BN_CTX_get(BN_CTX *ctx);
void	sssl_BN_CTX_end(BN_CTX *ctx);
int     sssl_BN_rand(BIGNUM *rnd, int bits, int top,int bottom);
int     sssl_BN_pseudo_rand(BIGNUM *rnd, int bits, int top,int bottom);
int	sssl_BN_rand_range(BIGNUM *rnd, const BIGNUM *range);
int	sssl_BN_num_bits(const BIGNUM *a);
int	sssl_BN_num_bits_word(BN_ULONG);
BIGNUM *sssl_BN_new(void);
void	sssl_BN_init(BIGNUM *);
void	sssl_BN_clear_free(BIGNUM *a);
BIGNUM *sssl_BN_copy(BIGNUM *a, const BIGNUM *b);
BIGNUM *sssl_BN_bin2bn(const unsigned char *s,int len,BIGNUM *ret);
int	sssl_BN_bn2bin(const BIGNUM *a, unsigned char *to);
int	sssl_BN_sub(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
int	sssl_BN_usub(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
int	sssl_BN_uadd(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
int	sssl_BN_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
int	sssl_BN_mul(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx);
int	sssl_BN_sqr(BIGNUM *r, const BIGNUM *a,BN_CTX *ctx);
/** sssl_BN_set_negative sets sign of a BIGNUM
 * \param  b  pointer to the BIGNUM object
 * \param  n  0 if the BIGNUM b should be positive and a value != 0 otherwise 
 */
void	sssl_BN_set_negative(BIGNUM *b, int n);
/** BN_is_negative returns 1 if the BIGNUM is negative
 * \param  a  pointer to the BIGNUM object
 * \return 1 if a < 0 and 0 otherwise
 */
#define BN_is_negative(a) ((a)->neg != 0)

int	sssl_BN_div(BIGNUM *dv, BIGNUM *rem, const BIGNUM *m, const BIGNUM *d,
	BN_CTX *ctx);
#define BN_mod(rem,m,d,ctx) sssl_BN_div(NULL,(rem),(m),(d),(ctx))
int	sssl_BN_nnmod(BIGNUM *r, const BIGNUM *m, const BIGNUM *d, BN_CTX *ctx);
int	sssl_BN_mod_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, const BIGNUM *m, BN_CTX *ctx);
int	sssl_BN_mod_add_quick(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, const BIGNUM *m);
int	sssl_BN_mod_sub_quick(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, const BIGNUM *m);
int	sssl_BN_mod_mul(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
	const BIGNUM *m, BN_CTX *ctx);
int	sssl_BN_mod_sqr(BIGNUM *r, const BIGNUM *a, const BIGNUM *m, BN_CTX *ctx);
int	sssl_BN_mod_lshift1_quick(BIGNUM *r, const BIGNUM *a, const BIGNUM *m);
int	sssl_BN_mod_lshift_quick(BIGNUM *r, const BIGNUM *a, int n, const BIGNUM *m);

int	sssl_BN_mul_word(BIGNUM *a, BN_ULONG w);
int	sssl_BN_add_word(BIGNUM *a, BN_ULONG w);
int	sssl_BN_sub_word(BIGNUM *a, BN_ULONG w);
int	sssl_BN_set_word(BIGNUM *a, BN_ULONG w);

int	sssl_BN_cmp(const BIGNUM *a, const BIGNUM *b);
void	sssl_BN_free(BIGNUM *a);
int	sssl_BN_is_bit_set(const BIGNUM *a, int n);
int	sssl_BN_lshift(BIGNUM *r, const BIGNUM *a, int n);
int	sssl_BN_lshift1(BIGNUM *r, const BIGNUM *a);

int	sssl_BN_mod_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
	const BIGNUM *m,BN_CTX *ctx);
int	sssl_BN_mod_exp_mont(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
	const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx);
int sssl_BN_mod_exp_mont_consttime(BIGNUM *rr, const BIGNUM *a, const BIGNUM *p,
	const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *in_mont);
int	sssl_BN_mod_exp_mont_word(BIGNUM *r, BN_ULONG a, const BIGNUM *p,
	const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx);

int	sssl_BN_mask_bits(BIGNUM *a,int n);
int	sssl_BN_reciprocal(BIGNUM *r, const BIGNUM *m, int len, BN_CTX *ctx);
int	sssl_BN_rshift(BIGNUM *r, const BIGNUM *a, int n);
int	sssl_BN_rshift1(BIGNUM *r, const BIGNUM *a);
BIGNUM *sssl_BN_dup(const BIGNUM *a);
int	sssl_BN_ucmp(const BIGNUM *a, const BIGNUM *b);
int	sssl_BN_set_bit(BIGNUM *a, int n);
int	sssl_BN_kronecker(const BIGNUM *a,const BIGNUM *b,BN_CTX *ctx); /* returns -2 for error */
BIGNUM *sssl_BN_mod_inverse(BIGNUM *ret,
	const BIGNUM *a, const BIGNUM *n,BN_CTX *ctx);
BIGNUM *sssl_BN_mod_sqrt(BIGNUM *ret,
	const BIGNUM *a, const BIGNUM *n,BN_CTX *ctx);

BN_MONT_CTX *sssl_BN_MONT_CTX_new(void );
void sssl_BN_MONT_CTX_init(BN_MONT_CTX *ctx);
int sssl_BN_mod_mul_montgomery(BIGNUM *r,const BIGNUM *a,const BIGNUM *b,
	BN_MONT_CTX *mont, BN_CTX *ctx);
#define BN_to_montgomery(r,a,mont,ctx)	sssl_BN_mod_mul_montgomery(\
	(r),(a),&((mont)->RR),(mont),(ctx))
int sssl_BN_from_montgomery(BIGNUM *r,const BIGNUM *a,
	BN_MONT_CTX *mont, BN_CTX *ctx);
void sssl_BN_MONT_CTX_free(BN_MONT_CTX *mont);
int sssl_BN_MONT_CTX_set(BN_MONT_CTX *mont,const BIGNUM *mod,BN_CTX *ctx);
BN_MONT_CTX *sssl_BN_MONT_CTX_copy(BN_MONT_CTX *to,BN_MONT_CTX *from);

void	sssl_BN_RECP_CTX_init(BN_RECP_CTX *recp);
void	sssl_BN_RECP_CTX_free(BN_RECP_CTX *recp);
int	sssl_BN_RECP_CTX_set(BN_RECP_CTX *recp,const BIGNUM *rdiv,BN_CTX *ctx);
int	sssl_BN_mod_mul_reciprocal(BIGNUM *r, const BIGNUM *x, const BIGNUM *y,
	BN_RECP_CTX *recp,BN_CTX *ctx);
int	sssl_BN_mod_exp_recp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
	const BIGNUM *m, BN_CTX *ctx);
int	sssl_BN_div_recp(BIGNUM *dv, BIGNUM *rem, const BIGNUM *m,
	BN_RECP_CTX *recp, BN_CTX *ctx);


#if 0
/* faster mod functions for the 'NIST primes' 
 * 0 <= a < p^2 */
int BN_nist_mod_192(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx);
int BN_nist_mod_224(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx);
int BN_nist_mod_256(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx);
int BN_nist_mod_384(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx);
int BN_nist_mod_521(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx);

const BIGNUM *BN_get0_nist_prime_192(void);
const BIGNUM *BN_get0_nist_prime_224(void);
const BIGNUM *BN_get0_nist_prime_256(void);
const BIGNUM *BN_get0_nist_prime_384(void);
const BIGNUM *BN_get0_nist_prime_521(void);
#endif

/* library internal functions */

#define bn_expand(a,bits) ((((((bits+BN_BITS2-1))/BN_BITS2)) <= (a)->dmax)?\
	(a):sssl_bn_expand2((a),(bits+BN_BITS2-1)/BN_BITS2))
#define bn_wexpand(a,words) (((words) <= (a)->dmax)?(a):sssl_bn_expand2((a),(words)))
BIGNUM *sssl_bn_expand2(BIGNUM *a, int words);

/* Bignum consistency macros
 * There is one "API" macro, bn_fix_top(), for stripping leading zeroes from
 * bignum data after direct manipulations on the data. There is also an
 * "internal" macro, bn_check_top(), for verifying that there are no leading
 * zeroes. Unfortunately, some auditing is required due to the fact that
 * bn_fix_top() has become an overabused duct-tape because bignum data is
 * occasionally passed around in an inconsistent state. So the following
 * changes have been made to sort this out;
 * - bn_fix_top()s implementation has been moved to bn_correct_top()
 * - if BN_DEBUG isn't defined, bn_fix_top() maps to bn_correct_top(), and
 *   bn_check_top() is as before.
 * - if BN_DEBUG *is* defined;
 *   - bn_check_top() tries to pollute unused words even if the bignum 'top' is
 *     consistent. (ed: only if BN_DEBUG_RAND is defined)
 *   - bn_fix_top() maps to bn_check_top() rather than "fixing" anything.
 * The idea is to have debug builds flag up inconsistent bignums when they
 * occur. If that occurs in a bn_fix_top(), we examine the code in question; if
 * the use of bn_fix_top() was appropriate (ie. it follows directly after code
 * that manipulates the bignum) it is converted to bn_correct_top(), and if it
 * was not appropriate, we convert it permanently to bn_check_top() and track
 * down the cause of the bug. Eventually, no internal code should be using the
 * bn_fix_top() macro. External applications and libraries should try this with
 * their own code too, both in terms of building against the openssl headers
 * with BN_DEBUG defined *and* linking with a version of OpenSSL built with it
 * defined. This not only improves external code, it provides more test
 * coverage for openssl's own code.
 */

#define bn_pollute(a)
#define bn_check_top(a)
#define bn_fix_top(a)		bn_correct_top(a)


#define bn_correct_top(a) \
{ \
        BN_ULONG *ftl; \
	int tmp_top = (a)->top; \
	if (tmp_top > 0) \
	{ \
		for (ftl= &((a)->d[tmp_top-1]); tmp_top > 0; tmp_top--) \
			if (*(ftl--)) break; \
		(a)->top = tmp_top; \
	} \
	bn_pollute(a); \
}

BN_ULONG sssl_bn_mul_add_words(BN_ULONG *rp, const BN_ULONG *ap, int num, BN_ULONG w);
BN_ULONG sssl_bn_mul_words(BN_ULONG *rp, const BN_ULONG *ap, int num, BN_ULONG w);
void     sssl_bn_sqr_words(BN_ULONG *rp, const BN_ULONG *ap, int num);
BN_ULONG sssl_bn_div_words(BN_ULONG h, BN_ULONG l, BN_ULONG d);
BN_ULONG sssl_bn_add_words(BN_ULONG *rp, const BN_ULONG *ap, const BN_ULONG *bp,int num);
BN_ULONG sssl_bn_sub_words(BN_ULONG *rp, const BN_ULONG *ap, const BN_ULONG *bp,int num);


#ifdef  __cplusplus
}
#endif
#endif
