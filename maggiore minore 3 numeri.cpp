#include <stdio.h>
/*Scrivere un programma in linguaggio C che, letti tre numeri interi a, b, c dallo standard input, stampi a terminale la sequenza dei tre numeri in ordine crescente.
Esempio: a = 10, b = 7, c = 9 deve dare in uscita 7 9 10*/
int main(){
	int a,b,c,temp;
	printf("Inserisci il numero a: ");
	scanf("%d", &a);
	printf("Inserisci il numero b: ");
	scanf("%d", &b);
	printf("Inserisci il numero c: ");
	scanf("%d", &c);
	/* se contenuto delle tre variabili non è ordinato, le scambiamo noi*/
	if (a>b){/* se non voglio che sia a>b, scambio i contenuti, uso una variabile ausiliaria*/
		temp = b;
		b=a;
		a=temp; /*ho scambiato i valori di a e b*/
	} 
	if (a>c){/* se non voglio che sia a>b, scambio i contenuti, uso una variabile ausiliaria*/
		temp = c;
		c=a;
		a=temp; /*ho scambiato i valori di a e b*/
	} /* in a ci sarà sicuramente valore più piccolo, non so se b e c in ordine.*/
	if (b>c){
		temp = b;
		b=c;
		c = temp;
	}
	printf("%d %d %d", a,b,c);
}