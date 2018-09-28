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

void preenche_matriz_manual(float** matriz, int l, int c){
	int i, j;
	for (i=0;i<l;i++){
		for (j=0;j<c;j++){
			printf("M[%d][%d] = ",i,j);
			scanf("%f",&matriz[i][j]);
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

void copia_e_ignora(float** orig, float** copia, int l, int c, int ig_l, int ig_c){ // copia deve ser no maximo 1 tamanho menor do que a original
	int ic,jc, io=0,jo=0; // ic-jc para a copia || io-jo para original
	int aux = 0;

	if (ig_l>=l || ig_l<0 || ig_c>=c || ig_c<0){ // se fornecer um valor invalido para ser ignorado, copia uma matriz para a outra
		printf("ERROR: invalid ignored matrix coordinates");
	} else { 
		//printf("\n\nIGNORANDO LINHA %d E COLUNA %d:\n\n",ig_l,ig_c);
		// varrendo e preenchendo a copia:
		for (ic=0;ic<l-1;ic++){
			
			if (io == ig_l){ // se a linha deve ser ignorada, forca o for para a proxima linha
				io++;
			}
			
			for (jc=0;jc<c-1;jc++){
				
				if (jo == ig_c){ // se a coluna deve ser ignorada, pula o elemento na matriz 
					jo++;
				}
				if (jo>c-1)
					jo=0;
				if (jo == ig_c){ // se a coluna deve ser ignorada, pula o elemento na matriz 
					jo++;
				}
				
				copia[ic][jc] = orig[io][jo];
				
				jo++;
			}
			io++;
		}
		//imprime_matriz(copia,ic,jc);
	}
}

void copia_matriz(float** orig, float** copia, int l, int c){
	int i,j;
	for (i=0;i<l;i++){
		for (j=0;j<c;j++){
			copia[i][j] = orig[i][j];
		}
	}
}

float determinante(float** m, int ordem){
	int j;
	float det = 0;

	// Caso base:
	if (ordem == 2){
		//imprime_matriz(m,ordem,ordem); 
		return m[0][0]*m[1][1] - m[0][1]*m[1][0];
	}
	
	// tratando a recursividade 
	float** m_aux;
	int ordem_aux = ordem-1;
	m_aux = cria_matriz(ordem_aux,ordem_aux);
	// o determinante da matriz eh calculado em funcao do determinante de cada elemento da primeira linha
	for (j=0;j<ordem;j++){
		copia_e_ignora(m,m_aux,ordem,ordem,0,j);
		if (j%2 == 0){ // linha + coluna == par:
			det += m[0][j]*determinante(m_aux,ordem_aux);
		} else { // linha + coluna == impar:
			det = det - m[0][j]*determinante(m_aux,ordem_aux);
		}
		//printf("%d ---> %f ----> %f\n",j,determinante(m_aux,ordem_aux),det); 
	}

	destroi_matriz(m_aux,ordem_aux);
	return det;
}

void cramer(float** m_orig, int l, int c){
	// retorna um ponteiro para um array com os resultados das incognitas
	int i,j,aux;
	int ordem = l;
	if (l<c-1){
		printf("sistema impossivel!\n");
	} else{
		float** m_incog = cria_matriz(ordem,ordem);
		for (i=0;i<ordem;i++){ // copia matriz sem as constantes
			for (j=0;j<ordem;j++){
				m_incog[i][j] = m_orig[i][j];
			}
		}
		float det = determinante(m_incog,ordem);
		float* det_array = malloc(sizeof(float)*ordem);
		for (aux=0;aux<ordem;aux++){ // criando um vetor com todos os determinantes necessarios para resolver o cramer
			for (i=0;i<ordem;i++){
				for (j=0;j<ordem;j++){
					if (j==aux)
						m_incog[i][j] = m_orig[i][c-1];
					else
						m_incog[i][j] = m_orig[i][j];
				}
			}
			det_array[aux] = determinante(m_incog,ordem)/det;
		}
		destroi_matriz(m_incog,ordem);
		printf("\n--> Por Cramer:\n");
		for (i=0;i<l;i++){
			printf("variavel %d = %f\n",i,det_array[i]);
		}
		free(det_array);
	}	
}

void troca_linhas(float** m_orig, int linhas, int colunas, int linha1, int linha2){
	float** m_aux = cria_matriz(linhas, colunas);
	int i,j;
	for (i=0;i<linhas;i++){
		for (j=0;j<colunas;j++){
			m_aux[i][j] = m_orig[i][j];
		}
	}
	
	for (j=0;j<colunas;j++){
		m_orig[linha1][j] = m_aux[linha2][j];
		m_orig[linha2][j] = m_aux[linha1][j];
	}
	
	//imprime_matriz(m_orig,linhas,colunas);
	destroi_matriz(m_aux,linhas);
}

void gauss(float** matriz, int linhas, int colunas){
	int k,j,i = 0;
	float pivo;
	
	float** m_aux = cria_matriz(linhas,colunas);
	copia_matriz(matriz,m_aux,linhas,colunas);
	
	// zerando em baixo da diagonal principal	
	for (k=0;k<linhas-1;k++){

		pivo = m_aux[k][k];
		while (pivo == 0){
			troca_linhas(m_aux,linhas,colunas,k+1,k); 
			imprime_matriz(m_aux,linhas,colunas);
			pivo = m_aux[k][k];
			
		}

		for (i=k+1;i<linhas;i++){
			float ml = (m_aux[i][k] / pivo); // multiplicador de linha (apartir da linha 1)
			for (j=0;j<colunas;j++){
				m_aux[i][j] = m_aux[i][j] - m_aux[k][j]*ml;
			}
		}
	}
	imprime_matriz(m_aux,linhas,colunas);
	
	// zerando em cima da diagonal principal
	for (k=linhas-1;k>=0;k=k-1){

		pivo = m_aux[k][k];
		
		for (i=k-1;i>=0;i=i-1){
			float ml = (m_aux[i][k] / pivo); // multiplicador de linha (apartir da linha 1)
			for (j=colunas;j>=0;j=j-1){
				m_aux[i][j] = m_aux[i][j] - m_aux[k][j]*ml;
			}
		}
	}
	imprime_matriz(m_aux,linhas,colunas);
	
	printf("\n--> Por Gauss:\n");
	for (i=0;i<linhas;i++){
		if (m_aux[i][i]!=0)
			printf ("variavel %d = %f\n",i,m_aux[i][colunas-1]/m_aux[i][i]);
		else
			printf ("\nvariavel %d = 0\n",i);
	}
}

int main (int argc, char* argv[]){
	
	int linhas,colunas;
	float** matriz;
	
	printf("linhas: ");
	scanf("%d", &linhas);
	printf("colunas: ");
	scanf("%d", &colunas);
	
	matriz = cria_matriz(linhas,colunas);
	preenche_matriz_manual(matriz,linhas,colunas);
	
	imprime_matriz(matriz,linhas,colunas);

	gauss(matriz,linhas,colunas);
			
	cramer(matriz, linhas, colunas);
	
	destroi_matriz(matriz,linhas);
	
	system("pause");
	return 0;
}
