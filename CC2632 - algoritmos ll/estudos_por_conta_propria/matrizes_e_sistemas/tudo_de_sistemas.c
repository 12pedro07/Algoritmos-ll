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

void imprime_sistema(float** sistema){
	int i;
	puts("");
	for (i=0;i<3;i++){
		printf("%.2fx + %.2fy + %.2fz = %.2f", sistema[i][0],sistema[i][1],sistema[i][2],sistema[i][3]);
		printf("\n");
	}
}

void preenche_sistema(float** sistema){
	int i;
	for (i=0;i<3;i++){
		printf("x = ");
		scanf("%f",&sistema[i][0]);
		printf("y = ");
		scanf("%f",&sistema[i][1]);
		printf("z = ");
		scanf("%f",&sistema[i][2]);
		printf("resultado = ");
		scanf("%f",&sistema[i][3]);
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
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			if (j==0)
				aux[i][j] = sistema[i][3];
			else
				aux[i][j] = sistema[i][j];
		}
	}
	float dx = determinante(aux);
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			if (j==1)
				aux[i][j] = sistema[i][3];
			else
				aux[i][j] = sistema[i][j];
		}
	}
	float dy = determinante(aux);
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			if (j==2)
				aux[i][j] = sistema[i][3];
			else
				aux[i][j] = sistema[i][j];
		}
	}
	float dz = determinante(aux);
	float x = dx/d;
	float y = dy/d;
	float z = dz/d;
	printf("\nPOR CRAMER:\n------------------------------------\nx = %f\ty = %f\tz = %f\n------------------------------------\n",x,y,z);
}

int main(int argc, char* argv[]){
	
	float** sis;
	sis = cria_sistema();
	preenche_sistema(sis);
	imprime_sistema(sis);
	cramer(sis);
	destroi_sistema(sis);
	
	system("pause");
	return 0;
}
