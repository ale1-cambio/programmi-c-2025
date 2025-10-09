#include <stdio.h>

int main(){
	int num, sentinella=-1,cont=0;
	printf("Inserisci sequenza di numeri (-1 per terminare)");
	do{
		scanf("%d", &num);
		if(num>1 && ((num%5==0) || (num%7==0) || (num%3==0)))
			cont++;
	}while(num!=sentinella);
		
	printf("%d",cont);
	
	return 0;
}