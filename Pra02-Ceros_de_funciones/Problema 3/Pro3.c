#include <stdio.h>
#include <math.h>
#define error 1.e-16

double f(double x);
double df(double x);
double x(int k,double aprox);

int main(){
	double aprox,ek,ek1,ek2;
	printf("Introduzca una aproximación inical: ");
	scanf("%lf",&aprox);
	int k=2;
	do{
		ek=x(k,aprox);
		ek1=x(k-1,aprox);
		ek2=x(k-2,aprox);
		printf("e_%i/e_%i^3=%.16G\n",k,k-1,fabs(ek-ek1)/pow(fabs(ek1-ek2),3));
		k++;
	}while(fabs(ek-ek1)!=0);
	
	return 0;
}

double f(double x){
	return x*x*x-x-400;
}
double df(double x){
	return 3*x*x-1;
}
double ddf(double x){
	return 6*x;
}
double x(int k,double x0){
	if(k==0)
		return x0;
	int i=0;
	double x=x0;
	do{
		x0=x;
		x=x0-2*f(x0)*df(x0)/(2*df(x0)*df(x0)-f(x0)*ddf(x0));
		i++;
	}while(i<k && fabs(x-x0)>error);
	return x;
}

