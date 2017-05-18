#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int lista[TAM];
int tamanho = 0;
int i;

void insereLista(int valor, int posicao) {
    if(tamanho == TAM) {
        printf("Lista cheia!");
        return;
    }
    if(posicao < 0 || posicao > tamanho) {
        printf("Posição inválida");
        return;
    }
    for(i=tamanho; i > posicao; i--)
        lista[i] = lista[i-1];

    lista[posicao] = valor;
    tamanho++;
}

void removeLista(int posicao) {
    if(posicao < 0 || posicao > tamanho) {
        printf("Posição inválida");
        return;
    }
    lista[posicao] = 0;
    for(i=posicao; i > tamanho; i++)
        lista[i] = lista[i+1];
}

void imprimeLista() {
    if(tamanho == 0) {
        printf("Lista fazia!");
        return;
    }
    for (i=0; i<TAM; i++)
        printf("[%i]", lista[i]);
    printf("\n");
}

void recupera(int posicao) {
    if(posicao < 0 || posicao >= tamanho) {
        printf("Posição inválida");
        return;
    }
    printf("%d", lista[posicao]);
}

int main() {
    insereLista(10, 0);
    insereLista(33, 1);
    imprimeLista();
    removeLista(0);

    return 0;
}
