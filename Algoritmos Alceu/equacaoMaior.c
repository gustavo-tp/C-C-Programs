#include <stdio.h>
#include <stdlib.h>

int main() {
    float a, b, c;
    printf("Informe tres valores: ");
    scanf("%f %f %f", &a, &b, &c);
    if (a>b && a>c) printf("Maior %.2f\n", a);
    else if (b>c) printf("Maior %.2f\n", b);
        else printf("Maior %.2f\n", c);
    system("pause");
    return 0;
}
