#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int a,b;
	int *ptr;
	a=5;
	b=3;
	ptr=&a;
	*ptr=10;
	ptr=&b;
	*ptr=*ptr+4;
	printf("%d\n",&a);
	printf("%d\n",&b);
	printf("%d\n",a);
	system("pause");
	return 0;	
}
