#include <stdio.h>
#include <math.h>

double f(double x);
double F(double x);
double simpson(int N,double a,double b);

int main(){
    double a=1,b=2;
    int N=8;
    printf("Integral de log(x) entre %.16G i %.16G calculada mediante el metodo de Simpson partiendo el intervalo en 8 partes iguales:\n\n",a,b);
    printf("Simpson:\t%.16G\n",simpson(N,a,b));
    printf("Valor exacto:\t%.16G\n",F(2)-F(1));
    return 0;
}

double f(double x){
    return log(x);
}
double F(double x){
    return x*log(x)-x;
}

double simpson(int N,double a,double b){
    double h=(b-a)/N,integral=0;
    for(int i=1;i<N/2;i++)
        integral+=2*f(a+h*2*i)+4*f(a+h*(2*i-1));
    integral+=4*f(a+h*(N-1))+f(a)+f(b);
    return h*integral/3;  
}