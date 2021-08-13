#include "../headers/thread_shop.h"

void *tracker(void *args)
{
    int i = 0;
    int food = 0;

    while(1)
    {
        i = rand () % 5;
        food = 200 + rand () % 50;
        if (!pthread_mutex_trylock(&mutex[i]))
        {
            printf("\n\nTRACKER WORKING\n\n");
            printf("BEFORE SENDING - SHOP %d COST: %d\n", i, shop[i]);
            shop[i] += food;
            printf("TRACKER SEND TO SHOP %d - %d FOOD\n", i, food);
            printf("AFTER SENDING - SHOP %d COST: %d\n", i, shop[i]);
            printf("\nTRACKER END WORKING\n\n");
            pthread_mutex_unlock(&mutex[i]);
        }
        sleep(1);
    }
}