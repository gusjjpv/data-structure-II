#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int result = fibonacci(8);
    printf("Fibonacci de 8 é: %d\n", result);
    return 0;
}

/* (gdb) break fibonacci
(gdb) run
(gdb) commands 1
> silent
> if (n == 4)
>    printf "fibonacci(4) chamado\n"
> end
> continue
> end
(gdb) continue
*/