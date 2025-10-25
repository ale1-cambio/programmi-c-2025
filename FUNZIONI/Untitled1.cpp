#include <stdio.h>
#include <math.h>
typedef struct {float x;float y;} punto;
typedef punto pentagono[5]; // è un vettore di punti, 5 caselle che a loro volta contegnon campo x e y
float erone(punto p1,punto p2,punto p3){
	punto tri[3];float p;
	tri[0]=p1; tri[1]=p2;tri[3]=p3;
	p=0.5*perimetro(tri,3);
}
int main(){
	
	pentagono pn={{0,0},{0.2,1},{1,1},{2,0.5},{1,-0.3}};
	int i=0;
	float perimetro = 0,distanza;
	for(i=0;i<4;i++){
		distanza = sqrt((pn[i].x - pn[i+1].x)*(pn[i].x - pn[i+1].x)+(pn[i].y-pn[i+1].y)*(pn[i].y-pn[i+1].y));
		perimetro = perimetro + distanza;
	}// ora manca distanza sa punto zero a punto quattro!
	perimetro =perimetro + sqrt((pn[0].x-pn[4].x)*(pn[0].x-pn[4].x)+(pn[0].y-pn[4].y)*(pn[0].y-pn[4].y));
	printf("%f", perimetro);
}