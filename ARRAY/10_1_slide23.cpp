#define DIM 10
#define N 5
#include <stdio.h>

/*Chiedere all’utente di inserire un array di interi (di dimensione definita precedentemente) e quindi un numero intero t. Il programma quindi
Salva gli elementi inseriti in un vettore v1
Copia tutti gli elementi di v1 che sono maggiori di n in un secondo vettore v2
La copia deve avvenire nella parte iniziale di v2 senza lasciare buchi
*/

int main(){
	int i=0,j,val, v1[DIM], v2[DIM];
	printf("Inserisci un numero: ");
	scanf("%d", &val);
	do{
		v1[i]=val;
		scanf("%d", &val);	
		i++;		
	}while(i<9);
	for(j=0;j<DIM;j++){
		printf(" %d ", v1[j]);
	}
	j=0;
	for(i=0;i<DIM;i++){
		if(v1[i]>N){
			v2[j]=v1[i];
			j++;
		}
	}
	printf("I caratteri maggiori di 5 sono: ");
	for(i=0; i<j;i++){
		printf(" %d ",v2[i]);
	}
}