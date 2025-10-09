#include <stdio.h>

int main(){
	int num, div,i=2,j;
	do{
		printf("Inserisci un umero positivi: ");
		scanf("%d", &num);
	}while(num<=0);
	while(i<=num){
		j=0;
		
		while(num%i==0){
			num=num/i;
			j++;
		}
		if(j>=0){
			printf("%d divide %d volte ", i,j);
		}
		
		i++;
	}
}