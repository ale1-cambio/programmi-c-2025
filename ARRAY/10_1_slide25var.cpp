#include <stdio.h>
#define SIZE 10
int main(){
	int v1[SIZE]={19, 3,15,7,11,9,13,5,17,1},i=0,j,max;
	/*printf("%s%8s%17s\n\n", "Element", "Value", "Histogram");
	for(i=0;i<SIZE;i++){
		printf("%d%12d            ",i,v1[i]);
		for(j=1;j<=v1[i];j++){
			printf("*");
		}
		printf("\n");
	}*/
	max=v1[i];
	for(i=1;i<SIZE;i++){
		if(v1[i]>max){
			max=v1[i];
		}
	}
	for(j=max;j>0;j--){
		for(i=0;i<SIZE;i++){
			if(v1[i]>=j){
				printf("   *");
			}else{
				printf("    ");
			}
		}
		printf("\n");
	}
	for(i=0;i<SIZE;i++){
		printf("%4d",v1[i]);
	}
	printf("\n");
	for(i=0;i<SIZE;i++){
		printf("%4d",i);
	}
	return 0;
}