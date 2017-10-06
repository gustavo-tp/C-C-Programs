#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define TAM 20000
int vetor[TAM];
int chaveBusca;
float qtdSequencial = 0;
float qtdBinaria = 0;
float qtdArvore = 0;
float qtdArvoreAvl = 0;

struct no {
    int dado;
    struct no *esq;
    struct no *dir;
    int bal;
};
struct no *raiz = NULL, *raiz_avl = NULL;

void gera() {
    int i;
    //srand( (unsigned)time(NULL) );
    for (i=0; i<TAM; i++)
        vetor[i] = rand();
}

void insere(int valor) {
   struct no *atual, *aux;

   aux = new(struct no);
   aux->dado = valor;
   aux->esq = NULL;
   aux->dir = NULL;

   atual=raiz;

	if (atual==NULL) {
	    raiz = aux;
		return;
    }

    while (1) {
    if (valor < atual->dado)
        if (atual->esq==NULL) {
            atual->esq=aux;
            return;
        } else atual=atual->esq;
        else if (atual->dir==NULL) {
            atual->dir=aux;
            return;
        }
        else atual=atual->dir;
    }
}

// Cira um no e preenche os membros
struct no *cria_no(int valor){
    struct no *aux = new (struct no);
    aux->dado=valor;
    aux->dir=NULL;
    aux->esq=NULL;
    aux->bal=0;
    return aux;
};

//Rotação para a direita
void direita(struct no *p) {

	struct no *q, *hold;

   q = p->esq;
   hold = q->dir;
   q->dir = p;
   p->esq = hold;

}

// Rotação para a esquerda
void esquerda(struct no *p) {

	struct no *q, *hold;

   q = p->dir;
   hold = q->esq;
   q->esq = p;
   p->dir = hold;

}

//Insere valor em uma árvore AVL
void insere_bal(int chave) {
	struct no *pp=NULL, *p=raiz_avl, *pajovem=NULL, *ajovem=raiz_avl, *q, *filho;
    int imbal;

    if (p==NULL) {                   /* Arvore vazia */
		raiz_avl = cria_no(chave);   /* Funcao para criacao de um novo no */
        return;
    }

	/* Insere chave e descobre ancestral mais jovem a ser desbalanceado */
    while (p!=NULL) {
   	if (chave < p->dado)
	    q = p->esq;
	    else q = p->dir;
        if (q!=NULL)
    		if (q->bal != 0) {
        	pajovem=p;
            ajovem=q;
		}
		pp = p;
		p = q;
    }

    q = cria_no(chave);

    if (chave<pp->dado)
		pp->esq=q;
    else pp->dir=q;

	/* Balanceamento de todos os nós entre ajovem e q devem ser ajustados */
	if (chave<ajovem->dado)
		filho = ajovem->esq;
    else filho = ajovem->dir;

   p = filho;

    while (p!=q) {
		if (chave < p->dado) {
			p->bal=1;
			p=p->esq;
		} else {
			p->bal = -1;
			p=p->dir;
		}
    }

    if (chave<ajovem->dado)
		imbal = 1;
	else imbal = -1;

    if (ajovem->bal==0) {        /*Não houve desbalanceamento */
		ajovem->bal=imbal;
    	return;
    }


	if (ajovem->bal!=imbal) {   /*Não houve desbalanceamento */
		ajovem->bal=0;
		return;
    }

	/* Houve desbalanceamento */
    if (filho->bal == imbal) {
		p=filho;
		if (imbal==1)        /* Faz rotação simples */
			direita(ajovem);
		else esquerda(ajovem);
		ajovem->bal=0;
    	filho->bal=0;
    } else {
		if (imbal==1) {	  /*Faz rotação dupla */
    		p=filho->dir;
    		esquerda(filho);
    		ajovem->esq=p;
    		direita(ajovem);
		} else {
    			p=filho->esq;
    			direita(filho);
    			ajovem->dir=p;
    			esquerda(ajovem);
    	}
    	if (p->bal==0) {
    		ajovem->bal=0;
    		filho->bal=0;
    	} else {
    		if (p->bal == imbal) {
    			ajovem->bal = - imbal;
        		filho->bal = 0;
	        } else {
	            ajovem->bal = 0;
	            filho->bal = imbal;
	        }
	    }
    	p->bal=0;
   }

	if (pajovem == NULL)  /* Ajusta ponteiro do pai do ancestral mais jovem */
    	raiz_avl = p;
    else if (ajovem==pajovem->dir)
    	pajovem->dir = p;
    else pajovem->esq = p;

   return;
}

