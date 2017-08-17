#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

#define TAM 10 // Obs.: Merge Sort trava com TAM acima de 32488 no Dev-C++ e 32560 no Code::Blocks
int vetor[TAM];
clock_t tempo1, tempo2;

void gera() {
    int i;
    for (i=0; i<TAM; i++)
        vetor[i] = rand();
}

void imprime() {
	int i;
	for (i=0; i<TAM; i++)
		printf("[%d]", vetor[i]);
}

// INICIO BUBBLE
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
// FIM BUBBLE

// INICIO QUICK
int PARTITION(int p, int r) {
	int piv, aux;
	piv = vetor[p];
	int i = p - 1;
	int j = r + 1;
	while (true) {
		do j = j - 1; while (vetor[j] > piv);
		do i = i + 1; while (vetor[i] < piv);
		if (i < j) {
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
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
// FIM QUICK

// INICIO SELECTION
void SELECTION_SORT () {
    int i, k, atual, aux;
    for (i=0; i<=TAM-2;i++) {
       atual = i;
       for (k=i+1; k<=TAM-1; k++)
           if (vetor[atual] > vetor[k])
            	atual = k;
        aux = vetor[i];
        vetor[i] = vetor[atual];
        vetor[atual] = aux;
    }
}
// FIM SELECTION

// INICIO HEAP
int tam_heap;

void HEAPIFY (int i) {
	int l, r, max, aux;
	l = 2 * i + 1;
	r = 2 * i + 2;
	if (l < tam_heap && vetor[l] > vetor[i])
		max = l;
	else max = i;
	if (r < tam_heap && vetor[r] > vetor[max])
		max = r;
	if (max != i) {
		aux = vetor[i];
		vetor[i] = vetor[max];
		vetor[max] = aux;
		HEAPIFY (max);
	}
}

void BUILD_HEAP () {
	int j;
	tam_heap = TAM;
	for (j=(TAM/2)-1;j>=0;j--) {
		HEAPIFY(j);
	}
}

void HEAPSORT () {
	int k, aux;
	BUILD_HEAP();
	for (k=TAM-1;k>=1;k--) {
		aux = vetor[0];
		vetor[0] = vetor[k];
		vetor[k] = aux;
		tam_heap--;
		HEAPIFY(0);
	}
}
// FIM HEAP

// INICIO INSERT
void INSERTION_SORT () {
    int k, x, i, aux;
    bool achou;
    for (k=1; k<=TAM-1; k++) {
    	x = vetor[k];
    	i = k - 1;
    	achou = false;
    	while (!achou && i>=0) {
    		if (vetor[i] > x) {
    			aux = vetor[i+1];
    			vetor[i+1] = vetor[i];
    			vetor[i] = aux;
    			i--;
			} else achou = true;
		}
	}
}
// FIM INSERT

// INICIO MERGE
void MERGESORT(int lo, int hi) {
	int meio, L, H, k;
	int arranhar[TAM];
	if (lo < hi) {
		meio = (lo + hi) / 2;
		MERGESORT(lo, meio);
		MERGESORT(meio+1, hi);
		L = lo;
		H = meio + 1;
		for (k=lo; k<=hi; k++) {
			if (L <= meio && (H > hi || vetor[L] < vetor[H])) {
				arranhar[k] = vetor[L];
				L++;
			} else {
				arranhar[k] = vetor[H];
				H++;
			}
		}
		for (k=lo; k<=hi; k++)
			vetor[k] = arranhar[k];
	}
}
// FIM MERGE

void mostra_ordenado(int m) {
	char mtd[9];
	switch (m) {
		case 1: strcpy(mtd, "Bubble"); break;
		case 2: strcpy(mtd, "Quick"); break;
		case 3: strcpy(mtd, "Selection"); break;
		case 4: strcpy(mtd, "Heap"); break;
		case 5: strcpy(mtd, "Insertion"); break;
		case 6: strcpy(mtd, "Merge"); break;
	}
	printf("\n\nMétodo de ordenação %s Sort aplicado, tempo de excecução: %f\n", mtd, (float) tempo2 / CLOCKS_PER_SEC);
	if (TAM <= 10) {
	    printf("Vetor ordenado:\n");
		imprime();
		printf("\n");
	}
}

void mostra_gerado() {
	gera();
    if (TAM <= 10) {
	    printf("\nVetor aleatório:\n");
		imprime();
	}
}

int main() {
    setlocale(LC_ALL,"");

    mostra_gerado();

	tempo1 = clock();
	BUBBLE_SORT();
	tempo2 = clock()-tempo1;
	mostra_ordenado(1);

    mostra_gerado();

	tempo1 = clock();
	QUICKSORT(0, TAM-1);
	tempo2 = clock()-tempo1;
	mostra_ordenado(2);

	mostra_gerado();

	tempo1 = clock();
	SELECTION_SORT();
	tempo2 = clock()-tempo1;
	mostra_ordenado(3);

	mostra_gerado();

	tempo1 = clock();
	HEAPSORT();
	tempo2 = clock()-tempo1;
	mostra_ordenado(4);

	mostra_gerado();

	tempo1 = clock();
	INSERTION_SORT();
	tempo2 = clock()-tempo1;
	mostra_ordenado(5);

	mostra_gerado();

	tempo1 = clock();
	MERGESORT(0, TAM-1);
	tempo2 = clock()-tempo1;
	mostra_ordenado(6);

    return 0;
}
