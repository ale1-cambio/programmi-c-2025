#include <stdio.h>
#define N 5
int quantiUgualiConNestedLoop(int A[][N],int B[][N], int k);
int quantiUgualiConMergeScan(int A[][N],int B[][N], int k);

int main() {
    int A[N][N] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int B[N][N] = {
        {5, 4, 3, 2, 1},       // stessi numeri della prima riga di A ma invertiti
        {6, 7, 8, 0, 0},       // primi tre uguali alla seconda riga di A
        {11, 12, 0, 0, 0},     // primi due uguali alla terza riga di A
        {0, 17, 0, 19, 0},     // alcuni uguali alla quarta riga di A
        {21, 0, 23, 0, 25}     // alcuni uguali alla quinta riga di A
    };

  //  printf("%d",quantiUgualiConNestedLoop(A,B,2));
	printf("%d",quantiUgualiConMergeScan(A,B,3));
    return 0;
}

int quantiUgualiConNestedLoop(int A[][N],int B[][N], int k){
	int i=0,j=0,cont=0,cont_bis=0;
	while(cont_bis<k){
		if(A[i][j%N]==B[i][j%N]){
			cont++;
		}
		j++;
		cont_bis++;
		if(j%N==0){
			i++;
		}
	}
	return cont;
	
}

int quantiUgualiConMergeScan(int A[][N],int B[][N], int k){
	int i,j,cont=0,num=0;
	for(i=0;i<N && num<k;i++){
		for(j=0;j<N && num<k;j++){
			num++;
			if(A[i][j]==B[i][j]){
				cont++;
			}
		}
	}
	return cont;
}



