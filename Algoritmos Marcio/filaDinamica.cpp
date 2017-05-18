#include <stdio.h>
#include <stdlib.h>

struct no {
    int dado;
    struct no *prox;
};

struct no *inicio = NULL;
struct no *fim = NULL;

void insereFila(int valor) {
    struct no *aux;
    aux = new(struct no);
    aux -> dado = valor;
    aux -> prox = NULL;
    if (inicio == NULL) {
        inicio = aux;
        fim = aux;
    } else {
        fim -> prox = aux;
        fim = aux;
    }
}

void imprimeFila() {
    struct no *aux;
    if (inicio == NULL) {
        printf("Fila vazia");
        return;
    }
    aux = inicio;
    while (aux != NULL) {
        printf("[%d]", aux->dado);
        aux = aux -> prox;
    }
    printf("\n");
}

void removeFila() {
    struct no *aux;
    if (inicio == NULL) {
        printf("Fila vazia!");
        return;
    }
    aux = inicio;
    inicio = inicio -> prox;
    if (inicio == NULL)
        fim = NULL;
    delete(aux);
}

int main() {
    insereFila(10);
    insereFila(20);
    insereFila(30);
    imprimeFila();

    return 0;
}
