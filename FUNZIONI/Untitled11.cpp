#include <stdio.h>
#include <stdlib.h>
void somma1(int a){
	a=a+1;
}


int main(){
	int a=5;
	somma1(a);
	printf("%d",a);
}