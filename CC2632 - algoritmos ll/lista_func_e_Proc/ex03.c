#include <stdio.h>
#include <stdlib.h>

/* antes:
void efetuaSoma ( int a , int b ){
int c = a + b ;
return c; 
}

int main ( int argc , char * argv [] ) {
int a ;
int b ;
scanf( "\%d" , a ) ;
scanf( "\%d" , b ) ;

printf( "\%d" , efetuaSoma ( a , b ) ) ;
}
*/

// depois:
int efetuaSoma ( int a , int b ){ //funcao tem que ser do tipo int
int c = a + b ;
return c; 
}

int main ( int argc , char * argv [] ) {
int a;
int b;
scanf("%d",&a); // faltou o & e tirar a \.
scanf("%d",&b); // faltou o & e tirar a \.

printf( "%d" , efetuaSoma(a,b)); // faltou tirar a \.

system("pause"); // faltou a linha inteira
return 0; // faltou a linha inteira
}
