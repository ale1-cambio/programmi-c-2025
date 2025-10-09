#include <stdio.h>

int main(){
	char a,b;
	int valA,valB;
	printf("Inserisci il primo dato: ");
	scanf("%c", &a);
	valA = a;
	fflush(stdin);
	printf("Inserisci il secondo dato: ");
	scanf("%c", &b);
	valB = b;
	fflush(stdin);
	a++;
	while(valA<(valB-1)){
		printf("%c", a);
		valA = a;
		a++;
	}
}