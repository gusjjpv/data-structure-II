#include <stdio.h>

// Declaração de variáveis globais para contagem
int chamadas = 0;
int retornos = 0;
int atribuicoes = 0;
int divisoes = 0;

int funcRecursiva(int n) {
    if (n == 0) {
        retornos++;
        return 1;
    }

    // Incrementa as contagens apropriadas
    chamadas++;
    atribuicoes++;
    divisoes++;

    return funcRecursiva(n - 1) + 1 / funcRecursiva(n - 1);
}

int main() {
    int resultado = funcRecursiva(5); // Altere para o valor desejado
    printf("Resultado: %d\n", resultado);

    // Exibe as contagens de operações
    printf("Chamadas recursivas: %d\n", chamadas);
    printf("Retornos: %d\n", retornos);
    printf("Atribuições e somas: %d\n", atribuicoes);
    printf("Divisões: %d\n", divisoes);

    return 0;
}
