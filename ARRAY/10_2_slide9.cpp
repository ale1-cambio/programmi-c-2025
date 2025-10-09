#include <stdio.h>
#define MAXSIZE 20
int main(){
	int N,val,V[MAXSIZE],i;
	do{
		printf("Inserisci lunghezza del tuo vettore: ");
		scanf("%d",&N);
	}while(N<=0 || N>MAXSIZE);
	for(i=0;i<N;i++){
		printf("inserisci un numero: ");
		scanf("%d", &val);
		V[i]=val;
	}
	for(i=0; i<N;i++){
		printf("%d ", V[i]);
	}
	printf("\n");
	for(i=1;i<N;i++){
		if(V[i-1]%2==0){
			printf("%d ",V[i]);
		}
	}
}