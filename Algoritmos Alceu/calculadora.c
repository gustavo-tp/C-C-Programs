#include <stdio.h>
#include <stdlib.h>

int main() {
    float a, b;
    char op;
    printf("Digite sua operacao: ");
    scanf("%f %c %f", &a, &op, &b);
    switch (op) {
        case '+': printf("Soma = %f\n", a+b); break;
        case '-': printf("Subtracao = %f\n", a-b); break;
        case '*': printf("Produto = %f\n", a*b); break;
        case '/': printf("Divisao = %f\n", a/b); break;
        default: printf("Operador incorreto\n");
    }
    system("pause");
    return 0;
}
