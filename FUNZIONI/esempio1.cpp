#include <stdio.h>
void f(int i, int k){
	printf("Inizio f:%d %d\n", i, k);
	i++;
	k++;
	printf("Fine f:%d %d\n", i,k);
}
void f1(int i, int * k){
	printf("Inizio f:%d %d\n", i,  *k);
	i++;
	(*k)++;
	printf("Fine f:%d %d\n", i,*k); // devo passare &b.
}
void scambia(int * i, int * k){
	int temp;
	temp = *i;
	*i=*k;
	*k=temp;
	//azioni fatte su ciò che è puntato da i e da k.
}
int main(){
	int a=2,b=4;
	printf("Inizio main:%d %d\n",a,b);
	//f1(a,&b); //con f il passaggio è per copia! a e b copiati dentro i e k, non cè nessun ritorno indietro.
	//con f1 passo alla modifica l'indirizzo di k. Se copio indirizzo, l'azione è fatte sulla variabile del chiamante
	//printf("Fine main:%d %d\n",a,b);
	scambia(&a,&b);
	printf("Dopo scambia: %d %d",a,b);
}
