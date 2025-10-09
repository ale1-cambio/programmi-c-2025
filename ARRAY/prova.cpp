#include <stdio.h>
#define SIZE 10
int main(){
	int n[SIZE] ={19,3,15,7,11,9,13,5,17,1},i,temp;
	int k=9;
	for(i=0;i<SIZE/2;i++){
		temp=n[i];
		n[i]=n[k];
		n[k]=temp;
		k--;
	}
	for(i=0;i<SIZE;i++){
		printf("%d ",n[i]);
	}
}