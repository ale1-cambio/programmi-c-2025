#include <stdio.h>

int main(){
	char val;
	int  contatore;
	printf("Inserisci un carattere: ");
	do{
		scanf("%c", &val);
		if((val!= '#' && (val=='a' || val== 'e' ||val=='i'||val=='o'||val=='u'))){
			contatore++;
		}
	}while(val!='#');
	printf("%d", contatore);
}