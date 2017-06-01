#include <stdio.h>

struct no {
    int dado;
    struct no *esq;
    struct no *dir;
};
struct no *raiz = NULL;

void insereArvore(int valor) {
    struct no *atual;
    struct no *anterior;
    struct no *aux;

    aux = new(struct no);
    aux->dado = valor;
    aux->esq = NULL;
    aux->dir = NULL;

    if (raiz == NULL) {
        raiz = aux;
        return;
    }
    atual = raiz;

    while(atual != NULL) {
        if (atual->dado == valor) {
            printf("Valor repetido\n");
            delete(aux);
            return;
        }
        anterior = atual;
        if (valor < atual->dado)
            atual = atual->esq;
        else atual = atual->dir;
    }

    if (valor < anterior->dado)
        anterior->esq = aux;
    else anterior->dir = aux;
}

void em_ordem(struct no *atual) {
    if (atual != NULL) {
        em_ordem(atual->esq);
        printf("%d ", atual->dado);
        em_ordem(atual->dir);
    }
}

void buscaArvore(int valor) {
    struct no *atual;
    atual = raiz;
    while (atual != NULL) {
        if (atual->dado == valor) {
            printf("Achei");
            delete(atual);
            return;
        }
        if (atual->dado < valor)
            atual = atual->esq;
        else atual = atual->dir;
    }
    printf("Não achei");
}

int main() {
    insereArvore(10);
    insereArvore(20);
    insereArvore(15);
    insereArvore(65);
    insereArvore(5);
    insereArvore(20);
    em_ordem(raiz);

    return 0;
}
