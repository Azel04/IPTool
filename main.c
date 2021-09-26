#include <stdio.h>
#include <math.h>
#include "input_ip.h"
#include "output_ip.h"
#include "conversione_decimale_binario_ip.h"
#include "controllo_tipo_ip.h"
#include "creatore_sottoreti.h"

int main(){
	int ip_bin_dot[32];
	int ip_dec_dot[4];
	int scelta;
	int fine;
	fine = 0;
	do{
		printf("1) Inserisci un indirizzo ipv4 e calcolane la sua classe e il suo corrispettivo ip in binario\n2) Crea un numero di sottoreti a tua scelta\n 3)Fine\nFai la tua scelta: ");
		scanf("%d", &scelta);
		switch(scelta){
			case 1:
				input_ip(ip_dec_dot);
    			printf("L'indirizzo inserito e' il seguente: ");
    			output_ip_dec(ip_dec_dot);	
				printf("\n");
				controllo_tipo_ip(ip_dec_dot);
				conversione_decimale_binario(ip_dec_dot, ip_bin_dot);
    			printf("\nL'indirizzo ip in binario e' il seguente: \n");
				output_ip_bin(ip_bin_dot);
				break;
			case 2:
				creatore_sottoreti();
				break;
			case 3:
				printf("Fine\n");
				fine = 1;
				break;
			default:
				printf("Input non valido\n");
				break;
		}
	}while(fine == 0);

    return 0;
}
