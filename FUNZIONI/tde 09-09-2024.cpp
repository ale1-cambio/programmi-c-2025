
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 1000
/*Si scriva una funzione conta che riceve in ingresso una stringa S contenente più parole separate 
da virgole e contenenti solamente lettere minuscole (oltre ad eventuali parametri aggiuntivi utili per lo 
sviluppo della funzione). La funzione conta deve restituire al chiamante la lettera dell’alfabeto che compare 
più frequentemente tra le iniziali delle parole (si supponga per semplicità sia unica).
  
Si scriva quindi una seconda funzione elimina che riceve in ingresso la stringa S (contenente più parole e solo
 caratteri minuscoli), un carattere C (oltre ad eventuali parametri aggiuntivi ritenuti utili per lo sviluppo 
 della funzione), e riporta al chiamante una stringa T contenente le sole parole di S che iniziano per C, 
 separate da virgole. Nel main si stampi il vettore restituito dalla funzione elimina.*/
typedef char String[MAX_STR_LEN];
char conta(char string[]){
	int i,len,k=0,n=0;
	char c;
	String stringaa;
	len=strlen(string);
	stringaa[k]=string[0];
	k++;
	for(i=0;i<len;i++){
		if(string[i]==','){
			stringaa[k]=string[i+1];
			k++;
		}
	}
	stringaa[k]='\0';
	len=strlen(stringaa);
	int max=1,max_rel=0;
	for(i=0;i<len;i++){
		for(n=i+1;n<len-1;n++){
			if(stringaa[i]==stringaa[n]){
				max++;
			}
		}
		if(max>max_rel){
			max_rel=max;
			c=stringaa[i];
		}
		max=1;
	}
	return c;
}
void elimina(char S[],char C,char stringa[]){
	int i,len,n=0;
	len=strlen(S);
	strcpy(stringa," ");
	if(S[0]==C){
		while(S[n]!=','){
			stringa[n]=S[n];
			n++;
		}
		stringa[n]=',';
		n++;
		i=n;
	}else{
		i=0;
	}
	while(i<len){
		if(S[i]==','&& S[i+1]==C){
			while(S[i+1]!=',' && S[i+1]!='\0'){
				stringa[n]=S[i+1];
				n++;
				i++;
			}
			stringa[n]=',';
			n++;
		}else{
			i++;
		}
	}
	if(stringa[n-1]==','){
		stringa[n-1]='\0';
	}else{
		stringa[n]='\0';
	}
}
void stampa(char S[],char C,char stringa[]){
	elimina(S,C,stringa);
	printf("parole che iniziano con %c: %s",C,stringa);
}
int main() {
    char S[MAX_STR_LEN] = "cane,gatto,albero,fiore,acqua,sole,amico,giardino,pietra,vento";
    printf("%s\n",S);
    
    /*Usando la stringa nel file allegato il programma stamperà
	
	Lettera maggiormente frequente: a
  
	Parole che iniziano con a: albero,acqua,amico*/
	char c=conta(S);
	char string[MAX_STR_LEN];
	
	//elimina(S,'a',string);
	stampa(S,'a',string);
    return 0;
}