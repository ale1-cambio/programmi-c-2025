/*Supponendo date le seguenti definizioni:
typedef struct El {int s; 
                          struct El *next;}Elemento;
typedef Elemento *ListaDiInteri;
definire una funzione MinEven che, data una ListaDiInteri restituisce la posizione (puntatore) del minimo elemento 
pari nella lista (restituisce NULL se la lista non contiene elementi pari).
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct El {
	int s; 
    struct El *next;
}Elemento;
typedef Elemento *ListaDiInteri;

ListaDiInteri MinEven(ListaDiInteri* list);

ListaDiInteri FirstEven(ListaDiInteri lis);
int main(){
	
}


ListaDiInteri MinEven(ListaDiInteri* list){
	ListaDiInteri ris;
	ris=FirstEven(list);
	if(ris!=NULL){
		list=ris->next;
		while(list!=NULL){
			if(((list->s)%2)==0 && (list->s <ris->s)){
				ris=list;	
			}
			list=list->next;
		}
	}
	return ris;
}
ListadiInteri MinEl(ListaDiInteri p, ListaDiInteri q){
	if(p<q){
		return p;
	}else if(p>=q){
		return q;
	}
}
ListaDiInteri FirstEven(ListaDiInteri lis){
	if(lis==NULL){
		return NULL;
	}else{
		if((lis->s)%2==0)
			return lis;
		else{
			return FirstEven(lis->next);
		}
	}
}