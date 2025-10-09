#include <stdio.h>
#define N 4

int main(){
	int M[N][N];
	int i=0,k=0;
	for(i=0;i<N;i++){//per scorrere tutte le righe
		for(k=0;k<N;k++){
			printf("Inserire l'elemento (%d,%d)",i,k);//per riempire caselle di una riga
			scanf("%d",&M[i][k]);
		}
	
	}
	for(i=0;i<N;i++){
		for(k=0;k<N;k++){
			printf("%d ",M[i][k]);
		}
		printf("\n");
	}
	return 0;
}