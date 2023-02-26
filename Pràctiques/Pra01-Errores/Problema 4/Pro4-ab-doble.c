#include <stdio.h>
#include <math.h>

double suma_creixent(int N);
double suma_decreixent(int N);

int main(){
	int N;
	printf("PROGRAMA EN PRECISION DOBLE:\n\n");
	printf("Numero de terminos que se quiere sumar: ");
	scanf("%i",&N);
	
	printf("La suma de manera creciente utilizando %i terminos es %.16G.\n",N,suma_creixent(N));
	printf("La suma de manera decreciente utilizando %i terminos es %.16G.\n",N,suma_decreixent(N));
	return 0;
}

double suma_creixent(int N){
	double sum=0;
	for(int k=1;k<=N;k++)
		sum+=(1./k)*(1./k);
	return sum;
}

double suma_decreixent(int N){
	double sum=0;
	for(int k=N;k>=1;k--)
		sum+=(1./k)*(1./k);
	return sum;
}

