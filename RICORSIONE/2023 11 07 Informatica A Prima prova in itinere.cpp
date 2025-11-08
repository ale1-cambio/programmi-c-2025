#include <stdio.h>
#include <string.h>
#define N 8
#define M 9

/*Si sviluppi un programma per simulare alcune operazioni di un gioco in cui bisogna trovare alcune parole all'interno di una 
matrice di caratteri. Per semplicità si assuma che le parole possano solo comparire in orizzontale (solo scritte da sinistra a 
destra) o verticale (solo scritte dall'alto verso il basso) all'interno della matrice.
trovate il main.c e la definizione ed inizializzazione di due matrici, una contenente la griglia di gioco (G) e un'altra (P) 
contenente su ogni riga una parola come una stringa ben formata.

Si chiede di:
- scrivere una funzione cercaParola che, ricevuta in ingresso una matrice di caratteri e una stringa ben formata, cerca nella
 matrice la parola contenuta nella stringa e restituisce un'opportuna struttura dati contenente le coordinate della prima
  lettera e se è stata trovata in verticale o orizzontale.
- scrivere una funzione gioca che riceve in ingresso le due matrici G e P e, sfruttando la funzione definita nel punto
 precedente, trova tutte le parole di P che compaiono in G e sostituisce le lettere delle parole trovate in G con un '*'.
  Per semplicità si supponga che le parole da trovare non si intreccino, quindi non vi siano lettere sovrapposte.  
- Infine si scriva una funzione parolaRimasta che riceve in ingresso le due matrici G e P e, sfruttando le funzioni
 definite nel punto precedente, restituisce al main una stringa contenente tutte le lettere che non sono state sostituite 
 da un '*' in G (perchè corrispondenti a parole di P). Per popolare la parola delle lettere rimaste ci si muova per righe, 
 partendo dall'elemento in alto a sinistra fino a quello in basso a destra.

N.B. tutte le funzioni possono prendere in input variabili aggiuntive che sono necessarie / utili alla soluzione.*/
typedef struct{
	int x;
	int y;
	char direzione[12];
}Punto;
int checkOrizz(char G[][N],int i,int j, char s[]){
	int k,flag=0;
	for(k=0;k<strlen(s) && j<N;k++){
		if(G[i][j]==s[k]){
			flag=1;
			j++;
		}else{
			flag=0;
			return flag;
		}
	}
	return 1;
}
int checkVer(char G[][N],int i,int j, char s[]){
	int k,flag=0;
	for(k=0;k<strlen(s) && i<N;k++){
		if(G[i][j]==s[k]){
			flag=1;
			i++;
		}else{
			flag=0;
			return flag;
		}
	}
	return 1;
}
int checkVer(char c, char s[]);
Punto cercaParola(char G[][N], char s1[]){
	int i,j,check_or=0,check_ver=0;
	Punto coordinata;
	strcpy(coordinata.direzione,"");
	char prima;
	prima=s1[0];
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(G[i][j]==prima){
				check_or=checkOrizz(G,i,j,s1);
				check_ver=checkVer(G,i,j,s1);
			}
			if(check_or==1){
				coordinata.x=i;
				coordinata.y=j;
				strcpy(coordinata.direzione,"orizzontale");
				return coordinata;
			}else if(check_ver==1){
				coordinata.x=i;
				coordinata.y=j;
				strcpy(coordinata.direzione,"verticale");
				return coordinata;
			}
		}
	}
	if (check_or == 0 && check_ver==0){
		coordinata.x=-1;
		coordinata.y=-1;
		strcpy(coordinata.direzione,"NON TROVATA");
		return coordinata;
	}
}
void gioca(char G[][N],char P[][M]){
	char parola[M];
	int i,j,k=0;
	Punto punto;
	for(j=0;j<M;j++){
		for(i=0;i<M;i++){
			strcpy(parola,P[j]);
			k++;
		}
		k=0;
		parola[i]='\0';
		punto =cercaParola(G,parola);
		if(strcmp(punto.direzione,"orizzontale")==0){
			for(i=0;i<strlen(parola);i++){
				G[punto.x][punto.y+i]='*';
			}
		
		}else if(strcmp(punto.direzione,"verticale")==0){
			for(i=0;i<strlen(parola);i++){
				G[punto.x+i][punto.y]='*';
			}
			
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%c ",G[i][j]);
		}
		printf("\n");
	}
}
void parolaRimasta(char G[][N],char P[][M]){
	int i ,j,cont=0;
	char parola[10];
	gioca(G,P);
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(G[i][j]!='*'){
				parola[cont++]=G[i][j];
			}
		}
	}
	parola[cont]='\0';
	printf("La parola finale rimasta e': %s",parola);
}
int main(){
	int i,k; 
    char G[N][N]={'B','R','I','S','A','T','A','B',
                    'A','A','R','A','N','C','I','A',
                    'N','C','I','P','O','L','L','A',
                    'A','V','I','O','L','I','N','O',
                    'N','R','A','T','O','R','T','A',
                    'A','V','O','L','A','N','T','E',
                    'D','I','S','C','O','R','S','O',
                    'A','N','A','T','R','A','V','O'};
    char P[M][M]={'R','I','S','A','T','A','\0','\0','\0',
              'A','R','A','N','C','I','A','\0','\0',
              'B','A','N','A','N','A','\0','\0','\0',
              'C','I','P','O','L','L','A','\0','\0',
              'V','I','O','L','I','N','O','\0','\0',
              'T','O','R','T','A','\0','\0','\0','\0',
              'V','O','L','A','N','T','E','\0','\0',
              'D','I','S','C','O','R','S','O','\0',
              'A','N','A','T','R','A','\0','\0','\0'};
                    
    printf("Matrice caratteri\n");                
    for(i=0;i<N;i++){
    	for(k=0;k<N;k++){
    		printf("%c ",G[i][k]);
		}
		printf("\n");
	}         
    printf("\nParole\n");                
    for(i=0;i<M;i++){
    	printf("%s",P[i]);
		printf("\n");
	}         
	/*SCRIVERE QUI LE CHIAMATE DI FUNZIONI E I COMANDI DI STAMPA*/
	Punto coordinate;
	//char parola[N]="OSRO";
	//coordinate=cercaParola(G,parola);
	//printf("%d (x), %d (y), %s",coordinate.x,coordinate.y,coordinate.direzione);
	//gioca(G,P);
	parolaRimasta(G,P);
	return 0;
}


