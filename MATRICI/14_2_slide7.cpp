#include <stdio.h>
#define R 5
#define C 5

int main(){
	int  A[R][C],B[R][C], i=0, j=0,k=0,t=0;
	for(i=0;i<R;i++){
		for (j=0;j<C;j++){
			printf("Inserisci valore nella posizione (%d,%d): ",i,j);
			scanf("%d", &A[i][j]);
		}
	}
	for(i=0;i<R;i++){
		for(j=0;j<C;j++){
			if((A[i][j]%2)!=0){
				B[k][t]=A[i][j];
				t++;
				if(t==C){
					t=0;
					k++;
				}
			}
		}

	}
	printf("Matrice B:\n");
	for(i=0;i<=k;i++){
		if(i<k){
			for(j=0;j<C;j++){
				printf("%d ", B[i][j]);
			}
		}else if(i==k){
			for(j=0;j<=t;j++){
				printf("%d ", B[i][j]);
			}
			for(j=t+1;j<C;j++){
				B[i][j]=0;
				printf("%d ", B[i][j]);
			}
			printf("\n");
			for(i=k+1;i<R;i++){
				for(j=0;j<C;j++){
					B[i][j]=0;
					printf("%d ", B[i][j]);
				}
				printf("\n");
			}
		}
		
		printf("\n");
		
	}
	return 0;
}