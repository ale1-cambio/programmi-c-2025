#include <stdio.h>
#define MAXSIZE 10

int main(){
	int val, V[MAXSIZE],i=0,j;
	printf("Inserisci un numero: ");
	do{
		scanf("%d",&val);
		V[i]=val;
		i++;
	}while(i<MAXSIZE);
	for(i=0;i<MAXSIZE;i++){
		for(j=i+1;j<MAXSIZE;j++){
			if(V[j]*2==V[i]){
				printf("%d %d",V[i],V[j]);
				printf(" / ");
			}
		}
		
	}
}
