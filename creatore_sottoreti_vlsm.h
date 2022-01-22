void creatore_sottoreti_c_variabile(int *ip_dec);
void creatore_sottoreti_b_variabile(int *ip_dec);
void creatore_sottoreti_a_variabile(int *ip_dec);

typedef struct{
  int ip_bin[32];
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

void creatore_sottoreti_a_variabile(int *ip_dec){
  indirizzi_vlsm ip;
  int somma;
  int resto;
  int *host_sottorete;
  int num_sottoreti;
  int bit_host[64];
  int ip_temp[32];
  int clone_ip_dec[4];
  int somma_host;
  int i;
  int j;
  int k;
  int temp;
  int cont;
  int cont_pot;
  int cont_bit;
  int cont_host;
  int max_sottoreti;
  int percentuale;
  max_sottoreti = pow(2, 22);
  ip_dec[3] = 0;
  ip_dec[2] = 0;
  ip_dec[1] = 0;
  somma_host = 0;
  int pot2_controllo_possibile_esponente;
  int pot2_controllo_possibile;
  int max_pot2;
  max_pot2 = 256 * 256 * 256;
  max_sottoreti = pow(2, 22);
  for(i = 0; i < 32; i++){
    if(i < 8){
      ip.subnet_mask_bin[i] = 1;
    }
    else{
      ip.subnet_mask_bin[i] = 0;
    }
  }
  do{
    printf("Inserisci il numero di sottoreti (MAX %d): ", max_sottoreti);
    scanf("%d", &num_sottoreti);
  }while(num_sottoreti > max_sottoreti || num_sottoreti <= 1);
  host_sottorete = (int*) malloc(num_sottoreti * sizeof(int));
  for(i = 0; i < num_sottoreti && max_pot2 > 0; i++){
    do{
      printf("Inserisci il numero di host della sottorete numero %d: ", i + 1);
      scanf("%d", &host_sottorete[i]);
    }while(host_sottorete[i] <= 0);
    pot2_controllo_possibile_esponente = log2(host_sottorete[i] + 3) + 1;
    pot2_controllo_possibile = pow(2, pot2_controllo_possibile_esponente);
    max_pot2 = max_pot2 - pot2_controllo_possibile;
    if(max_pot2 > 0){
      printf("Spazio disponibile = %d\n", max_pot2);
    }
  }
  if(i < num_sottoreti && max_pot2 <= 0){
  	printf("Non e' possibile completare la tua richiesta\n");
  	return;
  }
  for(i = 0; i < num_sottoreti; i++){
    somma_host = somma_host + host_sottorete[i];
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
  j = 0;
  cont_host = 0;
  printf("Ecco l'ordine delle reti:\n");
  for(i = 0; i < num_sottoreti; i++){
    printf("%d) %d Host, Potenza di 2 piu' vicina: 2^%d\n", i + 1, host_sottorete[i] - 2, bit_host[i]);
  }
  printf("\tNETWORK ID\tGATEWAY\t\tBROADCAST\tPRIMO HOST\tULTIMO HOST\tSUBNET MASK\n");
  cont_bit = 0;
  cont_pot = 24 - bit_host[cont_bit];
  conversione_decimale_binario(ip_dec, ip.ip_bin);
  for(cont = 0; cont < num_sottoreti; cont++){
    cont_pot = 24 - bit_host[cont_bit];
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin[i];
    }
    for(i = 7 + (cont_pot + 1); i < 32; i++){
      ip_temp[i] = 0;
    }
    conversione_binario_decimale(ip_dec, ip.ip_bin);
    printf("%d)\t", cont + 1);
    printf("%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]);
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin[i];
    }
    ip_temp[31] = 1;
    conversione_binario_decimale(ip_dec, ip_temp);
    ip.range[0] = ip_dec[3] + 1;
    printf("%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]);
    ip.ip_gateway[0] = ip_dec[0];
    ip.ip_gateway[1] = ip_dec[1];
    ip.ip_gateway[2] = ip_dec[2];
    ip.ip_gateway[3] = ip_dec[3];
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin[i];
    }
    for(i = 7 + (cont_pot + 1); i < 32; i++){
      ip_temp[i] = 1;
    }  
    conversione_binario_decimale(ip_dec, ip_temp);
    printf("%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]);
    conversione_decimale_binario_semplice((host_sottorete[cont_host] - 3), ip.numero_sottorete_bin);
    for(i = 31; i > 31 - bit_host[cont_bit]; i--){
      ip_temp[i] = ip.numero_sottorete_bin[i];
    }
    cont_host++;
    conversione_binario_decimale(ip_dec, ip_temp);
    printf("%03d.%03d.%03d.%03d\t", ip.ip_gateway[0], ip.ip_gateway[1], ip.ip_gateway[2], ip.range[0]);
    printf("%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]);
    for(i = 8; i <= 31 - bit_host[cont_bit]; i++){
      ip.subnet_mask_bin[i] = 1;
    }
    conversione_binario_decimale(ip.subnet_mask_dec, ip.subnet_mask_bin);
    printf("%03d.%03d.%03d.%03d\t", ip.subnet_mask_dec[0], ip.subnet_mask_dec[1], ip.subnet_mask_dec[2], ip.subnet_mask_dec[3]);
    conversione_decimale_binario_semplice(cont + 1, ip.numero_sottorete_bin);
    
    k = 31;
    printf("\n\n");
    cont_bit++;
    resto = 0;
    somma = 1;
    for(i = 7 + cont_pot; i >= 8; i--){
      resto = ip.ip_bin[i] * somma;
      ip.ip_bin[i] = ip.ip_bin[i] ^ somma;
      ip.ip_bin[i - 1] = ip.ip_bin[i - 1] ^ resto;
      somma = 0;
    }
  }
  percentuale = (100 * max_pot2) / 256;
  percentuale = 100 - percentuale;
  printf("Rete utilizzata: %d%c\n", percentuale, '%');
}

void creatore_sottoreti_b_variabile(int *ip_dec){
  indirizzi_vlsm ip;
  int somma;
  int resto;
  int *host_sottorete;
  int num_sottoreti;
  int bit_host[64];
  int ip_temp[32];
  int clone_ip_dec[4];
  int somma_host;
  int i;
  int j;
  int k;
  int temp;
  int cont;
  int cont_pot;
  int cont_bit;
  int cont_host;
  int max_sottoreti;
  int pot2_controllo_possibile_esponente;
  int pot2_controllo_possibile;
  int max_pot2;
  int percentuale;
  max_pot2 = 256 * 256;
  max_sottoreti = pow(2, 14);
  ip_dec[3] = 0;
  ip_dec[2] = 0;
  somma_host = 0;
  for(i = 0; i < 32; i++){
    if(i < 16){
      ip.subnet_mask_bin[i] = 1;
    }
    else{
      ip.subnet_mask_bin[i] = 0;
    }
  }
  do{
    printf("Inserisci il numero di sottoreti (MAX %d): ", max_sottoreti);
    scanf("%d", &num_sottoreti);
  }while(num_sottoreti > pow(2, 14) || num_sottoreti <= 1);
  host_sottorete = (int*) malloc(num_sottoreti * sizeof(int));  
  for(i = 0; i < num_sottoreti && max_pot2 > 0; i++){
    do{
      printf("Inserisci il numero di host della sottorete numero %d: ", i + 1);
      scanf("%d", &host_sottorete[i]);
    }while(host_sottorete[i] <= 0);
    pot2_controllo_possibile_esponente = log2(host_sottorete[i] + 3) + 1;
    pot2_controllo_possibile = pow(2, pot2_controllo_possibile_esponente);
    max_pot2 = max_pot2 - pot2_controllo_possibile;
    if(max_pot2 > 0){
      printf("Spazio disponibile = %d\n", max_pot2);
    }
  }
  if(i < num_sottoreti && max_pot2 <= 0){
  	printf("Non e' possibile completare la tua richiesta\n");
  	return;
  }
  for(i = 0; i < num_sottoreti; i++){
    somma_host = somma_host + host_sottorete[i];
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
  printf("Ecco l'ordine delle reti:\n");
  for(i = 0; i < num_sottoreti; i++){
    printf("%d) %d Host, Potenza di 2 piu' vicina: 2^%d\n", i + 1, host_sottorete[i] - 2, bit_host[i]);
  }
  printf("\tNETWORK ID\tGATEWAY\t\tBROADCAST\tPRIMO HOST\tULTIMO HOST\tSUBNET MASK\n");
  cont_bit = 0;
  cont_pot = 16 - bit_host[cont_bit];
  conversione_decimale_binario(ip_dec, ip.ip_bin);
  j = 0;
  cont_host = 0;
  for(cont = 0; cont < num_sottoreti; cont++){
    cont_pot = 16 - bit_host[cont_bit];
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin[i];
    }
    for(i = 15 + (cont_pot + 1); i < 32; i++){
      ip_temp[i] = 0;
    }
    conversione_binario_decimale(ip_dec, ip_temp);
    printf("%d)\t", cont + 1);
    printf("%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]);
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin[i];
    }
    ip_temp[31] = 1;
    conversione_binario_decimale(ip_dec, ip_temp);
    ip.range[0] = ip_dec[3] + 1;
    printf("%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]);
    ip.ip_gateway[0] = ip_dec[0];
    ip.ip_gateway[1] = ip_dec[1];
    ip.ip_gateway[2] = ip_dec[2];
    ip.ip_gateway[3] = ip_dec[3];
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin[i];
    }
    for(i = 15 + (cont_pot + 1); i < 32; i++){
      ip_temp[i] = 1;
    }  
    conversione_binario_decimale(ip_dec, ip_temp);
    printf("%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]);
    conversione_decimale_binario_semplice((host_sottorete[cont_host] - 3), ip.numero_sottorete_bin);
    for(i = 31; i > 31 - bit_host[cont_bit]; i--){
      ip_temp[i] = ip.numero_sottorete_bin[i];
    }
    conversione_binario_decimale(ip_dec, ip_temp);
    cont_host++;
    printf("%03d.%03d.%03d.%03d\t", ip.ip_gateway[0], ip.ip_gateway[1], ip.ip_gateway[2], ip.range[0]);
    printf("%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]);
    for(i = 16; i <= 31 - bit_host[cont_bit]; i++){
      ip.subnet_mask_bin[i] = 1;
    }
    conversione_binario_decimale(ip.subnet_mask_dec, ip.subnet_mask_bin);
    printf("%03d.%03d.%03d.%03d\t", ip.subnet_mask_dec[0], ip.subnet_mask_dec[1], ip.subnet_mask_dec[2], ip.subnet_mask_dec[3]);
    conversione_decimale_binario_semplice(cont + 1, ip.numero_sottorete_bin);
    
    k = 31;
    printf("\n\n");
    cont_bit++;
    resto = 0;
    somma = 1;
    for(i = 15 + cont_pot; i >= 16; i--){
      resto = ip.ip_bin[i] * somma;
      ip.ip_bin[i] = ip.ip_bin[i] ^ somma;
      ip.ip_bin[i - 1] = ip.ip_bin[i - 1] ^ resto;
      somma = 0;
    }
  }
  percentuale = (100 * max_pot2) / 256;
  percentuale = 100 - percentuale;
  printf("Rete utilizzata: %d%c\n", percentuale, '%');
}


void creatore_sottoreti_c_variabile(int *ip_dec){
  indirizzi_vlsm ip;
  int somma;
  int resto;
  int host_sottorete[64];
  int num_sottoreti;
  int bit_host[64];
  int ip_temp[32];
  int clone_ip_dec[4];
  int somma_host;
  int i;
  int j;
  int k;
  int temp;
  int cont;
  int cont_pot;
  int cont_bit;
  int cont_host;
  int max_sottoreti;
  int pot2_controllo_possibile_esponente;
  int pot2_controllo_possibile;
  int max_pot2;
  int percentuale;
  max_pot2 = 256;
  max_sottoreti = pow(2, 6);
  ip_dec[3] = 0;
  somma_host = 0;
  for(i = 0; i < 32; i++){
    if(i < 24){
      ip.subnet_mask_bin[i] = 1;
    }
    else{
      ip.subnet_mask_bin[i] = 0;
    }
  }
  do{
    printf("Inserisci il numero di sottoreti (MAX 64): ", max_sottoreti);
    scanf("%d", &num_sottoreti);
  }while(num_sottoreti > 64 || num_sottoreti <= 1);
  for(i = 0; i < num_sottoreti && max_pot2 > 0; i++){
    do{
      printf("Inserisci il numero di host della sottorete numero %d: ", i + 1);
      scanf("%d", &host_sottorete[i]);
    }while(host_sottorete[i] <= 0);
    pot2_controllo_possibile_esponente = log2(host_sottorete[i] + 3) + 1;
    pot2_controllo_possibile = pow(2, pot2_controllo_possibile_esponente);
    max_pot2 = max_pot2 - pot2_controllo_possibile;
    if(max_pot2 > 0){
      printf("Spazio disponibile = %d\n", max_pot2);
    }
  }
  if(i < num_sottoreti && max_pot2 <= 0){
  	printf("Non e' possibile completare la tua richiesta\n");
  	return;
  }
  for(i = 0; i < num_sottoreti; i++){
    somma_host = somma_host + host_sottorete[i];
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
  printf("Ecco l'ordine delle reti:\n");
  for(i = 0; i < num_sottoreti; i++){
    printf("%d) %d Host, Potenza di 2 piu' vicina: 2^%d\n", i + 1, host_sottorete[i] - 2, bit_host[i]);
  }
  printf("\tNETWORK ID\tGATEWAY\t\tBROADCAST\tPRIMO HOST\tULTIMO HOST\tSUBNET MASK\n");
  cont_bit = 0;
  cont_pot = 8 - bit_host[cont_bit];
  conversione_decimale_binario(ip_dec, ip.ip_bin);
  j = 0;
  cont_host = 0;
  for(cont = 0; cont < num_sottoreti; cont++){
    cont_pot = 8 - bit_host[cont_bit];
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin[i];
    }
    for(i = 23 + (cont_pot + 1); i < 32; i++){
      ip_temp[i] = 0;
    }
    conversione_binario_decimale(ip_dec, ip.ip_bin);
    printf("%d)\t", cont + 1);
    printf("%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]);
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin[i];
    }
    ip_temp[31] = 1;
    conversione_binario_decimale(ip_dec, ip_temp);
    ip.range[0] = ip_dec[3] + 1;
    printf("%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]);
    ip.ip_gateway[0] = ip_dec[0];
    ip.ip_gateway[1] = ip_dec[1];
    ip.ip_gateway[2] = ip_dec[2];
    ip.ip_gateway[3] = ip_dec[3];
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin[i];
    }
    for(i = 23 + (cont_pot + 1); i < 32; i++){
      ip_temp[i] = 1;
    }  
    conversione_binario_decimale(ip_dec, ip_temp);
    printf("%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]);
    conversione_decimale_binario_semplice((host_sottorete[cont_host] - 3), ip.numero_sottorete_bin);
    for(i = 31; i > 31 - bit_host[cont_bit]; i--){
      ip_temp[i] = ip.numero_sottorete_bin[i];
    }
    cont_host++;
    conversione_binario_decimale(ip_dec, ip_temp);
    printf("%03d.%03d.%03d.%03d\t", ip.ip_gateway[0], ip.ip_gateway[1], ip.ip_gateway[2], ip.range[0]);
    printf("%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]);
    for(i = 24; i <= 23 + (8 - bit_host[cont_bit]); i++){
      ip.subnet_mask_bin[i] = 1;
    }
    conversione_binario_decimale(ip.subnet_mask_dec, ip.subnet_mask_bin);
    printf("%03d.%03d.%03d.%03d\t", ip.subnet_mask_dec[0], ip.subnet_mask_dec[1], ip.subnet_mask_dec[2], ip.subnet_mask_dec[3]);
    conversione_decimale_binario_semplice(cont + 1, ip.numero_sottorete_bin);
    k = 31;
    printf("\n\n");
    cont_bit++;
    resto = 0;
    somma = 1;
    for(i = 23 + cont_pot; i >= 24; i--){
      resto = ip.ip_bin[i] * somma;
      ip.ip_bin[i] = ip.ip_bin[i] ^ somma;
      ip.ip_bin[i - 1] = ip.ip_bin[i - 1] ^ resto;
      somma = 0;
    }
  }
  percentuale = (100 * max_pot2) / 256;
  percentuale = 100 - percentuale;
  printf("Rete utilizzata: %d%c\n", percentuale, '%');
}
