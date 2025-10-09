#include <stdio.h>

int main(){
	int n1,n2,div;
	do{
		printf("Inserisci il primo numero: ");
		scanf("%d",&n1);
		printf("Inserisci il secondo numero: ");
		scanf("%d",&n2);
	}while(n1<=0 && n2<= 0);
	if(n1<n2){
		div=n1;
	}else if(n1>=n2){
		div=n2;
	}
	while(div>=1){
		if(n1%div==0 && n2%div==0){
			printf("%d ", div);
		}
		div--;
	}
}