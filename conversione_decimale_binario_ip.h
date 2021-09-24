void conversione_decimale_binario(int *ip_dec_dot, int *ip_bin_dot){
	int i;
	int j;
	int k;
	
    i = 0;
    j = 7;
    k = 0;
    do{
        do{
            ip_bin_dot[j] = ip_dec_dot[i] % 2;
            ip_dec_dot[i] = ip_dec_dot[i] / 2;
            j--;
            k++;
        }while(k < 8);
        i++;
        j = 8 * i + 7; // Per esempio: 8 - 1 + 8 = 15
        k = 0;
    }while(i < 4);
}
