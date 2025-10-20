#include <stdio.h>
/*Definire un nuovo tipo di dato chiamato VT vettore di 10 int. Scrivere in C la funzione ft che:
ha in ingresso un vettore A di tipo VT già caricato e restituisce, attraverso un opportuno parametro,
 una struct con 2 campi a e b di tipo int che contengono rispettivamente la somma degli elementi di A di 
 posto pari e quella degli elementi di A di posto dispari;
restituisce la sommatoria di tutti gli elementi di A.
*/

/*typedef int VT[10];

int ft(VT A){
	int i=0,somma_pari=0,somma_dispari=0;
	VT *p;
	for(i=0;i<10;i++){
		if(i%2==0){
			somma_dispari=somma_dispari+A[i];
		}else{
			somma_pari=somma_pari+A[i];
		}
	}
	
	int sommatoria = somma_pari+somma_dispari;
	struct{
		int a = somma_pari;
		int b= somma_dispari;
	} Somme;
	printf("Somma posti pari: %d\n",somma_pari);
	printf("Somma posti dispari: %d\n",somma_dispari);
	printf("Sommatoria: %d\n",sommatoria);
	return sommatoria;

};*/
typedef int VT[10];
struct Somme{
	int a;
	int b;
};
Somme ft(VT A){
	int i=0,somma_pari=0,somma_dispari=0;
	for(i=0;i<10;i++){
		if(i%2==0){
			somma_pari=somma_pari+A[i];
		}else{
			somma_dispari=somma_dispari+A[i];
		}
	}
	
	int sommatoria = somma_pari+somma_dispari;
	Somme result;
	result.a = somma_pari;
	result.b = somma_dispari;
	printf("Somma posti pari: %d\n",somma_pari);
	printf("Somma posti dispari: %d\n",somma_dispari);
	printf("Sommatoria: %d\n",sommatoria);
	return result;

};

int main(){

	VT ciao={1,3,2,4,6,7,4,3,2,1};
	
	ft(ciao);
}