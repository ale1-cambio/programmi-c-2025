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
#define N 3

int main(){
	int A[N][N],num=1,i,j,i_ref=N-1,j_ref=((N-1)/2);
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			A[i][j]=0;
		}
	}
	i=0;
	j=0;
	A[i_ref][j_ref]=num;
	i_ref=N-1;
	j_ref=(N-1)/2;
	for(num=2;num<=(N*N);num++){
	/*	i_ref++;
		j_ref++;
		if(i_ref==N){
			i_ref=0;
		}
		if(j_ref==N){
			j_ref=0;
		}
		if(A[i_ref][j_ref]==0){
			A[i_ref][j_ref]=num;
		}else{
			A[i_ref-1][j_ref]=num;
		}*/
		i=i_ref;
		j=j_ref;
		i++;
		j++;
		if(i==N){
			i=0;
		}
		if(j==N){
			j=0;
		}
		if(A[i][j]==0){
			A[i][j]=num;
		}else{
			if(i_ref-1<0){
				for(int k=0;k<N;k++){
					if(A[N-1][k]==0){
						A[N-1][k]==num;
						i=N-1;
						j=k;
						break;
					}
				}
			}else{
				for(int k=0; k<N;k++){
					if(A[i_ref-1][k]==0){
						A[i_ref-1][k]=num;
						i=i_ref-1;
						j=k;
						break;
					}
				}
			}
			
			
		}
		i_ref=i;
		j_ref=j;
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d   ",A[i][j]);
		}
		printf("\n");
	}
}