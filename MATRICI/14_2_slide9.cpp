#include <stdio.h>
#define N 3
/*Si scriva un programma che acquisisce una matrice quadrata NxN (con N costante predefinita con l’struzione #define N
 …) di interi positivi M ed un array A di dimensione N. La funzione restituisce 1 se almeno uno degli elementi di
  A è divisore di tutti gli elementi di una qualsiasi riga di M.
*/
int main(){
	int M[N][N], A[N],i,j,cont=1,tutti=0;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("Inserisci un numero positivo in posizione (%d,%d): ",i,j);
			scanf("%d", &M[i][j]);
			if(M[i][j]<1){
				j--;
			}
		}
	}
	for(i=0;i<N;i++){
		printf("Inserisci un numero positivo nell'array: ");
		scanf("%d", &A[i]);
		if(A[i]<1){
				i--;
		}
	}
	for(int k=0;k<N;k++){
		for(i=0;i<N && !tutti;i++){
			for(j=0;j<N;j++){
				if(A[k]%M[i][j]){
					cont++;
				}else{
					break;
				}
			}
			if(cont==N){
				tutti=1;
			}
			cont=0;
		}
	}
	if(tutti==1){
		printf("%d",tutti);
	}else{
		printf("0");
	}
}