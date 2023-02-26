#include <stdio.h>
#include <math.h>
#define error 1.e-16

double f(double x);
double df(double x);
double ddf(double x);
double p(int k,double a0,double b0,double s0);

int main(){
	double a0=1,b0=1/sqrt(2),s0=0.5;
	double ek,ek1,ek2;
	int n;
	printf("Introduce el numero de iterciones: ");
	scanf("%i",&n);
	for(int i=0;i<=n;i++)
		printf("p_%i=%.16G\n",i,p(i,a0,b0,s0));
	printf("\n");
	for(int j=1;j<=3;j++)
		printf("\t\t\t%i",j);
	printf("\n");
	for(int i=2;i<=n;i++){
		ek=p(i,a0,b0,s0);
		ek1=p(i-1,a0,b0,s0);
		ek2=p(i-2,a0,b0,s0);
		printf("e_%i/e_%i^j\t%.16G\t%.16G\t%.16G\n",i,i-1,fabs(ek-ek1)/fabs(ek1-ek2),fabs(ek-ek1)/pow(fabs(ek1-ek2),2),fabs(ek-ek1)/pow(fabs(ek1-ek2),3));
	}
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

double p(int k,double a0,double b,double s){
	if(k==0)
		return 2*a0*a0/s;
	double a,c,p,p0=2*a0*a0/s;
	int i=0;
	do{
		p=p0;
		a=(a0+b)/2;
		b=sqrt(a0*b);		
		c=a*a-b*b;
		s=s-pow(2,i+1)*c;
		p=2*a*a/s;
		a0=a;
		i++;
	}while(i<k && fabs(p-p0)>error);
	return p;
}

