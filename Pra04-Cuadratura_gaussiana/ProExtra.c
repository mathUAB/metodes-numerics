#include <stdio.h>
#include <math.h>

#define TOL 1.e-7

double omega(double metodo(int, double), double x);
double legendre(int n, double x);
double derivative(int n, double f(int, double), double x);
double newton(double n, double f(int, double), double x0, int iter);
void zeros(int n, double f(int, double), double v[]);
void coeficientes(int n, double f(int, double), double v[], double A[]);
double cuadratura(int n, double metodo(int, double), double a, double b, double f(double));
double elipse_derivada(double x);

int main() {
    int N;
    printf("Introducir el numero maximo de nodos: ");
    scanf("%i",&N);
    printf("Longitud de la elipse:\n\n");
    for (int n = 1; n <= N; n++)
        printf("\t\tn = %i: %.16G\n", n, cuadratura(n, legendre, -1, 1, elipse_derivada));
    return 0;    
}

double omega(double metodo(int, double), double x){
    if (metodo == legendre)
        return 1;
    else
        return 1 / sqrt(1 - x * x);
}

double legendre(int n, double x) {
    if (n == 0)
        return 1;
    double p0 = 1, p1 = x, aux;
    for (int i = 2; i <= n; i++) {
        aux = ((2 * i - 1) * x * p1 - (i - 1) * p0) / i;
        p0 = p1;
        p1 = aux;
    }
    return p1;
}

double derivative(int n, double f(int, double), double x) {
    return n * (- x * f(n, x) + f(n - 1, x)) / (1 - x * x);
}

double newton(double n, double f(int, double), double x0, int iter) {
    for (int i = 0; i < iter; i++){
        x0 = x0 - f(n, x0) / derivative(n, f, x0);
    }
	return x0;
}

void zeros(int n, double f(int, double), double v[]) { //v tiene longitud n y en la salida guarda los zeros de f.
    double h = 2. / (n * n), a = -1, b;
    for (int numRoot = 0; numRoot < n; numRoot++, a = b) { // Calculate an initial aproximation of the roots of f and savi it in v[].
        b = a + h;
        while (f(n, a) * f(n, b) > 0) {
            a = b;
            b += h;
        }
        v[numRoot] = (a + b) / 2;
    }
    for (int numRoot = 0; numRoot < n; numRoot++) { // Computing the roots of f.
        v[numRoot] = newton(n, f, v[numRoot], 7); //Newton con 7 iteraciones.
        if (fabs(v[numRoot]) < TOL)
            v[numRoot] = 0;
    }
}

void coeficientes(int n, double metodo(int, double), double v[], double A[]) {
    if (metodo == legendre){
        for (int i = 0; i < n; i++)
            A[i] = 2 / ((1 - v[i] * v[i]) * pow(derivative(n, legendre, v[i]), 2));
    }else{
        for (int i = 0; i < n; i++)
            A[i] = M_PI / n;
    }    
}

double cuadratura(int n, double metodo(int, double), double a, double b, double f(double)) {
    double v[n], A[n], sum = 0;
    zeros(n, metodo, v);
    coeficientes(n, metodo, v, A);
    for (int i = 0; i < n; i ++)
        sum += A[i] * (b - a) / 2 * f(((b - a) * v[i] + b + a) / 2) / omega(metodo, v[i]); //Caso particular a = -1, b = 1: sum += A[i] * f(v[i]) / omega(metodo, v[i]);
    return sum;
}

double elipse_derivada(double x) {
    double dy = - x / (8 * sqrt(1 - x * x / 4));
    return sqrt(1 + dy * dy);
}
