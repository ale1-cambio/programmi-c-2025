//come si passano vettori alle funzioni?
#include <stdio.h>
int somma(int v[]);
int somma1(int v[],int dim);//dim è dimensione vettore
int main(){
	int vett[4]={1,2,3,4};
//	int k= somma(vett);
	//printf("%d",k);
	//printf("%d", somma1(vett,2));
	printf("%d",somma1(vett+1,2));//passo indirizzo di vett+, per la funzione il vettore inizia dove gli dico io che inizia. funzione uso vettore della funzione chiamante
	return 0;
}
int somma1(int v[],int dim){
	int tot=0,i;
	for(i=0;i<dim;i++){
		tot = tot+v[i];
	}
	return tot;
}
int somma(int v[]){//dimensione di vett ignorata, sto passando l'indirizzo del vettore, perchè
	int tot=0,i;
	for(i=0;i<4;i++){
		tot = tot+v[i];
	}
	return tot;
	// quando prendo puntatore e sommo 2, aumenta di due la dimensione del tipo. Se prendo punt float +
}// va avanti di due puntatori float("puo saltare piu avanti")