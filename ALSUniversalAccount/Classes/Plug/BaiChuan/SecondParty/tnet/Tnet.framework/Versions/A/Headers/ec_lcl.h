/* crypto/ec/ec_lcl.h */
/*
 * Originally written by Bodo Moeller for the OpenSSL project.
 */
/* ====================================================================
 * Copyright (c) 1998-2010 The OpenSSL Project.  All rights reserved.
 *
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


#include <stdlib.h>
#include "../obj_mac.h"
#include "../ec.h"
#include "../bn.h"

#if defined(__SUNPRO_C)
# if __SUNPRO_C >= 0x520
# pragma error_messages (off,E_ARRAY_OF_INCOMPLETE_NONAME,E_ARRAY_OF_INCOMPLETE)
# endif
#endif

/* Use default functions for poin2oct, oct2point and compressed coordinates */
#define EC_FLAGS_DEFAULT_OCT	0x1

/* Structure details are not part of the exported interface,
 * so all this may change in future versions. */

struct ec_method_st {
	/* Various method flags */
	int flags;
	/* used by sssl_EC_METHOD_get_field_type: */
	int field_type; /* a NID */

	/* used by sssl_EC_GROUP_new, sssl_EC_GROUP_free, sssl_EC_GROUP_clear_free, EC_GROUP_copy: */
	int (*group_init)(EC_GROUP *);
	void (*group_finish)(EC_GROUP *);
	void (*group_clear_finish)(EC_GROUP *);
	int (*group_copy)(EC_GROUP *, const EC_GROUP *);

	/* used by sssl_EC_GROUP_set_curve_GFp, EC_GROUP_get_curve_GFp, */
	/* EC_GROUP_set_curve_GF2m, and EC_GROUP_get_curve_GF2m: */
	int (*group_set_curve)(EC_GROUP *, const BIGNUM *p, const BIGNUM *a, const BIGNUM *b, BN_CTX *);
	int (*group_get_curve)(const EC_GROUP *, BIGNUM *p, BIGNUM *a, BIGNUM *b, BN_CTX *);

	/* used by sssl_EC_GROUP_get_degree: */
	int (*group_get_degree)(const EC_GROUP *);

	/* used by EC_GROUP_check: */
	int (*group_check_discriminant)(const EC_GROUP *, BN_CTX *);

	/* used by sssl_EC_POINT_new, sssl_EC_POINT_free, sssl_EC_POINT_clear_free, sssl_EC_POINT_copy: */
	int (*point_init)(EC_POINT *);
	void (*point_finish)(EC_POINT *);
	void (*point_clear_finish)(EC_POINT *);
	int (*point_copy)(EC_POINT *, const EC_POINT *);

	/* used by sssl_EC_POINT_set_to_infinity,
	 * sssl_EC_POINT_set_Jprojective_coordinates_GFp,
	 * EC_POINT_get_Jprojective_coordinates_GFp,
	 * sssl_EC_POINT_set_affine_coordinates_GFp,     ..._GF2m,
	 * sssl_EC_POINT_get_affine_coordinates_GFp,     ..._GF2m,
	 * sssl_EC_POINT_set_compressed_coordinates_GFp, ..._GF2m:
	 */
	int (*point_set_to_infinity)(const EC_GROUP *, EC_POINT *);
	int (*point_set_Jprojective_coordinates_GFp)(const EC_GROUP *, EC_POINT *,
		const BIGNUM *x, const BIGNUM *y, const BIGNUM *z, BN_CTX *);
	int (*point_get_Jprojective_coordinates_GFp)(const EC_GROUP *, const EC_POINT *,
		BIGNUM *x, BIGNUM *y, BIGNUM *z, BN_CTX *);
	int (*point_set_affine_coordinates)(const EC_GROUP *, EC_POINT *,
		const BIGNUM *x, const BIGNUM *y, BN_CTX *);
	int (*point_get_affine_coordinates)(const EC_GROUP *, const EC_POINT *,
		BIGNUM *x, BIGNUM *y, BN_CTX *);
	int (*point_set_compressed_coordinates)(const EC_GROUP *, EC_POINT *,
		const BIGNUM *x, int y_bit, BN_CTX *);

