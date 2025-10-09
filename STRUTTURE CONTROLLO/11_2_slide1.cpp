#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 100
int main(){
	char str1[LUNG], str2[LUNG], strTot[LUNG*2];
	int i=0,j;
	printf("Inserisci la prima stringa: ");
	scanf("%s", str1);
	printf("Inserisci la seconda stringa: ");
	scanf("%s", str2);
	/*for(i=0;str1[i]!='\0';i++){
		strTot[i]=str1[i];
	}
	for(j=0;str2[j] != '\0';j++){
		strTot[j+i]=str2[j];	
	}
	strTot[i+j] = '\0';
	printf("%s",strTot);*/
	strcpy(strTot,str1); //destinazione è strTot
	strcat(strTot,str2); //non uso copy perchè farebbe dall'inizio, uso concatenazione,parte dal terminatore e copia tutto il resto.
	printf("%s",strTot);
}