# EP 4 - Jantar dos Filósofos

- Gabriel Hoffman - 10783250
- Guilherme Balog - 11270649

# Introdução
Primeiramente é válido entender no que se consiste o problema do jantar dos filósofos.
Este nada mais é do que um problema de sistemas operacionais onde cada filósofo representa uma thread e os talheres representam recursos do processo que todas as threads compartilham acesso. Então temos que modelar uma solução para que não aconteça os problemas de deadlock e starvation.

# Ambiente
A solução foi desenvolvida utilizando o code editor Visual Studio Code num sistema operacional baseado em Linux.

# Solução
Nossa solução foi baseada na utilização de mutex, com estes, conseguimos bloquear o uso dos talheres por um único filósofo, sem que outros possam pegar o talher.
Ou seja, um filósofo só começa a comer assim que ele consegue a "permissão" dos demais filósofos para pegar os talheres que estão a sua direita e a sua esquerda.

# Compilar e executar
Para compilar basta executor o seguinte comando:
`gcc main.c -o ./a -pthread`

E para executar basta executar o seguinte comando:
`./a`