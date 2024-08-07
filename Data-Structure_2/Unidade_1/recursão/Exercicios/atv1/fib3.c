#include <stdio.h>

// Variáveis globais para contar as operações
long long num_chamadas_recursivas = 0;
long long num_retorno_chamadas = 0;
long long num_atribuicoes_soma = 0;
long long num_subtracoes = 0;

int fib(int n) {
    num_chamadas_recursivas++;
    if (n < 3) {
        num_retorno_chamadas++;
        return 1;
    } else {
        num_subtracoes += 3; // Três subtrações (n-1, n-2, n-3)
        num_atribuicoes_soma++; // Uma atribuição e uma soma para o retorno
        return fib(n - 1) + fib(n - 2) + fib(n - 3);
    }
}

int main() {
    fib(12);

    // Calcula o tempo total
    double tempo_total = 
        num_chamadas_recursivas * 2.0 +
        num_retorno_chamadas * 1.0 +
        num_atribuicoes_soma * 0.5 +
        num_subtracoes * 0.3;

    // Imprime o número de operações e o tempo total
    printf("Número de chamadas recursivas: %lld\n", num_chamadas_recursivas);
    printf("Número de retornos de chamadas: %lld\n", num_retorno_chamadas);
    printf("Número de atribuições e somas: %lld\n", num_atribuicoes_soma);
    printf("Número de subtrações: %lld\n", num_subtracoes);
    printf("Tempo total: %.2f ns\n", tempo_total);

    return 0;
}

/* considere os seguintes tempos para o algoritmo:
chamada recursiva: 2ns
retorno de chamada recursiva: 1ns
atribuição e soma: 0.5ns
subtração: 0.3ns */