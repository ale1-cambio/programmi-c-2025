#include <stdio.h>

int main(){
	int N,V[10],R[10],i,j=0,k;
	for(i=0;i<10;i++){
		printf("Inserisci un numero: ");
		scanf("%d", &N);
		if(N>=0 && N<=1023){
			V[j]=N;
			j++;
		}
	}
	for(i=0;i<10;i++){
		for(k=9;k>=0;k--){
			R[k]=V[i]%2;
			V[i]=V[i]/2;
			
		}
		for(k=0;k<10;k++){
			printf("%d ", R[k]);
		}
		printf("\n");
	}

		
	
}