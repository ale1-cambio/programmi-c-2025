/*Si definisce percorso in una matrice una sequenza di lunghezza nota di coordinate (x,y) in una matrice in cui x indica la riga (contando da 0) e y la colonna (sempre contando da 0). Si considerino le seguente strutture dati:
	#define N 100
	typedef struct {int x,y;} punto;
	typedef struct {int numCoordinate, 
                                     punto coordinate[N]} percorso;
Nel tipo percorso il campo numCoordinate dice quante caselle del vettore sono effettivamente utilizzate e quindi di quanti passi si compone il percorso, mentre il vettore coordinate contiene le effettive coordinate (notate che l'array è sovradimensionato e sarà quindi usato solo da 0 a numCoordinate-1)
Il file 
https://www.dropbox.com/s/be6rv6bv90caqud/testoConAstrazione.cpp?dl=0
contiene la definizione dei tipi dati e l'allocazione di due percorsi (per1 inizializzato con 8 coordinate e per2, non inizializzato) e di una matrice mat di caratteri 8x8. Si noti che il percorso non è valido rispetto alla matrice perché contiene due punti con coordinate negative e un punto con riga=8 (che non esiste).
*/
#include <stdio.h>


#define N 100
#define M 8


typedef struct {int x,y;} punto; 
typedef struct {int numeroCoordinate;
                punto coordinate[N];} percorso; 


//scrivere qui i prototipi delle funzioni richieste


int main(){
	int i;
	percorso per1={8,{{0,0},{0,-4},{2,6},{4,5},{3,1},{7,2},{8,2},{2,-4}}};
	percorso per2;
	char mat[M][M]={'B','R','S','P','E','E','F','A',
                    'Y','V','K','W','F','H','H','W',
                    'J','C','S','I','E','R','R','F',
                    'F','V','C','P','L','N','B','Q',
                    'P','C','D','F','Y','A','O','P',
                    'C','G','W','S','C','Q','O','O',
                    'D','H','H','S','L','L','U','I',
                    'X','R','O','L','E','N','T','Y'};
	
	//scrivere qui le chiamate a funzione
	for(i=0;i<per1.numeroCoordinate;i++){
		printf("(%d,%d)",per1.coordinate[i].x,per1.coordinate[i].y);
	}
	for(i=0;i<per1.numeroCoordinate;i++){
		if((per1.coordinate[i].x < 0 || per1.coordinate[i].x >7) || (per1.coordinate[i].y < 0 || per1.coordinate[i].y >7)){
			
		}
	}
}


//scrivere qui le funzioni richieste
