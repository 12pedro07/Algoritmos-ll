#include <stdlib.h>
#include <stdio.h>

float** cria_sistema(){
	int i;
	float** sistema = malloc(sizeof(float*)*3);
	for (i=0;i<3;i++){
		sistema[i] = malloc(sizeof(float)*4);
	}
	return sistema;
}

void copia_sistema(float** original, float** copia){
	int i, j;
	for (i=0;i<3;i++){
		for (j=0;j<4;j++){
			copia[i][j] = original [i][j];
		}
	}
}

void imprime_sistema(float** sistema){
	int i;
	puts("");
	for (i=0;i<3;i++){
		printf("%.2fx + %.2fy + %.2fz = %.2f", sistema[i][0],sistema[i][1],sistema[i][2],sistema[i][3]);
		printf("\n");
	}
}

void preenche_sistema(float** sistema){
	int i,j;
	char xyz[3] = "xyz";
	for (i=0;i<3;i++){
		printf("equacao numero %d:\n",i+1);
		for (j=0;j<3;j++){
			printf("%c = ",xyz[j]);
			scanf("%f",&sistema[i][j]);
		}
		printf("resultado = ");
		scanf("%f",&sistema[i][j]);
		printf("\n");
	}
}

void destroi_sistema(float** sistema){
	int i;
	for (i=0;i<3;i++)
		free(sistema[i]);
	free(sistema);
}

float determinante(float** sistema){
	float det = 0;
	det += sistema[0][0]*sistema[1][1]*sistema[2][2];
	det += sistema[0][1]*sistema[1][2]*sistema[2][0];
	det += sistema[0][2]*sistema[1][0]*sistema[2][1];
	det -= sistema[2][0]*sistema[1][1]*sistema[0][2];
	det -= sistema[2][1]*sistema[1][2]*sistema[0][0];
	det -= sistema[2][2]*sistema[1][0]*sistema[0][1];
	return det;
}

void cramer(float** sistema){
	float** aux = cria_sistema();
	float d = determinante(sistema);
	int i,j;
	// constroi aux para substituir a primeira coluna por o resultado
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			if (j==0)
				aux[i][j] = sistema[i][3];
			else
				aux[i][j] = sistema[i][j];
		}
	}
	float dx = determinante(aux);
	
	// re-constroi aux para substituir a segunda coluna por o resultado
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			if (j==1)
				aux[i][j] = sistema[i][3];
			else
				aux[i][j] = sistema[i][j];
		}
	}
	float dy = determinante(aux);
	
	// re-constroi aux para substituir a terceira coluna por o resultado
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			if (j==2)
				aux[i][j] = sistema[i][3];
			else
				aux[i][j] = sistema[i][j];
		}
	}
	float dz = determinante(aux);
	
	destroi_sistema(aux);
	
	float x = dx/d;
	float y = dy/d;
	float z = dz/d;
	printf("\nPOR CRAMER:\n------------------------------------\n");
	printf("d = %f\tdx = %f\tdy = %f\tdz = %f\t\n\n",d,dx,dy,dz);
	printf("x = %f\ty = %f\tz = %f\n------------------------------------\n",x,y,z);
}

void gauss(float** sistema){
	int i,j;
	float pivo = sistema[0][0];
	float** aux = cria_sistema();
	copia_sistema(sistema,aux);
	float ml1 = (sistema[1][0]) / pivo; // multiplicador da linha 1 (linha 0 nao precisa de multiplicador)
	float ml2 = (sistema[2][0]) / pivo; // multiplicador da linha 2
	
	// ---------- zerando o primeiro elemento de cada linha ----------
	for (j=0;j<4;j++){
		aux[1][j] = aux[1][j] - aux[0][j]*ml1;
		aux[2][j] = aux[2][j] - aux[0][j]*ml2;
	}
	// ---------------------------------------------------------------
	
	pivo = aux[1][1];
	ml2 = aux[2][1] / pivo;
	// ---------- zerando o segundo elemento da ultima linha ----------
	for (j=1;j<4;j++){
		aux[2][j] = aux[2][j] - aux[1][j]*ml2;
	}
	// ----------------------------------------------------------------
	
	float z = aux[2][3]/aux[2][2];
	float y = (aux[1][3]-aux[1][2]*z)/aux[1][1];
	float x = (aux[0][3] - aux[0][2]*z - aux[0][1]*y)/aux[0][0];
	
	printf("\n\nPOR GAUSS:\n------------------------------------\nSISTEMA TRATADO:\n");
	imprime_sistema(aux);
	printf("\n\nx = %f\ty = %f\tz = %f\n------------------------------------\n",x,y,z);
	
	destroi_sistema(aux);
}

int main(int argc, char* argv[]){
	
	float** sis;
	sis = cria_sistema(); // cria um sistema
	preenche_sistema(sis); // pede para o usuario preencher o sistema
	imprime_sistema(sis); // imprime para garantir
	cramer(sis); // resolve e imprime por cramer
	gauss(sis); // resolve e imprime por gauss
	destroi_sistema(sis); // destroi o sistema

	system("pause");
	return 0;
}
