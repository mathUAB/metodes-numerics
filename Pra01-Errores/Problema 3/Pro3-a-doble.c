#include <stdio.h>
#include <math.h>

double varianza_muestral_formula3(int N,double vector[]);
double varianza_muestral_formula4(int N,double vector[]);
int main(){
	int N;
	printf("PROGRAMA EN PRECISION DOBLE:\n\n");
	printf("Introduce el numero de muestras: ");
	scanf("%i",&N);
	double vector[N];
	for(int i=0;i<N;i++){
		printf("Muestra numero %i:",i+1);
		scanf("%lf",&vector[i]);
	}

	printf("La varianza muestral utilizando la formula 3 es: %.16G\n", varianza_muestral_formula3(N,vector));
	printf("La varianza muestral utilizando la formula 4 es: %.16G\n", varianza_muestral_formula4(N,vector));
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
