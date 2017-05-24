#include <stdio.h>
#include <stdlib.h>
#define N 10

int main(){
	int A[N], i, j, AUX;
	/* lendo o vetor */
	for(i=0; i<N-2; i++) {
		printf("Digite a sequencia do vetor A[%d]: ", i);
		scanf("%d", &A[i]);
	}
	/* ordenando vetor em ordem crescente - método seleção direta */
	for(i=0; i<N-2; i++)
	   for(j=i+1; j<N; j++)
	      if(A[i]>A[j]) {
	      	 AUX=A[i];
	      	 A[i]=A[j];
	      	 A[j]=AUX;
		  }
	/* mostrando vetor ordenado */
	printf("Vetor em ordem\n");
	for(i=0; i<N; i++)
	   printf("%d ", A[i]);
	printf("\n");
	system("pause");
	return 0;
}
