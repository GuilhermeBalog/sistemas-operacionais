#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <error.h>

void *runner(void *param);

/* Thread principal do processo */
int main(int argc, char *argv[])
{
    pthread_t thread_id;
    pthread_attr_t atributos_da_thread;

    /* Inicia os atributos da thread com os valores padrão */
    pthread_attr_init(&atributos_da_thread);

    /* Inicializa x threads através da função "pthread_create" */
    for(int i = 0; i < 4; i++)
    {
        pthread_create(&thread_id, &atributos_da_thread, runner, NULL);
    }

}

/* Função que será executada pelas threads */
void *runner(void *param)
{
    printf("Hello world!\n");
    pthread_exit(0);
}