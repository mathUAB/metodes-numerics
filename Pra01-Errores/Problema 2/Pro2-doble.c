#include <stdio.h>
#include <math.h>

typedef struct{
    double x;
    double y;
}solucions;

solucions resoldre_metode1(double a, double b, double c);
solucions resoldre_metode2(double a, double b, double c);

int main(){
	double a,b,c;
	solucions metode1,metode2;
	printf("PROGRAMA EN PRECISION DOBLE:\n\n");
	
	printf("Valores de a,b,c del polinomio ax^2+bx+c: ");
	scanf("%lf%lf%lf",&a,&b,&c);
	if(b*b-4*a*c<0 || a<=0){
		printf("No se cumplen las condiciones del problema (a>0, b*b>4ac).\n");
		return 1;
	}
	metode1=resoldre_metode1(a,b,c);
	metode2=resoldre_metode2(a,b,c);
	printf("Metodo 1 (algoritmo clasico):\t solucion1: %.16G\n\t\t\t\t solucion2: %.16G\n", metode1.x, metode1.y);
	printf("Metodo 2 (algoritmo propuesto):\t solucion1: %.16G\n\t\t\t\t solucion2: %.16G\n", metode2.x, metode2.y);
	return 0;
}

solucions resoldre_metode1(double a, double b, double c){
	solucions solucio;
	solucio.x=(-b+sqrt(b*b-4*a*c))/(2*a);
	solucio.y=(-b-sqrt(b*b-4*a*c))/(2*a);
	return solucio;
}

solucions resoldre_metode2(double a, double b, double c){
	solucions solucio;
	if(b>0){
		solucio.x=(2*c)/(-b-sqrt(b*b-4*a*c));
		solucio.y=(-b-sqrt(b*b-4*a*c))/(2*a);
	}else{
		solucio.x=(-b+sqrt(b*b-4*a*c))/(2*a);
		solucio.y=(2*c)/(-b+sqrt(b*b-4*a*c));
	}
	return solucio;
}
