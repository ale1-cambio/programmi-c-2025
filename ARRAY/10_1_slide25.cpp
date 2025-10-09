#include <stdio.h>

int main(){
	int N=10, v1[N],i=0,val,j;
	printf("Inserisci un numero: ");
	scanf("%d", &val);
	do{
		v1[i]=val;
		scanf("%d", &val);
		i++;
	}while(i<9);
	for(i=0;i<10;i++){
		printf("%d",v1[i]);
		for(j=0;j<=v1[i];j++){
			printf("*");
		}
		printf("\n");
	}
}