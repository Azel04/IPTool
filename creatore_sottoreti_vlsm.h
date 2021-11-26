void creatore_sottoreti_c_variabile(int *ip_dec_dot);
void creatore_sottoreti_b_variabile(int *ip_dec_dot);
void creatore_sottoreti_a_variabile(int *ip_dec_dot);

typedef struct{
  int ip_bin_dot[32];
  int ip_gateway[4];
  int subnet_mask_bin[32];
  int subnet_mask_dec[4];
  int numero_sottorete_bin[32];
  int gateway;
  int range[2];
  int host_per_sottorete;
  int broadcast;
  int net_id;
  int host;
}indirizzi_vlsm;

void creatore_sottoreti_a_variabile(int *ip_dec_dot){
  indirizzi_vlsm ip;
  int somma;
  int resto;
  int host_sottorete[64];
  int num_sottoreti;
  int bit_host[64];
  int ip_temp[32];
  int clone_ip_dec_dot[4];
  int i;
  int j;
  int k;
  int temp;
  int cont;
  int cont_pot;
  int cont_bit;
  int cont_host;
  int max_sottoreti;
  max_sottoreti = pow(2, 7);
  ip_dec_dot[3] = 0;
  ip_dec_dot[2] = 0;
  ip_dec_dot[1] = 0;
  do{
    printf("Inserisci il numero di sottoreti (MAX %ld): ", max_sottoreti);
    scanf("%d", &num_sottoreti);
  }while(num_sottoreti > pow(2, 7) || num_sottoreti < 0);

  for(i = 0; i < num_sottoreti; i++){
    do{
      printf("Inserisci il numero di host della sottorete numero %d: ", i + 1);
      scanf("%d", &host_sottorete[i]);
    }while(host_sottorete[i] <= 0 || host_sottorete[i] > pow(2, 24) - 2);
  }
  for(i = 0; i < num_sottoreti; i++){
    for(j = i + 1; j < num_sottoreti; j++){
      if(host_sottorete[j] > host_sottorete[i]){
        temp = host_sottorete[i];
        host_sottorete[i] = host_sottorete[j];
        host_sottorete[j] = temp;
      }
    }
  }
  for(i = 0; i < num_sottoreti; i++){
    host_sottorete[i] = host_sottorete[i] + 2;
  }
  for(i = 0; i < num_sottoreti; i++){
    bit_host[i] = log2(host_sottorete[i]) + 1;
  }
  if(num_sottoreti > 2 && bit_host[0] == 23 && bit_host[1] == 23){
    printf("Non e' possibile soddisfare la tua richiesta\n");
    return;
  }
  j = 0;
  cont_host = 0;
  printf("Ecco l'ordine delle reti:\n");
  for(i = 0; i < num_sottoreti; i++){
    printf("%d) %d Host, Potenza di 2 piu' vicina: 2^%d\n", i + 1, host_sottorete[i] - 2, bit_host[i]);
  }
  printf("\tNETWORK ID\tGATEWAY\t\tBROADCAST\tPRIMO HOST\tULTIMO HOST\n");
  cont_bit = 0;
  cont_pot = 24 - bit_host[cont_bit];
  conversione_decimale_binario(ip_dec_dot, ip.ip_bin_dot);
  for(cont = 0; cont < num_sottoreti; cont++){
    cont_pot = 24 - bit_host[cont_bit];
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin_dot[i];
    }
    for(i = 7 + (cont_pot + 1); i < 32; i++){
      ip_temp[i] = 0;
    }
    conversione_binario_decimale(ip_dec_dot, ip.ip_bin_dot);
    printf("%d)\t", cont + 1);
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip_dec_dot[3]);
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin_dot[i];
    }
    ip_temp[31] = 1;
    conversione_binario_decimale(ip_dec_dot, ip_temp);
    ip.range[0] = ip_dec_dot[3] + 1;
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip_dec_dot[3]);
    ip.ip_gateway[0] = ip_dec_dot[0];
    ip.ip_gateway[1] = ip_dec_dot[1];
    ip.ip_gateway[2] = ip_dec_dot[2];
    ip.ip_gateway[3] = ip_dec_dot[3];
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin_dot[i];
    }
    for(i = 7 + (cont_pot + 1); i < 32; i++){
      ip_temp[i] = 1;
    }  
    conversione_binario_decimale(ip_dec_dot, ip_temp);
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip_dec_dot[3]);
    conversione_decimale_binario_semplice((host_sottorete[cont_host] - 3) + ip.range[0], ip.numero_sottorete_bin);
    for(i = 31; i > 31 - bit_host[cont_bit]; i--){
      ip_temp[i] = ip.numero_sottorete_bin[i];
    }
    cont_host++;
    conversione_binario_decimale(ip_dec_dot, ip_temp);
    printf("%d.%d.%d.%d\t", ip.ip_gateway[0], ip.ip_gateway[1], ip.ip_gateway[2], ip.range[0]);
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip.range[1]);
    conversione_decimale_binario_semplice(cont + 1, ip.numero_sottorete_bin);
    
    k = 31;
    printf("\n\n");
    cont_bit++;
    resto = 0;
    somma = 1;
    for(i = 7 + cont_pot; i >= 8; i--){
      resto = ip.ip_bin_dot[i] * somma;
      ip.ip_bin_dot[i] = ip.ip_bin_dot[i] ^ somma;
      ip.ip_bin_dot[i - 1] = ip.ip_bin_dot[i - 1] + resto;
      somma = 0;
    }
  }

}

