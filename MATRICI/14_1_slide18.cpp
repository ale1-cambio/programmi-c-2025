#include <stdio.h>
#define R 2
#define C 3

int main(){
	int M[R][C], val, i=0,k,j;
		for(i=0;i<R;i++){
			for(k=0;k<C;k++){
				printf("Inserisci un valore: ");
				scanf("%d",&M[i][k]);
				if(M[i][k]%2!=0){
					k--; //in questo modo torno indietro e risciverò nella casella in cui ho messo un dispari
				}
			}
		}
		
	
}