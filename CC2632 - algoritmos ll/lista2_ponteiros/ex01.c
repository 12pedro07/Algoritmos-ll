#include <stdio.h>
#include <stdlib.h>

void preenchevetor(int *v, int n){
	int i;
	for(i=0;i<n;i++){
		printf("insira o elemento %d: ",i);
		scanf("%d",&v[i]);
	}
}

int main(int argc, char *argv[]) {
	int n, i;
	int *v;
	printf("entre com o tamanho do vetor: ");
	scanf("%d",&n);
	v=malloc( sizeof(int)*n );
	preenchevetor(v,n);
	for(i=0;i<n;i++){
		printf("v[%d] = %d\n", i, v[i]);
	}
	free(v);
	system("pause");
	return 0;	
}
