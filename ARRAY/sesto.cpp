#include <stdio.h>
#include <string.h>

int main(){
	char str1[32],str2[32],i=0,j=0,compatibili=1,lunghezza1,lunghezza2;
	printf("Inserisci la prima parola: ");
	scanf("%s", str1);
	printf("Inserisci la seconda parola: ");
	scanf("%s", str2);
	
		if(str1[0]==str2[0]){
			i=2;
			j=2;
			while(j<lunghezza2){
				if(str1[i]!=str2[j]){
					compatibili=0;
				}
				i=i+2;
				j=j+2;
			}
		}
		else if(str1[i+1]==str2[j+1]){
			i=3;
			j=3;
			while(j<lunghezza2){
				if(str1[i]!=str2[j]){
 					compatibili=0;
				}
				i=i+2;
				j=j+2;
			}
			
		}else{
			compatibili=0;
		}
	if(compatibili==1){
		printf("Le parole sono Hertzianamente compatibili");
	}else{
		printf("NO");
	}
	
}