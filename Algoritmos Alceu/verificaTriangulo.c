#include <stdio.h>
#include <stdlib.h>

int main() {
    float A, B, C;
    printf("Informe os lados dos triangulos: ");
    scanf("%f %f %f", &A, &B, &C);
    if (A<B+C && B<A+C && C<A+B)
    	if (A==B && B==C)
            printf("Trinangulo Equilatero\n");
    	else if (A==B || B==C || A==C)
    		printf("Triangulo Isosceles\n");
            else
                printf("Triangulo Qualquer\n");
    else printf("Nao formam um triangulo");
    system("pause");
    return 0;
}
