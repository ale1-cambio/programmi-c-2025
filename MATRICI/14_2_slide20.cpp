/*Si scriva un programma che chiede all’utente di riempire una matrice NxN (con N costante globale predefinita) 
di interi e stampa la lunghezza della sequenza più lunga orizzontale, verticale o diagonale di numeri uguali
 consecutivi.
*/

#include <stdio.h>
#define N 4

int main(){
	int A[N][N]={1,1,2,4,
				2,5,2,3,
				1,2,5,3,
				1,1,8,3				
	};
	int i,j, cont,orizz_ref=0,verticale_ref=0,diagonale_ref;
	//controllo verticali
	for(j=0;j<N;j++){
		cont=1;
		for(i=0;i<N-1;i++){
			if(A[i][j]==A[i+1][j]){
				cont++;
			}
		}
		if(cont>verticale_ref){
			verticale_ref=cont;
		}
	}
	
	//controllo orizzontali
	for(i=0;i<N;i++){
		cont=1;
		for(j=0;j<N-1;j++){
			if(A[i][j]==A[i][j+1]){
				cont++;
			}
		}
		if(cont>orizz_ref){
			orizz_ref=cont;
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	//diagonali
	
	
	printf("Il massimo numero di elementi lungo la verticale e': %d\n",verticale_ref);
	printf("Il massimo numero di elementi lungo l'orizzontale e': %d",orizz_ref);

	
}