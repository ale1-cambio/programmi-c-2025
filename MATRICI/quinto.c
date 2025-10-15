#include <stdio.h>
#define N 6
/*Si scriva un programma che costruisce una matrice di interi e stampa 
il massimo K per cui è vero che la matrice contiene almeno un quadrato KxK 
di caselle di valore identico.
*/

int main() {
	int M[N][N] = { 1,12,0,7,8,8,
				 4,3,5,5,5,4,
				 3,8,5,5,5,4,
				 6,9,5,5,5,9,
				 0,1,2,3,4,4,
				 6,7,8,9,4,4 };
	int i, j, cont, cont_ref;
	for (i = 0; i < N; i++) {
			for(j=0;j<N;j++){
				if(M[i][j]==M[i][j+1] && M[i][j]==M[i+1][j] && M[i][j]==M[i+1][j+1]){
					cont=2;
					cont_ref = cont;
					while(M[i][j]==M[i+cont-1][j+cont-1] && M[i][j]==M[i+cont-1][j] && M[i][j]==M[i][j+cont-1]){
						cont++;
						cont_ref= cont;
						if(i+cont-1>=N || j+cont-1>=N) break;
					}
				}
		}
	}

	printf("Quadrato di lato: %d",cont_ref);

	return 0;
}
