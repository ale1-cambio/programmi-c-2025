#include<stdio.h>
#include<string.h>
#include <math.h>
#define N 20


typedef struct{
char nome[N];
int pop;
}Popolo;

typedef struct{
	char piuNumeroso[N];
	char mediano[N];
}Ris;

Ris analizzaPopoli(Popolo popol[],int len){
	Ris risultato;
	strcpy(risultato.mediano,"");
	strcpy(risultato.piuNumeroso,"");
	int i=0,max=0,somma=0,diff=0,new_diff=0;
	float media=0.0;
	for(i=0;i<len;i++){
		if(popol[i].pop>max){
			somma += popol[i].pop;
			max=popol[i].pop;
			strcpy(risultato.piuNumeroso,popol[i].nome);
		}
	}
	media=somma/len;
	diff=(float)popol[0].pop - media;
	
	if(diff<0){
		diff = (-1)*diff;
	}
	strcpy(risultato.mediano,popol[0].nome);
	for(i=1;i<len;i++){
		new_diff=popol[i].pop - media;
		if(new_diff<0){
			new_diff = (-1)*new_diff;
		}
		if(new_diff<diff){
			strcpy(risultato.mediano,popol[i].nome);
			diff=new_diff;
		}	
	}
	return risultato;
}

int main()
{
Popolo indiani[5];
// TODO aggiungere dichiarazione variabili aggiuntive


strcpy(indiani[0].nome, "Cayuga");
indiani[0].pop = 652;
strcpy(indiani[1].nome, "Oneida");
indiani[1].pop = 2123;
strcpy(indiani[2].nome, "Seneca");
indiani[2].pop = 3521;
strcpy(indiani[3].nome, "Onondaga");
indiani[3].pop = 1763;
strcpy(indiani[4].nome, "Mohawak");
indiani[4].pop = 4512;


// TODO Invoca la funzione
Ris risultato_;
risultato_=analizzaPopoli(indiani,5);

// TODO stampa i nomi dei popoli come richiesto

printf("Piu numerosi: %s, piu vicini alla media: %s",risultato_.piuNumeroso,risultato_.mediano);
return 0;
}


