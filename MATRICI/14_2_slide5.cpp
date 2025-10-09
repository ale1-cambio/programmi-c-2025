#include <stdio.h>
#define N 50

int main(){
	int M[N][N], i, cont_neg=0;
	for(i=0;i<N && cont_neg<2;i++){
		printf("Inserisci un numero: ");
		scanf("%d", &M[0][i]);
		if(M[0][i]<0){
			cont_neg++;
		}
	}
}