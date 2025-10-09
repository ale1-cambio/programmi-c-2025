#include <stdio.h>

int main(){
	int cont = 1,N,fatt=1;
	printf("Inserisci il numero di cui vuoi calcolare il fattoriale: ");
	scanf("%d", &N);
	if(N>=0){
		while(cont<=N){/* posso anche partire da N,decrementare e arrivare fino a che N >1*/
		fatt=fatt * cont;
		cont++;
		}
	/*	for(N>1;n--){
			fatt=fatt*N;
		}*/
	}else{
		printf("Il valore inserito è negativo.");
	}
	
	printf("%d", fatt);
	return 0;
}