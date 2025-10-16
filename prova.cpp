#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[20];
	char cognome[20];
	int eta;
}Persona;
int main() {
    int i, j;
	Persona persone[10],temp;
	Persona* pereta[10]; Persona * percognome[10];
	//faccio puntare puntatori a celle di persone
	for (i = 0; i < 10; i++) {
		pereta[i] = &persone[i]; //sto puntando alla casella della persona, non solo al nome o cognome
		percognome[i] = &persone[i];
	}
    strcpy(persone[0].nome, "Luca");
    strcpy(persone[0].cognome, "Rossi");
    persone[0].eta = 25;

    strcpy(persone[1].nome, "Maria");
    strcpy(persone[1].cognome, "Bianchi");
    persone[1].eta = 30;

    strcpy(persone[2].nome, "Giovanni");
    strcpy(persone[2].cognome, "Verdi");
    persone[2].eta = 28;

    strcpy(persone[3].nome, "Elena");
    strcpy(persone[3].cognome, "Neri");
    persone[3].eta = 22;

    strcpy(persone[4].nome, "Marco");
    strcpy(persone[4].cognome, "Ferrari");
    persone[4].eta = 35;

    strcpy(persone[5].nome, "Chiara");
    strcpy(persone[5].cognome, "Conti");
    persone[5].eta = 27;

    strcpy(persone[6].nome, "Alessandro");
    strcpy(persone[6].cognome, "Gallo");
    persone[6].eta = 33;

    strcpy(persone[7].nome, "Francesca");
    strcpy(persone[7].cognome, "Romano");
    persone[7].eta = 29;

    strcpy(persone[8].nome, "Davide");
    strcpy(persone[8].cognome, "Costa");
    persone[8].eta = 31;

    strcpy(persone[9].nome, "Sara");
    strcpy(persone[9].cognome, "Marini");
    persone[9].eta = 26;
	//ordinamento per età crescente (con bubble sort)
    /*for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (persone[i].eta > persone[j + 1].eta) {
                temp = persone[j + 1];
                persone[j + 1] = persone[j];
                persone[j] = temp;
            } 
        }
    }*/
	//ordino per cognome crescente (con bubble sort) con puntatori
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (strcmp(percognome[j]->cognome, percognome[j + 1]->cognome) < 0) {
                temp = *percognome[j + 1];
                *percognome[j + 1] = *percognome[j];
                *percognome[j] = temp;
            } 
        }
    }
    for ( i = 0; i < 10; i++){
        for (j = 0; j < 10; j++) {
            if(pereta[j]->eta > pereta[j + 1]->eta) {
                temp = *pereta[j + 1];
                *pereta[j + 1] = *pereta[j];
                *pereta[j] = temp;
			}
        }
    }
    printf("Persone ordinate per età crescente:\n");
 	for (i = 0; i < 10; i++) {
        printf("%s %s, Età: %d\n", pereta[i]->nome, pereta[i]->cognome, pereta[i]->eta);
    }
    printf("\nPersone ordinate per cognome crescente:\n");
    for (i = 0; i < 10; i++) {
        printf("%s %s, Età: %d\n", percognome[i]->nome, percognome[i]->cognome, percognome[i]->eta);
    }
	return 0;
    
    
}
