#include <stdio.h>
int main() { /* Legge un carattere e ne stampa il codice ASCII */
	char c;    /* se è una lettera minuscola; altrimenti termina */
	int i; 
	printf("scrivi un car. minuscolo (maiuscolo per finire)\n");
	scanf ("%c", &c);
	fflush(stdin); /* buffer viene svuotato, scanf non prende INVIO!!!*/
	while ( c >= 'a' && c <= 'z' ) { /*devo lavorare sulle lettere minuscole*/
		i = c; /* ciò è possibile perchè prende codifica ascii del carattere, che è intera e la assegna ad una variabile*/
		printf("valore ASCII per %c risulta %d\n", c, i);
		printf("scrivi un car. minuscolo (ogni altro per finire)\n"); /* dovrebbe aspettare che metta un carattere!!*/
		scanf ("%c", &c); /* scanf non è in grado di capire cosa sia lettera che voglio e quale terminatore, se scivo a , nel tubo a e \n*/
		fflush(stdin);		
	 }	
	 /*Devoa aggiungere istruzione dopo la scanf*/
}