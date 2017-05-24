#include <stdio.h>
#include <stdlib.h>

int main() {
    float peso, peso_calculado;
    int planeta;
    printf("1 = Mercurio\n2 = Venus\n3 = Marte\n4 = Jupiter\n5 = Saturno\n6=Urano\n");
    printf("Digite seu peso e um planeta: ");
    scanf("%f %d", &peso, &planeta);
    switch (planeta) {
        case 1: peso_calculado = peso * 0.37;
                printf("Peso em Mercurio = %.2f: ", peso_calculado);
                break;
        case 2: peso_calculado = peso * 0.88;
                printf("Peso em Venus = %.2f: ", peso_calculado);
                break;
        case 3: peso_calculado = peso * 0.38;
                printf("Peso em Marte = %.2f: ", peso_calculado);
                break;
        case 4: peso_calculado = peso * 2.64;
                printf("Peso em Jupiter = %.2f: ", peso_calculado);
                break;
        case 5: peso_calculado = peso * 1.15;
                printf("Peso em Saturno = %.2f: ", peso_calculado);
                break;
        case 6: peso_calculado = peso * 1.17;
                printf("Peso em Urano = %.2f: ", peso_calculado);
                break;
        default: printf("Planeta Incorreto");
    }
    system("pause");
    return 0;
}
