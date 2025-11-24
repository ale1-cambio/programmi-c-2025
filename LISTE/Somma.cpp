#include <stdio.h>
#include <stdlib.h>
typedef struct El { 
	  int dato;
	  struct El *next;
}ELEMENTO;
typedef ELEMENTO * punt;

int somma(ELEMENTO *Testa, int M);

int main(){
	punt Testa = NULL;
	punt corrente = NULL;
	
	Testa = (punt) malloc(sizeof(ELEMENTO));
	Testa->dato = 8;
	Testa->next = NULL;
	
	// creo un primo nodo
	corrente = (punt) malloc(sizeof(ELEMENTO));
	corrente->dato = 5;
	corrente->next = NULL;
	Testa->next = corrente;
	
	// creo un secondo nodo
	punt nuovo = (punt) malloc(sizeof(ELEMENTO));
	nuovo->dato = 10;
	nuovo->next = NULL;
	corrente->next = nuovo;
	
	// creo un terzo nodo
	punt ultimo = (punt) malloc(sizeof(ELEMENTO));
	ultimo->dato = 9;
	ultimo->next = NULL;
	nuovo->next = ultimo;
	
		
		
    // Creazione di una lista di 10 nodi
    /*for(int i=0; i<10; i++){
        punt nuovo = (punt)malloc(sizeof(ELEMENTO));
        nuovo->dato = (i+1)*5;   // valori di esempio: 5,10,15,...
        nuovo->next = NULL;

        if(Testa == NULL){
            Testa = nuovo;
            corrente = nuovo;
        } else {
            corrente->next = nuovo;
            corrente = nuovo;
        }
    }*/

    // Stampa della lista
    printf("Lista creata:\n");
    corrente = Testa;
    while(corrente != NULL){
        printf("%d -> ", corrente->dato);
        corrente = corrente->next;
    }
    printf("NULL\n");

    // Calcolo della somma
    printf("La somma dei valori divisibili per 5 è: %d\n", somma(Testa, 5));

    return 0;
}

int somma(ELEMENTO *Testa, int M){
	int som=0;
	if(Testa==NULL){
		return -1;
	}while(Testa !=NULL){
		if(Testa->dato%M==0){
				som+=Testa->dato;
		}
		Testa=Testa->next;
	}
	return som;
		
}