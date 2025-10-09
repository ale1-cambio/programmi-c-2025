#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int r;
	srand(time(0));
	r=rand()%(50-10)+10;
	printf("Un numero a caso: %d\n",r);
}