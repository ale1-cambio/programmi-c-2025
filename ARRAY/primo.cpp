#include <stdio.h>

int main(){
	char carattere, V1[5];
	int i=0,ordine=1;
	do{
		printf("Inserisci un carattere: ");
		scanf("%c", &carattere);
		fflush(stdin);
		if(carattere < 'a' || carattere > 'z'){
			i--;
		}else{
			V1[i]=carattere;
			i++;
		}
	}while(i<5);
	for(i=0;i<4;i++){
		if(V1[i]>V1[i+1]){
			ordine=0;
		}
	}
	if(ordine==1){
		printf("I caratteri inseriti sono in ordine alfabetico.");
	}else{
		printf("I caratteri inseriti non sono in ordine alfabetico.");
	}
}
