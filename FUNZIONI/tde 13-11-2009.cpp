/*Implementare una funzione C per il lancio di dadi. 
La funzione prenda in ingresso il numero di facce del dado, e il numero di lanci che si vuole effettuare. La funzione simula i 
lanci del dado e stampa a video quante volte è uscita ciascuna faccia del dado.  Si faccia inoltre in modo che la stampa risulti 
ordinata per numero di volte che è uscita una faccia in senso crescente.
Ad esempio, dopo 5 lanci con un dado a 6 facce in cui sono usciti i numeri (1, 1, 5, 4, 6), si stampi a video:
	La faccia 4 è uscita 1 volta
	La faccia 5 è uscita 1 volta
	La faccia 6 è uscita 1 volte
	La faccia 1 è uscita 2 volte
 Attenzione, devono essere riportati sia il numero della faccia che il numero di volte che è uscita.
Si supponga esista e dunque si faccia uso della funzione 
	int rand(int inf, int sup);
	che restituisce un numero intero casuale compreso tra inf e sup.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void dado(int facce, int lanci){
	int r,i;
	int dado [facce];
	for(i=0;i<facce;i++){
		dado[i]=0;
	}
	srand(time(0));
	for(i=0;i<lanci;i++){
		r=rand()%(1,6)+1;
		printf("%d ",r);
		dado[r-1] +=1;
	}
	for(i=0;i<facce;i++){
		if(dado[i]!=0){
			printf("\nla faccia %d e' uscita %d volte",i+1,dado[i]);
			printf("\n");
		}
	}
	
}
int main(){
	dado(6,5);
}