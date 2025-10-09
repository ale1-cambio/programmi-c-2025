#include <stdio.h>
#include <string.h>

int main(){
	int a = 2;
	char amac[] = "amac";
	amac[strlen(amac)]=amac[a];
	printf("%s\n",amac);
	printf("%d\n", strlen(amac));
}