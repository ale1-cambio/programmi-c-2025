#include <stdio.h>
#include <string.h>

typedef struct {
	char tyarga[7];
	char marca[15];
	char modello [20];
	int cilindrata;
	float potenza;
	char categoria[16];
} Motoveicolo;
typedef struct{
	char nome[30];
	char cognome[40];
	char codicefiscale[16];
} Proprietario;
typedef struct{
	Motoveicolo motoveicolo;
	Proprietario proprietario;
} VocePRA;
typedef struct{
	VocePRA elementi[10000];
	int cont;
}PRA;
int main(){
	PRA p;
	Proprietario pr;
	int sommacilindrate=0,i=0,sommariferimento;
	/*for(i=0;i<cont;i++){                    proprietario con auto di cilindrata maggiore.
		if(PRA.elementi.motoveicolo[i].cilindrata>maxcc){
			maxcc=PRA.elementi[i].motoveicolo.cilindrata;
			pr=PRA.elementi[i].proprietario;
		}
	}*/
	for(i=0;i<cont;i++){
		for(j=0;j<cont;j++){
			sommacilindrate=sommacilindrate+PRA.elementi[i].motoveicolo[j].cilindrata;
			if(sommacilindrate>sommariferimento){
				sommariferimento=sommacilindrate;
				pr=PRA.elementi.proprietario;
			}
		}
	}
}