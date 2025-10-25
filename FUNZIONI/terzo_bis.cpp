/*Si consideri questa struttura che caratterizza lo stato di una partita a tris:
 
typedef struct {
    int turno;    // 1 se è il turno del giocatore 1, 2 se è il turno del giocatore 2
    int griglia[3][3];    // contiene tutti 0 all'inizializzazione, 1 e 2 per i giocatori 1 e 2
}
 
Si scriva un programma che inizializzi una griglia vuota e che contenga le seguenti funzioni:
- un menù che a turno faccia scegliere ai giocatori una mossa (tramite coordinate) e ne controlli la validità
- una funzione che inserisce un nuovo valore nella griglia
- una funzione per visualizzare la griglia attuale (con X e O per i giocatori 1 e 2)
- una funzione che controlla se la partita è finita (tris o caselle piene)
*/

#include <stdio.h>

typedef struct {
    int turno;    // 1 se è il turno del giocatore 1, 2 se è il turno del giocatore 2
    int griglia[3][3];    // contiene tutti 0 all'inizializzazione, 1 e 2 per i giocatori 1 e 2
} partita;
void inizializzaPartita(partita *p) {
    p->turno = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            p->griglia[i][j] = 0;
        }
    }
}
void visualizzaGriglia(partita *p) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (p->griglia[i][j] == 1) {
                printf(" X ");
            } else if (p->griglia[i][j] == 2) {
                printf(" O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}
int controllaVittoria(partita *p) {
    // Controlla righe e colonne
    for (int i = 0; i < 3; i++) {
        if (p->griglia[i][0] == p->griglia[i][1] && p->griglia[i][1] == p->griglia[i][2] && p->griglia[i][0] != 0) {
            return p->griglia[i][0];
        }
        if (p->griglia[0][i] == p->griglia[1][i] && p->griglia[1][i] == p->griglia[2][i] && p->griglia[0][i] != 0) {
            return p->griglia[0][i];
        }
    }
    // Controlla diagonali
    if (p->griglia[0][0] == p->griglia[1][1] && p->griglia[1][1] == p->griglia[2][2] && p->griglia[0][0] != 0) {
        return p->griglia[0][0];
    }
    if (p->griglia[0][2] == p->griglia[1][1] && p->griglia[1][1] == p->griglia[2][0] && p->griglia[0][2] != 0) {
        return p->griglia[0][2];
    }
    // Controlla se la griglia è piena
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (p->griglia[i][j] == 0) {
                return 0; // La partita continua
            }
        }
    }
    return -1; // Pareggio
}
int inserisciMossa(partita *p, int riga, int colonna) {
    if (riga < 0 || riga >= 3 || colonna < 0 || colonna >= 3) {
        return 0; // Mossa non valida
    }
    if (p->griglia[riga][colonna] != 0) {
        return 0; // Casella già occupata
    }
    p->griglia[riga][colonna] = p->turno;
	if (p->turno == 1)
  	  	p->turno = 2;
	else
   		p->turno = 1;
    return 1; // Mossa valida
}
int main() {
    partita p;
    inizializzaPartita(&p);
    int riga, colonna, risultato;

    while (1) {
        visualizzaGriglia(&p);
        printf("Giocatore %d, inserisci la tua mossa (riga e colonna): ", p.turno);
        scanf("%d %d", &riga, &colonna);

        if (!inserisciMossa(&p, riga, colonna)) {
            printf("Mossa non valida. Riprova.\n");
            continue;
        }

        risultato = controllaVittoria(&p);
        if (risultato == 1) {
            visualizzaGriglia(&p);
            printf("Giocatore 1 vince!\n");
            break;
        } else if (risultato == 2) {
            visualizzaGriglia(&p);
            printf("Giocatore 2 vince!\n");
            break;
        } else if (risultato == -1) {
            visualizzaGriglia(&p);
            printf("La partita è finita in pareggio!\n");
            break;
        }
    }

    return 0;
}
