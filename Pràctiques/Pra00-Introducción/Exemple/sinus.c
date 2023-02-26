#include <stdio.h>
#include <math.h>

int main(void){
	double dx;
	int i;
	dx=2*M_PI/100;
	for (i=0; i<=100; i++)
	printf("%.16G %.16G\n", i*dx, sin(i*dx));
	return 0;
}
