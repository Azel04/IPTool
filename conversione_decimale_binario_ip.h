void conversione_decimale_binario(int *ip_dec, int *ip_bin){
	int i;
	int j;
	int k;
	
    i = 0;
    j = 7;
    k = 0;
    do{
        do{
            ip_bin[j] = ip_dec[i] % 2;
            ip_dec[i] = ip_dec[i] / 2;
            j--;
            k++;
        }while(k < 8);
        i++;
        j = 8 * i + 7; // Per esempio: 8 - 1 + 8 = 15
        k = 0;
    }while(i < 4);
}
void conversione_decimale_binario_semplice(int numero, int binario[]){
	int i;
    for(i = 31; i >= 0; i--){
      binario[i] = numero % 2;
      numero = numero / 2;
    }
}