	/* used by sssl_EC_POINT_point2oct, sssl_EC_POINT_oct2point: */
	size_t (*point2oct)(const EC_GROUP *, const EC_POINT *, point_conversion_form_t form,
	        unsigned char *buf, size_t len, BN_CTX *);
	int (*oct2point)(const EC_GROUP *, EC_POINT *,
	        const unsigned char *buf, size_t len, BN_CTX *);

	/* used by sssl_EC_POINT_add, sssl_EC_POINT_dbl, ECP_POINT_invert: */
	int (*add)(const EC_GROUP *, EC_POINT *r, const EC_POINT *a, const EC_POINT *b, BN_CTX *);
	int (*dbl)(const EC_GROUP *, EC_POINT *r, const EC_POINT *a, BN_CTX *);
	int (*invert)(const EC_GROUP *, EC_POINT *, BN_CTX *);

	/* used by sssl_EC_POINT_is_at_infinity, sssl_EC_POINT_is_on_curve, sssl_EC_POINT_cmp: */
	int (*is_at_infinity)(const EC_GROUP *, const EC_POINT *);
	int (*is_on_curve)(const EC_GROUP *, const EC_POINT *, BN_CTX *);
	int (*point_cmp)(const EC_GROUP *, const EC_POINT *a, const EC_POINT *b, BN_CTX *);

	/* used by EC_POINT_make_affine, sssl_EC_POINTs_make_affine: */
	int (*make_affine)(const EC_GROUP *, EC_POINT *, BN_CTX *);
	int (*points_make_affine)(const EC_GROUP *, size_t num, EC_POINT *[], BN_CTX *);

	/* used by sssl_EC_POINTs_mul, sssl_EC_POINT_mul, EC_POINT_precompute_mult, EC_POINT_have_precompute_mult
	 * (default implementations are used if the 'mul' pointer is 0): */
	int (*mul)(const EC_GROUP *group, EC_POINT *r, const BIGNUM *scalar,
		size_t num, const EC_POINT *points[], const BIGNUM *scalars[], BN_CTX *);
	int (*precompute_mult)(EC_GROUP *group, BN_CTX *);
	int (*have_precompute_mult)(const EC_GROUP *group);


	/* internal functions */

	/* 'field_mul', 'field_sqr', and 'field_div' can be used by 'add' and 'dbl' so that
	 * the same implementations of point operations can be used with different
	 * optimized implementations of expensive field operations: */
	int (*field_mul)(const EC_GROUP *, BIGNUM *r, const BIGNUM *a, const BIGNUM *b, BN_CTX *);
	int (*field_sqr)(const EC_GROUP *, BIGNUM *r, const BIGNUM *a, BN_CTX *);
	int (*field_div)(const EC_GROUP *, BIGNUM *r, const BIGNUM *a, const BIGNUM *b, BN_CTX *);

	int (*field_encode)(const EC_GROUP *, BIGNUM *r, const BIGNUM *a, BN_CTX *); /* e.g. to Montgomery */
	int (*field_decode)(const EC_GROUP *, BIGNUM *r, const BIGNUM *a, BN_CTX *); /* e.g. from Montgomery */
	int (*field_set_to_one)(const EC_GROUP *, BIGNUM *r, BN_CTX *);
} /* EC_METHOD */;

typedef struct ec_extra_data_st {
	struct ec_extra_data_st *next;
	void *data;
	void *(*dup_func)(void *);
	void (*free_func)(void *);
	void (*clear_free_func)(void *);
} EC_EXTRA_DATA; /* used in EC_GROUP */

struct ec_group_st {
	const EC_METHOD *meth;

	EC_POINT *generator; /* optional */
	BIGNUM order, cofactor;

	int curve_name;/* optional NID for named curve */
	int asn1_flag; /* flag to control the asn1 encoding */
	point_conversion_form_t asn1_form;

	unsigned char *seed; /* optional seed for parameters (appears in ASN1) */
	size_t seed_len;

	EC_EXTRA_DATA *extra_data; /* linked list */

	/* The following members are handled by the method functions,
	 * even if they appear generic */
	
	BIGNUM field; /* Field specification.
	               * For curves over GF(p), this is the modulus;
	               * for curves over GF(2^m), this is the 
	               * irreducible polynomial defining the field.
	               */

	int poly[6]; /* Field specification for curves over GF(2^m).
	              * The irreducible f(t) is then of the form:
	              *     t^poly[0] + t^poly[1] + ... + t^poly[k]
	              * where m = poly[0] > poly[1] > ... > poly[k] = 0.
	              * The array is terminated with poly[k+1]=-1.
	              * All elliptic curve irreducibles have at most 5
	              * non-zero terms.
	              */

