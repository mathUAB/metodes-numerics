#include <stdio.h>
#include <math.h>

#define MAXITER 500

double f(double x);
double df(double x);
double newton(double x0);

int main(){
	double x0;
	printf("PROGRAMA EN PRECISION SIMPLE:\n\n");
	printf("Introduce el valor de la approximacion inicial: ");
	scanf("%lf",&x0);
	printf("El valor aproximado de la solucion en precision simple es %.16G.\n",newton(x0));
	return 0;
}
double f(double x){
	return x*x*x-x-40;
}
double df(double x){
	return 3*x*x-1;
}
double newton(double x0){//x0=aproximacion inicial
	int n=0;
	double xn=x0,error=1.e-15;
	do{
		x0=xn;
		xn=x0-f(x0)/df(x0);
		n++;
	}while(n<MAXITER && fabs(f(xn)-f(x0))>error);
	return xn;
}
