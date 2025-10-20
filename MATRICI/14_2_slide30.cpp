/*Si realizzi un programma in linguaggio C che, data una matrice NxM di interi, trovi l’elemento per cui la media
 degli elementi ad esso adiacenti sia massima. Si stampino le coordinate di tale elemento ed il suo valore.
Si considerino come adiacenti a ciascun elemento i quattro elementi nelle quattro direzioni cardinali. Si tratti 
inoltre l’ultima colonna come adiacente alla prima, e l’ultima riga come adiacente alla prima. Si supponga che N ed 
M possano variare tra 1 e 100. I valori di N ed M, così come i valori degli elementi della matrice, vengono acquisiti 
da tastiera.
*/

int main(){
	int N,M,i,j,somma;
	float media,max_media=-1;
	int max_i,max_j;
	do{
		printf("Inserisci un numero (da 1 a 100):");
		scanf("%d", &N);
	}while(N<1 || N>100);
	do{
		printf("Inserisci un numero (da 1 a 100):");
		scanf("%d", &M);
	}while(M<1 || M>100);
	int A[N][M];
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("Inserisci un numero: ");
			scanf("%d",&A[i][j]);
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			if(N==1 && M==1){
				media=0;
			}else if(N==1){
				if(j==0){
					somma=A[i][j+1]+A[i][M-1];
					media=somma/2.0;
				}else if(j==M-1){
					somma=A[i][0]+A[i][j-1];
					media=somma/2.0;
				}else{
					somma=A[i][j+1]+A[i][j-1];
					media=somma/2.0;
				}
			}else if(M==1){
				if(i==0){
					somma=A[i+1][j]+A[N-1][j];
					media=somma/2.0;
				}else if(i==N-1){
					somma=A[i-1][j]+A[0][j];
					media=somma/2.0;
				}else{
					somma=A[i-1][j]+A[i+1][j];
					media=somma/2.0;
				}
			}else{
				
			}
		}


	}
}