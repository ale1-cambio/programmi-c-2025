#include <stdio.h>
#define N 3
int main(){
	int A[N][N]={1,2,3,
				5,2,1,
				9,6,7
	};
	int B[N][N]={5,2,2,
				3,9,8,
				2,1,1
	};
	int C[N][N];
	int i,j,k,t;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			C[i][j]= A[i][j]+B[i][j];
		}
	}
	for(i=0;i<N;i++){
		for(k=0;k<N;k++){
			C[i][k]=0;
			for(int t=0;t<N;t++){
				C[i][k]= C[i][k]+A[i][t]*B[t][k];
			}
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d ",C[i][j]);
		}
		printf("\n");
	}
}