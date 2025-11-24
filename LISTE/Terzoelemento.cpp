#include <stdio.h>
#include <stdlib.h>

typedef int Tipo;
typedef struct El{
	Tipo s;
	struct El*next;
}Elemento;
typedef Elemento * Lista;


void foo(Lista l, Tipo el);

void StampaLista(Lista list) {
	Lista curr = list;
	while (curr != NULL) {
		printf("%d -> ", curr->s);
		curr = curr->next;
	}
	printf("NULL\n");
}


int main(){
	Lista n1 = (Lista)malloc(sizeof(Elemento));
	Lista n2 = (Lista)malloc(sizeof(Elemento));
	Lista n3 = (Lista)malloc(sizeof(Elemento));
	Lista n4 = (Lista)malloc(sizeof(Elemento));

	// Assegnazione dei valori
	n1->s = 5;
	n2->s = 10;
	n3->s = 19;
	//n4->s = 20;

	// Collegamento dei nodi
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;
//	n4->next = NULL;
	StampaLista(n1);

	foo(n1,5);
	StampaLista(n1);
	// Liberazione memoria
	free(n1);
	free(n2);
	free(n3);
	//free(n4);
}

Lista third(Lista lis, int n){
	int count =1;
	while((lis!=NULL) && (count<3)){
		count++;
		lis=lis->next;
	}
	if(count==3 && lis!=NULL){
		return lis;
	}else{
		return NULL;
	}
}



void foo(Lista l, Tipo el){
	Lista temp,new2;
	temp=third(l,3);
	if(temp!=NULL){
		new2 = (Lista)malloc(sizeof(Elemento));
		new2->next=temp->next;
		new2->s=el;
		temp->next=new2;
	}
}