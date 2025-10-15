#include <stdio.h>
#define N 4
#define M 5
int main(){
	int A[N][M]={4,-1,7,0,0,
				-4,-9,-1,0,0,
				2,8,16,1,4,
				-1,7,5,2,5},i,j,somma,claque=1,cont;
	for(i=0;i<N-1;i++){
		for(j=0;j<M-1;j++){
			if(A[i][j]+A[i+1][j+1]==A[i+1][j]+A[i][j+1]){
				cont++;
			}
		}
	}
	printf("Il numero di clauqe sono %d",cont);
}