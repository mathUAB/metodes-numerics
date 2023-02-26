#include <stdio.h>
#include <math.h>

float varianza_muestral_formula3(int N,float vector[]);
float varianza_muestral_formula4(int N,float vector[]);
int main(){
	int N;
	printf("PROGRAMA EN PRECISION SIMPLE:\n\n");
	printf("Introduce el numero de muestras: ");
	scanf("%i",&N);
	float vector[N];
	for(int i=0;i<N;i++){
		printf("Muestra numero %i:",i+1);
		scanf("%f",&vector[i]);
	}

	printf("La varianza muestral utilizando la formula 3 es: %.8G\n", varianza_muestral_formula3(N,vector));
	printf("La varianza muestral utilizando la formula 4 es: %.8G\n", varianza_muestral_formula4(N,vector));
	return 0;
}

float varianza_muestral_formula3(int N,float vector[]){
	float x=0,varianza=0;
	for(int i=0;i<N;i++)
		x+=vector[i];
	x=x/N;
	for(int i=0;i<N;i++)
		varianza+=(vector[i]-x)*(vector[i]-x);
	varianza=varianza/(N-1);
	return varianza;
}

float varianza_muestral_formula4(int N,float vector[]){
	float x=0,y=0,varianza;
	for(int i=0;i<N;i++)
		x+=vector[i];
	x=x*x/N;
	for(int i=0;i<N;i++)
		y+=vector[i]*vector[i];
	varianza=(y-x)/(N-1);
	return varianza;
}
