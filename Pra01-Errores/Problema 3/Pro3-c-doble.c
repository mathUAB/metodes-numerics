#include <stdio.h>
#include <math.h>

double varianza_muestral_formula3(int N,double vector[]);
double varianza_muestral_formula4(int N,double vector[]);
int main(){
	int N=200;
	double vector1[N],vector2[N];
	for(int i=0;i<N;i++){
		vector1[i]=1000000+i;
		vector2[i]=1+i*1.e-6;
	}
	printf("PROGRAMA EN PRECISION DOBLE:\n\n");
	printf("Vector x1:\n(1000000,1000001,1000002,...,1000198,1000199)\n");
	printf("La varianza muestral utilizando la formula 3 es: %.16G\n", varianza_muestral_formula3(N,vector1));
	printf("La varianza muestral utilizando la formula 4 es: %.16G\n", varianza_muestral_formula4(N,vector1));
	printf("\nVector x2:\n(1,1.000001,1.000002,1.000003,...,1.000198,1.000199)\n");
	printf("La varianza muestral utilizando la formula 3 es: %.16G\n", varianza_muestral_formula3(N,vector2));
	printf("La varianza muestral utilizando la formula 4 es: %.16G\n", varianza_muestral_formula4(N,vector2));
	return 0;
}

double varianza_muestral_formula3(int N,double vector[]){
	double x=0,varianza=0;
	for(int i=0;i<N;i++)
		x+=vector[i];
	x=x/N;
	for(int i=0;i<N;i++)
		varianza+=(vector[i]-x)*(vector[i]-x);
	varianza=varianza/(N-1);
	return varianza;
}

double varianza_muestral_formula4(int N,double vector[]){
	double x=0,y=0,varianza;
	for(int i=0;i<N;i++)
		x+=vector[i];
	x=x*x/N;
	for(int i=0;i<N;i++)
		y+=vector[i]*vector[i];
	varianza=(y-x)/(N-1);
	return varianza;
}
