#include <stdio.h>
#include <stdlib.h>

int main() {
    float h, peso;
    char sexo;
    printf("INFORME A ALTURA E SEXO (m/f): ");
    scanf("%f %c", &h, &sexo);
    switch (sexo) {
        case 'f':
        case 'F': peso = (62.1 * h) - 44.7;
                  printf("Senhorita seu peso ideal eh %.2f\n", peso);
                  break;
        case 'm':
        case 'M': peso = (72.7 * h) - 58;
                  printf("Senhor seu peso ideal eh %.2f\n", peso);
                  break;
        default: printf("Sexo incorreto");
    }
    system("pause");
    return 0;
}
