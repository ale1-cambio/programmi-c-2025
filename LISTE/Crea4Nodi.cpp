#include <stdio.h>
#include <stdlib.h>

typedef struct El{
	int dato;
	struct El * next;
} Nodo;

typedef Nodo * Testa;

int main(){
	// Creazione di 4 nodi
	Testa n1 = (Testa)malloc(sizeof(Nodo));
	Testa n2 = (Testa)malloc(sizeof(Nodo));
	Testa n3 = (Testa)malloc(sizeof(Nodo));
	Testa n4 = (Testa)malloc(sizeof(Nodo));

	// Assegnazione dei valori
	n1->dato = 1;
	n2->dato = 2;
	n3->dato = 3;
	n4->dato = 4;

	// Collegamento dei nodi
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	// Stampa della lista per verifica
	Testa p = n1;
	while(p != NULL){
		printf("%d ", p->dato);
		p = p->next;
	}
	printf("\n");

	return 0;
}
