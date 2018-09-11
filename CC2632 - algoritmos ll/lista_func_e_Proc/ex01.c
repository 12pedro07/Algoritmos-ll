#include <stdio.h>
#include <stdlib.h>

void niver(int* dia, int* mes, int* ano){
	printf("digite o seu aniversario (dd mm aa): ");
	scanf("%d %d %d", dia, mes, ano);
}

int main(int argc, char *argv[]) {
	int dia=0, mes=0, ano=0;
	niver(&dia,&mes,&ano);
	printf("%d/%d/%d\n",dia,mes,ano);
	system("pause");
	return 0;	
}
