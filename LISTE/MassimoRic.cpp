#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct El { 
	  int dato;
	  struct El *next;
}ELEMENTO;
typedef ELEMENTO * punt;

ELEMENTO * MassimoRic(punt Testa);

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
	nuovo->dato = 20;
	nuovo->next = NULL;
	corrente->next = nuovo;
	
	// creo un terzo nodo
	punt ultimo = (punt) malloc(sizeof(ELEMENTO));
	ultimo->dato = 9;
	ultimo->next = NULL;
	nuovo->next = ultimo;
	
	punt mass = (punt) malloc(sizeof(ELEMENTO));
	mass=MassimoRic(Testa);
	printf("%d ",mass->dato);
}

ELEMENTO * MassimoRic(punt Testa){
	ELEMENTO * e;
	if(Testa==NULL){
		
	}
	if(Testa->next ==NULL){
		return Testa;
	}
	e=MassimoRic(Testa->next);
	if(e->dato < Testa->dato){
		return Testa;
	}else{
		return e;
	}
}

int Max(punt *Testa){
	int temp_max=0,MAX=0;
	punt corr=(punt) malloc(sizeof(ELEMENTO));
	if(Testa==NULL){
		return -10000;
	}
	if(Testa->next==NULL){
		return Testa->dato;
	}
	corr=Testa->next;
	temp_max=Max(corr);
	if(temp_max>MAX){
		MAX=temp_max;
	}
	return MAX;
}