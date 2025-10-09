#include <stdio.h>

int main() {
	int i,j=0;
	int v1[10]= {5,6,7,89,568,68,657,989,96,98};
	int v2[10];
	for(i=0; i<10; i++) {
		if(v1[i]%2 == 0) {
			v2[j] = v1[i];
			j++;
		}
	}/* quando esco dal ciclo j ha valore esattamente come numeri elementi copiati nel vettore v2*/
	for(i=0; i<j; i++) {
		printf("%d ", v2[i]);
	}
}