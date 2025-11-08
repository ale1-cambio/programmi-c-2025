/*Scrivere una funzione f che riceve un array di interi e la sua lunghezza e restituisce 1 se uno degli 
elementi contenuti è divisore proprio di tutti gli altri, 0 altrimenti*/

#include <stdio.h>
#define N 5


int f(int v[], int k);

int main(){
	int c[N]={8,2,6,4,10};
	int k=f(c,N);
	printf("%d",k);
	return 0;
}

int f(int v[], int k){
	int i,j,flag;
	for(i=0;i<k;i++){
		flag=1;
		for(j=0;j<k;j++){
			if(i!=j && v[j]%v[i]!=0){
				flag=0;
				break;
			}
		}
		if (flag==1){
			return 1;
		}
	}
	return 0;
}