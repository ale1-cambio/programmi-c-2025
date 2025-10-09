#include <stdio.h>
#include <string.h>

int main(){
	char str1[64],str2[32];
	int i=0,j=0,cont,tot,volte=0;
	printf("Inserisci la prima stringa: ");
	scanf("%s", str1);
	printf("Inserisci la seconda stringa: ");
	scanf("%s", str2);
	int lunghezza1= strlen(str1);
	int lunghezza2= strlen(str2);
	while(i<lunghezza1){
		if(str2[0]==str1[i]){
			while(j<lunghezza2){
				if(str2[j]==str1[i+j]){
					cont++;
				}
				j++;
			}
			tot=cont/lunghezza2;
			if(tot<1){
				tot=0;
				cont=0;
			}else if(tot==1){
				volte++;
				tot=0;
				cont=0;
			}
			i++;
		}else{
			i++;
		}
		j=0;
	
		
	}
	printf("%d", volte);
}