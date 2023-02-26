#include <stdio.h>
#include <math.h>

double f(double x);
double g(double x);

int main(){
	double x;
	printf("PROGRAMA EN PRECISION DOBLE:\n\n");
	printf("Valor de x: ");
	scanf("%lf",&x);
	
	printf("Valor de la funcion utilizando 1-cos(x): f(%.16G)=%.16G\n", x, f(x));
	printf("Valor de la funcion utilizando 2*sin(x/2)^2: g(%.16G)=%.16G\n", x, g(x));
	return 0;
}

double f(double x){
	if(x!=0) //no nos preocupamos de posibles errores al escribir x!=0.
		return (1-cos(x))/(x*x);
	else
		return 1./2;
}

double g(double x){
	if(x!=0) //no nos preocupamos de posibles errores al escribir x!=0.
		return 2*sin(x/2)*sin(x/2)/(x*x);
	else
		return 1./2;
}
