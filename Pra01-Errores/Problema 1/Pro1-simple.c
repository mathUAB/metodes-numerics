#include <stdio.h>
#include <math.h>

float f(float x);
float g(float x);

int main(){
	float x;
	printf("PROGRAMA EN PRECISION SIMPLE:\n\n");
	printf("Valor de x: ");
	scanf("%f",&x);
	
	printf("Valor de la funcion utilizando 1-cos(x): f(%.8G)=%.8G\n", x, f(x));
	printf("Valor de la funcion utilizando 2*sin(x/2)^2: g(%.8G)=%.8G\n", x, g(x));
	return 0;
}

float f(float x){
	if(x!=0) //no nos preocupamos de posibles errores al escribir x!=0.
		return (1-cosf(x))/(x*x);
	else
		return 1./2;
}

float g(float x){
	if(x!=0) //no nos preocupamos de posibles errores al escribir x!=0.
		return 2*sinf(x/2)*sinf(x/2)/(x*x);
	else
		return 1./2;
}
