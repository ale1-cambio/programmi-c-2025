#include <stdio.h>
#define N 5

int main(){
	int M[N][N],val,i,k,j,l,cegia=0;
	for(i=0;i<(N);i++){
		for(k=0;k<N;k++){
			do{
				cegia=0;
				printf("Inserisci un numero: ");
				scanf("%d", &M[i][k]);
				for(j=0;j<i;j++){
						for(l=0;l<N;l++){
							if(M[i][k]==M[j][l]){
								printf("Gia messo!");
								cegia=1;
								//i--;
							//	j--;
							}
						}
				}for(l=0;l<k;l++){
					if(M[i][k]==M[i][l]){
						printf("Gia messo!");	
						cegia=1;
								//i--;
								//j--;
					}
				}
						
					
				
			}while(cegia);
		}
	}
	return 0;
	
}