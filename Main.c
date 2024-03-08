#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

static pthread_mutex_t cs_mutex;


void* print1 (void *pParam)
{
    int i;
    for (i = 0 ; i < 3 ; i++)
    {
        pthread_mutex_lock(&cs_mutex);

            printf("Podesavanje");
            printf(" GIT-a");
            printf(" i");
            printf(" VSCoda\n");

        pthread_mutex_unlock(&cs_mutex);
    }

    return 0;
}

void* print2 (void *lpParam)
{
    int i;
    for (i = 0 ; i < 6; i++)
    {
        pthread_mutex_lock(&cs_mutex);

            printf("Pozdrav");
            printf(" iz");
            printf(" Linux-a\n");

        pthread_mutex_unlock(&cs_mutex);
    }

    return 0;
}

void* print3 (void *lpParam)
{
    int i;
    for(i = 0 ; i < 9 ; i++)
    {
        pthread_mutex_lock(&cs_mutex);

            printf("Danas");
            printf(" je");
            printf(" petak");
            printf(" moj");
            printf(" omiljeni");
            printf(" dan \n");

        pthread_mutex_unlock(&cs_mutex);
    }

    return 0;
}

int main (void)
{
    pthread_t hPrint1;
    pthread_t hPrint2;
    pthread_t hPrint3;

    pthread_mutex_init(&cs_mutex, NULL);

    pthread_create(&hPrint1, NULL, print1, 0);
    pthread_create(&hPrint2, NULL, print2, 0);
    pthread_create(&hPrint3, NULL, print3, 0);

    getchar();

    pthread_mutex_destroy(&cs_mutex);

    return 0;
}
