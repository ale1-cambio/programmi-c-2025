#include <stdio.h>

int main(){
	int N_voti, somma_crediti, credito,voto,voto_ponderato,somma,i;
	float media_ponderata;
	printf("Inserisci il numero di voti che vuoi inserire: ");
	scanf("%d", &N_voti);
	for(i=1;i<N_voti;i++){
		do{
			printf("Inserisci un voto (in 30esimi): ");
			scanf("%d",&voto);
		}while(voto<=0 || voto>30);
		do{
			printf("Inserisci un credito (in 30esimi): ");
			scanf("%d",&credito);
		}while(credito<0);
		voto_ponderato=voto*credito;		
		somma_crediti=somma_crediti + credito;
		somma=somma+voto_ponderato;		
	}
	media_ponderata=somma/somma_crediti;
	printf("La media ponderata è: %f",media_ponderata);
	printf("Il numero dei crediti è: %d",somma_crediti);
}