
#ifndef SLIGHT_SSL_BITMAP_H
#define SLIGHT_SSL_BITMAP_H

#include <stdint.h>


typedef struct sssl_bitmap_t {
    int map_size;
    uint8_t* map;
}sssl_bitmap;

// methods

// create a bitmap
sssl_bitmap* sssl_bitmap_create(int size);
// if succeed return 0 or 1; if failed return -1
int sssl_bitmap_check(sssl_bitmap* bm, int index);
// set the element under index to be tag(0/1);
// succeed return 0, else return -1
int sssl_bitmap_set(sssl_bitmap* bm, int index, int tag);
// free the map
void sssl_bitmap_free(sssl_bitmap* bm);

#endif