void insereVetorArvore() {
    for (int i = 0; i<TAM; i++) {
        insere(vetor[i]);
        insere_bal(vetor[i]);
    }
}

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

void geraChaveAleatoria() {
	chaveBusca = rand();
}

void sequencial(int valor) {
	int i, j;
    i = 0;
    while (i < TAM) {
        qtdSequencial++;
		if (valor == vetor[i]) {
        	printf("Achei\n");
        	return;
        }
    	i++;
    }
	printf("Não achei\n");
}

void binaria (int valor) {
    int inicio = 0;
    int fim = TAM - 1;
    int meio, contadorBin;
    while (inicio <= fim) {
        meio = (inicio + fim)/2;
        qtdBinaria++;
        if (valor == vetor[meio]) {
            printf("Achei\n");
            return;
        }
        if (valor < vetor[meio])
            fim = meio-1;
        else inicio = meio+1;
    }
    printf("Não achei\n");
}

void buscaArvore(int valor) {
    struct no *atual;
    atual = raiz;
    while (atual != NULL) {
        qtdArvore++;
        if (atual->dado == valor) {
            printf("Achei\n");
            delete(atual);
            return;
        }
        if (atual->dado > valor)
            atual = atual->esq;
        else atual = atual->dir;
    }
    printf("Nao achei\n");
}

void buscaArvoreAVL(int valor) {
    struct no *atual;
    atual = raiz_avl;
    while (atual != NULL) {
        qtdArvoreAvl++;
        if (atual->dado == valor) {
            printf("Achei\n");
            delete(atual);
            return;
        }
        if (atual->dado > valor)
            atual = atual->esq;
        else atual = atual->dir;
    }
    printf("Não achei\n");
}

void imprime() {
    for (int i=0; i<TAM; i++) {
        printf("[%d]", vetor[i]);
    } printf("\n");
}

void em_ordem(struct no *atual) {
    if (atual != NULL) {
        em_ordem(atual->esq);
        printf("[%d]", atual->dado);
        em_ordem(atual->dir);
    }
}

int main() {
    setlocale(LC_ALL,"");
    // 1- Gerar um vetor de números aleatórios;
    gera();

    // 2- Armazenar esses números em uma árvore de busca binária;
    // 3- Armazenar esses números em uma árvore AVL;
    insereVetorArvore();

    // 4- Classificar o vetor usando um método de ordenação rápido;
    QUICKSORT(0, TAM-1);

    // 5- Gerar uma chave de busca aleatória
    geraChaveAleatoria();

    // 6- Buscar essa chave usando os seguintes métodos de busca:
    sequencial(chaveBusca);     // a. Busca seqüencial;
    binaria(chaveBusca);        // b. Busca binária;
    buscaArvore(chaveBusca);    // c. Busca em árvore binária;
    buscaArvoreAVL(chaveBusca); // d. Busca em árvore AVL.
    printf("Chave: %d\n", chaveBusca);

    // 7- Medir o número de comparações dos 4 métodos de busca;
    // Obs.: Contadores: qtdSequencial, qtdBinaria, qtdArvore e qtdArvoreAvl incrementados em cada comparação dos algoritmos de busca

    // 8- Repetir o passo 5, 6 e 7 várias vezes, e calcular o número médio de comparações dos quatro métodos;
    int i;
    for (i=0; i<999; i++) {
        geraChaveAleatoria();
        sequencial(chaveBusca);
        binaria(chaveBusca);
        buscaArvore(chaveBusca);
        buscaArvoreAVL(chaveBusca);
        printf("Chave: %d\n", chaveBusca);
    }

    // 9-  Imprimir o nome do método de busca e o número médio de comparações.
    printf("A média do algoritmo de busca sequencial foi: %.2f\n", qtdSequencial/1000);
    printf("A média do algoritmo de busca binária foi: %.2f\n", qtdBinaria/1000);
    printf("A média do algoritmo de busca em arvore binária foi: %.2f\n", qtdArvore/1000);
    printf("A média do algoritmo de busca em arvore AVL foi: %.2f\n", qtdArvoreAvl/1000);

    return 0;
}
