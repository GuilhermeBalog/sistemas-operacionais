#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <error.h>

void critical_section(int id);
void non_critical_section(int id);

int count = 0;
int turn = 0;

int true = 1;


/* Função que será executada pelas threads */
void *runner_1(void * param)
{
    int id = 0;
    int other = 1;
    
    while(true){
        while(turn != id){}

        critical_section(id);
        turn = other;
        non_critical_section(id);
    }

    pthread_exit(NULL);
}

void *runner_2(void * param)
{
    int id = 1;
    int other = 0;
    
    while(true){
        while(turn != id){}

        critical_section(id);
        turn = other;
        non_critical_section(id);
    }

    pthread_exit(NULL);
}

/* Thread principal do processo */
int main(int argc, char *argv[])
{
    printf("[Inicio do programa]\n\n");
    pthread_t thread_1, thread_2;
    pthread_attr_t thread_attributes;

    /* Inicia os atributos da thread com os valores padrão */
    pthread_attr_init(&thread_attributes);

    /* Inicializa x threads através da função "pthread_create" */
    
    pthread_create(&thread_1, NULL, runner_1, NULL);
    pthread_create(&thread_2, NULL, runner_2, NULL);

    printf("\n[Fim do programa]\n\n");

    pthread_exit(NULL);
    
}

void critical_section(int id){
    printf("Thread %d entrou na seção crítica\n", id);
    printf("Thread %d mudou count para %d\n", id, ++count);
    printf("Thread %d saiu na seção crítica\n", id);
}

void non_critical_section(int id){
    printf("Thread %d entrou na seção não crítica\n", id);
    printf("Thread %d está executando a seção não crítica...\n", id);
    printf("Thread %d saiu na seção não crítica\n", id);
}