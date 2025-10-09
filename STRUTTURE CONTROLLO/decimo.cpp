
//	for(i=0;i<N;i++){
		/*if(i==0 || i ==N-1){
			for(j=0;j<=N-1;j++){
				printf("%d ",N);
			}
		}else{
			for(j=0;j<N;j++){
				if(j==0 || j==N-1){
					printf("%d ",N);
				}else if(j<=(N/2)){
					printf("%d ",N-j);
				}else{
					printf("%d ",j);
				}
			}
			
		}
		printf("\n");*/
		/*for(i=0;i<N;i++){
			if(i==0 || i==N-1){
				for(j=0;j<N;j++){
					printf("%d ", N);
				}
			}else{
				for(j=0;j<N;j++){
					printf("%d ", N-j);
				}
			}
			
			printf("\n");
		}*/
#include <stdio.h>

int main() {
    int n,i, valore,dim;
    printf("Inserisci un numero da 1 a 9: ");
    scanf("%d", &n);

    if (n < 1 || n > 9) {
        printf("Numero non valido.\n");
        return 0;
    }
	dim = 2 * n - 1;  // dimensione del quadrato

    for (i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            int distanza = i;
            if (j < distanza){
            	distanza = j;
			} 
            if (dim - 1 - i < distanza){
            	distanza = dim - 1 - i;
			} 
            if (dim - 1 - j < distanza){
            	distanza = dim - 1 - j;
			} 

            valore = n - distanza;
            printf("%d ", valore);
        }
        printf("\n");
    }

    return 0;
}
	
