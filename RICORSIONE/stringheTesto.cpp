#include<stdio.h>
#include<string.h>
#define N 100

/*Si implementi una funzione verifica per controllare che un acronimo corrisponda ad un determinato testo. 
In particolare la funzione verifica prende in ingresso due stringhe acr e txt (oltre ad eventuali variabili necessarie) e 
controllerà che tutti e soli i caratteri di acr corrispondono all'iniziale di una parola in txt e che questi appaiano in ordine
 corretto.

In particolare:
Acronimi troppo lunghi o troppo corti rispetto al testo non sono considerati validi.
Si assuma pure che i caratteri in acr siano tutti maiuscoli, e che in in txt ogni parola inizi con lettera maiuscola
Si assuma che acr sia correttamente formattata e txt oltre a essere correttamente formattata contenga sempre un solo spazio
 prima di ogni parola e che non ci siano spazi prima del ‘\0’*/
typedef char Stringa[N];
int verifica(Stringa acr,Stringa txt);

int main(){


    Stringa acr1="ATM", txt1 = "Azienda Trasporti Milanesi"; //SI
    Stringa acr2="AT", txt2 = "Azienda Trasporti Milanesi";  //NO
    Stringa acr3="ATM", txt3 = "Azienda Trasporti Lombardi"; //NO
    Stringa acr4="ATMK", txt4 = "Azienda Trasporti Milanesi";//NO
    Stringa acr5="ATM", txt5 = "Azienda Trasporti Milanesi Lombardi"; //NO


    // TODO: invocazione della funzione e stampa risultato
	int check=verifica(acr5,txt5);
	if(check==1){
		printf("SI");
	}else{
		printf("NO");
	}
}


// TODO: funzione (� vietato stampare nella funzione)
int verifica(Stringa acr,Stringa txt){
	int len_acr=strlen(acr),len_txt=strlen(txt),cont=0;
	int i,k=0;
	if(acr[0]!=txt[0]){
		return 0;
	}else{
		cont++;
		k++;
	}
	//printf("Prima lettera e': %c",txt[0]);
	for(i=1;i<len_txt;i++){
		if(txt[i]==' '){
			cont++;
			if(txt[i+1]==acr[k]){
				//printf("\nAltra lettera e': %c",txt[i+1]);
				k++;
			}
		}
	}
	//printf("\nnumero di prime lettere: %d",cont);
	//printf("\n%d",k);
	//printf("\n%d",len_acr);
	if(k==len_acr && k==cont){
		return 1;
	}else{
		return 0;
	}
}
