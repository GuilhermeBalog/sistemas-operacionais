
#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 

pthread_t tid[2]; 
int counter; 
pthread_mutex_t lock; 

void* trythis(void* arg) 
{ 
    pthread_mutex_lock(&lock); 

    pthread_mutex_unlock(&lock); 

    return NULL; 
} 

int main(void) 
{ 
    int i = 0; 
    int error; 

    if (pthread_mutex_init(&lock, NULL) != 0) { 
        printf("\n mutex init has failed\n"); 
        return 1; 
    } 

    while (i < 2) { 
        pthread_create(&(tid[i]),NULL,&trythis, NULL); 
    } 

    pthread_join(tid[0], NULL); 
    pthread_join(tid[1], NULL); 
    pthread_mutex_destroy(&lock); 

    return 0; 
} 
