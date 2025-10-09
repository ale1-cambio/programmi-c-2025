#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	int numero, val,indovinato=0;
	srand(time(0));
	numero =rand()%(100);
	while(indovinato!=1){
		printf("Inserisci un numero compreso tra 0 e 100: ");
		scanf("%d", &val);
		printf("\n");
		if(val>numero){
			printf("Il tuo numero è maggiore");
		}else if(val<numero){
			printf("Il tuo numero è minore");
		}else{
			indovinato=1;
		}
		printf("\n");
	}
	printf("Esatto, il numero ero %d",numero);
}