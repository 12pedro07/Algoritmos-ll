#include <stdio.h>
#include <stdlib.h>

void proc ( int* a , int* b ){
	int c = *a ;
	*a = *b ;
	*b = c ;
}

int main ( int argc , char *argv[] ) {
	int a = 7 ;
	int b = 12;

	proc (&a , &b);
	a = 2*a;
	printf("O valor de a = %d\n" , a);
	printf("O valor de b = %d\n" , b );
}

