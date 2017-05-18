#include <stdio.h>

struct no {
    int dado;
    struct no *ant;
    struct no *prox;
};

struct no *lista = NULL;

void insere(int valor) {
    struct no *atual;
    struct no *anterior;
    struct no *aux;
    atual = lista;
    anterior = NULL;
    aux = new(struct no);
    aux->dado = valor;
    while (atual != NULL && atual->dado < valor) {
        anterior= atual;
        atual= atual->prox;
    }
    aux->prox = atual;
    if (atual != NULL)
        atual->ant = aux;
    aux->ant = anterior;
    if (anterior != NULL)
        anterior->prox = aux;
    else lista = aux;
}

void removePosicao(int posicao) {
    struct no *atual;
    struct no *aux;
    int cont = 0;
    atual = lista;
    while (atual != NULL && cont < posicao) {
        cont++;
        atual = atual->prox;
    }
    if (atual == NULL || posicao < 0) {
        printf("Erro");
        return;
    }
    if(atual->prox != NULL) {
        aux = atual->prox;
        aux->ant = atual->ant;
    }
    if (atual->ant != NULL) {
        aux = atual->ant;
        aux->prox = atual->prox;
    } else lista = lista->prox;
    delete(atual);
}

void imprime() {
    if (lista == NULL) {
        printf("\n\t    Lista Vazia! Insira um novo elemento.");
        return;
    }
    int i = 1;
    struct no *aux;
    aux = lista;
    printf("\n\n\t\t\t     Posição   Valores\n");
    while (aux != NULL) {
        printf("\t\t\t\t");
        printf("%d\t[%d]\n", i, aux->dado);
        i++;
        aux = aux -> prox;
    }
}

int main() {
    insere(30);
    insere(20);
    insere(10);
    imprime();
    removePosicao(2);
    imprime();

    return 0;
}
