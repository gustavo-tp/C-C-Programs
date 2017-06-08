#include <stdio.h>
#include <string.h>

struct no {
    char dado[50];
    int contador;
    struct no *esq;
    struct no *dir;
};
struct no *raiz = NULL;

void insereArvore(char valor[]) {
    struct no *atual;
    struct no *anterior;
    struct no *aux;

    aux = new(struct no);
    strcpy(aux->dado, valor);
    aux->esq = NULL;
    aux->dir = NULL;

    if (raiz == NULL) {
        raiz = aux;
        return;
    }
    atual = raiz;

    while(atual != NULL) {
        if (strcmp(valor, atual->dado) == 0) {
            atual->contador++;
            delete(aux);
            return;
        }
        anterior = atual;
        if (strcmp(valor, atual->dado) < 0)
            atual = atual->esq;
        else atual = atual->dir;
    }

    if (strcmp(valor, anterior->dado) < 0)
        anterior->esq = aux;
    else anterior->dir = aux;
}

void em_ordem(struct no *atual) {
    if (atual != NULL) {
        em_ordem(atual->esq);
        printf("%s ", atual->dado);
        em_ordem(atual->dir);
    }
}

void buscaArvore(char valor[]) {
    struct no *atual;
    atual = raiz;
    while (atual != NULL) {
        if (strcmp(valor, atual->dado) == 0) {
            printf("Achei");
            delete(atual);
            return;
        }
        if (strcmp(valor, atual->dado) < 0)
            atual = atual->esq;
        else atual = atual->dir;
    }
    printf("Nao achei");
}

void menu() {
    int op;
    char str[50];
    printf("1 - Imprimir a arvore\n");
    printf("2 - Buscar um valor\nR: ");
    scanf("%d", &op);
    switch (op) {
        case 1:
            em_ordem(raiz);
            break;
        case 2:
            printf("Digite o valor: ");
            scanf("%s", str);
            buscaArvore(str);
            break;
        default:
            printf("Opcao nao existente");
    }
}

int main() {
    char auxiliar[50];
    FILE *fp;
    fp = fopen("G:\\texto.txt", "r");
    if (fp == NULL) {
        printf("Erro!");
        return 0;
    }
    while (!feof(fp)) {
        fscanf(fp, "%s", auxiliar);
        insereArvore(auxiliar);
    }
    fclose(fp);
    menu();
}
