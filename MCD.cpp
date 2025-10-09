#include <stdio.h>

int main(){
	int a,b, x, mcd, min;
	printf("Inserisci a: ");
	scanf("%d", &a);
	printf("Inserisci b: ");
	scanf("%d", &b);
	/*if (a<b){
		x=a;
	}else{
		x=b;
	}
	while(!(a%x==0 && b%x==0)){
		--x;

	}
	printf("MCD è %d", x);*/
	/*METODO DI EUCLIDE*/
	while(a != b){
		if (a>b)
			a = a-b;
		else
			b = b-a;
		
	}
	printf("MCD e': %d", a);
	return 0;
}