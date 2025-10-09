#include <stdio.h>
#define LEN 20
int main(){
	char pari[LEN],dispari[LEN],altro[LEN] ,carattere;
	int a=0,p=0,d=0,i;
	do{
		scanf("%c", &carattere);
		fflush(stdin);
		switch(carattere){
			case ' ': break;
			case '0':
			case'2':
			case'4':
			case'6':
			case '8':
				pari[p++]=carattere;
				break;
			case '1':
			case '3':
			case '5':
			case'7':
			case'9':
				dispari[d++]=carattere;
				break;
			default:
				altro[a++]=carattere;	
				break;
		}
		i++;
	}while(i<LEN);
	printf("pari sono %d, dispari %d, altro %d",p,d,a);
}