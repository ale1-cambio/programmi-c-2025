#include <iostream>
#include <cstdlib>

typedef struct El { 
	  int dato;
	  struct El *next;
} ELEMENTO;

typedef ELEMENTO * punt;

int somma(ELEMENTO *Testa, int M);

int main(){
	punt Testa = NULL;
	punt corrente = NULL;
	
	// Creazione manuale della lista: 8 -> 5 -> 10 -> 9
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
	
    // Stampa della lista
    std::cout << "Lista creata:" << std::endl;
    corrente = Testa;
    while(corrente != NULL){
        std::cout << corrente->dato << " -> ";
        corrente = corrente->next;
    }
    std::cout << "NULL" << std::endl;

    // Calcolo della somma
    int result = somma(Testa, 5);
    std::cout << "La somma dei valori divisibili per 5 e': " << result << std::endl;

    // Free memory
    corrente = Testa;
    while(corrente != NULL){
        punt temp = corrente;
        corrente = corrente->next;
        free(temp);
    }

    return 0;
}

int somma(ELEMENTO *Testa, int M){
	int som=0;
	if(Testa==NULL){
		return -1; // Restituisce -1 se la lista è vuota
	}
	while(Testa !=NULL){
		if(Testa->dato % M == 0){
				som += Testa->dato;
		}
		Testa = Testa->next;
	}
	return som;
}
