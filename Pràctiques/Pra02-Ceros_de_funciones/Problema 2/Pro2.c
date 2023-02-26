#include <stdio.h>
#include <math.h>
#define error 1.e-16

double f(double x);
double df(double x);
double x(int k,double aprox);

int main(){
	int i=0,ordres=5;
	double aprox,ek,ek1,ek2;
	printf("Introduzca una aproximación inical: ");
	scanf("%lf",&aprox);
	printf("\n");
	do{
		printf("x_%i=%.16G\n",i,x(i,aprox));
		i++;
	}while(fabs(x(i,aprox)-x(i-1,aprox))>error);
	printf("\n");
	for(int j=1;j<ordres;j++)
		printf("\t\t\t%i",j);
	printf("\n");
	i=2;
	do{
		printf("e_%i/e_%i^j\t",i,i-1);
		for(int j=1;j<ordres;j++){
			ek=x(i,aprox);
			ek1=x(i-1,aprox);
			ek2=x(i-2,aprox);
			printf("%.16G\t",fabs(ek-ek1)/pow(fabs(ek1-ek2),j));
		}
		printf("\n");
		i++;
	}while(fabs(ek-ek1)>error);
	printf("\n\t\t\t1.8\t\t\t1.9\n");
	i=2;
	do{
		printf("e_%i/e_%i^j\t",i,i-1);
		for(int j=8;j<10;j++){
			ek=x(i,aprox);
			ek1=x(i-1,aprox);
			ek2=x(i-2,aprox);
			printf("%.16G\t",fabs(ek-ek1)/pow(fabs(ek1-ek2),j*0.1+1));
		}
		printf("\n");
		i++;
	}while(fabs(ek-ek1)>error);
	return 0;
}

double f(double x){
	return x*x*x-x-400;
}
double df(double x){
	return 3*x*x-1;
}
double x(int k,double x0){
	if(k==0)
		return x0;
	int i=0;
	double b0,b,x=x0;
	b0=1./df(x0);
	do{
		x0=x;
		x=x0-b0*f(x0);
		b=b0*(2-df(x)*b0);
		b0=b;
		i++;
	}while(i<k && fabs(x-x0)>error);
	return x;
}

