#include <stdio.h>
#define N 4


int main() {
	int M[N][N] = { 1,12,0,7,
					4,3,5,5,
					6,4,3,8,
					7,5,2,4 };
	int r, c,maggiore =1,i;
	do {
		printf("Inserisci un numero tra 0 e %d ", N - 1);
		scanf("%d", &r);
		printf("Inserisci un numero tra 0 e %d ", N - 1);
		scanf("%d", &c);
	} while ((r < 0 || r >= N) || (c < 0 || c >= N));
	
	
	for ( i = 0; i < N && maggiore!=0; i++)
	{
		if (M[r][i] > M[r][c]) {
			maggiore = 0;
		}
	}
	for( i = 0; i < N && maggiore!=0; i++)
	{
		if (M[i][c] > M[r][c]) {
			maggiore = 0;
		}
	}
	if(maggiore == 1)
		printf("Il numero %d in posizione [%d][%d] e' il piu' grande della colonna e il piu' grande della riga", M[r][c], r, c);
	else
		printf("Il numero %d in posizione [%d][%d] non e' il piu' grande della colonna e il piu' grande della riga", M[r][c], r, c);


	return 0;
}
