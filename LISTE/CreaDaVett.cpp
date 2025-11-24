#include <stdio.h>
#include <stdlib.h>

typedef struct El{
	int dato;
	struct El * next;
}Nodo;

typedef Nodo * Testa;
Testa CreaDaVett(int v[],int n);
int main(){
	int vett[4]={3,5,15,7};
	Testa testa;
	testa=CreaDaVett(vett,4);
	for(int i=0;i<4;i++){
		printf("%d ",testa->dato);
		testa=testa->next;
	}
	return 0;
}

Testa CreaDaVett(int v[],int n){
	Testa testa;
	if(n==0){
		return NULL;
	}
	testa=(Testa)malloc(sizeof(Nodo));
	testa->dato=v[0];
	testa->next=CreaDaVett(&v[1],n-1);
	return testa;
}