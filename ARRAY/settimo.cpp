#include <stdio.h>
#include <string.h>
#define MAXLEN 100
int main(){
	char str[MAXLEN], res[MAXLEN], spazio = ' ';
	int i,lunghezza1,lunghezza2,j=0;
	printf("Inserisci una stringa di massimo 100 caratteri: ");
	fgets(str, sizeof(str), stdin);
	lunghezza1=strlen(str);
	for(i=0;i<lunghezza1;i++){
		if(i==0){
			res[j]=str[i];
		}
		else if(str[i]== ' '){
			res[j+1]=str[i-1];
			res[j+2]=str[i+1];
			j=j+2;
		} else if(i==lunghezza1-1){
			res[j+1]=str[i];
		}
	}
	printf("%s", res);
	
	
}