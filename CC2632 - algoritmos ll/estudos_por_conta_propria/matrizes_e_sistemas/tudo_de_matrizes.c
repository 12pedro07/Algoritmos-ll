#include <stdio.h>
#include <stdlib.h>

float** cria_matriz(int linhas,int colunas){
	int i;
	float** matriz = malloc(sizeof(float*)*linhas);
	for (i=0;i<linhas;i++){
		matriz[i] = malloc(sizeof(float)*colunas);
	}
	return matriz;
}

void destroi_matriz(float** matriz, int linhas){
	int i;
	for (i=0;i<linhas;i++)
		free(matriz[i]);
	free(matriz);
}

void imprime_matriz(float** matriz,int linhas,int colunas){
	int i, j;
	printf("\n-------------------------\n\t->matriz %d x %d:\n\n\n",linhas,colunas);
	for (i=0;i<linhas;i++){
		for (j=0;j<colunas;j++){
			printf("%f\t",matriz[i][j]);
		}
		printf("\n");
	}
}

void preenche_matriz(float** matriz, int linhas, int colunas){
	int i, j;
	for (i=0; i<linhas; i++){
		for (j=0;j<colunas;j++){
			matriz[i][j] = ((i*colunas)+j+1); // matriz[i][j] == *(*(matriz + i) + j)
		}
	}
}

void multiplica_matriz(float** r, float** m1, float** m2,int l1,int c1,int c2){
	int i, j, k;
	for(i = 0 ; i < l1 ; i++){
		for(j = 0 ; j < c2 ; j++){
			r[i][j] = 0;
			for(k = 0; k < c1; k++){
				r[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
}

int main (int argc, char* argv[]){
	
	float** m1;
	float** m2;
	float** r;
	m1 = cria_matriz(3,4);
	m2 = cria_matriz(4,3);
	r = cria_matriz(3,3);
	preenche_matriz(m1,3,4);
	preenche_matriz(m2,4,3);
	imprime_matriz(m1,3,4);
	imprime_matriz(m2,4,3);
	multiplica_matriz(r,m1,m2,3,4,3);
	imprime_matriz(r,3,3);
	destroi_matriz(m1,3);
	destroi_matriz(m2,4);
	destroi_matriz(r,3);
	
	system("pause");
	return 0;
}
