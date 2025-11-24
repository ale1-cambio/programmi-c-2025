#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int numero;
	struct Node*next;
}Nodo;

typedef Nodo * Lista;
/*Si progetti e codifichi una funzione C che riceve in ingresso una lista definita

La funzione deve verificare se l’andamento della lista è monotono crescente, cioè se ogni elemento è strettamente 
superiore al suo predecessore.
*/
int ListaMonotona(Lista list);
int RicListaMonotona(Lista list);
int main(){
	// Allocazione dei nodi
	Lista n1 = (Lista)malloc(sizeof(Nodo));
	Lista n2 = (Lista)malloc(sizeof(Nodo));
	Lista n3 = (Lista)malloc(sizeof(Nodo));
	Lista n4 = (Lista)malloc(sizeof(Nodo));

	// Assegnazione dei valori
	n1->numero = 5;
	n2->numero = 10;
	n3->numero = 19;
	n4->numero = 20;

	// Collegamento dei nodi
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	// Verifica monotonia
	if (RicListaMonotona(n1)) {
		printf("La lista e' strettamente crescente.\n");
	} else {
		printf("La lista NON e' strettamente crescente.\n");
	}

	// Liberazione memoria
	free(n1);
	free(n2);
	free(n3);
	free(n4);

}

int ListaMonotona(Lista list){
	int flag=1,i;
	Lista curr= list,curr2;
	if(list!=NULL){
		curr2=curr->next;
		while(curr2!=NULL){
			if(curr->numero > curr2->numero){
				return 0;
			}
			curr=curr2;
			curr2=curr2->next;
		}
	}
	return 1;
	
}
int RicListaMonotona(Lista list){
	if(list==NULL){
		return 1;
	}if(list->next==NULL){
		return 1;
	}if(list->numero < list->next->numero){
		return RicListaMonotona(list->next);
	}else{
		return 0;
	}
	
}