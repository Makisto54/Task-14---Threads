#ifndef _THREAD_SHOP_
#define _THREAD_SHOP_

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>

#define SHOP_COUNT 5
#define CLIENT_COUNT 3

struct thread_client
{
    int id;
    int cost;
    pthread_t tid;
};

extern int shop[SHOP_COUNT];
extern pthread_mutex_t mutex[SHOP_COUNT];

void *client(void *);
void *tracker(void *);

#endif