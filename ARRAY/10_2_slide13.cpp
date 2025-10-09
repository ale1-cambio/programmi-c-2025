#include <stdio.h>
#define MAXSIZE 100
int main(){
	float val,somma=0,dati[MAXSIZE];
	int i=0,z,k;
	do{
		printf("Inserisci un numero reale(diverso da zero): ");
		scanf("%f",&val);
		somma=somma+val;
		
		dati[i]=val;
		i++;
		
	}while(((val!=0) || (i<MAXSIZE)) && somma <50);
	if(i>2){
		for(z=1;z<i+1;z++){
			for(k=2;k<i+1;k++){
				if(((dati[z]/dati[k])==dati[0]||(dati[k]/dati[z])==dati[0])){
					printf("Il rapporto o il suo inverso tra %f e %f vale %f",dati[z],dati[k],dati[0]);
					break;
				}
			}
		}
	}
}