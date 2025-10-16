#include <stdio.h>
#include <string.h>
#define MAX_CORS 30
#define maxstud 10
#define NumeroIscritti 10	
#define maxclassi 5
/*
*/
typedef struct{
	char NomeStudente[10];
	char CognomeStudente [10];
	int Eta;
}Studente;

/*typedef struct{
	char Lingua[10];
	int Livello;
	int NumeroIscritti;
	char NomeInsegnante[15];
	Studenti studenti[10];
}Corso;

typedef struct{
	Corso corsi[MAX_CORS];
}ScuolaLingue;*/
typedef struct { char lingua[10] ;
    int liv;
    int numiscritti;
    char nomeinsegn[15];    
	Studente alunni[maxstud];
} Classe ;
//Scrivere in linguaggio C la parte di algoritmo per calcolare l’età media degli studenti iscritti ai corsi di lingua inglese (supponendo di aver inizializzato la variabile ScuolaLingue con le informazioni relative a 30 corsi).

int main(){
	Classe ScuolaLingue[maxclassi];
	int sommaeta=0,conta=0,i=0,j=0;
	float mediaeta;
	for(i=0;i<maxclassi;i++){
			if(strcmp(ScuolaLingue[i].lingua,"Inglese")==0){
				for(j=0;j<ScuolaLingue[i].numiscritti;j++){
					sommaeta=sommaeta+ScuolaLingue[i].alunni[j].Eta;
					conta++;
				}
			} 
	}
	mediaeta=(float)sommaeta/conta;
	printf("L'età media degli studenti iscritti ai corsi di lingua inglese è: %f",mediaeta);

	return 0;

}

