#include <stdio.h>

int main(){
	int num,div=1,contatore_divisori_numero=0,divisori_riferimento=0,cont=0;
	num=1;
	while(cont<=20){
		while(div<=num){
			if(num%div==0){
				contatore_divisori_numero++;
			}
			div++;
		}
		if(contatore_divisori_numero>divisori_riferimento){
			divisori_riferimento=contatore_divisori_numero;
			cont++;
			printf("%d ",num);
		}
		num++;
		div=1;
		contatore_divisori_numero=0;
	}
		
}