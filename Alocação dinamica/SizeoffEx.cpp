#include <stdio.h>

int main() {
    int a = 10;
    double b = 3.14;
    char c = 'A';

    printf("Tamanho de a (int): %zu bytes\n", sizeof(a));
    printf("Tamanho de b (double): %zu bytes\n", sizeof(b));
    printf("Tamanho de c (char): %zu byte\n", sizeof(c));
    
    return 0;
}
