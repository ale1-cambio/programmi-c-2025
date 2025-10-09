#include <stdio.h>
#include <string.h>

int main(){
	int i=0,palindroma=0,leng,j;
	char stringa[20];
	printf("Inserisci una stringa: ");
	scanf("%s", stringa);
	leng=strlen(stringa);
	while(i<(leng/2)){
		for(j=leng-1;j>=(leng/2);j--){
			if(stringa[i]!=stringa[j]){
				palindroma=1;
			}
			i++;
		}
	}
	if(palindroma==0){
		printf("La stringa e' palindroma");
	}else{
		printf("la stringa NON e' palindroma");
	}
}