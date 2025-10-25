/*Scrivere una funzione che riceve in input una matrice di interi di dimensione N*N e un punto così definito
	typedef struct {int x; int y;} punto
	La funzione deve restituire il numero di multipli dell’elemento della matrice di cui sono state fornite le
	 coordinate.
*/
#include <stdio.h>
#define N 3
typedef struct {int x; int y;} punto;
int multipli(int M[N][N],punto punt);

int main(){
	int M[N][N]={1,3,4,
		5,16,1,
		2,2,5};
	punto punt={1,1};
	printf("%d",multipli(M,punt));
}

int multipli(int M[N][N],punto punt){
	int a,mult=0,i;
	a=M[punt.x][punt.y];
	for(i=1;i<=a;i++){
		if(a%i==0){
			mult++;
		}
	}
	return mult;
}