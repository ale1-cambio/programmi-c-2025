#include <stdio.h>
int main ( ) {
	int base, altezza;
	float area;
	printf ("Area del triangolo.\n\n"); 
	do{
		printf ("Inserisci Base: ");
		scanf ("%d", &base);

	}while(base < 0);
	do{
		printf ("Inserisci Altezza: ");
		scanf ("%d", &altezza);
	}while(altezza < 0);
	area=(float)(base*altezza)/2;
	printf("%f",area);

	return 0;
}