#include <stdio.h>
#include <math.h>
#include <time.h>
#define e 2.71828182845904523536

double aproximacio(int xifres_denominador, int nombres[]);

int main(){
	int nombres[2]={0,e};
	double aprox;
	clock_t begin=clock();
	for(int i=1;i<9;i++){
		aprox=aproximacio(i,nombres);
		printf("L'aproximacio a e en %i xifres al denominador es %i/%i i l'error comes es de %lg.\n",i,nombres[0],nombres[1],fabs(aprox-e));
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time spent: %lf\n",time_spent);
	return 0;
}

double aproximacio(int xifres_denominador, int nombres[]){
	double error=fabs(nombres[0]/nombres[1]-e);
	for(int i=1;i<pow(10,xifres_denominador);i++){
		for(int j=(e-error)*i;j<(e+error)*i;j++){
			if(fabs(j*1./i-e)<error){
				nombres[0]=j;
				nombres[1]=i;
				error=fabs(nombres[0]*1./nombres[1]-e);
			}	
		}
	}
	return nombres[0]*1./nombres[1];
}
