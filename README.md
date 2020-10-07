
# Sistemas Operacionais

 
Relatório do exercícios-programa (EP) para a matéria de Sistemas Operacionais da EACH-USP

  

## EP 1

  

### Exercício 1

Criação de um processo pai, “hello world”, fork processo filho, “hello world”,finalização de ambos. Válida qualquer linguagem de programação.

  

#### Resolução 1

  

Neste exercício, nós utilizamos a função `fork()` da biblioteca `unistd.h` para realizar o processo de fork do processo em questão. O fork funciona basicamente criando processo filho para o processo pai que é executada utilizando o mesmo *program counter*, registradores e arquivos do processo pai, ou seja, a partir da linha do fork, ambos os processos serão executados concorrentemente.


  

Para compilar é necessário utilizar o `gcc`, que é um compilador de c. O comando para compilar é:

  

```bash

gcc exercicio1.c -o exercicio1

```

  

Dependendo da plataforma utilizada, a extensão do arquivo pode variar, sendo `exercicio1.exe` no Windows e `exercicio1.out` ou apenas `exercicio1` no Linux. E para executar basta executar o comando `exercicio1` no terminal.

Como *output* teremos as seguintes linhas:

```bash
Hello world!
Hello world!
```
Sendo que um dos `printf()` é referente ao processo pai e o outro ao processo filho.

  ---

### Exercício 2

  

Criação de um processo, criação de várias Java threads, “hello world” de todos, finalização

  

#### Resolução 2

  

Nessa resolução utilizamos a classe `Thread` que serve para lidar múltiplas threads. O construtor recebe um `Runnable` como parâmetro, que é uma interface da classe `Thread` do Java, esta sobrescreve o método `run` da classe `Thread` e este é o responsável por exibir o `Hello world!`  ou executar qualquer outro comando que se deseja que a thread em questão faça.

Além da criação da thread também utilizamos o método `start()` para iniciar a execução da thread em questão.

  

Para compilar é necessário utilizar o comando `javac exercicio2.java` e rodar com `java exercicio2`.

Como *output* temos as seguintes linhas:
```bash
Hello world!
Hello world!
Hello world!
```

  ---

### Exercício 3

  

Criação de um processo, criação de várias POSIX threads (código fonte em C ou C++), “hello world” de todos, finalização

  

#### Resolução 3

  

Aqui tivemos uma solução que se parecia muito com a desenvolvida em Java, porem, como era de se esperar em C, com um nível um pouco mais baixo. Isso porque ao utilizar o POSIX temos que manipular dados como o ID da thread e os atributos da thread de forma manual.

Uma diferença que foi observada entre o C e o Java é que no C não precisamos iniciar a thread, ao criá-la ela já inicia a execução simultaneamente.

Como *output* temos as seguintes linhas:
```bash
Hello world!
Hello world!
Hello world!
Hello world!
```
---
