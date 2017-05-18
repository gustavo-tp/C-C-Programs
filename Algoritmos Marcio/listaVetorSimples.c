#include <stdio.h>
#include <locale.h>

#define TAM 7
int lista[TAM];
int tamanho = 0;

void insereLista(int valor) {
    if (tamanho == TAM) {
        printf("\n\t\t\tLista Cheia!");
        return;
    }
    int i;
    for (i = tamanho; i>0 && valor<lista[i-1]; i--) {
        lista[i] = lista[i-1];
    }
    lista[i] = valor;
    tamanho++;
    printf("\n\t\tValor inserido na lista com sucesso!");
}

void removeLista(int posicao) {
    if (tamanho == 0) {
        printf("\n\t    Lista Vazia! Insira um novo elemento.");
        return;
    }
    if (posicao <= 0 || posicao > tamanho) {
        printf("\n\t    Posição inválida, digite outra posição!");
        return;
    }
    if (posicao == 7) {
        lista[posicao-1] = 0;
        tamanho--;
        printf("\n\t\tValor removido da lista com sucesso!");
        return;
    } else {
        int i = posicao;
        while (lista[i] != 0) {
            lista[i-1] = lista[i];
            i++;
        }
        lista[i-1] = 0;
    }
    tamanho--;
    printf("\n\t\tValor removido da lista com sucesso!");
}

void buscaLista(int valor) {
    if (tamanho == 0) {
        printf("\n\t    Lista Vazia! Insira um novo elemento.");
        return;
    }
    int i;
    for (i=0; i<tamanho; i++) {
        if (lista[i] == valor) {
            printf("\n\t\tValor encontrado na posição: %d\n\n\t", i+1);
            return;
        }
    }
    printf("\n\t  O valor digitador não se encontra na lista!\n\n\t");
}

void imprime() {
    if (tamanho == 0) {
        printf("\n\t    Lista Vazia! Insira um novo elemento.");
        return;
    }
    int i;
    printf("\n\n\t\t\t     Posição   Valores\n");
    for (i=0; i<TAM; i++) {
        printf("\t\t\t\t");
        printf("%d\t[%d]\n", i+1, lista[i]);
    }
    printf("\n\n\t\t");
}

void recuperaLista(int posicao) {
    if (tamanho == 0) {
        printf("\n\t    Lista Vazia! Insira um novo elemento.");
        return;
    }
    if (posicao < 0 || posicao > tamanho) {
        printf("\n\t    Posição inválida, digite outra posição!");
        return;
    }
    printf("\n\tO valor que está armazenado na posição informada é: %d\n\n\t", lista[posicao-1]);
}

int main() {
    setlocale(LC_ALL, "");

    return 0;
}
