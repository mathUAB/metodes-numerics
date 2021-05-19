#include <stdio.h>
#include <math.h>

#define MAXITER 500
#define TOL 1.e-15

typedef struct{
    int n;
    double aprox;
}iteracio;

double f(double x);
double df(double x);
double Cardano(double p,double q);
iteracio biseccion(double a,double b);
iteracio secante(double x0,double x1);
iteracio newton(double x0);
double secante2(double x0,double x1,int iter);
double newton2(double x0,int iter);


int main(){
	iteracio iter;
	printf("PROGRAMA EN PRECISION DOBLE:\n\nAproximacion de las soluciones de la equacion x^3=x+400 mediante 3 metodos.\n\t\t\t   Aproximacion\t   Numero de iteraciones\n");
	printf("Metodo Cardano:\t\t%.16G\n", Cardano(-1,-400));
	iter=biseccion(2,8);
	printf("Metodo biseccion:\t%.16G\t%i\n",iter.aprox,iter.n);
	iter=secante(2,8);
	printf("Metodo secante:\t\t%.16G\t%i\n",iter.aprox,iter.n);
	iter=newton(8);
	printf("Metodo Newton:\t\t%.16G\t%i\n",iter.aprox,iter.n);
	printf("\n\n\n");
	int i=2;
	double aprox=2,ek,ek1,ek2,error=1.e-16;
	do{
		printf("e_%i/e_%i\t",i,i-1);
		ek=secante2(aprox,8,i);
		ek1=secante2(aprox,8,i-1);
		ek2=secante2(aprox,8,i-2);
		//printf("%.16G\t",fabs(ek-ek1)/pow(fabs(ek1-ek2),1.62));
		printf("%.16G\t",fabs(ek-ek1)/pow(fabs(ek1-ek2),(1+sqrt(5))/2));
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
double Cardano(double p,double q){//Valores de x^3+px+q=0
	double A=q*q+4*p*p*p/27;
	double s1=pow((-q+sqrt(A))/2,1./3),s2=pow((-q-sqrt(A))/2,1./3);
	return s1+s2;
}
iteracio biseccion(double a,double b){
	iteracio bis;
	bis.n=0;
	do{
		bis.n++;
		bis.aprox=(a+b)/2;
		if(fabs(f(bis.aprox))<TOL) 
			return bis;
		else if(f(a)*f(bis.aprox)<0) 
			b=bis.aprox;
		else 
			a=bis.aprox;
	}while(1>0);
}

iteracio secante(double x0,double x1){//x0,x1=aproximaciones iniciales
	iteracio sec;
	sec.n=0;
	do{
		sec.aprox=x0-f(x0)*(x1-x0)/(f(x1)-f(x0));//(x0*f(x1)-x1*f(x0))
		sec.n++;
		x0=x1;
		x1=sec.aprox;
	}while(sec.n<MAXITER && fabs(f(sec.aprox))>TOL);
	return sec;
}

iteracio newton(double x0){//x0=aproximacion inicial
	iteracio new;
	new.n=0;
	new.aprox=x0;
	do{
		x0=new.aprox;
		new.aprox=x0-f(x0)/df(x0);
		new.n++;
	}while(new.n<MAXITER && fabs(f(new.aprox))>TOL);
	return new;
}
/*double biseccio2(double a, double b, int iter){
	double aprox=(a+b)/2
	for(int i=0;i<iter;i++){
		
	}
}*/
double secante2(double x0,double x1,int iter){
	double c;
	for(int i=0;i<iter;i++){
		c=x1;
		x1=x0-f(x0)*(x1-x0)/(f(x1)-f(x0));
		x0=c;
	}
	return x1;
}
double newton2(double x0,int iter){
	for(int i=0;i<iter;i++)
		x0=x0-f(x0)/df(x0);
	return x0;
}
