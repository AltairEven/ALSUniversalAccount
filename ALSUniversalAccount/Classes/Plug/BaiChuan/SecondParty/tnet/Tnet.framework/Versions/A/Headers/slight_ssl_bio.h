
#ifndef SLIGHT_SSL_BIO_H
#define SLIGHT_SSL_BIO_H

ssize_t sssl_bio_default_method_read(SSSL_BIO* bio, void* buf, size_t len, int flags);;
ssize_t sssl_bio_default_method_write(SSSL_BIO* bio, const void* buf, size_t len, int flags);

#endif

