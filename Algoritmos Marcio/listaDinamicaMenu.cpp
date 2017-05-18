#include <iostream>
#include <cstdlib>
#include <clocale>
#include <windows.h>

using namespace std;

struct no {
    int dado;
    struct no *prox;
};
struct no *lista = NULL;

void insereLista(int valor) {
    system("cls");
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
    cout << "\n\n\n\n\n\n\t\tValor inserido na lista com sucesso!";
    Sleep(2000);
}

void removeLista(int posicao) {
    system("cls");
    int i;
    struct no *atual;
    struct no *anterior;
    atual = lista;
    if (posicao == 1) {
        lista = lista->prox;
        delete(atual);
        cout << "\n\n\n\n\n\n\t\tValor removido da lista com sucesso!";
        Sleep(2000);
        return;
    }
    for (i=1; i<posicao; i++) {
        if (atual->prox == NULL) {
            cout << "\n\n\n\n\n\n\t    Posição inválida, digite outra posição!";
            Sleep(2000);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    anterior->prox = atual->prox;
    delete(atual);
    cout << "\n\n\n\n\n\n\t\tValor removido da lista com sucesso!";
    Sleep(2000);
}

void buscaLista(int valor)  {
    system("cls");
    struct no *aux;
    aux = lista;
    int i = 1;
    while (aux != NULL) {
        if (aux->dado == valor) {
            cout << "\n\n\n\n\n\t\tValor encontrado na posição: " << i << "\n\n\t";
            system("pause");
            return;
        }
        aux = aux->prox;
        i++;
    }
    cout << "\n\n\n\n\n\n\t  O valor digitador não se encontra na lista!\n\n\t";
    system("pause");
    return;
}

void imprime() {
    system("cls");
    int i = 1;
    struct no *aux;
    aux = lista;
    cout << "\n\n\t\t\t     Posição   Valores\n";
    while (aux != NULL) {
        cout << "\t\t\t\t";
        cout << i << "\t[" << aux -> dado << "]\n";
        i++;
        aux = aux -> prox;
    }
    cout << "\n\n\t\t";
    system("pause");
}

void recuperaLista(int posicao) {
    system("cls");
    struct no *aux;
    aux = lista;
    int i = 1;
    while (i != posicao) {
        if (aux->prox == NULL) {
            cout << "\n\n\n\n\n\n\t    Posição inválida, digite outra posição!";
            Sleep(2000);
            return;
        }
        aux = aux->prox;
        i++;
    }
    cout << "\n\n\n\n\n\tO valor que está armazenado na posição informada é: " << aux->dado << "\n\n\t    ";
    system("pause");
}

void menu() {
    system("cls");
    int aux;
    cout << "\n\n\t   Bem vindo ao sistema de estrutura em lista!\n";
    cout << "\t\t(utilizando alocação dinâmica)\n\n";
    cout << "\tPara inserir um novo elemento na lista digite:  1\n";
    cout << "\tPara remover um elemento da lista digite:       2\n";
    cout << "\tPara buscar um elemento na lista digite:        3\n";
    cout << "\tPara exibir a lista completa digite:            4\n";
    cout << "\tPara recuperar um elemento da lista digite:     5\n";
    cout << "\tPara sair do programa digite                    6\n";
    cout << "\n\t\t\tResposta: ";
    cin >> aux;
    switch (aux) {
    case 1:
        system("cls");
        cout << "\n\n\n\n\n\n\tDigite o valor que deseja inserir na lista: ";
        cin >> aux;
        cout << "\n";
        insereLista(aux);
        menu();
    case 2:
        system("cls");
        if (lista == NULL) {
            cout << "\n\n\n\n\n\n\t    Lista Vazia! Insira um novo elemento.";
            Sleep(2000);
            menu();
        }
        cout << "\n\n\n\n\n\n\tDigite a posição do valor que deseja remover: ";
        cin >> aux;
        cout << "\n";
        removeLista(aux);
        menu();
    case 3:
        system("cls");
        if (lista == NULL) {
            cout << "\n\n\n\n\n\n\t    Lista Vazia! Insira um novo elemento.";
            Sleep(2000);
            menu();
        }
        cout << "\n\n\n\n\n\n\tDigite o valor que deseja buscar na lista: ";
        cin >> aux;
        cout << "\n";
        buscaLista(aux);
        menu();
    case 4:
        if (lista == NULL) {
            system("cls");
            cout << "\n\n\n\n\n\n\t    Lista Vazia! Insira um novo elemento.";
            Sleep(2000);
            menu();
        }
        imprime();
        menu();
    case 5:
        system("cls");
        if (lista == NULL) {
            cout << "\n\n\n\n\n\n\t    Lista Vazia! Insira um novo elemento.";
            Sleep(2000);
            menu();
        }
        cout << "\n\n\n\n\n\n\t\t  Digite a posição do elemento\n\t\tque deseja recuperar da lista: ";
        cin >> aux;
        cout << "\n";
        recuperaLista(aux);
        menu();
    case 6:
        system("cls");
        cout << "\n\n\n\n\n\tObrigado pela preferência, até a próxima!\n";
        exit(0);
    default:
        system("cls");
        cout << "\n\n\n\n\n\n\t    Comando inválido, digite outro número!";
        Sleep(2000);
        menu();
    }
}

int main() {
    setlocale(LC_ALL, "");
    menu();

    return 0;
}
