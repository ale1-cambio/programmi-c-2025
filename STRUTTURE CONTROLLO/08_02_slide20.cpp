#include <stdio.h>

int main(){
	int num, sentinella=-1, mult;
	printf("Inserisci un numero: ");
	scanf("%d", &num);
	do{
		if((num%5==0) || (num%3==0) || (num%7==0)){
			mult++;
		}
	scanf("%d", &num);
	}while(num!=sentinella);
	printf("%d", mult);//
}