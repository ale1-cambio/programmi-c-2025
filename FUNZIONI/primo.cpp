/*Un numero è perfetto se corrisponde alla somma dei suoi divisori, escluso se stesso 
(ad esempio 6 è perfetto 1+2+3 = 6)
Un numero è abbondante se è > della somma dei suoi divisori (es 15 è abbondante 1 + 3 +5 < 15), altrimenti difettivo 
(es 12 è difettivo, 1+2+3+4+6 > 12)
Scrivere un programma che chiede all'utente di inserire un numero positivo n (nel caso in cui il numero non è positivo 
ripetere inserimento) e verifica se n è perfetto, stampando un messaggio all’utente.
Se n non è perfetto stampa un messaggio per dire se n è abbondante o difettivo.
Consiglio per la soluzione, si sviluppino le seguenti funzioni:
int sommaDivisori(int num);
int controllaSePerfetto(int num);*/

#include <stdio.h>
#include <math.h>
int sommaDivisori(int num);
void controllaSePerfetto(int num);

int main(){
	int n;
	do{
		printf("inserisci un numero intero positivo: ");
		scanf("%d",&n);
	}while(n<=0);
	controllaSePerfetto(n);
}
int sommaDivisori(int num){
	int i, somma = 1;
	int limite = (int)sqrt(num);
	
	for(i = 2; i <= limite; i++){
		if(num % i == 0){
			somma += i;
			if(i != num/i){
				somma += num/i;
			}
		}
	}
	return somma;
}

void controllaSePerfetto(int num){
	int somma = sommaDivisori(num);
	
	if(somma == num){
		printf("Il numero è perfetto");
	}else if(somma < num){
		printf("Il numero è abbondante");
	}else{
		printf("Il numero è difettivo");
	}
}