	BIGNUM a, b; /* Curve coefficients.
	              * (Here the assumption is that BIGNUMs can be used
	              * or abused for all kinds of fields, not just GF(p).)
	              * For characteristic  > 3,  the curve is defined
	              * by a Weierstrass equation of the form
	              *     y^2 = x^3 + a*x + b.
	              * For characteristic  2,  the curve is defined by
	              * an equation of the form
	              *     y^2 + x*y = x^3 + a*x^2 + b.
	              */

	int a_is_minus3; /* enable optimized point arithmetics for special case */

	void *field_data1; /* method-specific (e.g., Montgomery structure) */
	void *field_data2; /* method-specific */
	int (*field_mod_func)(BIGNUM *, const BIGNUM *, const BIGNUM *,	BN_CTX *); /* method-specific */
} /* EC_GROUP */;

struct ec_key_st {
	int version;

	EC_GROUP *group;

	EC_POINT *pub_key;
	BIGNUM	 *priv_key;

	unsigned int enc_flag;
	point_conversion_form_t conv_form;

	int 	references;
	int	flags;

	EC_EXTRA_DATA *method_data;
} /* EC_KEY */;

/* Basically a 'mixin' for extra data, but available for EC_GROUPs/EC_KEYs only
 * (with visibility limited to 'package' level for now).
 * We use the function pointers as index for retrieval; this obviates
 * global ex_data-style index tables.
 */
int sssl_EC_EX_DATA_set_data(EC_EXTRA_DATA **, void *data,
	void *(*dup_func)(void *), void (*free_func)(void *), void (*clear_free_func)(void *));
void *sssl_EC_EX_DATA_get_data(const EC_EXTRA_DATA *,
	void *(*dup_func)(void *), void (*free_func)(void *), void (*clear_free_func)(void *));
void sssl_EC_EX_DATA_free_all_data(EC_EXTRA_DATA **);
void sssl_EC_EX_DATA_clear_free_all_data(EC_EXTRA_DATA **);



struct ec_point_st {
	const EC_METHOD *meth;

	/* All members except 'meth' are handled by the method functions,
	 * even if they appear generic */

	BIGNUM X;
	BIGNUM Y;
	BIGNUM Z; /* Jacobian projective coordinates:
	           * (X, Y, Z)  represents  (X/Z^2, Y/Z^3)  if  Z != 0 */
	int Z_is_one; /* enable optimized point arithmetics for special case */
} /* EC_POINT */;



/* method functions in ec_mult.c
 * (ec_lib.c uses these as defaults if group->method->mul is 0) */
int sssl_ec_wNAF_mul(const EC_GROUP *group, EC_POINT *r, const BIGNUM *scalar,
	size_t num, const EC_POINT *points[], const BIGNUM *scalars[], BN_CTX *);


/* method functions in ecp_smpl.c */
int sssl_ec_GFp_simple_group_init(EC_GROUP *);
void sssl_ec_GFp_simple_group_finish(EC_GROUP *);
void sssl_ec_GFp_simple_group_clear_finish(EC_GROUP *);
int sssl_ec_GFp_simple_group_copy(EC_GROUP *, const EC_GROUP *);
int sssl_ec_GFp_simple_group_set_curve(EC_GROUP *, const BIGNUM *p, const BIGNUM *a, const BIGNUM *b, BN_CTX *);
int sssl_ec_GFp_simple_group_get_curve(const EC_GROUP *, BIGNUM *p, BIGNUM *a, BIGNUM *b, BN_CTX *);
int sssl_ec_GFp_simple_group_get_degree(const EC_GROUP *);
int sssl_ec_GFp_simple_group_check_discriminant(const EC_GROUP *, BN_CTX *);
int sssl_ec_GFp_simple_point_init(EC_POINT *);
void sssl_ec_GFp_simple_point_finish(EC_POINT *);
void sssl_ec_GFp_simple_point_clear_finish(EC_POINT *);
int sssl_ec_GFp_simple_point_copy(EC_POINT *, const EC_POINT *);
int sssl_ec_GFp_simple_point_set_to_infinity(const EC_GROUP *, EC_POINT *);
int sssl_ec_GFp_simple_set_Jprojective_coordinates_GFp(const EC_GROUP *, EC_POINT *,
	const BIGNUM *x, const BIGNUM *y, const BIGNUM *z, BN_CTX *);
