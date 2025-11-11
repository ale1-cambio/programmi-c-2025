#include <stdio.h>
#include <string.h>

typedef struct {
    char piatto[100];
    int calorie;
} portata;


typedef struct {
    portata primo;
    portata secondo;
    portata frutta;
    portata dolce;
} pasto;


typedef struct {
    pasto menu[10];
    int numPasti;
} menu;

void stampaMenu(menu m);

void sommePasti(menu m, int out[]);

int eliminaPastiIpercalorici(menu *m,int soglia);

int main(void) {
    menu m = {
        {{{"Risotto ai funghi",720},{"Salmone al forno",520},{"Pera",95},{"Panna cotta",360} },
         {{"Penne al pesto",700},{"Vitello tonnato",560},{"Banana",105},{"Cheesecake",430} },
         {{"Minestrone",250},{"Bresaola rucola",300},{"Arancia",70},{"Sorbetto",160} },
         {{"Maccheroni ala gricia",950},{"Costata di manzo",850},{"Mela",80},{"Tiramisu",420} },
         {{"Lasagne",820},{"Costata di manzo",850},{"Kiwi",60},{"Cannolo",440} },
         {{"Gnocchi burro e salvia",680},{"Orata alla piastra",410},{"Fragole",50},{"Gelato",220} }
        },6};
	stampaMenu(m);
	int outt[m.numPasti];
	sommePasti(m,outt);
	int i,k=0;
	for(i=0;i<m.numPasti;i++){
		printf("CALORIE PASTO %d: %d kcal\n",i,outt[i]);
	}
	k=eliminaPastiIpercalorici(&m,2000);
	printf("\nDOPO ELIMINAZIONE: %d rimossi\n\n",k);
	stampaMenu(m);
    return 0;
}

void stampaMenu(menu m){
 	int i;
 	for(i=0;i<m.numPasti;i++){
 		printf("Pasto %d:\n",i);
 		printf("Primo: %3s %10d \n",m.menu[i].primo.piatto,m.menu[i].primo.calorie);
 		printf("Secondo: %3s %10d \n",m.menu[i].secondo.piatto,m.menu[i].secondo.calorie);
 		printf("Frutta: %3s %21d\n",m.menu[i].frutta.piatto,m.menu[i].frutta.calorie);
 		printf("Dolce: %3s %18d \n",m.menu[i].dolce.piatto,m.menu[i].dolce.calorie);
 		printf("\n");
	 }
 }
void sommePasti(menu m, int out[]){
	int i,somma=0;
	for(i=0;i<m.numPasti;i++){
		out[i]=0;
	}
	for(i=0;i<m.numPasti;i++){
		out[i]+=m.menu[i].primo.calorie;
		out[i]+=m.menu[i].secondo.calorie;
		out[i]+=m.menu[i].frutta.calorie;
		out[i]+=m.menu[i].dolce.calorie;
	}
	
}

int eliminaPastiIpercalorici(menu *m,int soglia){
	int quanti;
	int i,k=0;
	int out[m->numPasti];
	quanti=m->numPasti;
	sommePasti(*m,out);
	for(i=0;i<m->numPasti;i++){
		if(out[i]<soglia){
			m->menu[k]=(*m).menu[i];
			k++;
		}
	}
	
	m->numPasti=k;
	return quanti-k;
}