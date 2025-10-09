#include <stdio.h>

int main(){
	int i, cont;
	for (cont=1;cont<=10;cont++){
		for(i=1;i<=10;i++){
			printf("%d ",cont*i);
		}
		printf("\n");	
	}
	return 0;
}