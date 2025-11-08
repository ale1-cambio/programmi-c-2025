#include <stdio.h>

/*Si scriva una funzione verificaCorrispondenza che prende in ingresso un vettore v di dimensione N e una matrice M di 
dimensione Nx4 e che verifica che ogni elemento di v corrisponde alla somma di una riga di M (non necessariamente il primo 
elemento è la somma della prima riga o il secondo elemento della seconda riga…). 
Se la proprietà è verificata la funzione verificaCorrispondenza restituisce 1, altrimenti 0. Nella funzione da implementare non
 è ammesso usare istruzioni di stampa, il risultato restituito sarà usato nel main per decidere cosa stampare. Si supponga per 
 semplicità che non esistano due righe con la stessa somma. Si noti che (come anche negli esempi nel main) le dimensioni di 
 vettori e matrici non sono tutti uguali, ma le matrici hanno sempre esattamente 4 colonne.*/

void stampa(int N, int v[], int M[][4]);

int verificaCorrispondenza(int N, int v[],int M[][4]);

int main() {
    int v1[] = {14, 6, 10, 8};
    int M1[][4] = {{1, 2, 3, 4},
                   {0, 1, 2, 3},
                   {4, 3, 6, 1},
                   {2, 2, 2, 2}};
    int v2[] = {4, 6, 8};
    int M2[][4] = {{1, 1, 1, 1},
                   {0, 2, 2, 2},
                   {1, 2, 3, 2}};
    int v3[] = {10, 20};
    int M3[][4] = {{1, 2, 3, 4},
                   {2, 4, 6, 8}};
    int v4[] = {3, 5, 9};
    int M4[][4] = {{1, 1, 1, 1},
                   {0, 2, 2, 2},
                   {1, 2, 7, 2}};
    int v5[] = {10, 6, 16, 8};
    int M5[][4] = {{1, 2, 3, 4},
                   {0, 1, 2, 3},
                   {5, 3, 2, 1},
                   {2, 2, 2, 2}};

	/*Risultato 1: Corrisponde
	Risultato 2: Corrisponde
	Risultato 3: Corrisponde
	Risultato 4: Non corrisponde
	Risultato 5: Non corrisponde*/
	stampa(4,v1,M1);               
    stampa(3,v2,M2);               
    stampa(2,v3,M3);               
    stampa(3,v4,M4);               
    stampa(4,v5,M5);               
    int check= verificaCorrispondenza(3,v4,M4);
    if (check==1){
    	printf("Risultato: Corrisponde");
	}else{
		printf("Risultato: Non corrisponde");
	}
    return 0;
}


void stampa(int N, int v[], int M[][4]) {
	int i,j;
	printf("Vettore\n");
    for (i = 0; i < N; i++) {
    	printf("%d ",v[i]);
    }
    printf("\nMatrice\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ",M[i][j]);
        }
		printf("\n");
    }
    printf("\n\n");
}


int verificaCorrispondenza(int N, int v[],int M[][4]){
	int i,k,j,l,somma=0,cont=0;
		for(i=0;i<N;i++){
			for(j=0;j<4;j++){
				somma=somma+M[i][j];
			}
			for(l=0;l<N;l++){
				if(somma==v[l]){
					cont++;
				}
			}
			somma=0;
		}somma=0;

	if(cont==N){
		return 1;
	}
	return 0;
}
