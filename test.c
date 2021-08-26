#include <stdio.h>
#include <pthread.h>

void *func(void *args)
{
    int *ptr = (int *)args;
    printf("%d\n", *ptr);
    pthread_exit(NULL);
}

int main(void)
{
    int i;
    int mas[5] = {0};
    pthread_t tid[5] = {0};

    for (i = 1; i <= 5; i++)
    {
        mas[i - 1] = i;
        pthread_create(&tid[i - 1], NULL, func, &mas[i - 1]);
    }

    for (i = 1; i <= 5; i++)
    {
        pthread_join(tid[i - 1], NULL);
    }

    return 0;
}
