#include <stdio.h>
#include <math.h>

void J_positivo(int n, double v[][n+1]);
void J_negativo(int n, double v[][n+1]);
void J_simetrico(int n, double v[][n+1]);
double w(int j, double v[], double x);
double p(int n, double v[][n+1], double x);
void diferencias_divididas(int n, double v[][n+1]);

int main(){
	/*APARTADO a)*/
	printf("APARTADO a):");
	for(int i=1;i<=5;i+=2){
	  double v[i+2][i+1];
	  J_positivo(i,v);
	  diferencias_divididas(i,v);
	  printf("\n\tGrado %i: x=%.16G",i,p(i,v,0));
	}
	/*APARTADO b)*/
	printf("\nAPARTADO b):");
	for(int i=1;i<=5;i+=2){
    double v[i+2][i+1];
	    J_negativo(i,v);
	    diferencias_divididas(i,v);
	    printf("\n\tGrado %i: x=%.16G",i,p(i,v,0));
	  }
	/*APARTADO c)*/
	printf("\nAPARTADO c):");
	for(int i=1;i<=5;i+=2){
	  double v[i+2][i+1];
	  J_simetrico(i,v);
	  diferencias_divididas(i,v);
	  printf("\n\tGrado %i: x=%.16G",i,p(i,v,0));
	}
	printf("\n");	
	return 0;
}
void J_positivo(int n, double v[][n+1]){//n=grado_del_polinomio
  double i=2.4;
  for(int k=0;k<=n;k++,i-=0.1){
    v[0][k]=j0(i);
    v[1][k]=i;
  }
}
void J_negativo(int n, double v[][n+1]){//n=grado_del_polinomio
  double i=2.5;
  for(int k=0;k<=n;k++,i+=0.1){
    v[0][k]=j0(i);
    v[1][k]=i;
  }
}
void J_simetrico(int n, double v[][n+1]){//n=grado_del_polinomio
  double i=2.4;
  for(int k=0;k<=n;k++,i-=0.1){
    v[0][k]=j0(i);
    v[1][k]=i;
    k++;
    v[0][k]=j0(i+0.1*k);
    v[1][k]=i+0.1*k;
  }
}
double w(int j, double v[], double x){//w_j=(x-x0)(x-x1)...(x-x(j-1)) con w_0=1.
	double w=1;
	for(int i=0;i<j;i++)
		w*=(x-v[i]);
	return w;
}
double p(int n,double v[][n+1], double x){//polinomio_interpolador.
	double valor=0;
	for(int j=0;j<=n;j++)
		valor+=v[j+1][0]*w(j,v[0],x);
	return valor;
}
void diferencias_divididas(int n, double v[][n+1]){
	for(int k=2;k<=n+1;k++){
		for(int j=0;j<=n+1-k;j++)
			v[k][j]=(v[k-1][j+1]-v[k-1][j])/(v[0][j+(k-1)]-v[0][j]); //diferencias divididas quedan en la primera columna a partir de la fila 2.
	}
}
