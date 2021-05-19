#include <stdio.h>
#include <math.h>

#define MAXITER 500

float f(float x);
float df(float x);
float newton(float x0);

int main(){
	float x0;
	printf("PROGRAMA EN PRECISION SIMPLE:\n\n");
	printf("Introduce el valor de la approximacion inicial: ");
	scanf("%f",&x0);
	printf("El valor aproximado de la solucion en precision simple es %.8G.\n",newton(x0));
	return 0;
}
float f(float x){
	return x*x*x-x-40;
}
float df(float x){
	return 3*x*x-1;
}
float newton(float x0){//x0=aproximacion inicial,cifras=cifras_significativas
	int n=0;
	float xn=x0,error=1.e-7;
	do{
		x0=xn;
		xn=x0-f(x0)/df(x0);
		n++;
	}while(n<MAXITER && fabsf(f(xn)-f(x0))>error);
	return xn;
}
