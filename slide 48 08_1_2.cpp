#include <stdio.h>

int main(){
	int num, sentinella=0,cont=0, sequenza;
	printf("Inserisci num: ");
	scanf("%d",&num);
	printf("Inserisci sequenza (0 per terminare): ");
	do{
		scanf("%d", &sequenza);
		if(sequenza%2==0 && num%sequenza==0)
			cont++;
	}while(sequenza!=sentinella);
		
	printf("%d",cont);
	
	return 0;
}