#include <stdio.h>

/*Scrivere un programma per il calcolo delle tabelline. Il programma riceve dall’utente due numeri. Il primo corrisponde al numero di cui è necessario calcolare la tabellina mentre il secondo indica la lunghezza della tabellina richiesta.
Es: 2, 10 produce come risultato: 2 4 6 8 10 12 14 16 18 20
Es: 3, 8 produce come risultato: 3 6 9 12 15 18 21 24
Accettare solamente numeri positivi: se l’utente inserisce un numero negativo mostrare un messaggio di errore e richiedere un altro numero.*/

int main(){
	int N,M,i,val;
	printf("Inserisci il numero di cui vuoi calcolare la tabellina: ");
	scanf("%d", &N);
	while(N<0){
		printf("Valore non accettabile, inseriscilo di nuovo: ");
		scanf("%d", &N);
	}
	printf("Inserisci il numero a cui vuoi far corrispondere la lunghezza della tabellina: ");
	scanf("%d", &M);
	while(M<0){
		printf("Valore non accettabile, inseriscilo di nuovo: ");
		scanf("%d", &M);
	}
		
	for(i=1;i<=M;i++){
		val = N*i;         
		printf("%d ",val);
	}
	
}