#include <stdio.h>
#include <locale.h>

struct no {
    int dado;
    struct no *prox;
};
struct no *lista = NULL;

void insereLista(int valor) {
    struct no *atual;
    struct no *anterior;
    struct no *aux;
    atual = lista;
    aux = new (struct no);
    aux->dado = valor;
    if (lista==NULL || lista->dado > valor) {
        aux->prox = lista;
        lista = aux;
    } else {
        while (atual != NULL && atual->dado < valor)
        {
            anterior = atual;
            atual = atual->prox;
        }
        aux->prox = atual;
        anterior->prox = aux;
    }
    printf("\n\t\tValor inserido na lista com sucesso!");
}

void removeLista(int posicao) {
    if (lista == NULL) {
        printf("\n\t    Lista Vazia! Insira um novo elemento.");
        return;
    }
    if (posicao < 1) {
    	printf("\n\t    Posição inválida, digite outra posição!");
        return;	
	}
    int i;
    struct no *atual;
    struct no *anterior;
    atual = lista;
    if (posicao == 1) {
        lista = lista->prox;
        delete(atual);
        printf("\n\t\tValor removido da lista com sucesso!");
        return;
    }
    for (i=1; i<posicao; i++) {
        if (atual->prox == NULL) {
            printf("\n\t    Posição inválida, digite outra posição!");
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    anterior->prox = atual->prox;
    delete(atual);
    printf("\n\t\tValor removido da lista com sucesso!");
}

void buscaLista(int valor)  {
    if (lista == NULL) {
        printf("\n\t    Lista Vazia! Insira um novo elemento.");
        return;
    }
    struct no *aux;
    aux = lista;
    int i = 1;
    while (aux != NULL) {
        if (aux->dado == valor) {
            printf("\n\n\t\tValor encontrado na posição: %d\n\n\t", i);
            return;
        }
        aux = aux->prox;
        i++;
    }
    printf("\n\t  O valor digitador não se encontra na lista!\n\n\t");
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
    printf("\n\n\t\t");
}

void recuperaLista(int posicao) {
    if (lista == NULL) {
        printf("\n\t    Lista Vazia! Insira um novo elemento.");
        return;
    }
    struct no *aux;
    aux = lista;
    int i = 1;
    while (i != posicao) {
        if (aux->prox == NULL) {
            printf("\n\t    Posição inválida, digite outra posição!");
            return;
        }
        aux = aux->prox;
        i++;
    }
    printf("\n\tO valor que está armazenado na posição informada é: %d\n\n\t", aux->dado );
}

int main() {
    setlocale(LC_ALL, "");

    return 0;
}
