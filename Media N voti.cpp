#include <stdio.h>

int main(){
	int cont=0,sentinella = -1,somma =0, voto;
	float media;
	printf("Inserisci un voto (-1 se hai finito): ");
	scanf("%d", &voto);
	while(voto!=-1){
		somma=somma+voto;
		cont++;
		printf("Inserisci un voto (-1 se hai finito): ");
		scanf("%d", &voto); /* importnate perchè evito che -1 si aggiunga alla somma*/
	}
	if(cont==0)
		printf("Media non valida");
	else{
		media= somma/cont;
		printf("la media è %f", media);
	}

	return 0;
}