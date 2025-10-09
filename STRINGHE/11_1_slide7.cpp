/* Stringhe e array di caratteri */
#include <stdio.h>
#include <string.h>
int main () {
	char str1[20], str2[] = "string literal";
	int i;
	printf ("\n Enter a string: ");
	scanf ("%s", str1);
	printf ("str1: %s\n str2: %s\n", str1, str2);
	printf ("str1 with spaces is: \n");
	i = 0;
	while(str1[i]!='\0' ){
		printf ("%c ", str1[i]);
		i++;
	}
	printf ("\n");
	return 0;
}
