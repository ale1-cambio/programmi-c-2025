#include <stdio.h>
#define N 5
int copiaPari(int A[],int B[]);

int main(){
	int A[N]={2,8,7,5,8};
	int B[N]={0,4,9,8,1};
	printf("%d",copiaPari(A,B));
}

int copiaPari(int A[N],int B[N]){
	int i=0,k=0;
	for(i=0;i<N;i++){
		B[i]=0;
	}
	for(i=0;i<N;i++){
		if(A[i]%2==0){
			B[k]=A[i];
			k++;
		}
	}
	return k;
}
