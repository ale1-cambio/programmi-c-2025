#include <stdio.h>
#define MAXSIZE 15

int main(){
	int A[MAXSIZE]={1, 2 , 5, 9 , 8, 7 , 15, 6, 3, 22, 45, 15, 13, 85, 56}, B[5],cont,i=0,j,presenti=1;
	while(i<5){
		printf("Inserisci un numero: ");
		scanf("%d", &B[i]);
		i++;
	}
	for(j=0;j<5;j++){
		for(i=0;i<MAXSIZE;i++){
			if(B[j]==A[i]){
				cont++;
				break;
			}
		}
	}
	if(cont%5==0){
		presenti=1;
		printf("TUtti gli elementi di B sono presenti in A");
	}else{
		presenti = 0;
		printf("Non tutti gli elementi di B sono presenti in A");
	}
	
	
}