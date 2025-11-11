/*La seguenti definizione di tipi definiscono la disposizione di un mercato rionale in cui le bancarelle sono disposte come 
in una matrice quadrata di dimensioni effettive variabili in base al mercato. Dato che il numero di bancarelle non supera mai 
le 10.000 unità si usa per rappresentate il mercato una parte di una matrice 100x100 usando però solo una sottomatrice quadrata 
di dimensioni contenute nel campo dimensioniReali; 

typedef char Stringa[M];
typedef struct {    
  Stringa tipo;     
  float costoKg;} Bancarella;
typedef struct {    
  Bancarella Mercato[N][N];    
  int dimensioniReali;} MercatoRionale;

Per una regola del mercato, tutte e sole le bancarelle che vendono pesce devono stare sull'antidiagonale. Si implementi la
 funzione controllaDisposizione prende in ingresso la matrice del mercato m (e tutte le variabili necessarie) e che riporta al 
 main:
0 se m soddisfa le regole del mercato e quindi l'antidiagonale contiene solo bancherelle che vendono pesce e non vi sono 
bancarelle che vendono pesce fuori dall'antidiagonale
un intero pari al numero di violazioni della regola nella matrice m
Si implementi quindi una funzione sistema che prende in ingresso m (e tutte le variabili necessarie) e che:
identifica la bancarella b1 di pesce con il prezzo al kg più basso
identifica la bancarella b2 all'interno di m (indipendentemente da cosa vende) che ha il costo al kg più basso
Inoltre la funzione sistema 
modifica la matrice m sostituendo b1 alle bancarelle sull'antidiagonale che non vendono pesce
modifica la matrice m sostituendo b2 alle bancarelle fuori dall'antidiagonale che vendono pesce

Si invochi quindi nel main la funzione controllaDisposizione e qualora questa restituisse un valore > 0 si invochi la funzione 
sistema e, sempre nel main, si stampi la matrice m modificata, la bancarella di pesce più economica, la bancarella più economica
 in assoluto
Suggerimento:
Si assuma che esiste sempre una bancarella che vende pesce nel mercato dopo l'inizializzazione.
Non è possibile stampare nelle funzioni o sostituire le funzioni richieste da funzioni che restituiscono solo parte degli 
input. Fare funzioni ausiliarie è invece possibile.*/


#include<stdio.h>
#include<string.h>
#define N 3
#define M 100


/*
Esempio di esecuzione con le variabili fornite
     frutta (1.5)     salumi (15.0)     salumi (22.2)
    vestiti (25.3)      pesce (10.2) casalinghi (7.2)
      pesce (14.2)     frutta (2.0)      pesce (17.2)
errori da sistemare: 2
la matrice viene sistemata:
     frutta (1.5)     salumi (15.0)      pesce (10.2)
    vestiti (25.3)      pesce (10.2) casalinghi (7.2)
      pesce (14.2)     frutta (2.0)     frutta (1.5)
 la bancarella di pesce piu economica costa: pesce (10.2)
 la bancarella piu economica costa: frutta (1.5)
*/


typedef char Stringa[M];
typedef struct {
    Stringa tipo;
    float costoKg; } Bancarella;
typedef char Stringa[M];
typedef struct {
    Bancarella mercato[N][N];
    int dimensioniReali; } MercatoRionale;




MercatoRionale inizializza();
void stampa(MercatoRionale m);
int controllaDisposizione(MercatoRionale m);
void sistema(MercatoRionale *m,Bancarella *pesce_min, Bancarella *min_assoluto);

int main()
{
    MercatoRionale m;


    Bancarella pesce, noPesce;
    int res, n=3;
    float costo;

	Bancarella pesce_min,min_assoluto;
    m=inizializza();
    stampa(m);

	res=controllaDisposizione(m);
    // TODO: INVOCARE controllaDisposizione
	printf("%d",res);

    // TODO: se serve invocare sistema

	if(res !=0){
		sistema(&m,&pesce_min,&min_assoluto);
	}
	printf("\nla bancarella di pesce piu economica costa: %s (%f)\n la bancarella piu economica costa: %s (%f)",pesce_min.tipo,pesce_min.costoKg,min_assoluto.tipo,min_assoluto.costoKg);

    // TODO: stampare matrice sistemata
	

    // TODO: stampare output richiesti


    return 0;
}




