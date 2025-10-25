/*Si consideri questa struttura che caratterizza lo stato di una partita a tris:
 
typedef struct {
    int turno;    // 1 se è il turno del giocatore 1, 2 se è il turno del giocatore 2
    int griglia[3][3];    // contiene tutti 0 all'inizializzazione, 1 e 2 per i giocatori 1 e 2
}
 
Si scriva un programma che inizializzi una griglia vuota e che contenga le seguenti funzioni:
- un menù che a turno faccia scegliere ai giocatori una mossa (tramite coordinate) e ne controlli la validità
- una funzione che inserisce un nuovo valore nella griglia
- una funzione per visualizzare la griglia attuale (con X e O per i giocatori 1 e 2)
- una funzione che controlla se la partita è finita (tris o caselle piene)
*/
#include <stdio.h>

typedef struct {
    int turno;    // 1 se è il turno del giocatore 1, 2 se è il turno del giocatore 2
    int griglia[3][3];    // contiene tutti 0 all'inizializzazione, 1 e 2 per i giocatori 1 e 2
} partita;

/*void menu(int *x, int *y){
	do {
		printf("inserisci una mossa tramite coordinate: (x): ");
		scanf("%d", x);
	} while (*x < 0 || *x > 2);
	do {
		printf("inserisci una mossa tramite coordinate: (y): ");
		scanf("%d", y);
	} while (*y < 0 || *y > 2);
}
void InserisciVal(*M[][],int x, int y,int giocatore){
	if(giocatore ==1){
		*M[x][y]=1;
	}else{
		*M[x][y]=2;
	}
	
}

void visualizza(M[][]){
	int i,k;
	for(i=0;i<3;i++){
		for(k=0;k<3;k++){
			if(M[i][k]==1){
				printf("1 ");
			}else if(M[i][k]==2){
				printf("O ");
			}else{
				printf("%d ",M[i][k]);
			}
		}
		printf("\n");
	}
}
int finita(M[][]){
	int i,k,finita=1;
	for(i=0;i<3 &&finita;i++){
		if(M[i][0]!=M[i][1]){
			finita=0;
		}
		if(M[0][i]!=M[1][i]){
			finita=0;
		}
		for(k=0;k<3;k++){
			if(M[i][k]=="0"){
				finita=0;
			}
		}
	}
	if((M[0][0]!=M[1][1])||(M[0][2]!=M[1][1])){
		finita=0;
	}
	if(finita){
		printf("La partita è finita!");
	}
	else{
		printf("la partita Non è finita");
	}
	return finita;
}

int main(){
	partita partita;
	partita.turno=1;
	int i,k;
	for(i=0;i<3;i++){
		for(k=0;k<3;k++){
			partita.griglia[i][k]=0;
		}
	}
	int x, y;
	menu(&x, &y);
	InserisciVal(partita.griglia, x, y, partita.turno);
	visualizza(partita.griglia);
	finita(partita.griglia);
	
	return 0;
}
	