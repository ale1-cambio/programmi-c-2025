#include <stdio.h>
/*Si realizzi un programma che legga da tastiera un valore intero N, compreso tra 1 e 10, e stampi a video un “quadrato di asterischi” di lato N.*/
int main(){
	int N,i,j,k;
	do{
		printf("Inserisci un numero compreso tra 1 e 10: ");
		scanf("%d", &N);
	}while(N<1 || N>10);
	for(i=0;i<N;i++){
		if(i==0 || i==(N-1)){
			for(k=0;k<N;k++){
				printf("*");
			}
		}else{
			for(j=0;j<N;j++){
				if(j==0 || j== (N-1)){
					printf("*");
				}else{
					printf(" ");
				}	
			}
		}
		
		printf("\n");
	}
}