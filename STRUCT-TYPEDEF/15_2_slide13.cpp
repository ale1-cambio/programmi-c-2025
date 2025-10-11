#include <stdio.h>
#include <string.h>
#define N 4
typedef struct{
	int peso;
	float altezza;
	int eta;
} InfoFisiche;

typedef struct{
	InfoFisiche info;
}Persona;

int main(){
	Persona persone[N];
	int temp;
	int i=0,ordine=0;
	for(i=0;i<N;i++){
		printf("Inserisci peso della persona %d: ",i+1);
		scanf("%d",&persone[i].info.peso);
		printf("Inserisci altezza (in cm) della persona %d: ",i+1);
		scanf("%f",&persone[i].info.altezza);
		printf("Inserisci eta' della persona %d: ",i+1);
		scanf("%d",&persone[i].info.eta);
		if(persone[i].info.peso < 0 || (persone[i].info.altezza < 0 || persone[i].info.altezza >300) || persone[i].info.eta < 0){
			i--;
		}
	}
/*	for(i=0;i<N;i++){
		if(persone[i].info.eta <=20){
			printf("Il peso della persona %d e' %d kg\n l'altezza e' %f cm\n l'eta e' %d anni",i+1,persone[i].info.peso,persone[i].info.altezza,persone[i].info.eta);
		}
		printf("\n");
	}*/
	while(ordine==0){
		for(i=0;i<N-1;i++){
			if(persone[i].info.eta>persone[i+1].info.eta){
				ordine=0;
				temp=persone[i+1].info.eta;
				persone[i+1].info.eta = persone[i].info.eta;
				persone[i].info.eta = temp;
				i--;
			}else{
				ordine=1;
			}
		}
		
	}
	for(i=0;i<N;i++){
		printf("%d  ",persone[i].info.eta);
	}
}