#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 

pthread_t threadId[2];
pthread_attr_t attribute[2];
pthread_mutex_t mutex; 

int counter = 0;
int iterations = 10;

void* runner(void *threadId) 
{
    for (int i = 0; i < iterations; i++)
    {
        pthread_mutex_lock(&mutex);    
        counter = counter + 1;
        printf("Thread %d: Counter -> %d\n", threadId, counter);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main(void) 
{
    int threadId1 = 1,
        threadId2 = 2;

    pthread_mutex_init(&mutex, NULL);
    pthread_attr_init(&attribute[0]);
    pthread_attr_init(&attribute[1]);

    pthread_attr_setdetachstate(&attribute[0],PTHREAD_CREATE_JOINABLE);
    pthread_attr_setdetachstate(&attribute[1],PTHREAD_CREATE_JOINABLE);

    pthread_create(&(threadId[0]),&attribute[0], runner, (void *)threadId1); 
    pthread_create(&(threadId[1]),&attribute[1], runner, (void *)threadId2); 

    pthread_join(threadId[0], NULL);
    pthread_join(threadId[1], NULL);

    pthread_mutex_destroy(&mutex);

    pthread_exit(NULL);
}
