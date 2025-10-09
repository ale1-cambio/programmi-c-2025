/* somma di due interi*/
#include <stdio.h>

int main(){ /* chiedpo di inserire due numeri grazie alla libreria inputo output*/
	int integer1, integer2, sum;		/* dichiariamo le variabili: primo numero, secondo numero, somma di essi. Dobbiamo dire di che tipo sono le variabili (interi, con la virgola, stringa ecc.) In questo caso intero , int*/
	printf("Enter first integer \n");
	scanf("%d", &integer1); /*scanf legge ciò  che mettiamo da tastiera: un intero o altro. Per ssapere cosa viene inserito analizziamolo: ci sono du argomenti: il primo è una stringa con &d che avvisa scanf che quello che utente metterà è un intero. il secondo inizia con & che richiama l'indirizzo della variabile che voglio. scanf scannerizza e mette nella variabile che deve sapere dove è, indirizzo di locazione.*/
	printf("Enter second integer \n");
	scanf("%d", &integer2); /* scanf blocca programma finchè non viene digitato e inviato qualcosa*/
	sum = integer1 + integer2; /* = non è come nelle equazioni, ma è l'istruzione di assegnamento, a sx può avere solo il nome di una variabile, a dx una espressione ( un numero, un nome o somma di due variabili ecc.) L'assegasnmento guarda sempre prima a dx. Le variabili contengono l'ultima cosa inserita.*/
	printf("Sum is %d\n\n", sum);/* %d è una bandierina,placeholder dove inserisco il valore della variabile che voglio stampare, guarda altrove e inserisce il valore per quella bandierina, contenuto nel secondo argomento ovvero sum in questo caso.*/
}