MercatoRionale inizializza()
{
	MercatoRionale m;
	m.dimensioniReali=3;
    strcpy(m.mercato[0][0].tipo, "frutta"); m.mercato[0][0].costoKg = 1.5;
    strcpy(m.mercato[0][1].tipo, "salumi"); m.mercato[0][1].costoKg = 15.0;
    strcpy(m.mercato[0][2].tipo, "salumi"); m.mercato[0][2].costoKg = 22.2;
    strcpy(m.mercato[1][0].tipo, "vestiti"); m.mercato[1][0].costoKg = 25.3;
    strcpy(m.mercato[1][1].tipo, "pesce"); m.mercato[1][1].costoKg = 10.2;
    strcpy(m.mercato[1][2].tipo, "casalinghi"); m.mercato[1][2].costoKg = 7.2;
    strcpy(m.mercato[2][0].tipo, "pesce"); m.mercato[2][0].costoKg = 14.2;
    strcpy(m.mercato[2][1].tipo, "frutta"); m.mercato[2][1].costoKg = 2.0;
    strcpy(m.mercato[2][2].tipo, "pesce"); m.mercato[2][2].costoKg = 17.2;
    return m;
}


void stampa(MercatoRionale m)
{
    int i,j;
    printf("\n");
    for(i = 0; i<m.dimensioniReali; i++)
    {
        for(j = 0; j<m.dimensioniReali; j++)
            printf(" %10s (%2.1f)", m.mercato[i][j].tipo, m.mercato[i][j].costoKg);
        printf("\n");
    }
}

int controllaDisposizione(MercatoRionale m){
	int i,j,flag=0;
	for(i=0;i<m.dimensioniReali;i++){
		for(j=0;j<m.dimensioniReali;j++){
			if(strcmp(m.mercato[i][j].tipo,"pesce")==0 && (i+j)!=(m.dimensioniReali-1)){
				flag++;
			}
			if(strcmp(m.mercato[i][j].tipo,"pesce")!=0 && (i+j)==(m.dimensioniReali-1)){
				flag++;
			}
		}
	}
	if(flag!=0){
		return flag;
	}
	return 0;
}

void sistema(MercatoRionale *m,Bancarella *pesce_min, Bancarella *min_assoluto){
	/*int i,j;
	pesce_min->costoKg=m->mercato[0][0].costoKg;
	min_assoluto->costoKg=m->mercato[0][0].costoKg;
    pesce_min->tipo[0]='\0';
    min_assoluto->tipo[0]='\0';

	for(i=0;i<m->dimensioniReali;i++){
		for(j=0;j<m->dimensioniReali;j++){
			if(strcmp(m->mercato[i][j].tipo,"pesce")==0){
				if((m->mercato[i][j].costoKg < pesce_min->costoKg)){

					pesce_min->costoKg=m->mercato[i][j].costoKg;
					strcpy(pesce_min->tipo,m->mercato[i][j].tipo);
				}			
			}
			else if(m->mercato[i][j].costoKg<min_assoluto->costoKg){
				min_assoluto->costoKg=m->mercato[i][j].costoKg;
				strcpy(min_assoluto->tipo,m->mercato[i][j].tipo);
			}
		}
	}*/
    int i,j;
    Bancarella temp_pesce_min;
    Bancarella temp_min_assoluto;
    int first_pesce = 1;
    int first_assoluto = 1;
    for(i=0;i<m->dimensioniReali;i++){
        for(j=0;j<m->dimensioniReali;j++){
            if(strcmp(m->mercato[i][j].tipo,"pesce")==0){
                if(first_pesce || (m->mercato[i][j].costoKg < temp_pesce_min.costoKg)){
                    temp_pesce_min = m->mercato[i][j];
                    first_pesce = 0;
                }           
            }
            if(first_assoluto || (m->mercato[i][j].costoKg < temp_min_assoluto.costoKg)){
                temp_min_assoluto = m->mercato[i][j];
                first_assoluto = 0;
            }
        }
    }
    *pesce_min = temp_pesce_min;
    *min_assoluto = temp_min_assoluto;
    for(i=0;i<m->dimensioniReali;i++){
        for(j=0;j<m->dimensioniReali;j++){
            if((i+j)==(m->dimensioniReali-1)){
                if(strcmp(m->mercato[i][j].tipo,"pesce")!=0){
                    m->mercato[i][j] = *pesce_min;
                }
            }
            else{
                if(strcmp(m->mercato[i][j].tipo,"pesce")==0){
                    m->mercato[i][j] = *min_assoluto;
                }
            }
        }
    }
    
}