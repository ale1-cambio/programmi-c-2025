#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef int MATR[N][N];

typedef struct {
	MATR x; int L;
}EXT;

void f(MATR A, EST * V){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(i==j){
				V->x[i][j]=A[i][j]-1;
			}else{
				V->x[i][j]=A[i][j]
			}
		}
	}
}

int main(){
	
}