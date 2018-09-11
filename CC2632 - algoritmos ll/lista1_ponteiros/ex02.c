#include <stdio.h>
#include <stdlib.h>

/* antes:

int main(int argc, char *argv[]) {
	int x;
	int *ptr;
	*ptr=&x;
	scanf("%d",&x);
	scanf("%d",&ptr);
	ptr=10;
	printf("%d",x);
	printf("%d",ptr);
	return 0;	
}

*/

// depois:

int main(int argc, char *argv[]) {
	int x;
	int *ptr;
	ptr=&x; // Para o ponteiro apontar para x, nao eh necessario o asterisco
	scanf("%d",&x);
	scanf("%d",ptr); // O endereco deve ser o guardado por ptr, nao o do proprio ponteiro
	//*ptr=10; // Para escrever na variavel apontada por ptr eh necessario o asterisco
	printf("%d\n",x); // Um \n nao faz mal a ninguem
	printf("%d\n",*ptr); // A linha funciona, mas imprime o endereco de x, para imprimir o valor de x deve-se colocar o asterisco
	system("pause"); // Linha estava faltando
	return 0;	
}
