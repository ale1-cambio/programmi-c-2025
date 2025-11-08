/*
Scrivere un programma in linguaggio C che definendo
opportune funzioni, risolva il seguente problema.
Date due stringhe S1 e S2, stabilire se S2 
compare come sottosequenza di S1 e, in caso affermativo,
a partire da quale indice. Creare quindi una nuova stringa S3
costruita come S1 meno la prima occorrenza della stringa S2. 
Non è permesso utilizzare le funzioni di libreria del linguaggio
relative alla manipolazione di stringhe.
Esempio: S1 = “melograno”, S2 = “grano”; 
restituisce 5 (S2 è inclusa in S1 a partire dal 5° carattere) e
S3 = “melo”.
Se fosse S1 = “sperpero”, S2 = “per”;
il risultato è 2 e S3 = “spero”.


*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 10
typedef struct{
	int flag;
	int indice;
}Pos;

typedef struct {
	char S3[N];
	int indice1;
}Stringa ;

Pos e_sottosequenza(char *S1,char *S2);
int len(char *S);
Stringa nuova(char *S1,char *S2){
	Stringa s3;
	Pos posizione;
	int i,j=0,k=0;
	posizione=e_sottosequenza(S1,S2);
	if(posizione.flag==1){
		s3.indice1=posizione.indice;
		for(i=0;i<N;i++){
			if(S1[i]!=S2[k]){
				s3.S3[j]=S1[i];
				j++;
			}else{
				k++;
			}
		}
	}else{
		s3.indice1=posizione.indice;
		s3.S3[0]='\0';
	}
	return s3;
}

int main(){
	char S1[]="sperpero";
	char S2[]="cav";
	/*Pos position;
	position=e_sottosequenza(S1,S2);
	printf("%d con indice %d",position.flag,position.indice);*/
	Stringa S3;
	S3=nuova(S1,S2);
	printf("Nuova stringa: %s, inizio indice: %d",S3.S3,S3.indice1);
}
Pos e_sottosequenza(char *S1,char *S2){
	int i,k=0;
	Pos posizione;
	for(i=0;i<len(S1);i++){
		if(S1[i]==S2[k]){
			posizione.indice=i;
			break;
		}
	}
	for(i=0;i<len(S1);i++){
		if(S1[i]==S2[k]){
			k++;
		}
	}
	if(k==len(S2)){
		posizione.flag=1;
		return posizione;
	}else{
		posizione.flag=0;
		posizione.indice=-1;
		return posizione;
	}
}
int len(char *S){
	int i=0;
	
	while(S[i]!= '\0'){
		i++;
	}
	return i;
}