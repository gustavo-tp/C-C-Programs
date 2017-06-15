// P esq = 2*p+1
// P dir = 2*p+2
// heapSort

#include <stdio.h>

#define TAM 14

struct no {
    int dado;
    int usado;
};

struct no arvore[TAM];

void inicia() {
    int i;
    for (i=0; i<TAM; i++)
        arvore[i].usado = 0;
}

void insere(int valor) {
    int atual = 0;
    while (atual < TAM && arvore[atual].usado != 0) {
        if (valor < arvore[atual].dado)
            atual = 2*atual + 1;
        else atual = 2*atual + 2;
    }
    if (atual < TAM) {
        arvore[atual].dado = valor;
        arvore[atual].usado = 1;
    } else printf("Nao foi possivel inserir\n");
}

void emOrdem(int atual) {
    if (atual < TAM && arvore[atual].usado != 0) {
        emOrdem(2*atual+1);
        printf("%d ", arvore[atual].dado);
        emOrdem(2*atual+2);
    }
}

void busca(int valor) {
    int atual = 0;
    while (atual < TAM && arvore[atual].usado != 0) {
        if (arvore[atual].dado == valor) {
            printf("Achei\n");
            return;
        }
        if (valor < arvore[atual].dado)
            atual = 2*atual + 1;
        else atual = 2*atual + 2;
    }
}

void insereSemRepetidos(int valor) {
    int atual = 0;
    while (atual < TAM && arvore[atual].usado != 0) {
        if (valor == arvore[atual].dado) {
            printf("Valor Repetido\n");
            return;
        }
        if (valor < arvore[atual].dado)
            atual = 2*atual + 1;
        else atual = 2*atual + 2;
    }
    if (atual < TAM) {
        arvore[atual].dado = valor;
        arvore[atual].usado = 1;
    } else printf("Nao foi possivel inserir\n");
}

void vazia() {
    int i;
    for (i=0; i<TAM; i++) {
        if (arvore[i].usado == 1) {
            printf("A arvore nao esta vazia!\n");
            return;
        }
    }
    printf("Arvore vazia\n");
}

int main() {
    inicia();
    vazia();
    insere(2);
    insere(5);
    insere(10);
    insere(8);
    emOrdem(0);
    printf("\n");
    insereSemRepetidos(5);
    emOrdem(0);
    printf("\n");
    busca(5);
    vazia();

    return 0;
}
