#include <stdio.h>
#define N 3
int main(){
	int A[N][N],B[N][N],i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("Inserisci un numero in posizione (%d, %d): ",i,j);
			scanf("%d",&A[i][j]);
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(A[i][j]%2==0){
				B[i][j]=A[i][j]/2;
			}else{
				B[i][j]=A[i][j];			
			}
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d ",B[i][j]);
		}
		printf("\n");
	}
}