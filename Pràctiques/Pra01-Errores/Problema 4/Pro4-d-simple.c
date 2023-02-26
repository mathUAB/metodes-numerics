#include <stdio.h>
#include <math.h>

float fraccio(int k);
float suma_arcsinus(int N);
int main(){
	int N;
	printf("PROGRAMA EN PRECISION SIMPLE:\n\n");
	printf("Numero de terminos que se quiere sumar: ");
	scanf("%i",&N);
	
	printf("La suma utilizando la formula propuesta con %i terminos es %.8G.\n",N,suma_arcsinus(N));
	return 0;
}

float fraccio(int k){
	float product=1;
	for(int i=1;i<=k;i++)
		product*=(2*i-1)*1./(2*i);
	return product;
}

float suma_arcsinus(int N){
	float sum=0;
	for(int k=N;k>=1;k--)
		sum+=fraccio(k)/(2*k+1)/powf(2,2*k+1);
	sum+=1./2;
	return sum*sum*6;
}
