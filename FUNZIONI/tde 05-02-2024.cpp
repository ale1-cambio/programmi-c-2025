#include <stdio.h>
#define N 8

/*Si scriva in C la funzione colonneMassime che riceve in ingresso una matrice M contenente valori interi 
(e eventuali altri parametri) e cerca la colonna contenente la coppia di elementi di prodotto massimo. La funzione 
colonneMassime riporta al chiamante il numero di colonne aventi prodotto massimo e i loro indici. Nel caso in cui ci 
fossero più colonne contenenti coppie di elementi con prodotto uguale al massimo, si dovranno restituire tutte le colonne. 
Si ipotizzi che il numero di colonne della matrice sia fisso e uguale a N (#define N 8), mentre il numero di righe della 
matrice possa variare da invocazione ad invocazione della funzione.

Prima di scrivere la funzione colonneMassime si implementi una funzione ausiliaria maxProdColonna per calcolare il prodotto 
massimo tra le coppie di elementi in una colonna, in modo da facilitare lo sviluppo e l'interpretazione del codice.

 Si noti che nel file .c seguente vi sono diverse matrici ed è richiesto che le due funzioni diano risultati corretti per tutte
  queste. E' richiesto invocare la funzione colonneMassime su tutte queste matrici, stampando i risultati ottenuti nel main e 
  solo nel main con tutte le matrici.
Con le matrici nel file verrà stampato come output:
 
Trovati 3 colonne: 0 6 7
 Trovati 1 colonne: 7
 Trovati 1 colonne: 3
 Trovati 3 colonne: 3 4 5*/

typedef struct{
	int quali[N];
	int quanti[N];
}Valori;

typedef struct{
	int val[];
	int num;
}Ris;
int maxProdColonna(int M[][N], int num_righe, int colonna){
	int risultato=1;
	int i;
	for(i=0;i<num_righe;i++){
		risultato *= M[i][colonna];
	}
	return risultato;
}

Valori calcoloColonne(int M[][N],int num_righe){
	int i=0,max_rif=0,max;
	Valori colonne;
	for(i=0;i<N;i++){
		colonne.quanti[i]=0;
	}
	for(i=0;i<N;i++){
		colonne.quanti[i]=maxProdColonna(M,num_righe,i);
		colonne.quali[i]=i;
	}
	return colonne;
}

Ris colonneMassime(int M[][N],int num_righe){
	Ris risultato;
	Valori val;
	val=calcoloColonne(M,num_righe);
	int i,k=0;
	int max=0;
	for(i=0;i<N;i++){
		if(val.quanti[i]>max){
			max=val.quanti[i];
		}
	}
	printf("%d \n",max);
	for(i=0;i<N;i++){
		if(val.quanti[i]>=max){
			printf("colonna %d ha valore: %d\n",i,val.quanti[i]);
			risultato.val[k]=i;
			risultato.num++;
			k++;
		}
	}
	return risultato;
}
int main() {
		int M1[8][N] = {
        {1, 2, 3, 4, 5, 6, 7, 8},
        {8, 7, 6, 5, 1, 3, 2, 1},
        {2, 3, 4, 5, 6, 7, 8, 9},
        {9, 8, 7, 6, 5, 4, 3, 2},
        {1, 3, 5, 7, 9, 7, 5, 3},
        {3, 0, 4, 1, 5, 9, 2, 6},
        {6, 2, 9, 5, 1, 4, 9, 3},
        {3, 5, 7, 9, 7, 5, 3, 1}
    };


	int M2[4][N] = {
        {1, 2, 3, 4, 5, 6, 7, 8},
        {8, 7, 6, 5, 1, 3, 2, 1},
        {2, 3, 4, 5, 6, 7, 8, 9},
        {3, 5, 7, 9, 7, 5, 3, 1}
    };


	int M3[2][N] = {
        {1, 2, 3, 4, 5, 6, 7, 8},
        {3, 5, 7, 9, 7, 5, 3, 1}
    };
    
	int M4[4][N] = {
        {8, 7, 6, 5, 1, 3, 2, 1},
        {1, 3, 5, 7, 9, 7, 5, 3},
        {3, 0, 4, 1, 5, 9, 2, 6},
        {3, 5, 7, 9, 7, 5, 3, 1}
    };
    int i;
	Ris risul;
	risul=colonneMassime(M1,8);
	printf("Trovati %d colonne: ",risul.num);
	for(i=0;i<risul.num;i++){
		printf("%d ",risul.val[i]);
	}
	/*printf("\n");
	risul=colonneMassime(M2,4);
	printf("Trovati %d colonne: ",risul.num);
	for(i=0;i<risul.num;i++){
		printf("%d ",risul.val[i]);
	}
	printf("\n");
	risul=colonneMassime(M3,2);
	printf("Trovati %d colonne: ",risul.num);
	for(i=0;i<risul.num;i++){
		printf("%d ",risul.val[i]);
	}
	printf("\n");
	risul=colonneMassime(M4,4);
	printf("Trovati %d colonne: ",risul.num);
	for(i=0;i<risul.num;i++){
		printf("%d ",risul.val[i]);
	}*/
	


    //invocare la funzione e stampare le coppie i 4 casi
    
	return 0;
}
