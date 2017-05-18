#include <stdio.h>
#include <stdlib.h>

struct no {
    int dado;
    struct no *prox;
};

struct no *topo = NULL;

void push(int valor) {
    struct no *aux;
    aux = new(struct no);
    aux -> dado = valor;
    aux -> prox = topo;
    topo = aux;
}

void pop() {
    struct no *aux;
    if(topo == NULL) {
        printf("Pilha vazia!");
        return;
    }
    aux = topo;
    topo = topo -> prox;
    delete(aux);
}

void imprime() {
    struct no *aux;
    if(topo == NULL) {
        printf("Pilha vazia!");
        return;
    }
    aux = topo;
    while(aux != NULL) {
        printf("[%d]", aux -> dado);
        aux = aux -> prox;
    }
    printf("\n");
}

void imprimeTopo() {
	printf("O endereço do topo eh: %p\n", topo);
}

int main() {
    push(30);
    push(20);
    push(10);
    imprime();
    pop();
    imprime();
    pop();
    imprime();
    imprimeTopo();

    return 0;
}
