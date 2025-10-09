#include <stdio.h>

int main(){
	int v1[10]={1, 2 , 3, 4 ,5 , 6,7,8,9,8},i,j;
	int tutti=1;
	for(i=0;i<10 && tutti;i++){
		for(j=i+1;j<10 && tutti;j++){
			if(v1[i]==v1[j]){
				tutti = 0;
			}
		}
	}
	
		printf("%d",tutti);
	
	return 0;
}