#include <stdio.h>

int main(){
	int quanti=30, i, elem1=1, elem2=1, elem3=1,elem; /* 30 elementi*/
	printf(" 1 1 1");
	i=4;
	while(i<=quanti){
		elem = elem1 + elem3;
		printf(" %d ", elem); /*spostare gli elem in modo che elem1 ecc siano in posizione corretta*/
		elem3=elem2;       /*elem1 rappresenta l'ultimo valore stampato (i-1) mentre elem3 quello stampato tre volte fa (i-3)*/
		elem2=elem1;
		elem1=elem;
		i++;
	}
	return 0;
}