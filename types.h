#ifndef TYPES_H
#define TYPES_H

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>



typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

void lock(pthread_mutex_t* mutex);
void unlock(pthread_mutex_t* mutex);

#endif