#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define N 5

/*Il tipo Candidato definisce un candidato alle elezioni per il presidente del club degli scacchi. 

typedef struct{
    char nome[100], cognome[100];
    int voti;
} Candidato;

Si scriva una funzione calcolaVincitore che prende in ingresso un array di elementi di tipo Candidato (ed ulteriori variabili 
aggiuntive se necessarie) e riporta al chiamante il nome e cognome del vincitore. Si scriva poi una seconda funzione, candidatoMedio, 
che prende in ingresso un array di elementi di tipo Candidato (ed ulteriori variabili aggiuntive se necessarie) e riporta al chiamante 
il nome e cognome del candidato più vicino alla media dei voti dei vari candidati (si supponga sia unico). Per identificare il candidato 
più vicino alla media, si consideri la differenza in valore assoluto.

In riferimento all’array popolato nel main nel seguente codice (da utilizzare per sviluppare la soluzione)
ci si aspetta la seguente stampa dal main:

Più votato: Bobby Fisher

Più vicino alla media: Alex Fields*/
typedef struct{
	char nome[100], cognome[100];
	int voti;
}Candidato;

void calcolaVincitore(Candidato candidati[], int len,Candidato *vin){
	int i;
	strcpy(vin->cognome," ");
	strcpy(vin->nome," ");
	vin->voti=0;
	for(i=0;i<len;i++){
		if(candidati[i].voti>vin->voti){
			strcpy(vin->cognome,candidati[i].cognome);
			strcpy(vin->nome,candidati[i].nome);
			vin->voti=candidati[i].voti;
		}
	}
}

float abs(int a,float b){
	if(float(a-b)>0){
		return (a-b);
	}else{
		return (b-a);
	}
}

void candidatoMedio(Candidato candidati[], int len,Candidato *med){
	int i,somma=0;
	float media=0,diff=0,diff_ref;
	for(i=0;i<len;i++){
		somma+=candidati[i].voti;
	}
	media=somma/len;
	diff_ref=abs(candidati[0].voti,media);
	strcpy(med->cognome,candidati[0].cognome);
	strcpy(med->nome,candidati[0].nome);
	med->voti=candidati[0].voti;
	for(i=1;i<len;i++){
		diff=abs(candidati[i].voti,media);
		if(diff<diff_ref){
			strcpy(med->cognome,candidati[i].cognome);
			strcpy(med->nome,candidati[i].nome);
			med->voti=candidati[i].voti;
			diff_ref=diff;
		}
		diff=0;
	}
}


int main()
{
Candidato candidati[N];
// TODO aggiungere dichiarazione variabili aggiuntive


strcpy(candidati[0].nome, "Alex");
strcpy(candidati[0].cognome, "Fields");
candidati[0].voti = 4400;
strcpy(candidati[1].nome, "Bobby");
strcpy(candidati[1].cognome, "Fisher");
candidati[1].voti = 7800;
strcpy(candidati[2].nome, "Boris");
strcpy(candidati[2].cognome, "Spassky");
candidati[2].voti = 3400;
strcpy(candidati[3].nome, "Garry");
strcpy(candidati[3].cognome, "Kasparov");
candidati[3].voti = 5600;
strcpy(candidati[4].nome, "Emanuel");
strcpy(candidati[4].cognome, "Lasker");
candidati[4].voti = 1200;


// TODO invoca la funzione

Candidato vincitore;
Candidato medio;
calcolaVincitore(candidati,N,&vincitore);
candidatoMedio(candidati,N,&medio);
// TODO stampa nomi e cognomi richiesti
printf("Piu' votato: %s %s\n",vincitore.nome,vincitore.cognome);
printf("Piu' vicino alla media: %s %s\n",medio.nome,medio.cognome);

return 0;
}


