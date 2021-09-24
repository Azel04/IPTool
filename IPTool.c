#include "stdio.h"
#include "input_ip.h"
#include "output_ip.h"
#include "conversione_decimale_binario_ip.h"
#include "controllo_tipo_ip.h"

int main(){
    int ip_bin_dot[32];
    int ip_dec_dot[4];
    
	input_ip(ip_dec_dot);
    printf("L'indirizzo inserito e' il seguente: ");
    output_ip_dec(ip_dec_dot);
    printf("\n");
	controllo_tipo_ip(ip_dec_dot);
	conversione_decimale_binario(ip_dec_dot, ip_bin_dot);
    printf("\nL'indirizzo ip in binario e' il seguente: \n");
	output_ip_bin(ip_bin_dot);

    return 0;
}
