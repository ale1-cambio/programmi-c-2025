/*Si scriva un programma in linguaggio C che stampi sullo standard output il contenuto di un quadrato magico di
dimensione n, con n dispari. Un quadrato magico di ordine n contiene i primi n numeri naturali ( 1, 2, 3, …., n2 )
 disposti in modo tale che la somma dei numeri su ogni riga, su ogni colonna e sulle due diagonali principali sia
 sempre la stessa.
Es: n = 3
	4 9 2       0 0 0       0 0 2       0 0 2       4 0 2       4 0 2       4 0 2       4 0 2       4 0 2       4 9 2
	3 5 7       0 0 0       0 0 0       3 0 0       3 0 0       3 5 0       3 5 0       3 5 7       3 5 7       3 5 7
	8 1 6       0 1 0       0 1 0       0 1 0       0 1 0       0 1 0       0 1 6       0 1 6       8 1 6       8 1 6
Esiste una regola molto semplice per percorrere la matrice disponendo i numeri interi in ordine crescente.
ù Partendo col posizionare un 1 nella posizione centrale sull’ultima riga, si percorre la matrice incrementando
di una unità il numero di riga e il numero di colonna dell’elemento attuale, avendo cura di considerare i bordi
opposti della matrice come adiacenti. Se durante questa operazione si individua una cella vuota si scrive il numero
 successivo; altrimenti, il numero successivo, viene posizionato nella cella avente riga immediatamente superiore a
  quella dell’ultimo numero inserito.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Inserisci la dimensione dispari del quadrato magico (N > 1): ");
    scanf("%d", &N);

    if (N < 3 || N % 2 == 0) {
        printf("Errore: N deve essere un numero dispari maggiore di 1.\n");
        return 1;
    }

    int** M = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        M[i] = (int*)calloc(N, sizeof(int));

    int row = N - 1, col = N / 2;
    for (int num = 1; num <= N * N; num++) {
        M[row][col] = num;
        int next_row = (row + 1) % N;
        int next_col = (col + 1) % N;
        if (M[next_row][next_col] != 0) {
            row = (row - 1 + N) % N;
            // col remains the same
        }
        else {
            row = next_row;
            col = next_col;
        }
    }

    printf("\nQuadrato magico di ordine %d:\n", N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%4d", M[i][j]);
        printf("\n");
    }

    for (int i = 0; i < N; i++)
        free(M[i]);
    free(M);

    return 0;
}