#include <stdio.h>
#include <string.h>
int main(){
	char str1[32],g,G,i,lunghezza,j,g_riferimento,G_riferimento;
	printf("Inserisci una parola: ");
	scanf("%s", str1);
	lunghezza=strlen(str1);
	g=lunghezza;
	G=0;
	g_riferimento=lunghezza;
	G_riferimento=0;
	for(i=0;i<lunghezza;i++){
		for(j=0;j<lunghezza;j++){
			if(str1[i]==str1[j]){
				G++;
			}else{
				g--;
			}
		}
		if(G>G_riferimento){
			G_riferimento=G;
		}
		if(g<g_riferimento){
			g_riferimento=g;
		}
		g=lunghezza;
		G=0;
	}
	if(lunghezza==0){
		g_riferimento=0;
		G_riferimento=0;
	}
	printf("%s ha come g: %d e G: %d",str1,g_riferimento,G_riferimento);
}