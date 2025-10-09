#include <stdio.h>
#define MAXSIZE 10
int main(){
	int V[MAXSIZE]={4,5,9,8,7,1,2,6,3,7},i,min,tutti=1;
	min=V[0];
	for (i=1;i<MAXSIZE;i++){
		if(V[i]<min){
			min=V[i];
		}
	}/*devono esserci tutti numeri da min a min più N*/
	for(i=0;i<MAXSIZE;i++){
		if(!(V[i]>= min && V[i]<=min+MAXSIZE-1)){
			tutti=0;
		}
	}
	if(tutti==0){
		printf("Non sono presenti tutti");
	}else{
		printf("Sono presenti tutti");
	}
}