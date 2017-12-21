
#ifndef SLIGHT_SSL_ECDH_ERR_H
#define SLIGHT_SSL_ECDH_ERR_H

#define SSSL_ERR(title, name, msg)	fprintf(stderr, title " ERROR: " #name " " #msg "\n")
#define ECerr(name, msg)	SSSL_ERR("EC", name, msg)
#define ECDHerr(name, msg)	SSSL_ERR("ECDH", name, msg)
#define BNerr(name, msg)	SSSL_ERR("BN", name, msg)

#endif

