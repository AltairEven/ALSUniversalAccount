/*
 * ecdh.h - header file for ecdh.c
 *
 * Author: Linghua < peihua.zph @ alibaba-inc.com >
 */

#ifndef ECDH_CIPHER_H
#define ECDH_CIPHER_H

#include <stddef.h>
#include "ec.h"


/*
 * get keys pair (private key/public key) by curve name
 * 
 * nid:	curve name, has been defined:
 *		nid:704  comment: SECG/WTLS curve over a 112 bit prime field
 *		nid:705  comment: SECG curve over a 112 bit prime field
 *		nid:706  comment: SECG curve over a 128 bit prime field
 *		nid:707  comment: SECG curve over a 128 bit prime field
 *		nid:708  comment: SECG curve over a 160 bit prime field
 *		nid:709  comment: SECG curve over a 160 bit prime field
 *		nid:710  comment: SECG/WTLS curve over a 160 bit prime field
 *		nid:711  comment: SECG curve over a 192 bit prime field
 *		nid:712  comment: SECG curve over a 224 bit prime field
 *		nid:713  comment: NIST/SECG curve over a 224 bit prime field
 *		nid:714  comment: SECG curve over a 256 bit prime field
 *		nid:715  comment: NIST/SECG curve over a 384 bit prime field
 *		nid:716  comment: NIST/SECG curve over a 521 bit prime field
 *		nid:409  comment: NIST/X9.62/SECG curve over a 192 bit prime field
 *		nid:410  comment: X9.62 curve over a 192 bit prime field
 *		nid:411  comment: X9.62 curve over a 192 bit prime field
 *		nid:412  comment: X9.62 curve over a 239 bit prime field
 *		nid:413  comment: X9.62 curve over a 239 bit prime field
 *		nid:414  comment: X9.62 curve over a 239 bit prime field
 *		nid:415  comment: X9.62/SECG curve over a 256 bit prime field
 *		nid:717  comment: SECG curve over a 113 bit binary field
 *		nid:718  comment: SECG curve over a 113 bit binary field
 *		nid:719  comment: SECG/WTLS curve over a 131 bit binary field
 *		nid:720  comment: SECG curve over a 131 bit binary field
 *		nid:721  comment: NIST/SECG/WTLS curve over a 163 bit binary field
 *		nid:722  comment: SECG curve over a 163 bit binary field
 *		nid:723  comment: NIST/SECG curve over a 163 bit binary field
 *		nid:724  comment: SECG curve over a 193 bit binary field
 *		nid:725  comment: SECG curve over a 193 bit binary field
 *		nid:726  comment: NIST/SECG/WTLS curve over a 233 bit binary field
 *		nid:727  comment: NIST/SECG/WTLS curve over a 233 bit binary field
 *		nid:728  comment: SECG curve over a 239 bit binary field
 *		nid:729  comment: NIST/SECG curve over a 283 bit binary field
 *		nid:730  comment: NIST/SECG curve over a 283 bit binary field
 *		nid:731  comment: NIST/SECG curve over a 409 bit binary field
 *		nid:732  comment: NIST/SECG curve over a 409 bit binary field
 *		nid:733  comment: NIST/SECG curve over a 571 bit binary field
 *		nid:734  comment: NIST/SECG curve over a 571 bit binary field
 *		nid:684  comment: X9.62 curve over a 163 bit binary field
 *		nid:685  comment: X9.62 curve over a 163 bit binary field
 *		nid:686  comment: X9.62 curve over a 163 bit binary field
 *		nid:687  comment: X9.62 curve over a 176 bit binary field
 *		nid:688  comment: X9.62 curve over a 191 bit binary field
 *		nid:689  comment: X9.62 curve over a 191 bit binary field
 *		nid:690  comment: X9.62 curve over a 191 bit binary field
 *		nid:693  comment: X9.62 curve over a 208 bit binary field
 *		nid:694  comment: X9.62 curve over a 239 bit binary field
 *		nid:695  comment: X9.62 curve over a 239 bit binary field
 *		nid:696  comment: X9.62 curve over a 239 bit binary field
 *		nid:699  comment: X9.62 curve over a 272 bit binary field
 *		nid:700  comment: X9.62 curve over a 304 bit binary field
 *		nid:701  comment: X9.62 curve over a 359 bit binary field
 *		nid:702  comment: X9.62 curve over a 368 bit binary field
 *		nid:703  comment: X9.62 curve over a 431 bit binary field
 *		nid:735  comment: WTLS curve over a 113 bit binary field
 *		nid:736  comment: NIST/SECG/WTLS curve over a 163 bit binary field
 *		nid:737  comment: SECG curve over a 113 bit binary field
 *		nid:738  comment: X9.62 curve over a 163 bit binary field
 *		nid:739  comment: SECG/WTLS curve over a 112 bit prime field
 *		nid:740  comment: SECG/WTLS curve over a 160 bit prime field
 *		nid:741  comment: WTLS curve over a 112 bit prime field
 *		nid:742  comment: WTLS curve over a 160 bit prime field
 *		nid:743  comment: NIST/SECG/WTLS curve over a 233 bit binary field
 *		nid:744  comment: NIST/SECG/WTLS curve over a 233 bit binary field
 *		nid:745  comment: WTLS curvs over a 224 bit prime field
 *
 * Return:
 *	unNULL	key structure, the sturcture should be freed later
 *	NULL	error
 */
EC_KEY* ecdh_get_key(int nid);

/*
 * get public key from keys pair
 *
 * Return:
 *	unNULL	public key(the type is different from private key's type)
 *	NULL	error
 */
const EC_POINT* ecdh_get_public_key(const EC_KEY* key);

/*
 * free private key
 */
void ecdh_free_private_key(EC_KEY* key);

/*
 * free public key
 */
void ecdh_free_public_key(EC_POINT* point);

/*
 * get the length of share key
 */
int ecdh_get_share_key_size(const EC_KEY* key);

/*
 * compute the share key by a public key and a private key
 *
 * out:		output buffer
 * outlen:	the size of buffer
 * pubkey:	public key
 * prikey:	private key
 *
 * Return:
 *	>=0		the length of share key
 *	-1		error
 */
int ecdh_compute_share_key(char* out, int outlen,
							const EC_POINT* pubkey,
							EC_KEY* prikey);

/*
 * encode public key to octet string
 *
 * nid:		curve name
 * pubkey:	public key
 * out:		buffer to store octet string, if it is NULL, the function
 *			will return the size of buffer should be had
 * len:		buffer lenght
 *
 * Return:	
 *	>0	the length of octet string
 *	=0	error
 */
size_t ecdh_encode_public_key(int nid, const EC_POINT* pubkey,
									unsigned char* out, size_t len);

/*
 * decode public key from octet string
 *
 * nid:	curve name
 * in:	octet string
 * len:	the length of octet string
 *
 * Return:
 *	unNULL	pubkey structure, should be freed later
 *	NULL	error
 */
EC_POINT* ecdh_decode_public_key(int nid,
										const unsigned char * in,
										size_t len);

#endif
