#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int generarFichero(int numFicheros, FILE **ficheros);
double escribirDatos(int n, double v[][n+1], FILE *fichero);
double w(int j,double v[],double x);
double f(double x);
double x(int k);
double p(int n,double v[][n+1],double x);
void diferencias_divididas(int n,double v[][n+1]);
void equidist(int n,double v[][n+1]);
void chebyshev(int n,double v[][n+1]);

int main(){
	FILE **ficheros=malloc(8*sizeof(FILE *));
	int n=4;
	double (*v)[n+1],(*aux)[n+1];
	v=(double (*)[n+1]) malloc((n+2)*(n+1)*sizeof(double));//en la fila 1 los valores de la x, en la fila 2 los valores de f(x).
	if(v==NULL){
		printf("No se ha podido hacer la asignacion de memoria.\n");
		return 1;
	}
	if(generarFichero(8,ficheros)==1)
		return 1;
	printf("Errores maximos utilizando nodos n=4,8,16,32:\n\n\tNodos equidistantes\tNodos de Chebyshev\n");
	for(int i=0;i<4;i++,n*=2){
		if((aux=(double (*)[n+1]) realloc(v,(n+2)*(n+1)*sizeof(double)))==NULL){
			printf("No se ha podido hacer la asignacion de memoria.\n");
			return 1;
		}
		v=aux;
		equidist(n,v);
		printf("n=%i\t%.16G\t",n,escribirDatos(n,v,ficheros[i]));
		chebyshev(n,v);
		printf("%.16G\n",escribirDatos(n,v,ficheros[i+4]));
	}
	for(int i=0;i<8;i++)
		fclose(ficheros[i]);
	free(v);
	return 0;
}
int generarFichero(int numFicheros, FILE **ficheros){//Abre el array de ficheros
	char nombre[20];
    for(int i=0;i<numFicheros;i++){
        sprintf(nombre,"interpolacio%d.txt",i);
        ficheros[i]=fopen(nombre,"w");
        if(ficheros[i]==NULL){
			printf("No se ha podido crear el fichero.\n");
		    return 1;
		}
    }
    return 0;
}
double escribirDatos(int n, double v[][n+1], FILE *fichero){//Escribe los errores por pantalla y los datos en el fichero "fichero".
	int N=180;
	double error=fabs(f(x(0))-p(n,v,x(0)));
	for(int k=1;k<=N;k++){
		error=fmax(error,fabs(f(x(k))-p(n,v,x(k))));
		fprintf(fichero,"%.16G %.16G %.16G\n",x(k),f(x(k)),p(n,v,x(k)));
	}
	return error;
}
double w(int j,double v[],double x){//w_j=(x-x0)(x-x1)...(x-x(j-1)) con w_0=1.
	double w=1;
	for(int i=0;i<j;i++)
		w*=(x-v[i]);
	return w;
}
double f(double x){
	return 1./(1+25*x*x);
}
double x(int k){
	return -0.989+k*0.011;
}
double p(int n,double v[][n+1],double x){//polinomio_iterpolador.
	double valor=0;
	for(int j=0;j<=n;j++)
		valor+=v[j+1][0]*w(j,v[0],x);
	return valor;
}
void diferencias_divididas(int n,double v[][n+1]){
	for(int k=2;k<=n+1;k++){
		for(int j=0;j<=n+1-k;j++)
			v[k][j]=(v[k-1][j+1]-v[k-1][j])/(v[0][j+(k-1)]-v[0][j]); //diferencias divididas quedan en la primera columna a partir de la fila 2 (contadas des de 1).
	}
}
void equidist(int n,double v[][n+1]){
	for(int j=0;j<=n;j++){
		v[0][j]=-1+j*2./n;
		v[1][j]=f(v[0][j]);
	}
	diferencias_divididas(n,v);
}
void chebyshev(int n,double v[][n+1]){
	for(int j=0;j<=n;j++){
		v[0][j]=cos((2*j+1)*M_PI/(2*n+2));
		v[1][j]=f(v[0][j]);
	}
	diferencias_divididas(n,v);
}