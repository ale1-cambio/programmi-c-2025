/*4.La FPF Inc. (Fictional Pigs Farm) si dedica da sempre all'allevamento di maialini da palcoscenico più o meno famosi, e conserva i dati dei
 suoi piccoli divi in un vettore (di cui solo una parte è utilizzata, pari a num_maialini: gli elementi di indice da num_maialini a N-1 non 
 sono usati):

typedef struct { int giorno; int mese; int anno; } Data;

typedef struct { char nome[20]; Data datanascita; float peso; int popolarita; } Maialino;

typedef struct { int num_maialini; Maialino pigs[N]; } Allevamento;

I maialini non sono elencati nell'Allevamento in un alcun ordine particolare, ma la ditta necessita di scandirli in ordine di ognuna delle loro 
caratteristiche (cioè in ordine di nome, di data di nascita, di popolarità, e di peso corporeo), a seconda delle diverse necessità applicative 
(rispettivamente: appello nominale, trattamento pensionistico, merchandising, utilizzo culinario qualora la popolarità cali eccessivamente). 
A tal fine, si utilizzano quattro distinti vettori di puntatori, in cui ogni puntatore punta a un maialino specifico. In questo modo si 
rappresentano quattro diversi ordinamenti indipendenti degli elementi di uno stesso insieme (di maiali) senza dover replicare tutti i dati 
ad essi relativi, ma replicando solo i puntatori:

Maialino * ord_alfabetico[N], ord_data[N], ord_pop[N], ord_peso[N];

Si codifichi un programma che costruisca correttamente i quattro vettori di puntatori. Il programma deve dapprima stampare tutti i dati dei 
maialini, nell'ordine in cui si trovano nell'allevamento, poi ordinare i puntatori nei vari vettori, e visualizzare i maialini secondo i
 diversi ordinamenti. Si utilizzi (anche) la funzione   int confronta( Data d1, Data d2 ) che restituisce 0 se le due date sono uguali, 1 se
  in ordine cronologico crescente, -1 se in ordine inverso.

Nel file maialini.c trovate delle strutture dati già inizializzate e soprattutto le funzioni vuote già costruite:
https://www.dropbox.com/s/rjqf88ddlu9lok3/maialini.c?dl=0

Ricordo che le funzioni che ricevono vettori funzionano in modo tale che agendo sul vettore le modifiche saranno visibili anche nel main.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define n 7
typedef struct{
	int giorno;
	int mese; 
	int anno;
} Data;


typedef struct{
	char nome[20];
	Data data;
	float peso;
	int popolarita;
} Maialino;


typedef struct{
	int num_maialini;
	Maialino maialino[n];
} Allevamento;


int confronta(Data data1, Data data2);
int stampa(Maialino * v[]);
int inizializza(Maialino * v[],Allevamento allevamento);


void ordinealfabetico(Maialino * v[]);
void ordinepeso(Maialino * v[]);
void ordinedata(Maialino * v[]);
void ordinepopolarita(Maialino * v[]);


int main(){
	int i;
	Allevamento allevamento = { 7, "porky pig", {12, 7, 1936}, 33.50, 85, 
						"miss piggy", {17, 12,1974}, 23.95, 170,
						"babe",       {23, 1, 1999}, 18.80, 250,
						"pumba",      {14, 11,1994}, 79.99, 1690,
						"peppa",      {31, 5, 2004}, 12.50, 8500,
						"ham",        {12, 7, 1968}, 19.05, 290,
						"piglet",     {22, 4, 1926}, 9.30,  1260 };
	Maialino *ord_alfabetico[n]={ NULL };					
	Maialino *ord_data[n]={ NULL };					
	Maialino *ord_peso[n]={ NULL };					
	Maialino *ord_pop[n]={ NULL };					
	 
	inizializza(ord_alfabetico,allevamento);
	inizializza(ord_data,allevamento);
	inizializza(ord_peso,allevamento);
	inizializza(ord_pop,allevamento);
	
	ordinealfabetico(ord_alfabetico);
	ordinedata(ord_data);
	ordinepeso(ord_peso);
	ordinepopolarita(ord_pop);
	
	printf( "allevamento a:\n");
	for(i=0; i<7; i++){
	    printf("maialino %d: %12s, %2d-%d-%2d, %5f, %5d\n",i, allevamento.maialino[i].nome, allevamento.maialino[i].data.giorno, allevamento.maialino[i].data.mese, allevamento.maialino[i].data.anno, allevamento.maialino[i].peso, allevamento.maialino[i].popolarita);
	}


    stampa(ord_alfabetico);
    stampa(ord_data);
    stampa(ord_peso);
    stampa(ord_pop);
		
	return 0;
}

int inizializza(Maialino * v[],Allevamento allevamento){
	int i;
	for(i=0;i<n;i++)
	    v[i]=&(allevamento.maialino[i]);
}




int stampa(Maialino * v[]){
	int i;
	printf( "\nallevamento a:\n");
	for(i=0; i<7; i++){
	    printf("maialino %d: %12s, %2d-%d-%2d, %5f, %5d\n",i, v[i]->nome, v[i]->data.giorno, v[i]->data.mese, v[i]->data.anno, v[i]->peso, v[i]->popolarita);
	}
	
	return 0;
}


//ordinamento per nome
void ordinealfabetico(Maialino * ord_alfabetico[]){
	int i,ordine=1;
    char temp[20];
    for (i = 0; i < 7; i++){
        printf("maialino %d", ord_alfabetico[i]->nome);
    }
    do{
        for(i=1;i<7;i++){
            if (strcmp(ord_alfabetico[i]->nome,ord_alfabetico[i-1]->nome)<0){
                strcpy(temp,ord_alfabetico[i]->nome);
                strcpy(ord_alfabetico[i]->nome,ord_alfabetico[i-1]->nome);
                strcpy(ord_alfabetico[i-1]->nome,temp);
            }
            
        }
    }while (ordine==0);
    
    
}
	


//ordinamento per data
	void ordinedata(Maialino *ord_data[n]){
	}
//ordinamento per peso	
	void ordinepeso(Maialino *ord_peso[n]){
	}
//ordinamento per popolarita		
	void ordinepopolarita(Maialino *ord_pop[n]){
	}
	
	int confronta(Data data1, Data data2){
		if(data1.anno<data2.anno)
		    return 1;
		else if(data1.anno==data2.anno && data1.mese<data2.mese)
		    return 1;   
		else if(data1.anno==data2.anno && data1.mese==data2.mese && data1.giorno<data2.giorno)
		    return 1;   
		else if(data1.anno==data2.anno && data1.mese==data2.mese && data1.giorno==data2.giorno)
		    return 0;
		else return -1;   
	}


