/*
Si implementi una funzione che riceve
in input una matrice NxM di float.
Definito “picco” un numero circondato
in tutte le otto posizioni intorno solo da
numeri inferiori alla sua metà, la funzione
conta il numero di “picchi” della matrice
(attenzione a gestire correttamente gli
elementi ai bordi della matrice).
*/

#include <stdio.h>
#define N 5
#define M 3
typedef struct{
	float posizioni[8];
}Pos;

Pos esploraAdiacenti(float m[N][M], int i, int j){
	int k,h,cont=0;
	Pos immagazzino;
	for(k=i-1;k<=i+1;k++){
		for(h=j-1;h<=j+1;h++){
			if(!(k==i && h==j) &&(k>=0 && k<N) && (h>=0 && h<N)){
				immagazzino.posizioni[cont]=m[k][h];
				cont++;
			}else{
				immagazzino.posizioni[cont]=0.0;
				cont++;
			}
			
		}
	}
	return immagazzino;
}

int numPicchi(float m[N][M]){
	int i,j,l,cont_picchi=0,cont=0;
	Pos check;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			check = esploraAdiacenti(m,i,j);
			for(l=0;l<8;l++){
				if(check.posizioni[l] < (m[i][j])/2){
					cont++;
				}
			}
			if(cont==8){
				cont_picchi++;
			}
			cont=0;
		}
	}
	return cont_picchi;
}
int main(){
	float c[N][M]={7,5,3,
				   1,5,2,
				   6,6,6,
				   51,2,3,
				   3,4,100};
	int k;
	k=numPicchi(c);
	printf("i picchi sono: %d",k);
	return 0;
}