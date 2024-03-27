#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MAXVALUE 3

static sem_t startSemaphore1;
static sem_t startSemaphore2;
static sem_t startSemaphore3;

static pthread_t hPrint1;
static pthread_t hPrint2;
static pthread_t hPrint3;

void* print1 (void *pParam)
{
    sem_wait(&startSemaphore1);

    for (int i = 0; i < MAXVALUE; i++)
    {
        printf("Podesavanje");
        printf(" GIT-a");
        printf(" i");
        printf(" VSCoda\n");   
    }

    sem_post(&startSemaphore2);

    return 0;
}

void* print2 (void *lpParam)
{
    sem_wait(&startSemaphore2);

    for (int i = 0; i < MAXVALUE; i++)
    {   
        printf("Pozdrav");
        printf(" iz");
        printf(" Linux-a\n");     
    }

    sem_post(&startSemaphore3); 

    return 0;
}

void* print3 (void *lpParam)
{
    sem_wait(&startSemaphore3);

    for(int i = 0; i < MAXVALUE; i++)
    { 
        printf("Danas");
        printf(" je");
        printf(" petak");
        printf(" moj");
        printf(" omiljeni");
        printf(" dan \n");     
    }

    sem_post(&startSemaphore1); 

    return 0;
}

int main (void)
{
    sem_init(&startSemaphore1, 0, 0);
    sem_init(&startSemaphore2, 0, 0);
    sem_init(&startSemaphore3, 0, 0);

    pthread_create(&hPrint1, NULL, print1, 0);
    pthread_create(&hPrint2, NULL, print2, 0);
    pthread_create(&hPrint3, NULL, print3, 0);

    sem_post(&startSemaphore1);

    /* Prikljuci se na niti */
    pthread_join(hPrint1, NULL);
    pthread_join(hPrint2, NULL);
    pthread_join(hPrint3, NULL);

    sem_destroy(&startSemaphore1);
    sem_destroy(&startSemaphore2);
    sem_destroy(&startSemaphore3);

    return 0;
}