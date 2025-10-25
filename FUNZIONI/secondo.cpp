/*Si scriva un frammento di codice legga da input le coord x e y di una struct punto cosi definita:
typedef struct { float x; float y; } Punto; 
si sviluppino ed invochino in un main le seguenti funzioni
•	void stampaPunto(Punto p) che effettui la stessa STAMPA di un punto passato come parametro
•	Punto acquisisciPunto() che crea un punto dopo aver chiesto le coordinate all’utente. 
•	float calcolaNorma(Punto p) che restituisce la distanza del punto dall’origine
•	float calcolaDistanza(Punto p1, Punto p2) che calcola la distanza tra il punto p1 e p2

Si scriva infine una funzione “lunghezza” che riceve un vettore di punti e restituisce la lunghezza della linea spezzata composta dai punti nel vettore (nell’ordine in cui sono nel vettore). La funzione avrà prototipo:
float lunghezza(Punto linea[])*/

#include <stdio.h>
#include <math.h>
typedef struct { float x; float y; } Punto;

void stampaPunto (Punto p);
Punto acquisisciPunto();
float calcolaNorma(Punto p);
float calcolaDistanza(Punto p1, Punto p2);
float lunghezza(Punto linea[]);

int main(){
    Punto p1, p2;
    float dist;
    p1=acquisisciPunto();
    stampaPunto(p1);
    printf("\nLa norma del punto e': %.2f\n", calcolaNorma(p1));
    p2=acquisisciPunto();
    printf("La distanza tra i due punti e': %.2f\n", calcolaDistanza(p1,p2));
    Punto linee[5]={{0,1},{1,1},{2,1},{2,0},{1,0}};
    dist=lunghezza(linee);
    printf("%f",dist);
    return 0;

}

void stampaPunto (Punto p){
    printf("le coordinate del punto sono: (%f, %f)",p.x,p.y);
}

Punto acquisisciPunto(){
    Punto pp;
    printf("Inserisci la coordinata x del punto: ");
    scanf("%f", &pp.x);
    printf("Inserisci la coordinata y del punto: ");
    scanf("%f", &pp.y);
    return pp;
}

float calcolaNorma(Punto p){
    float dist;
    dist=sqrt((p.x*p.x)+(p.y*p.y));
    return dist;
}

float calcolaDistanza(Punto p1, Punto p2){
    float dist;
    dist=sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
    return dist;
}
float lunghezza(Punto linea[]){
	float lunghezza_=0;
	int i;
    int N=5; // Numero di punti nella linea spezzata
	for(i=1;i<N;i++){
		lunghezza_=lunghezza_+calcolaDistanza(linea[i-1],linea[i]);
	}
	return lunghezza_;
}