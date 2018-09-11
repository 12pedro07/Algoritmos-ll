#include <stdio.h>
#include <stdlib.h>

void preencheBuffer(int* v, int n){
	int i;
	for (i=0;i<n;i++){
		printf("V[%d] = ",i);
		scanf("%d",v+i);
	}
}

int procuraBuffer(int* v, int n, int p){
	int i;
	for (i=0;i<n;i++){
		if (p==v[i])
			return i;
	}
	return -1;
}

int main(int argc, char* argv[]){
	int *v = malloc(sizeof(int)*10);
	preencheBuffer(v,10);
	
	int pos = procuraBuffer(v,10,123); /* busca pelo numero 123 */
	
	if (pos == -1){
		printf("nao encontrado");	
	} else {
		printf("encontrado na pos. %d \n", pos);
	}
	
	free(v);
	system("pause");
	return 0;
}
