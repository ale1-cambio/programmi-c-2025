#include <stdio.h>
#define N 8
int main(){
	int max=0, pos, val, i;
	printf("Inserisci un valore: ");/* se valore inserito è subito il più grande*/
	scanf("%d", &max);
	pos=1;
	i=2;
	while (i<=N){
		printf("Inserisci un valore: "); /* supponiamo che non ci siano più massimi*/
		scanf("%d", &val);
		if(val>max){
			max=val;
			pos=i;
		}
		i++;
	}
	printf("Il valore massimo è %d nella posizione %d", max, pos);	
	return 0;
}