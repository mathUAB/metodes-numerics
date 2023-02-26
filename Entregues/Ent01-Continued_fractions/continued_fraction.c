#include <stdio.h>
#include <math.h>
#include <time.h>
#define e 2.71828182845904523536

#define N 100

typedef struct{
    int p;
    int q;
}rational;

void imprimeixvector(int [],int);
void continued_fractions(int lenght,rational r[],int sequence[]);

int main(){
	rational r[N];
	int sequence[N];
	clock_t begin=clock();
	continued_fractions(11,r,sequence);
	imprimeixvector(sequence,16);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time spent: %lf\n",time_spent);
	return 0;
}

void continued_fractions(int lenght,rational r[],int sequence[]){
	//create the continued fraction of e: 
	for(int i=0;i<lenght/3;i++){
		sequence[3*i]=1;
		sequence[3*i+1]=1;
		sequence[3*i+2]=2*(i+1);
	}
	if(lenght % 3==1){
		sequence[lenght-1]=1;
	}
	if(lenght % 3==2){
		sequence[lenght-2]=1;
		sequence[lenght-1]=1;
	}
	sequence[0]+=1;
	//compute approximation of e:
	
}
void imprimeixvector(int vect[],int dim){
    int i;
    printf("(");
    for(i=0;i<dim;i++){
        printf("%i,",vect[i]);
    }
    printf(")\n");
    return;
}