int sssl_ec_GFp_simple_get_Jprojective_coordinates_GFp(const EC_GROUP *, const EC_POINT *,
	BIGNUM *x, BIGNUM *y, BIGNUM *z, BN_CTX *);
int sssl_ec_GFp_simple_point_set_affine_coordinates(const EC_GROUP *, EC_POINT *,
	const BIGNUM *x, const BIGNUM *y, BN_CTX *);
int sssl_ec_GFp_simple_point_get_affine_coordinates(const EC_GROUP *, const EC_POINT *,
	BIGNUM *x, BIGNUM *y, BN_CTX *);
int sssl_ec_GFp_simple_set_compressed_coordinates(const EC_GROUP *, EC_POINT *,
	const BIGNUM *x, int y_bit, BN_CTX *);
size_t sssl_ec_GFp_simple_point2oct(const EC_GROUP *, const EC_POINT *, point_conversion_form_t form,
	unsigned char *buf, size_t len, BN_CTX *);
int sssl_ec_GFp_simple_oct2point(const EC_GROUP *, EC_POINT *,
	const unsigned char *buf, size_t len, BN_CTX *);
int sssl_ec_GFp_simple_add(const EC_GROUP *, EC_POINT *r, const EC_POINT *a, const EC_POINT *b, BN_CTX *);
int sssl_ec_GFp_simple_dbl(const EC_GROUP *, EC_POINT *r, const EC_POINT *a, BN_CTX *);
int sssl_ec_GFp_simple_invert(const EC_GROUP *, EC_POINT *, BN_CTX *);
int sssl_ec_GFp_simple_is_at_infinity(const EC_GROUP *, const EC_POINT *);
int sssl_ec_GFp_simple_is_on_curve(const EC_GROUP *, const EC_POINT *, BN_CTX *);
int sssl_ec_GFp_simple_cmp(const EC_GROUP *, const EC_POINT *a, const EC_POINT *b, BN_CTX *);
int sssl_ec_GFp_simple_make_affine(const EC_GROUP *, EC_POINT *, BN_CTX *);
int sssl_ec_GFp_simple_points_make_affine(const EC_GROUP *, size_t num, EC_POINT *[], BN_CTX *);
//int ec_GFp_simple_field_mul(const EC_GROUP *, BIGNUM *r, const BIGNUM *a, const BIGNUM *b, BN_CTX *);
//int ec_GFp_simple_field_sqr(const EC_GROUP *, BIGNUM *r, const BIGNUM *a, BN_CTX *);


/* method functions in ecp_mont.c */
int sssl_ec_GFp_mont_group_init(EC_GROUP *);
int sssl_ec_GFp_mont_group_set_curve(EC_GROUP *, const BIGNUM *p, const BIGNUM *a, const BIGNUM *b, BN_CTX *);
void sssl_ec_GFp_mont_group_finish(EC_GROUP *);
void sssl_ec_GFp_mont_group_clear_finish(EC_GROUP *);
int sssl_ec_GFp_mont_group_copy(EC_GROUP *, const EC_GROUP *);
int sssl_ec_GFp_mont_field_mul(const EC_GROUP *, BIGNUM *r, const BIGNUM *a, const BIGNUM *b, BN_CTX *);
int sssl_ec_GFp_mont_field_sqr(const EC_GROUP *, BIGNUM *r, const BIGNUM *a, BN_CTX *);
int sssl_ec_GFp_mont_field_encode(const EC_GROUP *, BIGNUM *r, const BIGNUM *a, BN_CTX *);
int sssl_ec_GFp_mont_field_decode(const EC_GROUP *, BIGNUM *r, const BIGNUM *a, BN_CTX *);
int sssl_ec_GFp_mont_field_set_to_one(const EC_GROUP *, BIGNUM *r, BN_CTX *);


#if 0
/* method functions in ecp_nist.c */
int ec_GFp_nist_group_copy(EC_GROUP *dest, const EC_GROUP *src);
int ec_GFp_nist_group_set_curve(EC_GROUP *, const BIGNUM *p, const BIGNUM *a, const BIGNUM *b, BN_CTX *);
int ec_GFp_nist_field_mul(const EC_GROUP *, BIGNUM *r, const BIGNUM *a, const BIGNUM *b, BN_CTX *);
int ec_GFp_nist_field_sqr(const EC_GROUP *, BIGNUM *r, const BIGNUM *a, BN_CTX *);


