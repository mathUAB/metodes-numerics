#include <stdio.h>
#include <math.h>

double f(double x);
double trapecios(int N,double a,double b);
double simpson(int N,double a,double b);

int main(){
    double a=0,b=1;
    int N=4;
    printf("Integral de 1/(1+x^2) entre %.16G i %.16G:\n\n",a,b);
    printf("Trapezios con %i intervalos iguales:\t%.16G\n",N,trapecios(N,a,b));
    printf("Simpson con %i intervalos iguales:\t%.16G\n",N,simpson(N,a,b));
    printf("Valor exacto:\t\t\t\t%.16G\n",atan(1)-atan(0));
    return 0;
}

double f(double x){
    return 1/(1+x*x);
}

double trapecios(int N,double a,double b){
    double h=(b-a)/N,integral=0;
    for(int i=1;i<N;i++)
        integral+=f(a+h*i);
    integral+=(f(a)+f(b))/2;
    return h*integral;   
}

double simpson(int N,double a,double b){
    double h=(b-a)/N,integral=0;
    for(int i=1;i<N/2;i++)
        integral+=2*f(a+h*2*i)+4*f(a+h*(2*i-1));
    integral+=4*f(a+h*(N-1))+f(a)+f(b);
    return h*integral/3;  
}