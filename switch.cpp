#include <stdio.h>

int main(){
	/*int i;
	printf("Inserisci valore: ");
	scanf("%d", &i);
	/*if(i==0){
		printf("zero");
	}
	else if(i==1){
		printf("uno");
	}
	else {
		printf("nessuno dei due");
	}*/
	/*switch(i){
		case 0: 
			printf("zero");
			break;
		case 1:
			printf("uno");
			break;
		default: 
			printf("nessuno dei due");
	}*/
	char c, throw_away;
	int n_cifre=0, n_separatori=0, n_altri=0;
	do {
		printf("dammi un carattere; ! per terminare  "); scanf("%c", &c);
		switch (c) {
			case '0':	case '1':	case '2':	case '3':
			case '4':	case '5':	case '6':	case '7':
			case '8':
			case '9': n_cifre++;
				break;
			case '.':
			case ';' :
			case ':' :
			case ',':n_separatori++;
				break;
			default:
				n_altri++;
		}
		scanf("%c", &throw_away); printf("\n");
	} while (c!='!');
	printf("cifre  %d\nseparatori   %d\naltri   %d\n", n_cifre, n_separatori, --n_altri);

	return 0;
}