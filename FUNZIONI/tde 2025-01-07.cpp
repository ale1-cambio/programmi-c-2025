/*
Tavolo M[3][3] = {{{2, 100}, {3, 150}, {4, 200}},
                             {{2,  80}, {4, 180}, {3, 120}},
                             {{4, 250}, {2,  90}, {3, 140}}};

in cui al tavolo (0,0) erano sedute due persone che hanno speso 100 euro, al tavolo (0,1) erano sedute tre persone che
 hanno speso 150 euro, ...

Si implementi una funzione “tavoliPiccoli” che riceve in input la matrice M rappresentante il ristorante, più eventuali
 variabili aggiuntive per la corretta gestione della matrice, e restituisce al chiamante i valori degli indici 
 corrispondenti al tavolo con il minor numero di commensali. Qualora ci fossero due tavoli con lo stesso numero di 
 commensali, la funzione restituisce gli indici del tavolo che ha speso di più. Il chiamante deve stampare a schermo la
  posizione del tavolo riportato dalla funzione. Nell'esempio i tavoli con meno persone sono i tre tavoli con due 
  persone, tra di essi quello in cui si è speso di più è quello con 100 euro spesi.

Si implementi una funzione “speseMedie” che prende in input la matrice M, più eventuali variabili aggiuntive per la 
corretta gestione della matrice, e che riporta al chiamante un array med contenente le medie dei totali spesi dai 
tavoli aventi 2, 3 e 4 commensali. Se in M non è presente un tavolo con un particolare numero dei commensali, il 
corrispettivo elemento di med deve essere zero. Il chiamante deve stampare med riportato dalla funzione. Nel tavolo di
 esempio il risultato sarà [90, 136.67, 210].*/
 
 
#include <stdio.h>


#define N 3


// Definizione del tipo Tavolo
typedef struct {
    int commensali; // Numero di persone sedute al tavolo
    float prezzo;     // Prezzo totale del cibo ordinato dal tavolo
} Tavolo;

typedef struct{
	int x;
	int y;
	float sold;
}Coordinate;



int ricercaMinPersone(Tavolo M[][N]){
	int min_ass,i,j;
	min_ass=M[0][0].commensali;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(M[i][j].commensali<min_ass){
				min_ass=M[i][j].commensali;
			}
		}
	}
	return min_ass;
}

int ricercaMaxPersone(Tavolo M[][N]){
	int max_ass,i,j;
	max_ass=M[0][0].commensali;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(M[i][j].commensali>max_ass){
				max_ass=M[i][j].commensali;
			}
		}
	}
	return max_ass;
}
Coordinate tavoliPiccoli(Tavolo M[][N]){
	int i,j,temp_x,temp_y;
	int primo=1;
	float max_soldi;
	int min;
	min=ricercaMinPersone(M);
	Coordinate coordinate;
	
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(M[i][j].commensali==min){
				if(primo==1){
					coordinate.sold=M[i][j].prezzo;
					coordinate.x=i;
					coordinate.y=j;
					max_soldi=coordinate.sold;
					primo=0;
				}else{
					if(M[i][j].prezzo>max_soldi){
						coordinate.sold=M[i][j].prezzo;
						coordinate.x=i;
						coordinate.y=j;
						//printf("%f soldi spesi in (%d, %d)",coordinate.sold,i,j);
						max_soldi=coordinate.sold;

					}
				}
			}
		}
	}
	return coordinate;
}

void speseMedie(Tavolo M[][N],float medie[]){
	int i,j,k,min,max,temp_min;
	min=ricercaMinPersone(M);
	max=ricercaMaxPersone(M);
	int quanti[max-min]={0};
	temp_min=min;
	for(i=0;i<=max-min;i++){
		quanti[i]=temp_min;
		temp_min++;
	}
	
	float somma_spese=0;
	int cont=0;
	//Tavolo spese[N*N];
	for(k=min;k<=max;k++){
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(M[i][j].commensali==k){
					somma_spese+=M[i][j].prezzo;
					cont++;
				}
			}
		}
		if(somma_spese!=0){
			medie[k]=(float)somma_spese/cont;
		}else{
			medie[k]=0;
		}
		somma_spese=0;
		cont=0;
	}
}


int main() {
    // Matrice di tavoli
    Tavolo M[N][N] = {
        {{2, 100}, {3, 150}, {4, 200}},
        {{2,  80}, {4, 180}, {3, 120}},
        {{4, 250}, {2,  90}, {3, 140}}
    };
	
	Coordinate coor;
	coor=tavoliPiccoli(M);
	printf("Indici del tavolo con meno commensali che ha speso di piu: (%d, %d)\n",coor.x,coor.y);
    // Chiamate alle funzioni
	/*Il programma stamperà
	> Indici del tavolo con meno commensali che ha speso di più: (0, 0)
	> Prezzo medio per 2, 3, 4 commensali: [90, 136.67, 210]*/
	float medie[N*N];
	speseMedie(M,medie);
    // Stampa dei risultati
	int min,max,i;
	min=ricercaMinPersone(M);
	max=ricercaMaxPersone(M);
	printf("[");
	for(i=min;i<=max;i++){
		printf("%f, ",medie[i]);
	}
	printf("]");
    return 0;
}

