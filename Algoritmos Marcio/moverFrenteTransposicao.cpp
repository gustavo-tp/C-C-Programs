//tbot.xyz/corsairs
#include <stdio.h>
#include <locale.h>

struct no {
    int dado;
    struct no  *prox;
};
struct no *lista = NULL;

void gera() {
    int i = 0;
    struct no *aux;
    while (i < 10) {
        aux = new(struct no);
        aux->dado = i;
        aux->prox = lista;
        lista = aux;
        i++;
    }
}

void imprime() {
    struct no *atual;
    atual = lista;
    while (atual != NULL) {
        printf("%d",atual->dado);
        atual = atual->prox;
    }
}

void sequencial(int valor) {
    struct no *atual;
    atual = lista;
    while (atual != NULL) {
        if (valor == atual->dado) {
            printf("Achei");
            return;
        }
        atual = atual->prox;
    }
    printf("Não achei");
}

void mover_frente(int valor) {
    struct no *atual, *anterior;
    atual = lista;
    while (atual != NULL) {
        if (valor == atual->dado) {
            printf("Achei");
            if (atual != lista) {
                anterior->prox = atual->prox;
                atual->prox = lista;
                lista = atual;
            }
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("Não achei");
}

void transposicao(int valor) {
    int aux;
    struct no *atual, *anterior;
    atual = lista;
    while (atual != NULL) {
        if (valor == atual->dado) {
            printf("Achei");
            if (atual != lista) {
                aux = anterior->dado;
                anterior->dado = atual->dado;
                atual->dado = aux;
            }
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("Não achei");
}

int main() {
    setlocale(LC_ALL,"");
    gera();
    imprime();
    printf("\n");
    mover_frente(0);
    printf("\n");
    imprime();
    printf("\n");
    transposicao(5);
    printf("\n");
    imprime();

    return 0;
}
