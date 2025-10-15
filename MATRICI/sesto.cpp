#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 4
//Si scriva un programma che costruisce una matrice di caratteri generati casualmente 
// e stampa il carattere presente più volte nella matrice.
int main() {
	int A[N][N], i, j, cont,val;
	srand(time(0));
	int max = 0, max_val = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			A[i][j] = rand() % 15 + 1;
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	for (i=0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cont = 0;
			val = A[i][j];
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < N; l++) {
					if (A[k][l] == val) {
						cont++;
					}
				}
			}
			if (cont > max) {
				max = cont;
				max_val = val;
			}
		}
	}
	if(max==1){
		printf("Tutti i valori si presentano una sola volta.");
	}else{
		printf("Il numero che si ripete di piu' e' %d, che si ripete %d volte", max_val, max);
	}
}