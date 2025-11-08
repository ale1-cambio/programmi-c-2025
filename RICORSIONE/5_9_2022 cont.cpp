#include<stdio.h>
#define N 20
typedef struct{
	int uno;
	int due;
}Coppia;

typedef struct{
	int piu_grande;
	int indice;
	Coppia coppia_prima;
	Coppia coppia_dopo;
}Ris;


Ris trovaIncrocio(int *V1, int *V2,int dim){
	Ris risultato;
	int i,j,rif;
	if(V1[i]>V2[i]){
		risultato.piu_grande=1;
		for(i=1;i<dim;i++){
			if(V1[i]<V2[i]){
				risultato.indice=i;
				risultato.coppia_dopo.uno=V1[i];
				risultato.coppia_dopo.due=V2[i];
				risultato.coppia_prima.uno=V1[i-1];
				risultato.coppia_prima.due=V2[i-1];
				return risultato;
			}
		}
	}else if(V1[i]<V2[i]){
		risultato.piu_grande=2;
		for(i=1;i<dim;i++){
			if(V1[i]>V2[i]){
				risultato.indice=i;
				risultato.coppia_dopo.uno=V1[i];
				risultato.coppia_dopo.due=V2[i];
				risultato.coppia_prima.uno=V1[i-1];
				risultato.coppia_prima.due=V2[i-1];
				return risultato;
			}
		}
	}//else{
	//	risultato.piu_grande=0;
	//}
	
}

int main(){
    int v1[N] = {1122, 1123, 1177, 1083, 1050, 1010, 919, 993, 1076, 1205, 1325, 1393, 1399};
    int v2[N] =  {1322, 1318, 1316, 1166, 1096, 1112, 1070, 912, 1154, 1294, 1350, 1624, 1782};
    int n = 13; // dimensioni effettive;
    int i;


    printf("\n v1 = [");
    for(i = 0; i < n; i++)
        printf("%d, ", v1[i]);


    printf("]\n v2 = [");
    for(i = 0; i < n; i++)
        printf("%d, ", v2[i]);
    printf("]\n");


    //INVOCARE QUI LA FUNZIONE E STAMPARE SOLO NEL MAIN
    Ris risultato;
    
    risultato=trovaIncrocio(v1,v2,N);
    printf("Incrocio quando V1 prima vale %d e poi %d, mentre V2 prima vale %d e poi %d",risultato.coppia_prima.uno,risultato.coppia_dopo.uno,risultato.coppia_prima.due,risultato.coppia_dopo.due);
    
	printf("\nIncrocio avvenuto all'indice numero %d",risultato.indice);
	printf("\nInizialmente il vettore con valore maggiore e': %d",risultato.piu_grande);
	return 0;


}


