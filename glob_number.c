#include <stdio.h>
#include <pthread.h>

int a = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *func(void *args)
{
    int i;
    int tmp = 0;

    for (i = 0; i < 1000; i++)
    {
        pthread_mutex_lock(&mutex);
        tmp = a;
        tmp = tmp + 1;
        a = tmp;
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main(void)
{
    int i;
    pthread_t tid[1000] = {0};

    for (i = 1; i <= 1000; i++)
    {
        pthread_create(&tid[i - 1], NULL, func, NULL);
    }

    for (i = 1; i <= 1000; i++)
    {
        pthread_join(tid[i - 1], NULL);
    }

    printf("%d\n", a);

    return 0;
}