#include <stdio.h>
int mcd(int n,int m);

int main(){
	int ris,a,b;
	printf("Inserisci un n umero: ");
	scanf("%d",&a);
	printf("Inserisci un n umero: ");
	scanf("%d",&b);
	ris=mcd(a,b);
	printf("mcd e': %d",ris);
}

int mcd(int n,int m){
	if(n==m){
		return n;
	}else if(m>n){
		return mcd(n,m-n);
	}else if(m<n){
		return mcd(m,n-m);
	}
}