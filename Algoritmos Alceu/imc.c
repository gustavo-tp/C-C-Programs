#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float P, H, IMC;
    printf("Informe Peso e Altura: ");
    scanf("%f %f", &P, &H);
    IMC = P / pow(H,2);
    printf("IMC = %.2f\n", IMC);
    if (IMC < 20) printf("Abaixo do Peso\n");
    else if (IMC <= 25) printf("Peso Normal\n");
        else if (IMC <= 30) printf("Sobre Peso\n");
            else if (IMC <= 40) printf("Obeso\n");
                else printf("Obeso Morbido\n");
    system("pause");
    return 0;
}
