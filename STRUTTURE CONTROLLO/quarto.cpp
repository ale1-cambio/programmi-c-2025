#include <stdio.h>
/*Scrivere un programma che acquisisca una sequenza di 10 numeri interi ed un indice X tra 0 e 9. Il programma dovrà stampare la somma dei numeri in posizioni minori di X e il prodotto dei numeri in posizioni successive a X.
*/
int main(){
	int val, X,i,j, somma=0, prodotto=1;
	
	do{
		printf("inserisci indice (compreso tra 0 e 9): ");
		scanf("%d", &X);
	}while(X<0 || X>9);
	for(i=0;i<10;i++){
		printf("Inserisci un numero: ");
		scanf("%d", &val);
		if(i<X){
			somma = somma +val;
		}else if(i>X){
			prodotto=prodotto*val;
		}
	}
	printf("La somma è: %d", somma);
	printf("Il prodotto è: %d", prodotto);
}