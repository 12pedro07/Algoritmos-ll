#include <stdio.h>
#include <stdlib.h>

// 2.
void preenchevetor(int* v, int n){
	int i;
	for (i=0;i<n;i++){
		printf("entre com valor de v[%d]: ",i);
		scanf("%d", (v+i) );
	}
}

// 3.
int somatoria(int* v, int n){
	int i, soma=0;
	for (i=0;i<n;i++){
		soma += *(v+i);
	}
	return soma;
}

// 4.
void somaealoca(int* v, int n){
	int i;
	for (i=1;i<n;i++){
		v[i] = v[i]+v[i-1];
	}
}

// 5.
void imprimevetor(int* v, int n){
	int i;
	for (i=0;i<n;i++){
		printf("v[%d] = %d\n", i, v[i]);
	}
	printf("\n");
}

// 7.
void copiavetor(int* v, int n, int* v2){
	int i;
	for (i=0;i<n;i++){
		*(v2+i) = *(v+i);
	}
}

int main(int argc, char *argv[]){
	// 1.
	int n;
	int* v;
	printf("tamanho do vetor: ");
	scanf("%d",&n);
	v = malloc( sizeof(int)*n );
	imprimevetor(v,n);
	
	// 2.
	preenchevetor(v, n);
	
	// 3.
	int soma = somatoria(v, n);
	printf("soma = %d\n", soma);
	
	// 4.
	somaealoca(v, n);
	imprimevetor(v,n);
	
	// 6.
	int* backup;
	backup = malloc( sizeof(int)*n );
	
	// 7.
	copiavetor(v, n, backup);
	imprimevetor(backup, n);
	
	free(v);
	free(backup);
	system("pause");
	return 0;
}
