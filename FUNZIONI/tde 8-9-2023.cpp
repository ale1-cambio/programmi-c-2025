/*Si scriva una funzione trovaFrequenti che riceve in ingresso un vettore di N interi e una matrice di interi NxN 
(dove N è una costante definita con #define).
La funzione trovaFrequenti conta, per ogni elemento del vettore, quante volte il valoreè presente nella matrice. La funzione 
trovaFrequenti trova i tre valori del vettore che sonopresenti il maggior numero di volte (si supponga pure che non esistano
elementi presenti lo stesso numero di volte) e li restituisce al main insieme al corrispettivo numero di occorrenze.
Precisiamo che il main deve invocare la trovaFrequenti ed il risultato deve essere restituitonei modi opportuni, siete liberi 
di usare parametri, vettori o strutture dati appositamente definite.Il main stampa il risultato.
Si parta dal file:https://www.dropbox.com/scl/fi/viknihv3t1ty3th0swk10/MatriciTesto.c?rlkey=aw8kjj3el17bxlljn06an949p&dl=0
*/

#include <stdio.h>
#define N 10


#include <stdio.h>
typedef struct{
	int vettore[N];
	int num[N];
}Aus;
typedef struct{
	int vettore[3];
	int num[3];
}Ris;
Ris trovaFrequenti(int vett[], int matr[][N],int len){
	int i,j,k;
	Aus ausiliario;
	for(i=0;i<len;i++){
		ausiliario.vettore[i]=vett[i];
		ausiliario.num[i]=0;
	}
	Ris ris;
	for(k=0;k<len;k++){
		for(i=0;i<len;i++){
			for(j=0;j<N;j++){
				if(matr[i][j]==ausiliario.vettore[k]){
					ausiliario.num[k]++;
				}
			}
		}
	}
	int flag=0,temp=0;
	while(flag!=1){
		flag=1;
		for(i=1;i<len;i++){
			if(ausiliario.num[i]>ausiliario.num[i-1]){
				flag=0;
				temp=ausiliario.num[i];
				ausiliario.num[i]=ausiliario.num[i-1];
				ausiliario.num[i-1]=temp;
				temp=ausiliario.vettore[i];
				ausiliario.vettore[i]=ausiliario.vettore[i-1];
				ausiliario.vettore[i-1]=temp;
			}
		}
	}
	for(i=0;i<3;i++){
		ris.vettore[i]=ausiliario.vettore[i];
		ris.num[i]=ausiliario.num[i];

	}
	return ris;
}

int main(){
	int i,k;
	int vettore[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


    int M1[N][N] = {
        {1, 1, 3, 3, 5, 6, 8, 8, 8, 10},
        {2, 3, 3, 1, 5, 8, 6, 8, 8, 10},
        {10, 9, 3, 2, 5, 6, 7, 8, 1, 4},
        {4, 5, 5, 8, 8, 9, 10, 1, 2, 3},
        {7, 6, 5, 4, 3, 2, 1, 0, 8, 8},
        {2, 4, 5, 8, 10, 1, 3, 5, 7, 9},
        {10, 8, 5, 4, 2, 9, 8, 5, 3, 1},
        {1, 3, 2, 5, 4, 5, 5, 8, 8, 0},
        {0, 1, 2, 3, 4, 5, 6, 8, 8, 8},
        {9, 7, 5, 3, 1, 2, 4, 6, 8, 10}
    };


    int M2[N][N] = {
        {6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
        {6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
        {7, 7, 1, 2, 2, 3, 3, 3, 10, 10},
        {7, 7, 5, 5, 5, 5, 5, 10, 7, 10},
        {6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 4},
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
        {6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
        {8, 8, 8, 8, 8, 8, 8, 8, 8, 8}
    };


    int M3[N][N] = {
        {5, 5, 6, 6, 6, 6, 6, 5, 5, 5},
        {1, 2, 2, 2, 9, 3, 4, 4, 4, 4},
        {10, 9, 8, 7, 3, 4, 4, 2, 1, 6},
        {6, 7, 8, 9, 10, 1, 2, 3, 4, 4},
        {10, 10, 10, 10, 10, 1, 1, 1, 10, 10},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5}
    };
	printf("M1\n");
	for(i=0;i<N;i++){for(k=0;k<N;k++){printf("%d ",M1[i][k]);}printf("\n");}
	printf("\nM2\n");
	for(i=0;i<N;i++){for(k=0;k<N;k++){printf("%d ",M2[i][k]);}printf("\n");}
	printf("\nM3\n");
	for(i=0;i<N;i++){for(k=0;k<N;k++){printf("%d ",M3[i][k]);}printf("\n");}
	
	/*SCRIVERE QUI LE CHIAMATE DI FUNZIONI E I COMANDI DI STAMPA*/
	Ris risultato;
	risultato=trovaFrequenti(vettore,M3,N);
	for(i=0;i<3;i++){
		printf("numero %d trovato %d volte\n",risultato.vettore[i],risultato.num[i]);
	}
	return 0;
}