void creatore_sottoreti_b_variabile(int *ip_dec_dot){
  indirizzi_vlsm ip;
  int somma;
  int resto;
  int host_sottorete[64];
  int num_sottoreti;
  int bit_host[64];
  int ip_temp[32];
  int clone_ip_dec_dot[4];
  int i;
  int j;
  int k;
  int temp;
  int cont;
  int cont_pot;
  int cont_bit;
  int cont_host;
  int max_sottoreti;
  max_sottoreti = pow(2, 14);
  ip_dec_dot[3] = 0;
  ip_dec_dot[2] = 0;
  do{
    printf("Inserisci il numero di sottoreti (MAX %ld): ", max_sottoreti);
    scanf("%d", &num_sottoreti);
  }while(num_sottoreti > pow(2, 14) || num_sottoreti < 0);

  for(i = 0; i < num_sottoreti; i++){
    do{
      printf("Inserisci il numero di host della sottorete numero %d: ", i + 1);
      scanf("%d", &host_sottorete[i]);
    }while(host_sottorete[i] <= 0 || host_sottorete[i] > pow(2, 16) - 2);
  }
  for(i = 0; i < num_sottoreti; i++){
    for(j = i + 1; j < num_sottoreti; j++){
      if(host_sottorete[j] > host_sottorete[i]){
        temp = host_sottorete[i];
        host_sottorete[i] = host_sottorete[j];
        host_sottorete[j] = temp;
      }
    }
  }
  for(i = 0; i < num_sottoreti; i++){
    host_sottorete[i] = host_sottorete[i] + 2;
  }
  for(i = 0; i < num_sottoreti; i++){
    bit_host[i] = log2(host_sottorete[i]) + 1;
  }
  if(num_sottoreti > 2 && bit_host[0] == 15 && bit_host[1] == 15){
    printf("Non e' possibile soddisfare la tua richiesta\n");
    return;
  }
  printf("Ecco l'ordine delle reti:\n");
  for(i = 0; i < num_sottoreti; i++){
    printf("%d) %d Host, Potenza di 2 piu' vicina: 2^%d\n", i + 1, host_sottorete[i] - 2, bit_host[i]);
  }
  printf("\tNETWORK ID\tGATEWAY\t\tBROADCAST\tPRIMO HOST\tULTIMO HOST\n");
  cont_bit = 0;
  cont_pot = 16 - bit_host[cont_bit];
  conversione_decimale_binario(ip_dec_dot, ip.ip_bin_dot);
  j = 0;
  cont_host = 0;
  for(cont = 0; cont < num_sottoreti; cont++){
    cont_pot = 16 - bit_host[cont_bit];
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin_dot[i];
    }
    for(i = 15 + (cont_pot + 1); i < 32; i++){
      ip_temp[i] = 0;
    }
    conversione_binario_decimale(ip_dec_dot, ip.ip_bin_dot);
    printf("%d)\t", cont + 1);
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip_dec_dot[3]);
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin_dot[i];
    }
    ip_temp[31] = 1;
    conversione_binario_decimale(ip_dec_dot, ip_temp);
    ip.range[0] = ip_dec_dot[3] + 1;
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip_dec_dot[3]);
    ip.ip_gateway[0] = ip_dec_dot[0];
    ip.ip_gateway[1] = ip_dec_dot[1];
    ip.ip_gateway[2] = ip_dec_dot[2];
    ip.ip_gateway[3] = ip_dec_dot[3];
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin_dot[i];
    }
    for(i = 15 + (cont_pot + 1); i < 32; i++){
      ip_temp[i] = 1;
    }  
    conversione_binario_decimale(ip_dec_dot, ip_temp);
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip_dec_dot[3]);
    conversione_decimale_binario_semplice((host_sottorete[cont_host] - 3) + ip.range[0], ip.numero_sottorete_bin);
    for(i = 31; i > 31 - bit_host[cont_bit]; i--){
      ip_temp[i] = ip.numero_sottorete_bin[i];
    }
    conversione_binario_decimale(ip_dec_dot, ip_temp);
    cont_host++;
    printf("%d.%d.%d.%d\t", ip.ip_gateway[0], ip.ip_gateway[1], ip.ip_gateway[2], ip.range[0]);
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip_dec_dot[3]);
    conversione_decimale_binario_semplice(cont + 1, ip.numero_sottorete_bin);
    
    k = 31;
    for(i = 15 + cont_pot - 1; j < cont_pot - 1; j++){
      ip.ip_bin_dot[i] = ip.numero_sottorete_bin[k];
      k--;
      i--;
    }
    printf("\n\n");
    cont_bit++;
    resto = 0;
    somma = 1;
    for(i = 15 + cont_pot; i >= 16; i--){
      resto = ip.ip_bin_dot[i] * somma;
      ip.ip_bin_dot[i] = ip.ip_bin_dot[i] ^ somma;
      ip.ip_bin_dot[i - 1] = ip.ip_bin_dot[i - 1] + resto;
      somma = 0;
    }
  }
}


