#include <stdio.h>
#define N 5
int f(int a[N]){
    int i,temp,ordine=1,prod=1,B[N];
    for(i=0;i<N-1;i++){
        prod=prod*a[i];
    }
    for(i=0;i<N;i++){
        B[N-1-i]=a[i];
    }
    printf("Prodotto: %d\n", prod);
    printf("Array B: ");
    for(i=0;i<N;i++){
        printf("%d ",B[i]);
    }
    printf("\n");
    return prod,B[N];

}
int main(){
    int A[N],i;
    for(i=0;i<N;i++){
        printf("Inserisci un numero: ");
        scanf("%d",&A[i]);
    }
    f(A);
    return 0;

}