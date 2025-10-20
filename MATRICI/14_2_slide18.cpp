#define N 3
#define M 3
#define P 4
#define Q 4
#include <stdio.h>
//Se A una matrice m×n e B una matrice p×q, allora il loro prodotto di Kronecker A x B è una matrice mxp×nxq definita a blocchi nel modo seguente:

int main(){
    int A[M][N]={{1,2,3},
                 {4,5,6},
                 {7,8,9}},
        B[P][Q]={{9,8,7,6},
                 {5,4,3,2},
                 {1,0,-1,-2},
                 {-3,-4,-5,-6}},
        C[M*P][N*Q],i,j,k;
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            for(k=0;k<P;k++){
                for(int t=0;t<Q;t++){
                    C[i*P+k][j*Q+t]=A[i][j]*B[k][t];
                }
            }
        }
    }
    for(i=0;i<M*P;i++){
        for(j=0;j<N*Q;j++){
            printf("%4d ",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}