#ifndef OPENSSL_EC_NISTP_64_GCC_128
/* method functions in ecp_nistp224.c */
int ec_GFp_nistp224_group_init(EC_GROUP *group);
int ec_GFp_nistp224_group_set_curve(EC_GROUP *group, const BIGNUM *p, const BIGNUM *a, const BIGNUM *n, BN_CTX *);
int ec_GFp_nistp224_point_get_affine_coordinates(const EC_GROUP *group, const EC_POINT *point, BIGNUM *x, BIGNUM *y, BN_CTX *ctx);
int ec_GFp_nistp224_mul(const EC_GROUP *group, EC_POINT *r, const BIGNUM *scalar, size_t num, const EC_POINT *points[], const BIGNUM *scalars[], BN_CTX *);
int ec_GFp_nistp224_points_mul(const EC_GROUP *group, EC_POINT *r, const BIGNUM *scalar, size_t num, const EC_POINT *points[], const BIGNUM *scalars[], BN_CTX *ctx);
int ec_GFp_nistp224_precompute_mult(EC_GROUP *group, BN_CTX *ctx);
int ec_GFp_nistp224_have_precompute_mult(const EC_GROUP *group);

/* method functions in ecp_nistp256.c */
int ec_GFp_nistp256_group_init(EC_GROUP *group);
int ec_GFp_nistp256_group_set_curve(EC_GROUP *group, const BIGNUM *p, const BIGNUM *a, const BIGNUM *n, BN_CTX *);
int ec_GFp_nistp256_point_get_affine_coordinates(const EC_GROUP *group, const EC_POINT *point, BIGNUM *x, BIGNUM *y, BN_CTX *ctx);
int ec_GFp_nistp256_mul(const EC_GROUP *group, EC_POINT *r, const BIGNUM *scalar, size_t num, const EC_POINT *points[], const BIGNUM *scalars[], BN_CTX *);
int ec_GFp_nistp256_points_mul(const EC_GROUP *group, EC_POINT *r, const BIGNUM *scalar, size_t num, const EC_POINT *points[], const BIGNUM *scalars[], BN_CTX *ctx);
int ec_GFp_nistp256_precompute_mult(EC_GROUP *group, BN_CTX *ctx);
int ec_GFp_nistp256_have_precompute_mult(const EC_GROUP *group);

/* method functions in ecp_nistp521.c */
int ec_GFp_nistp521_group_init(EC_GROUP *group);
int ec_GFp_nistp521_group_set_curve(EC_GROUP *group, const BIGNUM *p, const BIGNUM *a, const BIGNUM *n, BN_CTX *);
int ec_GFp_nistp521_point_get_affine_coordinates(const EC_GROUP *group, const EC_POINT *point, BIGNUM *x, BIGNUM *y, BN_CTX *ctx);
int ec_GFp_nistp521_mul(const EC_GROUP *group, EC_POINT *r, const BIGNUM *scalar, size_t num, const EC_POINT *points[], const BIGNUM *scalars[], BN_CTX *);
int ec_GFp_nistp521_points_mul(const EC_GROUP *group, EC_POINT *r, const BIGNUM *scalar, size_t num, const EC_POINT *points[], const BIGNUM *scalars[], BN_CTX *ctx);
int ec_GFp_nistp521_precompute_mult(EC_GROUP *group, BN_CTX *ctx);
int ec_GFp_nistp521_have_precompute_mult(const EC_GROUP *group);

/* utility functions in ecp_nistputil.c */
void ec_GFp_nistp_points_make_affine_internal(size_t num, void *point_array,
	size_t felem_size, void *tmp_felems,
	void (*felem_one)(void *out),
	int (*felem_is_zero)(const void *in),
	void (*felem_assign)(void *out, const void *in),
	void (*felem_square)(void *out, const void *in),
	void (*felem_mul)(void *out, const void *in1, const void *in2),
	void (*felem_inv)(void *out, const void *in),
	void (*felem_contract)(void *out, const void *in));
void ec_GFp_nistp_recode_scalar_bits(unsigned char *sign, unsigned char *digit, unsigned char in);
#endif
#endif
