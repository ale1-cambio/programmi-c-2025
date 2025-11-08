#include <stdio.h>
int fatt(int n);

int main(){
	int ris;
	ris =fatt(2);
	printf("%d",ris);
	return 0;
}


int fatt(int n){
	if(n==0){
		return 1;
	}
	return n*fatt(n-1);// sto chiamando la stessa funzione passandogli il dato più piccolo
}