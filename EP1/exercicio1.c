#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    // Inicia um novo processo filho
    // Função da biblioteca "unistd"
    fork();

    // Exibe Hello World em cada processo
    printf("Hello world!\n");

    return 0; 
}