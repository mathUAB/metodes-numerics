#include <stdio.h>
#include <math.h>

int main(){
	float a;
	double b;
	a=powf(20+sqrtf(32397)/9,1./3)+powf(20-sqrtf(32397)/9,1./3);
	printf("El valor de la solucion en precision simple es %.8G.\n",a);

	b=pow(20+sqrt(32397)/9,1./3)+pow(20-sqrt(32397)/9,1./3);
	printf("El valor de la solucion en precision doble es %.16G.\n",b);
	return 0;
}
