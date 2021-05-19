#include <stdio.h>
#include <math.h>

double f(double x);
double g(double x);
double raiz(int k,double x);

int main(){
	printf("COMPORVACIÓN APARTADO b)\n\nUsando el polinomio f(x)=(7*x*x*x+56*x*x+112*x+64)/(x*x*x+24*x*x+80*x+64) y x=1 obtenemos:\n");
	for(int k=0;k<7;k++)
		printf("Para k=%i: sqrt(2)=%.16G\n",k,raiz(k,1));
	return 0;
}

double f(double x){
	return (7*x*x*x+56*x*x+112*x+64)/(x*x*x+24*x*x+80*x+64);
}
double g(double x){
	return (1+x)/(f(x)*f(x))-1;
}
double raiz(int k,double x){//x=a0 es la aproximacion inicial.
	double prod=1;
	for(int i=0;i<=k;i++){
		prod*=f(x);
		x=g(x);
	}
	return prod*sqrt(1+x);
}
