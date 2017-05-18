void push_duplo(int valor1, int valor2) {
    if (topo >= TAM-2) {
        printf("Erro");
        return;
    }
    topo++;
    pilha[topo] = valor1;
    topo++;
    pilha[topo] = valor2;
}

void conta() {
    int contador = 0;
    struct no *atual;
    atual = lista;
    while (atual != NULL) {
        if (atual->dado > 10)
            contador++;
        atual = atual->prox;
    }
    printf("%d", contador);
}
