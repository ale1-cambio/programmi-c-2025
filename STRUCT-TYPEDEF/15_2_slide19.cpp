#include <stdio.h>
#include <string.h>
#define MAX_CORS 30

typedef struct{
	char NomeStudente[10];
	char CognomeStudente [10];
	int Eta;
}Studenti;

typedef struct{
	char Lingua[10];
	int Livello;
	int NumeroIscritti;
	char NomeInsegnante[15];
	Studenti studenti[10];
}Corso;

typedef struct{
	Corso corsi[MAX_CORS];
}ScuolaLingue;

int main(){
	ScuolaLingue cesaris;
	ScuolaLingue.corsi[0].Lingua = "Inglese";
	ScuolaLingue.corsi[0].Livello = 2;
	ScuolaLingue.corsi[0].NomeInsegnante ="Mr.Jones";
	ScuolaLingue.corsi[0].NumeroIscritti = 10;
	int i=0, somma=0,cont=0,media=0;
	for(i=0;i<NumeroIscritti;i++){
		somma = somma + Corso.studenti[i].Eta;
	} 
}