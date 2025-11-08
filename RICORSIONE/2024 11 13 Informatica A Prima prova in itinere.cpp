#include <stdio.h>
#include <string.h>

#define NUM_STUDENTI 5
#define NUM_VERIFICHE 5

typedef struct {
    char cognome[50];
    int voti[NUM_VERIFICHE];
    int n; // numero di verifiche effettivo
} Studente;
typedef struct{
	float media_massima;
	float media_totale;
}Medie;
typedef struct {
	 char cognomi[50];
} Cognomi_bravi;
Medie analizzaStudenti(Studente classe[NUM_STUDENTI],int num);
Cognomi_bravi studentiBravi(Studente classe[NUM_STUDENTI],int num);

int main() {
    // dichiarazione ed inizializzazione classe
    Studente classe[NUM_STUDENTI] = {
        {"Boracchi", {7, 8, 9, 6}, 4},
        {"Campi", {8, 8, 8, 8, 8}, 5},
        {"Peretti", {4, 6, 7, 5}, 4},
        {"Conti", {9, 8, 8}, 3},
        {"Valoriani", {4, 6, 7, 3}, 4}
    };
    Cognomi_bravi cognomi;
    /*1) Scrivere una funzione analizzaStudenti che prende in ingresso un array di 
	studenti definito come sopra, la sua lunghezza ed eventuali variabili aggiuntive e 
	restituisce sia:
		media_massima: il valore della media per lo studente con la media più alta nel 
		vettore.
		media_totale: la media delle medie di tutti gli studenti nel vettore. 
	*/
	Medie medie;
    medie=analizzaStudenti(classe,NUM_STUDENTI);
    printf("La media massima e' stata: %f\n",medie.media_massima);
	//INSERIRE QUI STAMPA DELLE MEDIE
	printf("La media totale e' stata: %f",medie.media_totale);
	printf("\n");
    //INSERIRE QUI INVOCAZIONE COSTRUZIONE RISULTATO STUDENTI CON MEDIA SUPERIORE
	cognomi=studentiBravi(classe,NUM_STUDENTI);
	//INSERIRE QUI STAMPA DEGLI STUDENTI CON MEDIA SUPERIORE
	printf("Studenti con media superiore alla media totale: %s",cognomi.cognomi);
    return 0;
}

Medie analizzaStudenti(Studente classe[],int num){
	float somma=0,media_max=0,media_tot=0,n_tot=0,somma_tot=0;
	int i,j;
	Medie medie;
	for(i=0;i<num;i++){
		for(j=0;j<classe[i].n;j++){
			somma=somma+classe[i].voti[j];
			somma_tot=somma_tot+classe[i].voti[j];
		}
		if((somma/classe[i].n)>media_max){
			media_max=somma/classe[i].n;
		}
		somma=0;
	}
	for(i=0;i<num;i++){
		n_tot=n_tot+classe[i].n;
	}
	media_tot=somma_tot/n_tot;
	medie.media_massima=media_max;
	medie.media_totale=media_tot;
	return medie;
}
Cognomi_bravi studentiBravi(Studente classe[NUM_STUDENTI],int num){
	int i=0,j;
	float somma=0;
	char temp[50];
	Medie medie;
	medie=analizzaStudenti(classe,NUM_STUDENTI);
	Cognomi_bravi cognomi;
	
	for(i=0;i<num;i++){
		for(j=0;j<classe[i].n;j++){
			somma=somma+classe[i].voti[j];
		}
		if((somma/classe[i].n) > medie.media_totale){
			strcat(cognomi.cognomi,classe[i].cognome);
			strcat(cognomi.cognomi," ");
		}
		somma=0;
	}
	cognomi.cognomi[strlen(cognomi.cognomi)]='\0';
	return cognomi;
}