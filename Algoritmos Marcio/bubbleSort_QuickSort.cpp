#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TAM 10
int vetor[TAM];

void gera() {
    int i;
    for (i=0; i<TAM; i++)
        vetor[i] = rand();
}

void BUBBLE_SORT() {
	int pass = 1, i, aux;
	bool sorted = false;
	while(!sorted && pass < TAM) {
		sorted = true;
		for (i=0; i<=TAM-pass-1; i++)
			if (vetor[i] > vetor[i+1]) {
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
				sorted = false;
			}
		pass++;
	}
}

int PARTITION(int p, int r) {
	int piv = vetor[p], aux;
	int i = p - 1;
	int j = r + 1;
	while (true) {
		do j = j - 1; while (vetor[j] > piv);
		do i = i + 1; while (vetor[i] < piv);
		if (i < j) {
			aux = vetor[i];
			vetor[i] = vetor[i+1];
			vetor[i+1] = vetor[i];
		} else return j;
	}
}

void QUICKSORT(int p, int r) {
	int q;
	if (p < r) {
		q = PARTITION(p, r);
		QUICKSORT(p, q);
		QUICKSORT(q+1, r);
	}
}

void imprime() {
	int i;
	for (i=0; i<TAM; i++)
		printf("[%d]", vetor[i]);
}

int main() {
    setlocale(LC_ALL,"");

	gera();
	printf("Vetor aleatório:\n");
	imprime();

	clock_t tempo1, tempo2;
	tempo1 = clock();

	BUBBLE_SORT();
	printf("\n");
	printf("\nMétodo de ordenação Bubble Sort aplicado:");
	printf("\n");
	imprime();
	gera();
	printf("\n");
	printf("\n");
	printf("Novo vetor aleatório:\n");
	imprime();
	printf("\n");
	printf("\nMétodo de ordenação Quick Sort aplicado:");
	QUICKSORT(0, TAM-1);
	printf("\n");
	imprime();

	tempo2 = clock()-tempo1;
	printf("\n");
	printf("\n%f", (float) tempo2 / CLOCKS_PER_SEC);
	printf("\n");

}

