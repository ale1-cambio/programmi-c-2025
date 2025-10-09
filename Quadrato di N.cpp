#include <stdio.h>

int main(){
	int N, quadrato=0,x=1, cont=0;
	printf("inserisci numero: "); /* scriviamo quadrato somma di primi N dispari*/
	scanf("%d", &N);
	while(cont<N){
		quadrato = quadrato +x;
		x = x+2;
		cont++;
	}
	printf("Quadrato è %d", quadrato);
	
	
	return 0;
}
