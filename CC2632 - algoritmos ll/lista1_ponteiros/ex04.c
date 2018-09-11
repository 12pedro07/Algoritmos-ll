#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int x;		//declara x inteiro
	int* ptr;	//declara ptr ponteiro para inteiros 
	ptr=&x;		//ptr aponta para o endereco de x
	printf("entre com o valor de x: ");
	scanf("%d",ptr); //associa um valor a x atraves do ponteiro
	printf("endereco de x: %d	\n", ptr );
	printf("valor de x: %d		\n", *ptr);
	system("pause");
	return 0;	
}
