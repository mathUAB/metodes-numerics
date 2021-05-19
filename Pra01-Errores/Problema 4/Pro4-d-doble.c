#include <stdio.h>
#include <math.h>

double fraccio(int k);
double suma_arcsinus(int N);
int main(){
	int N;
	printf("PROGRAMA EN PRECISION DOBLE:\n\n");
	printf("Numero de terminos que se quiere sumar: ");
	scanf("%i",&N);
	
	printf("La suma utilizando la formula propuesta con %i terminos es %.16G.\n",N,suma_arcsinus(N));
	return 0;
}

double fraccio(int k){
	double product=1;
	for(int i=1;i<=k;i++)
		product*=(2*i-1)*1./(2*i);
	return product;
}

double suma_arcsinus(int N){
	double sum=0;
	for(int k=N;k>=1;k--)
		sum+=fraccio(k)/(2*k+1)/pow(2,2*k+1);
	sum+=1./2;
	return sum*sum*6;
}
