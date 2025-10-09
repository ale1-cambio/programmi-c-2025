#include <stdio.h>
#define N 4
int main(){
	int MatQuadrata [N][N]={1,2,5,8,
							2,3,7,0,
							5,7,1,9,
							8,0,9,4};
	int i=0,k,sim=1;
	/*for(i=0;i<N;i++){
		for(k=0;k<N;k++){
			if(i!=k && MatQuadrata[i][k] != MatQuadrata[k][i]){
				sim=0;
			}
		}
	}Ok, ma migliorabile: è necessario controllare tutte le posizioni con tutte le posizioni, faccio doppio dei controlli: se elem1,2 è diverso da 2,1, è inutile opcntrollare se il elem2,1.
	*/
	for(i=0;i<N && sim;i++){
		for(k=i+1;k<N && sim;k++){
			if(MatQuadrata[i][k] != MatQuadrata[k][i]){
				sim=0;
			}
		}
	}
	if(sim){
		printf("Simmetrica");
	}else{
		printf("Non simmetrica");
	}
}