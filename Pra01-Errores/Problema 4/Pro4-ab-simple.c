#include <stdio.h>
#include <math.h>

float suma_creixent(int N);
float suma_decreixent(int N);

int main(){
	int N;
	printf("PROGRAMA EN PRECISION SIMPLE:\n\n");
	printf("Numero de terminos que se quiere sumar: ");
	scanf("%i",&N);
	
	printf("La suma de manera creciente utilizando %i terminos es %.8G.\n",N,suma_creixent(N));
	printf("La suma de manera decreciente utilizando %i terminos es %.8G.\n",N,suma_decreixent(N));
	return 0;
}

float suma_creixent(int N){
	float sum=0;
	for(int k=1;k<=N;k++)
		sum+=(1./k)*(1./k);
	return sum;
}

float suma_decreixent(int N){
	float sum=0;
	for(int k=N;k>=1;k--)
		sum+=(1./k)*(1./k);
	return sum;
}

