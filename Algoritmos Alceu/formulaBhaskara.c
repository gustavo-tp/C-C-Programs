#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float a, b, c, delta, x1, x2;
    printf("Informe os coeficientes da equacao: ");
    scanf("%f %f %f", &a, &b, &c);
    delta = pow(b,2)-4*a*c;         //pow(b,2) mesmo que b*b
    if (delta>0) {
        x1 = (-b+sqrt(delta))/2*a;  //sqrt(delta) mesmo que pow(delta, 1/2.0)
        x2 = (-b-sqrt(delta))/2*a;
        printf("x' = %.2f x'' = %.2f\n", x1, x2);
    } else if (delta==0) {
            x1 = -b/(2*a);
            printf("x = %.2f\n", x1);
        } else printf("Nao ha raiz real\n");
    system("pause");
    return 0;
}
