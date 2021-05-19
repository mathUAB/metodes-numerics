#include <stdio.h>
#include <math.h>

double f(double x);
double trapecios(int N,double a,double b);

int main(){
    double a=1,b=5;
    printf("Integral de e^x/x entre %.16G i %.16G calculada mediante el metodo de los trapecios partiendo el intervalo en n partes iguales:\n\n",a,b);
    for(int n=4;n<=64;n*=2)
        printf("n=%i: %.16G\n",n,trapecios(n,a,b));
    return 0;
}

double f(double x){
    return exp(x)/x;
}

double trapecios(int N,double a,double b){
    double h=(b-a)/N,integral=0;
    for(int i=1;i<N;i++)
        integral+=f(a+h*i);
    integral+=(f(a)+f(b))/2;
    return h*integral;   
}
