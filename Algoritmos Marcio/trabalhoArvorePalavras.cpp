#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int qtd = 0;
char maior[50];

struct no {
    char dado[50];
    int contador;
    struct no *esq;
    struct no *dir;
};
struct no *raiz = NULL;

//void verificaAlfabetico() {
//    fscanf(fp, "%c", &letra);
//    if (isalpha(letra))
//        printf("É alfabético")
//    else printf("Não é alfabético");
//}

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
        if (qtd < atual->contador) {
            strcpy(maior, atual->dado);
            qtd = atual->contador;
        }
        em_ordem(atual->dir);
    }
}

int main() {
    setlocale(LC_ALL,"");
    char palavra[50];
    char letra;
    int i;
    FILE *fp;
    fp = fopen("G:\\textoSobreC.txt", "r");
    if (fp == NULL) {
        printf("Erro!");
        return 0;
    }
    printf("Texto inserido:\n\n");
    while (!feof(fp)) {
        i = 0;
        fscanf(fp, "%c", &letra);
        if (isalpha(letra)) {
            while (isalpha(letra)) {
                printf("[%c]", letra);
                palavra[i] = tolower(letra);
                fscanf(fp, "%c", &letra);
                i++;
            }
            printf("\n");
            palavra[i] = '\0';
            insereArvore(palavra);
        }
    }
    printf("\nPalavras Ordenadas:\n\n");
    fclose(fp);
    em_ordem(raiz);
    printf("\n\nA palavra que mais apareceu no texto foi: %s\nSomando um total de %d vezes\n", maior, qtd);
}
