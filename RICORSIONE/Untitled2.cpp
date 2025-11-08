#include <stdio.h>
#include <stdlib.h>

/*Scrivere una funzione confronta che riceve due matrici M1 e M2 quadrate NxN di interi (ed eventuali altri parametri utili) 
e le scorre in parallelo confrontando le caselle in posizione corrispondente. La funzione deve riempire una terza matrice M3 
sempre NxN mettendo in ogni casella 0 se i due elementi corrispondenti delle altre due matrici sono uguali, 1 se l'elemento di
 M1 è più grande, -1 se l'elemento di M2 è più grande. La funzione inoltre riporta al chiamante un vettore di dimensione N 
 contenente la somma delle colonne di M3. M3 e il vettore devono essere riempiti nella funzione confronta e stampate nel main.


Con le matrici date il risultato sarà:
Matrice M3 (risultato confronto):
  0   1   0  -1
  1   0  -1   1
  1  -1   0  -1
  0  -1   1   1

Somma delle colonne di M3:
  2  -1   0   0*/

#define N 4  // Dimensione della matrice NxN
typedef struct{
	int M3[N][N];
	int V[N];
}Ris;


Ris confronta(int M1[N][N],int M2[N][N]){
	int i,j,somma=0;
	Ris risultato;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(M1[i][j]==M2[i][j]){
				risultato.M3[i][j]=0;
			}else if(M1[i][j]<M2[i][j]){
				risultato.M3[i][j]=-1;
			}else{
				risultato.M3[i][j]=1;
			}
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			somma += risultato.M3[j][i];
		}
		risultato.V[i]=somma;
		somma=0;
	}
	return risultato;
}

int main() {
    int M1[N][N] = {
        {3, 5, 2, 8},
        {6, 1, 4, 7},
        {9, 2, 5, 3},
        {4, 7, 6, 1}
    };
    int M2[N][N] = {
        {3, 2, 2, 9},
        {5, 1, 7, 6},
        {8, 3, 5, 4},
        {4, 8, 5, 0}
    };
  
    Ris risult;
    risult=confronta(M1,M2);
    printf("\n");
    int i,j;
    for(i=0;i<N;i++){
    	for(j=0;j<N;j++){
    		printf("%d ",risult.M3[i][j]);
		}
		printf("\n");
	}
	printf("Somma delle colonne di M3:\n");
	for(i=0;i<N;i++){
		printf("%d ",risult.V[i]);
	}
    return 0;
}
