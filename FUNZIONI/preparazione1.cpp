#include <stdio.h>
#include <string.h>

typedef struct{
	char prova[100];
	int punti;
}parziale;

typedef struct{
	parziale primo;
	parziale secondo;
	parziale terzo;
}test;
typedef test gara[5];//5 concorrenti

void stampa(gara g, int lun){
	int i=0,j;
	for(i=0;i<lun;i++){
		printf("%s %d %s %d %s %d ",g[i].primo.prova,g[i].primo.punti,g[i].secondo.prova,g[i].secondo.punti,g[i].terzo.prova,g[i].terzo.punti);
		printf("\n");
	}
}

void calcoloTotale(gara g,int vett[], int len){
	int i=0,j=0,somma=0;
	for(i=0;i<len;i++){
		vett[i] = g[i].primo.punti+g[i].secondo.punti+g[i].terzo.punti;
	}
}
int calcoloSingolo(int i, gara g){
	int somma=0;
	somma = g[i].primo.punti+g[i].secondo.punti+g[i].terzo.punti;
	return somma;
}
int quanti_rimasti(gara g,int len){
	int i=0,n=0,k;
	while(i<len){
		if(g[i].primo.punti+g[i].secondo.punti+g[i].terzo.punti<1000){
			for(k=i;k<len-1;k++){
				g[k]=g[k+1];
			}
			len=len-1;
		}else{
			i++;
		}
	}
	return len;
}

int main(){
	gara g = {
  { {"ProvaA1", 300}, {"ProvaA2", 400}, {"ProvaA3", 350} },
  { {"ProvaB1", 500}, {"ProvaB2", 300}, {"ProvaB3", 250} },
  { {"ProvaC1", 700}, {"ProvaC2", 100}, {"ProvaC3", 300} },
  { {"ProvaD1", 800}, {"ProvaD2", 50},  {"ProvaD3", 80}  },
  { {"ProvaE1", 600}, {"ProvaE2", 300}, {"ProvaE3", 200} }
};

	
	int totali[5];
	int nuovi_n;
//	
	
	calcoloTotale(g,totali,5);
	int i=0;
	for(i=0;i<5;i++){
		printf("concorrente %d: %d\n",i+1,totali[i]);
	}
	printf("quanti rimasti: %d",quanti_rimasti(g,5));
	quanti_rimasti(g,5);
	stampa(g,5);
}