void creatore_sottoreti_c_variabile(int *ip_dec_dot){
  indirizzi_vlsm ip;
  int somma;
  int resto;
  int host_sottorete[64];
  int num_sottoreti;
  int bit_host[64];
  int ip_temp[32];
  int clone_ip_dec_dot[4];
  int i;
  int j;
  int k;
  int temp;
  int cont;
  int cont_pot;
  int cont_bit;
  int cont_host;
  int max_sottoreti;
  max_sottoreti = pow(2, 21);
  ip_dec_dot[3] = 0;
  do{
    printf("Inserisci il numero di sottoreti (MAX %ld): ", max_sottoreti);
    scanf("%d", &num_sottoreti);
  }while(num_sottoreti > pow(2, 21) || num_sottoreti < 0);

  for(i = 0; i < num_sottoreti; i++){
    do{
      printf("Inserisci il numero di host della sottorete numero %d: ", i + 1);
      scanf("%d", &host_sottorete[i]);
    }while(host_sottorete[i] <= 0 || host_sottorete[i] > pow(2, 8) - 2);
  }
  for(i = 0; i < num_sottoreti; i++){
    for(j = i + 1; j < num_sottoreti; j++){
      if(host_sottorete[j] > host_sottorete[i]){
        temp = host_sottorete[i];
        host_sottorete[i] = host_sottorete[j];
        host_sottorete[j] = temp;
      }
    }
  }
  for(i = 0; i < num_sottoreti; i++){
    host_sottorete[i] = host_sottorete[i] + 2;
  }
  for(i = 0; i < num_sottoreti; i++){
    bit_host[i] = log2(host_sottorete[i]) + 1;
  }
  if(num_sottoreti > 2 && bit_host[0] == 7 && bit_host[1] == 7){
    printf("Non e' possibile soddisfare la tua richiesta\n");
    return;
  }
  printf("Ecco l'ordine delle reti:\n");
  for(i = 0; i < num_sottoreti; i++){
    printf("%d) %d Host, Potenza di 2 piu' vicina: 2^%d\n", i + 1, host_sottorete[i] - 2, bit_host[i]);
  }
  printf("\tNETWORK ID\tGATEWAY\t\tBROADCAST\tPRIMO HOST\tULTIMO HOST\n");
  cont_bit = 0;
  cont_pot = 8 - bit_host[cont_bit];
  conversione_decimale_binario(ip_dec_dot, ip.ip_bin_dot);
  j = 0;
  cont_host = 0;
  for(cont = 0; cont < num_sottoreti; cont++){
    cont_pot = 8 - bit_host[cont_bit];
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin_dot[i];
    }
    for(i = 23 + (cont_pot + 1); i < 32; i++){
      ip_temp[i] = 0;
    }
    conversione_binario_decimale(ip_dec_dot, ip.ip_bin_dot);
    printf("%d)\t", cont + 1);
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip_dec_dot[3]);
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin_dot[i];
    }
    ip_temp[31] = 1;
    conversione_binario_decimale(ip_dec_dot, ip_temp);
    ip.range[0] = ip_dec_dot[3] + 1;
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip_dec_dot[3]);
    ip.ip_gateway[0] = ip_dec_dot[0];
    ip.ip_gateway[1] = ip_dec_dot[1];
    ip.ip_gateway[2] = ip_dec_dot[2];
    ip.ip_gateway[3] = ip_dec_dot[3];
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin_dot[i];
    }
    for(i = 23 + (cont_pot + 1); i < 32; i++){
      ip_temp[i] = 1;
    }  
    conversione_binario_decimale(ip_dec_dot, ip_temp);
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip_dec_dot[3]);
    conversione_decimale_binario_semplice((host_sottorete[cont_host] - 3) + ip.range[0], ip.numero_sottorete_bin);
    for(i = 31; i > 31 - bit_host[cont_bit]; i--){
      ip_temp[i] = ip.numero_sottorete_bin[i];
    }
    cont_host++;
    conversione_binario_decimale(ip_dec_dot, ip_temp);
    printf("%d.%d.%d.%d\t", ip.ip_gateway[0], ip.ip_gateway[1], ip.ip_gateway[2], ip.range[0]);
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip_dec_dot[3]);
    conversione_decimale_binario_semplice(cont + 1, ip.numero_sottorete_bin);
    k = 31;
    printf("\n\n");
    cont_bit++;
    resto = 0;
    somma = 1;
    for(i = 23 + cont_pot; i >= 24; i--){
      resto = ip.ip_bin_dot[i] * somma;
      ip.ip_bin_dot[i] = ip.ip_bin_dot[i] ^ somma;
      ip.ip_bin_dot[i - 1] = ip.ip_bin_dot[i - 1] + resto;
      somma = 0;
    }
  }
}
