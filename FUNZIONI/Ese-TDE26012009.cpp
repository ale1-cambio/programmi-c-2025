/*
Si progetti e codifichi una funzione C che riceve in ingresso un array a di interi non negativi.
La funzione calcola il numero degli elementi dell’array che godono della seguente proprietà: 
il valore dell’elemento è pari al numero di elementi con valore inferiore considerando 
solo quelli in posizione precedente.
Ad esempio, si consideri il seguente vettore:
1 2 1 3 6 4 1 4 14
In questo caso solo i due numeri in grassetto (il 3 e il 4) 
soddisfano la proprietà descritta. Quindi la funzione restituisce 2.

*/

#include <stdio.h>
#define N 9
 int prop(int V[]);
 
 int main(){
 	int A[N]={1, 2, 1, 3, 6, 4, 1, 4, 14};
 	int b=prop(A);
 	printf("%d",b);
 	return 0;
 }

int prop(int V[]){
	int i,j,cont,cont_bis;
	for (i=1;i<N;i++){
		for(j=i-1;j>=0;j--){
			if(V[j]<V[i]){
				cont++;
			}
			if(cont==V[i] && j==0){
				cont_bis++;
			}
		}
		cont=0;
	}
	return cont_bis;
}