#include<stdio.h>
#define N 5

/*Si una funzione riordina che prende in ingresso due vettori u e v (più eventuali variabili necessarie) e che riordina gli 
elementi del primo vettore passato in input (u nel nostro caso) nel seguente modo:
tutti gli elementi di u che non compaiono in v saranno nelle prime posizioni di u dopo l'invocazione
tutti gli elementi di u che compaiono in v saranno nelle ultime posizioni di u dopo l'invocazione
Si faccia riferimento all'esempio sotto per eventuali dubbi su come modificare u.

Si invochi quindi la funzione relativamente al seguente codice e si stampi il contenuto del vettore u a schermo.

N.B non è possibile stampare all'interno della funzione riordina

Risultato atteso

u = 4 1 3 7 0
v = 1 6 8 4
dopo invocazione u = 3 7 0 4 1
*/

void riordina(int u[], int v[],int len1,int len2){
	int temp[N],i,k=0,n=0,trovato=0;
	for(i=0;i<N;i++){
		temp[i]=0;
	}
	for(i=0;i<len1;i++){
		for(k=0;k<len2;k++){
			if(u[i]==v[k]){
				trovato=1;
			}
		}
		if(trovato==0){
			temp[n]=u[i];
			n++;
		}
		trovato=0;
	}
	for(i=0;i<len1;i++){
		for(k=0;k<len2;k++){
			if(u[i]==v[k]){
				temp[n]=u[i];
				n++;
			}
		}
	}
	for(i=0;i<len1;i++){
		u[i]=temp[i];
	}
}


int main()
{
    int u[N] = {4,1,3,7,0}, v[N] = {1,6,8,4};


    // TODO stampa u e v

	int i=0;
	printf("u = ");
	for(i=0;i<N;i++){
		printf("%d ",u[i]);
	}
	printf("\nv = ");
	for(i=0;i<4;i++){
		printf("%d ",v[i]);
	}
    // TODO invocazione riordina
	riordina(u,v,N,4);

    // TODO stampa u dopo invocazione
	printf("\ndopo invocazione u = ");
	for(i=0;i<N;i++){
		printf("%d ",u[i]);
	}
    return 0;
}
