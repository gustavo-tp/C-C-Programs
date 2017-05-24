#include <stdio.h>
#include <stdlib.h>
#define N 5

int main(){
	int A[N], i, maior;
	for(i=0; i<N; i++) {
		printf("A[%d]: ", i);
		scanf("%d", &A[i]);
	}
	maior=A[0];
	for(i=1; i<N; i++)
	   if (A[i]>maior) maior=A[i];
	   
	printf("Maior valor encontrado no vetor = %d\n", maior);
	
	printf("Vetor invertido\n");
	for(i=N-1; i>=0; i--)
	   printf("%d ", A[i]);
	printf("\n");
	system("pause");
	return 0;   
}
