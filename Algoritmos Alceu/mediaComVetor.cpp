#include <stdio.h>
#include <stdlib.h>
#define N 10

int main(){
	float aluno[N], med=0;
	int i, qt=0;
	/* lendo vetor */
	for(i=0; i<N; i++) {
		printf("Informe nota do %do aluno: ", i+1);
		scanf("%f", &aluno[i]);
		med=med+aluno[i];
	}
	med=med/N;
	/* verificando qtde alunos abaixo da média */
	for(i=0; i<N; i++)
	   if (aluno[i]<med) qt++;
	printf("Media = %.2f\n", med);
	printf("Qtde alunos abaixo da media = %d\n", qt);
	system("pause");
	return 0;   
}
