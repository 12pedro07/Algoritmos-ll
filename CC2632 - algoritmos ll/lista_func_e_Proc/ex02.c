#include <stdlib.h>
#include <stdio.h>

int dist (int Vx,int Vy,int d){
	
	/*
	Sx = Vx * t
	Sy = Vy * t
	Sx-Sy = Vx*t - Vy*t -> Sx-Sy = d 
	d = t*(Vx-Vy)
	t = d/(Vx-Vy) -> abs() para nao dar negativo!
	*/
	
	int t = (abs(d/(Vx-Vy))); // tempo em horas
	return (t*60); // retorno convertendo para minutos
}

int main(int argc, char* argv[]){
	int vx,vy,d;
	printf("insira vx, vy e d consecutivamente: ");
	scanf("%d %d %d",&vx, &vy, &d);
	printf("tempo necessario = %d [min]\n",dist(vx,vy,d));
	system("pause");
	return 0;
}

