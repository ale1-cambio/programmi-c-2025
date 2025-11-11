#include <stdio.h>


#define N 8  // Numero di colonne (per matrici 8x8 o superiori)
/*Si scriva la funzione analizzaMatrice che riceve in ingresso
 - una matrice M di dimensioni NxN 
 - un intero k  
 e che restituisce 
 - il numero di coppie di interi che si trovano in posizioni "vicine" e che hanno prodotto uguale a k.
 
Si invochi la funzione analizzaMatrice nel main e si stampi il risultato.
 
Si scriva una funzione analizzaMatrice2 che, oltre a restituire il numero di coppie che soddisfano le condizioni sopra, popola un vettore 
con tutte le coppie individuate e lo riporta al chiamante. Si invochi la funzione analizzaMatrice2 nel main e si stampino le coppie 
identificate.
 
 
Si consideri che:
 - Occorre definire una semplice struttura dati per contenere le coppie di interi identificate.
 - Per semplicità, le coppie in posizioni "vicine" sono solo
   - un elemento ed il suo adiacente nella colonna di destra.
   - un elemento ed il suo adiacente nella nella riga sottostante. 
 - Per semplicità, le coppie che soddisfano il requisito non siano più di cento.
 - N è nota a priori e definita con #define N 8.
 - Non è possibile stampare nella funzione analizzaMatrice2
 
 */

int analizzaMatrice(int M[][N], int k);
typedef struct{
	int x;
	int y;
}Coordinate;
typedef struct{
	Coordinate vett[100];
	int num;	
}Ris; 

Ris analizzaMatrice2(int M[][N], int k);

int main() {
	int k;
    int M1[N][N] = {
        {1, 2, 3, 4, 50, 6, 7, 8},
        {8, 7, 6, 50, 1, 3, 2, 1},
        {2, 3, 4, 5, 6, 7, 8, 9},
        {9, 8, 7, 6, 5, 4, 3, 2},
        {1, 3, 5, 7, 9, 7, 5, 3},
        {3, 0, 4, 1, 5, 9, 2, 6},
        {6, 2, 90, 5, 1, 4, 9, 3},
        {3, 5, 7, 9, 7, 5, 3, 1}
    };
	int i=0;
	Ris risult;
    //casi di test: invocare la funzione e stampare le coppie per questi 4 casi
    k = 4;
    
    printf("coppie trovate per k = %d: %d\n",k,analizzaMatrice(M1,k));
    risult=analizzaMatrice2(M1,k);
    for(i=0;i<risult.num;i++){
    	printf("(%d, %d)\n",risult.vett[i].x,risult.vett[i].y);
	}

	k = 35;
    printf("\ncoppie trovate per k = %d: %d\n",k,analizzaMatrice(M1,k));
	risult=analizzaMatrice2(M1,k);
	for(i=0;i<risult.num;i++){
    	printf("(%d, %d)\n",risult.vett[i].x,risult.vett[i].y);
	}
	k = 200;
    printf("\ncoppie trovate per k = %d: %d\n",k,analizzaMatrice(M1,k));
   	risult=analizzaMatrice2(M1,k);
    for(i=0;i<risult.num;i++){
    	printf("(%d, %d)\n",risult.vett[i].x,risult.vett[i].y);
	}
	k = 90;
    printf("\ncoppie trovate per k = %d: %d\n",k,analizzaMatrice(M1,k));
  
    risult=analizzaMatrice2(M1,k);
    for(i=0;i<risult.num;i++){
    	printf("(%d, %d)\n",risult.vett[i].x,risult.vett[i].y);
	}
	return 0;
}


int analizzaMatrice(int M[][N], int k){
	int cont=0,i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(j+1<N){
				if(M[i][j]*M[i][j+1]==k){
					cont++;
				}
			}
			if(i+1<N){
				if(M[i][j]*M[i+1][j]==k){
					cont++;
				}	
			}
		}
	}
	return cont;
}

Ris analizzaMatrice2(int M[][N], int k){
	int i,j,cont=0,n=0;
	Ris risultato;
	risultato.num=analizzaMatrice(M,k);
	for(i=0;i<risultato.num;i++){
		risultato.vett[i].x=0;
		risultato.vett[i].y=0;
	}
	for(i=0;i<N && n<=risultato.num;i++){
		for(j=0;j<N && n<=risultato.num;j++){
			if(j+1<N){
				if(M[i][j]*M[i][j+1]==k){
					risultato.vett[n].x=M[i][j];
					risultato.vett[n].y=M[i][j+1];
					n++;
				}
			}
			if(i+1<N){
				if(M[i][j]*M[i+1][j]==k){
					risultato.vett[n].x=M[i][j];
					risultato.vett[n].y=M[i+1][j];
					n++;
				}	
			}
		}
	}
	return risultato;
}