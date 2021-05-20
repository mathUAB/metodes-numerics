#include <stdio.h>
#include <math.h>

#define TOL 1.e-7

double legendre(int n, double x);
double legendre_derivative(int n, double x);
double chebyshev(int n, double x);
double chebyshev_derivative(int n, double x);
void zeros(int n, double f(int, double), double df(int, double), double v[]);
double newton(double n, double f(int, double), double df(int, double), double x0, int iter);
void imprimeix_vector(int dim, double v[]);
double trapecios(int N, double a, double b);

int main() {
    int n, m;
    printf("Introduce 1 (Legendre) o 2 (Chebyshev) i el numero de raices: ");
    scanf("%i%i",&m,&n);
    double v[n];
    if (m == 1)
        zeros(n, legendre, legendre_derivative, v);
    else
        zeros(n, chebyshev, chebyshev_derivative, v);
    imprimeix_vector(n, v);
    return 0;    
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

double legendre_derivative(int n, double x) {
    if (n == 0)
        return 0;
    return n * (- x * legendre(n, x) + legendre(n - 1, x)) / (1 - x * x);
}

double chebyshev(int n, double x) {
    return cos(n * acos(x));
}

double chebyshev_derivative(int n, double x) {
    return n * sin(n * acos(x)) / sqrt(1 - x * x);
    // return n * (- x * chebyshev(n, x) + chebyshev(n - 1, x)) / (1 - x * x);
}

double newton(double n, double f(int, double), double df(int, double), double x0, int iter) {
    for (int i = 0; i < iter; i++){
        x0 = x0 - f(n, x0) / df(n, x0);
    }
	return x0;
}

void zeros(int n, double f(int, double), double df(int, double), double v[]) { //v tiene longitud n y en la salida guarda los zeros de f.
    double h = 2. / (n * n), a = -1, b;
    for (int numRoot = 0; numRoot < n; numRoot++, a = b) { // Calculate an initial aproximation of the roots of f
        b = a + h;
        while (f(n, a) * f(n, b) > 0) {
            a = b;
            b += h;
        }
        v[numRoot] = (a + b) / 2;
    }
    for (int numRoot = 0; numRoot < n; numRoot++) { // Computing the roots of f
        v[numRoot] = newton(n, f, df, v[numRoot], 7); //Newton con 7 iteraciones.
        if (fabs(v[numRoot]) < TOL)
            v[numRoot] = 0;
    }
}

void imprimeix_vector(int dim, double v[]) {
    for (int i = 0; i < dim; i++)
        printf("v[%i] = %.16G\n", i, v[i]);
}

/* double f(double x) {
    return 1 / (1 + x * x);
}

double g(double x) {
    return pow(x, 8) - 2 * pow(x, 6) + 3 * pow(x, 4) - x * x + 5;
}

double h(double x) {
    return fabs(x);
}

double trapecios(int N, double a, double b) {
    double h = (b - a) / N, integral = 0;
    for(int i = 1; i < N; i++)
        integral += f(a + h * i);
    integral += (f(a) + f(b)) / 2;
    return h * integral;   
} */