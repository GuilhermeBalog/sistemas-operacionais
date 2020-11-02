#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pthread_t threadId[5];
pthread_mutex_t forks_mutex[5];
pthread_attr_t attribute;

void wait()
{
    srand(time(NULL));
    int number_of_seconds = rand() % ((5 + 2) - 1) + 2;

    // int milli_seconds = 1000 * number_of_seconds;
    // clock_t start_time = clock();
    // while (clock() < start_time + milli_seconds)
    // {
    // };
    // printf("sleeping from %d seconds...", number_of_seconds);
    sleep(number_of_seconds);
}

void think(int i)
{
    printf("Philosopher %d is thinking.\n", i);
    wait();
}

struct tm *data_hora_atual;

void eat(int i)
{
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    data_hora_atual = localtime(&rawtime);
    printf("[%d:%d:%d] Philosopher %d start eating.\n", data_hora_atual->tm_hour, data_hora_atual->tm_min, data_hora_atual->tm_sec, i);

    wait();

    time(&rawtime);
    data_hora_atual = localtime(&rawtime);
    printf("[%d:%d:%d] Philosopher %d end eating.\n", data_hora_atual->tm_hour, data_hora_atual->tm_min, data_hora_atual->tm_sec, i);
}

void take_forks(int i)
{
    pthread_mutex_lock(&forks_mutex[i]);
    pthread_mutex_lock(&forks_mutex[(i + 1) % 5]);
}

void put_forks(int i)
{
    pthread_mutex_unlock(&forks_mutex[i]);
    pthread_mutex_unlock(&forks_mutex[(i + 1) % 5]);
}

void *philosopher(void *philosopher_id)
{
    for (int i = 0; i < 5; i++)
    {
        think(philosopher_id);
        take_forks(philosopher_id);
        eat(philosopher_id);
        put_forks(philosopher_id);
    }
    pthread_exit(NULL);
}

int main(void)
{
    int philosopher_id[5];

    for (int i = 0; i < 5; i++)
    {
        philosopher_id[i] = i;
        pthread_mutex_init(&forks_mutex[i], NULL);
    }

    pthread_attr_init(&attribute);

    pthread_attr_setdetachstate(&attribute, PTHREAD_CREATE_JOINABLE);

    for (int i = 0; i < 5; i++)
    {
        pthread_create(&threadId[i], &attribute, philosopher, (void *)philosopher_id[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_join(threadId[i], NULL);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_mutex_destroy(&forks_mutex[i]);
    }

    pthread_exit(NULL);
}
