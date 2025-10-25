/*Scrivere una funzione che riceve in input un array di N elementi e restituisce una struct composta da un 
intero e da un array. La funzione inserisce nell’array contenuto nella struct gli elementi pari dell’array che 
riceve in input e assegna all’intero contenuto nella struct il numero di elementi copiati. 
typedef struct {int v[N];int cont} arrayConCont*/
#include <stdio.h>
#define N 5
typedef struct {int v[N];int cont;}arrayConCont;
arrayConCont conta(int V[N]);
void conta_bis(int V[N], arrayConCont *ab);
int main(){
	int a[N]={8,2,3,4,5},i;
	arrayConCont x;
	/*x = conta(a);
	for(i=0;i<x.cont;i++){
		printf("%d ", x.v[i]);
	}
	printf("Numero elementi: %d", x.cont);*/
	conta_bis(a,*x);
	for(i=0;i<x->cont;i++){
		printf("%d ", x->v[i]);
	}
	printf("Numero elementi: %d", x->cont);
}
arrayConCont conta(int V[N]){
	int i,k;
	arrayConCont a;
	for(i=0;i<N;i++){
		if(V[i]%2==0){
			a.v[k]=V[i];
			k++;
		}
	}
	a.cont=k;
	return a;
}

void conta_bis(int V[N], arrayConCont *ab){
	int i,k;
	for(i=0;i<N;i++){
		if(V[i]%2==0){
			ab->v[k]=V[i];
			k++;
		}
	}
	ab->cont=k;
}
