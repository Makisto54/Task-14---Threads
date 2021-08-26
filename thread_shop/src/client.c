#include "../headers/thread_shop.h"

void *client(void *args)
{
    int i = 0;
    struct thread_client *client = (struct thread_client *)args;

    while (client->cost != 0)
    {
        i = rand () % 5;
        if (0 != shop[i])
        {
            if (!pthread_mutex_trylock(&mutex[i]))
            {
                printf("\n\nCLIENT %d WORKING\n\n", client->id);
                printf("CLIENT %d CURRENT COST - %d\nSHOP %d CURRENT COST - %d\n", 
                    client->id, client->cost, i, shop[i]);
                if (client->cost < shop[i])
                {
                    shop[i] -= client->cost;
                    client->cost = 0;
                }
                else
                {
                    client->cost -= shop[i]; 
                    shop[i] -= shop[i];          
                }
                printf("CLIENT %d AFTER BUYING - CURRENT COST - %d SHOP %d COST - %d\n", 
                    client->id, client->cost, i, shop[i]);
                printf("\nCLIENT %d END WORKING\n\n", client->id);
                pthread_mutex_unlock(&mutex[i]);
                sleep(2);  
            }         
        }
    }
 
    printf("CLIENT %d END HIS WORK. HIS COST - %d\n", client->id, client->cost);
    pthread_exit(NULL);
}
