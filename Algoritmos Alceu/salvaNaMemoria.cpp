#include <stdio.h>
#include <stdlib.h>
#define N 3
#define M 4

void inicializa(int mat[N][M]) {
     int i, j;
     srand(100);
     for (i = 0; i < N; i++)
         for (j = 0; j < M; j++) mat[i][j] = rand() % 1000;
}

void mostra(int mat[][M]) {
     int i, j;
     printf("\nMatriz\n");
     for (i = 0; i < N; i++) {
         for (j = 0; j < M; j++) printf("%5d", mat[i][j]);
         printf("\n");
         }     
}

int salva(int mat[][M]) {
    FILE *fp;
    fp = fopen("C:\\matriz.dad", "wb");
    if (fp == NULL) {
           printf("Erro ao abrir arquivo\n");
           return - 1;
           }
           fwrite(mat, N * M * sizeof(int), 1, fp);
           fclose(fp);
           return 0;    
}

int le(int mat[][M]) {
    FILE * fp;
    fp = fopen("C:\\matriz.dad", "rb");
    if (fp == NULL) {
           printf("Erro ao abrir rquivo de leitura\n");
           return -2;
           }    
           fread(mat, N * M * sizeof(int), 1, fp);
           return 0;
}

int salva_mod_texto(int mat[][M]) {
    FILE *fp;
    fp = fopen("C:\\MatrizTexto", "w");
    if (!fp) {
             printf("Erro ao abrir rquivo de leitura\n");
             return -3;
             }    
             for (int i = 0; i < N; i++) {
                 for (int j = 0; j < M; j++) fprintf(fp, "%5d ", mat[i][j]);
         }   
         fclose(fp);
         return 0;
}

int le_mod_texto(int mat[][M]) {
    FILE *fp;
    fp = fopen("C:\\MatrizTexto", "w");
    if (!fp) {
             printf("Erro ao abrir rquivo de leitura\n");
             return -4;
             }    
             for (int i = 0; i < N; i++) {
                 for (int j = 0; j < M; j++) fprintf(fp, "%5d ", &mat[i][j]);
                 fscanf(fp, "\n\n");
         }   
         fclose(fp);
         return 0;
}

int main() {
    int mat[N][M], bk[N][M];
    inicializa(mat);
    mostra(mat);
    salva(mat);
    le(bk);
    mostra(bk);
    salva_mod_texto(bk);
    system("pause");
    return 0;
}
