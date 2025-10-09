#include <stdio.h>
int main(){
	int a, i=0; 
	float somma = 0;
	float media;
	/*while(i<10){
		printf("Inserisci voto: ");
		scanf("%d", &a);
		somma = somma + a;
		++i;
	}*/
	for(i=0;i<4;i++){
		printf("Inserisci voto: ");
		scanf("%d", &a);
		somma =somma+a;
	}
	media = (float)somma/i; /* somma trattato come un float*/
	printf("La media e': %f", media);
	return 0;
}