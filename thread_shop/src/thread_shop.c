#include "../headers/thread_shop.h"

int shop[SHOP_COUNT] = {0};
pthread_mutex_t mutex[SHOP_COUNT] = {0};

int main(void)
{
    srand(time(NULL));
    pthread_t tracker_tid = 0;

    struct thread_client clients[CLIENT_COUNT] = {0};

    for (int i = 0; i < SHOP_COUNT; i++)
    {
        shop[i] = rand () % 1000;
        printf("SHOP %d COST: %d\n", i, shop[i]);
    }

    for (int i = 0; i < CLIENT_COUNT; i++)
    {
        clients[i].tid = 0;
        clients[i].id = i + 1;
        clients[i].cost = 10000 + rand () % 250;
        pthread_create(&clients[i].tid, NULL, client, &clients[i]);
    }
    pthread_create(&tracker_tid, NULL, tracker, NULL);

    for (int i = 0; i < CLIENT_COUNT; i++)
    {
        pthread_join(clients[i].tid, NULL);
    }
    pthread_kill(tracker_tid, SIGUSR1);

    return 0;
}