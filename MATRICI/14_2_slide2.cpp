#include <stdio.h>
/*Scrivere un programma che chiede all’utente di riempire una matrice, la stampa, cerca, 
se esiste, la prima posizione in cui appare lo 0, l’ultima posizione in cui appare lo 0 e la posizione mediana
 in cui appare lo 0 e dice in che posizione sono state trovate. */
#define N 3
int main(){
	int trovato = 0,cont=0;
	int A[N][N]={1,0,3,
				5,0,1,
				9,0,0
	};
	for(int i=0;i<N && !trovato;i++){
		for(int j=0;j<N && !trovato;j++){
			if(A[i][j]==0){
				printf("Il primo zero e' in posizione: %d, %d", i,j);
				trovato=1;
			}
		}
	}
	printf("\n");
	trovato=0;
	for(int i = N-1;i>=0 && !trovato;i--){
		for(int j=N-1;j>=0 && !trovato;j--){
			if(A[i][j]==0){
				printf("l'ultimo' zero e' in posizione: %d, %d", i,j);
				trovato=1;
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(A[i][j]==0){
				cont++;
			}
		}
	}
	printf("\n");
	int mediana = cont/2 + 1;
	cont =0;
	for(int i=0;i<N && cont<mediana;i++){
		for(int j=0;j<N && cont<mediana;j++){
			if(A[i][j]== 0){
				cont++;
				if(cont==mediana){
					printf("Poszione zero mediano: %d, %d", i,j);
				}
			
			}
		}
	}
	return 0;
}