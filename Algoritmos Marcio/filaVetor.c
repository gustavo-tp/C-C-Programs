void insereFila(int valor) {
    if (contador == 0) {
        printf("Erro");
        return;
    }
    if (inicio == TAM-1)
        inicio = 0;
    else inicio++;
    contador--;
}
