#include <stdio.h>
#define N 3

int main(){
	int A[N][N],B[N][N],i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("Inserisci un numero progressivo in (%d, %d): ",i,j);
			scanf("%d",&A[i][j]);
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(i!=j){
				B[j][i]=A[i][j]+A[j][i];
				B[i][j]=0;
			}else{
				B[i][j]=A[i][j];
			}
		}
	}
	printf("\n\n"); s
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d ",B[i][j]);
		}
		printf("\n");
	}
}