/*Scrivere una funzione che riceve in ingresso due stringhe lunghe al più N (con N definito come costante in una macro)
 e modifica la prima stringa togliendo da essa tutte le occorrenze di caratteri presenti nella seconda. La stringa risultante
  non deve avere buchi.
Gracchiare, atte --- Grcchir
*/
#include <stdio.h>
#include <string.h>
#define N 11
void Mod(char s1[],char s2[]){
	char s3[N];
	int i,j,k=0,len1,len2;
	len1=strlen(s1);
	len2=strlen(s2);
	for(i=0;i<len2;i++){
		for(j=0;j<len1;j++){
			if(s2[i]==s1[j]){
				s1[j]=' ';
			}
		}
	}
	for(i=0;i<len1;i++){
		if(s1[i]!=' '){
			s1[k]=s1[i];
			k++;
		}else{
			continue;
		}
	}
	s1[k]='\0';
	printf("%s",s1);
}
int main(){
	char s1[N],s2[N];
	printf("inserisci la prima stringa: ");
	scanf("%s",s1);
	fflush(stdin);
	printf("inserisci la seconda stringa: ");
	scanf("%s",s2);
	fflush(stdin);
	Mod(s1,s2);
}