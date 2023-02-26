#include <stdio.h>
#include <math.h>

double longitud(int n,double v[n]);

int main(){
    double v[15]={37.2,40.2,44.4,40.8,44.1,39.9,36.3,32.7,29.7,25.5,23.4,26.7,31.2,34.8,36.9};

    printf("Longitud de la pista: %.16G m\n",longitud(15,v));
    return 0;
}

double longitud(int n,double v[n]){
    double t=6,length=0;
    for(int i=1;i<n-1;i++)
        length+=v[i];
    length+=(v[0]+v[n-1])/2;
    return t*length; 
}