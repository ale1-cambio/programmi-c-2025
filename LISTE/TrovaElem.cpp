#include <stdio.h>
typedef struct El{
	int a;
	struct El * next;
}Lista;

Lista lis;
int trova(Lista lis, int k){
	if(lis==NULL){
		return 0;
	}
	if(lis->elem==k){
		return 1;
	}
	return trova(lis->next,k);
}