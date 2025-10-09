#include <stdio.h>
#define GIORNI 10
int main(){
	int quotX[GIORNI], i=0, val, giorno, max, j,cont=0,temp;
	do{
		printf("Inserisci valore al giorno %d: ", i+1);
		scanf("%d", &val);
		if(val<1 || val>100){
			i--;
		}else{
			quotX[i]=val;
		}
		i++;
	}while(i<GIORNI);
	max=quotX[0];
	giorno=1;
	for(j=1;j<GIORNI;j++){
		if(quotX[j]>max){
			max=quotX[j];
			giorno=j+1;
		}
	}
	for(i=0;i<GIORNI;i++){
		if(quotX[i]==quotX[i+1] && temp!=quotX[i+1]){
			cont++;
			temp=quotX[i+1];
		}
	}
	//printf("Giorno della quotazione massima: %d. Quotazione massima: %d\n",giorno,max);
	printf("%d",cont);
}