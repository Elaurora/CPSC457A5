#ifndef TYPES_H
#define TYPES_H

#define lock(a) pthread_mutex_lock(a)
#define unlock(a) pthread_mutex_unlock(a)

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

#endif