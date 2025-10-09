#include <stdio.h>

int main(){
	int N,i=1,val;
	printf("Inserisci un numero: ");
	scanf("%d",&N);
	val=N;
	while(val>0){
		val = val-i;
		i++;	
	}
	if(val==0)
			printf("Somma di numeri %d consecutivi",i-1);
	else
		printf("No");
	return 0;
}