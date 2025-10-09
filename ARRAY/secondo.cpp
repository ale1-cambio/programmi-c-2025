#include <stdio.h>
#define MAXSIZE 10


int main(){
	int i=0,X,V[MAXSIZE],somma=0,prodotto=1;
	do{
		printf("Inserisci un numero intero: ");
		scanf("%d", &V[i]);
		i++;
	}while(i<MAXSIZE);
	do{
		printf("Inserisci un indice tra 0 e 9: ");
		scanf("%d",&X);
	}while(X<0 || X>9);
	for(i=0;i<MAXSIZE;i++){
		if(i<X){
			somma=somma+V[i];
		}else if(i>X){
			prodotto=prodotto*V[i];
		}
	}
	printf("La somma dei numeri prima della poszione %d è %d, mentra il prodotto dopo la posizione %d è %d.",X,somma,X,prodotto);
}