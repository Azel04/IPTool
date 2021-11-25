void creatore_sottoreti_c(int *ip_dec_dot);
void creatore_sottoreti_b(int *ip_dec_dot);
void creatore_sottoreti_a(int *ip_dec_dot);
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
}indirizzi;

void creatore_sottoreti_a(int *ip_dec_dot){
  indirizzi ip;
  int clone_ip_dec_dot[4];  
  int num_sottoreti;
  int pot2;
  int j;
  int i;
  int k;
  int cont_pot;
  int cont;
  int intervallo_pot;
  int intervallo;
  int ip_temp[32];
  for(i = 0; i < 32; i++){
    ip.subnet_mask_bin[i] = 0;
  }
  pot2 = 0;
  cont_pot = 0;
  ip.net_id = 0;
  ip_dec_dot[1] = 0;
  ip_dec_dot[2] = 0;
  ip_dec_dot[3] = 0;
  do{
    printf("Digita il numero di sottoreti da creare: ");
    scanf("%d", &num_sottoreti);
		if(num_sottoreti <= 0 || num_sottoreti >= pow(2, 21)){
      printf("Non e' possibile soddisfare la tua richiesta\n");
    }
  }while(num_sottoreti <= 0 || num_sottoreti >= pow(2, 21));
  do{
    pot2 = pow(2,cont_pot);
    cont_pot++;
  }while(pot2 < num_sottoreti);
  intervallo = 256 / pot2;
  for(i = 0; i < 4; i++){
    clone_ip_dec_dot[i] = ip_dec_dot[i];
  }
  printf("\tNETWORK ID\tGATEWAY\t\tBROADCAST\tPRIMO HOST\tULTIMO HOST\n");
  conversione_decimale_binario(ip_dec_dot, ip.ip_bin_dot);
  for(cont = 0; cont < num_sottoreti; cont++){
    
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin_dot[i];
    }
    for(i = 7 + cont_pot; i < 32; i++){
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
    for(i = 7 + cont_pot; i < 32; i++){
      ip_temp[i] = 1;
    }  
    conversione_binario_decimale(ip_dec_dot, ip_temp);
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip_dec_dot[3]);
    ip.range[1] = ip_dec_dot[3] - 1;
    printf("%d.%d.%d.%d\t", ip.ip_gateway[0], ip.ip_gateway[1], ip.ip_gateway[2], ip.range[0]);
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip.range[1]);
    conversione_decimale_binario_semplice(cont + 1, ip.numero_sottorete_bin);
    j = 0;
    k = 31;
    for(i = 7 + cont_pot - 1; j <= cont_pot - 1; j++){
      ip.ip_bin_dot[i] = ip.numero_sottorete_bin[k];
      k--;
      i--;
    }
    printf("\n\n");
  }
  ip.host_per_sottorete = 0;
  ip.host_per_sottorete = pow(2, (32 - (8 + (cont_pot - 1)))) - 1;
  for(i = 0; i < 8 + (cont_pot - 1); i++){
    ip.subnet_mask_bin[i] = 1;
  }
  conversione_binario_decimale(ip.subnet_mask_dec, ip.subnet_mask_bin);
  printf("INDIRIZZO IP CON CIDR: %d.0.0.0/%d\nHost per sottorete: %d\nSubnet mask: %d.%d.%d.%d\n", clone_ip_dec_dot[0], 8 + (cont_pot - 1), ip.host_per_sottorete, ip.subnet_mask_dec[0], ip.subnet_mask_dec[1], ip.subnet_mask_dec[2], ip.subnet_mask_dec[3]);

}

void creatore_sottoreti_b(int *ip_dec_dot){
  indirizzi ip;
  int clone_ip_dec_dot[4];
  int num_sottoreti;
  int pot2;
  int j;
  int i;
  int k;
  int cont_pot;
  int cont;
  int intervallo_pot;
  int intervallo;
  int ip_temp[32];

  pot2 = 0;
  cont_pot = 0;
  ip.net_id = 0;
  for(i = 0; i < 32; i++){
    ip.subnet_mask_bin[i] = 0;
  }
  ip_dec_dot[2] = 0;
  ip_dec_dot[3] = 0;
  do{
    printf("Digita il numero di sottoreti da creare: ");
    scanf("%d", &num_sottoreti);
		if(num_sottoreti <= 0 || num_sottoreti >= pow(2, 14)){
      printf("Non e' possibile soddisfare la tua richiesta\n");
    }
  }while(num_sottoreti <= 0 || num_sottoreti >= pow(2, 14));
  do{
    pot2 = pow(2,cont_pot);
    cont_pot++;
  }while(pot2 < num_sottoreti);
  intervallo = 256 / pot2;
  
  printf("\tNETWORK ID\tGATEWAY\t\tBROADCAST\tPRIMO HOST\tULTIMO HOST\n");
  conversione_decimale_binario(ip_dec_dot, ip.ip_bin_dot);
  for(cont = 0; cont < num_sottoreti; cont++){

    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin_dot[i];
    }
    for(i = 15 + cont_pot; i < 32; i++){
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
    for(i = 15 + cont_pot; i < 32; i++){
      ip_temp[i] = 1;
    }  
    conversione_binario_decimale(ip_dec_dot, ip_temp);
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip_dec_dot[3]);
    ip.range[1] = ip_dec_dot[3] - 1;
    printf("%d.%d.%d.%d\t", ip.ip_gateway[0], ip.ip_gateway[1], ip.ip_gateway[2], ip.range[0]);
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip.range[1]);
    conversione_decimale_binario_semplice(cont + 1, ip.numero_sottorete_bin);
    j = 0;
    k = 31;
    for(i = 15 + cont_pot - 1; j <= cont_pot - 1; j++){
      ip.ip_bin_dot[i] = ip.numero_sottorete_bin[k];
      k--;
      i--;
    }
    printf("\n\n");
  }
  ip.host_per_sottorete = 0;
  ip.host_per_sottorete = pow(2, (32 - (16 + (cont_pot - 1)))) - 1;
  for(i = 0; i < 16 + (cont_pot - 1); i++){
    ip.subnet_mask_bin[i] = 1;
  }
  conversione_binario_decimale(ip.subnet_mask_dec, ip.subnet_mask_bin);
  printf("INDIRIZZO IP CON CIDR: %d.0.0.0/%d\nHost per sottorete: %d\nSubnet mask: %d.%d.%d.%d\n", clone_ip_dec_dot[0], 16 + (cont_pot - 1), ip.host_per_sottorete, ip.subnet_mask_dec[0], ip.subnet_mask_dec[1], ip.subnet_mask_dec[2], ip.subnet_mask_dec[3]);
}


void creatore_sottoreti_c(int *ip_dec_dot){
  indirizzi ip;
  int clone_ip_dec_dot[4];
  int num_sottoreti;
  int pot2;
  int j;
  int i;
  int cont2;
  int k;
  int cont_pot;
  int cont;
  int intervallo_pot;
  int intervallo;
  int ip_temp[32];
  for(i = 0; i < 32; i++){
    ip.subnet_mask_bin[i] = 0;
  }
  pot2 = 0;
  num_sottoreti =0 ;
  ip.net_id = 0;
  ip.broadcast = 0;
  ip.gateway = 0;
  ip.range[0] = 0;
  ip.range[1] = 0;
  cont_pot = 0;
  cont = 0;
  intervallo = 0;
  ip_dec_dot[3] = 0;

  for(cont = 0; cont < 4; cont++){
    clone_ip_dec_dot[cont] = ip_dec_dot[cont];
  }

  do{
    printf("Digita il numero di sottoreti da creare: ");
    scanf("%d", &num_sottoreti);
	  if(num_sottoreti <= 0 || num_sottoreti >= 64){
			printf("Non e' possibile soddisfare la tua richiesta.\n");
	  }
  }while(num_sottoreti <= 0 || num_sottoreti >= 64);
  do{
    pot2 = pow(2,cont_pot);
    cont_pot++;
  }while(pot2 <= num_sottoreti);
  intervallo = 256 / pot2;

  ip.net_id = 0;
    
  printf("\tNETWORK ID\tBROADCAST\t\tGATEWAY\tPRIMO HOST\tULTIMO HOST\n");
  for(cont = 0; cont < num_sottoreti; cont++){
    ip.broadcast = ip.net_id + intervallo - 1;
    ip.gateway = ip.net_id + 1;
    ip.range[0] = ip.gateway + 1;
    ip.range[1] = ip.broadcast - 1;
		printf("%d)\t%d.%d.%d.%03d", cont + 1, ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip_dec_dot[3]);
		printf("\t%d.%d.%d.%03d", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip.broadcast);
		printf("\t%d.%d.%d.%03d", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip.gateway);
		printf("\t%d.%d.%d.%03d", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip.range[0]);
		printf("\t%d.%d.%d.%03d\n", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip.range[1]);		
    printf("\t");
    conversione_decimale_binario(ip_dec_dot, ip.ip_bin_dot);
    output_ip_bin_sottorete_c(ip.ip_bin_dot, (8 - intervallo_pot));
    ip.net_id = ip.net_id + intervallo;
    ip_dec_dot[3] = ip.net_id;
    for(cont2 = 0; cont2 < 3; cont2++){
      ip_dec_dot[cont2] = clone_ip_dec_dot[cont2];
    }

    printf("\n\n");
    }
  ip.host_per_sottorete = 0;

  ip.host_per_sottorete = pow(2, (32 - (24 + (cont_pot - 1)))) - 1;
  for(i = 0; i < 24 + (cont_pot - 1); i++){
    ip.subnet_mask_bin[i] = 1;
  }
  conversione_binario_decimale(ip.subnet_mask_dec, ip.subnet_mask_bin);
  printf("INDIRIZZO IP CON CIDR: %d.0.0.0/%d\nNumero Host per sottorete: %d\nSubnet mask: %d.%d.%d.%d\n", clone_ip_dec_dot[0], 24 + (cont_pot - 1), ip.host_per_sottorete, ip.subnet_mask_dec[0], ip.subnet_mask_dec[1], ip.subnet_mask_dec[2], ip.subnet_mask_dec[3]);

}


void creatore_sottoreti_a_variabile(int *ip_dec_dot){
  indirizzi ip;
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
  ip_dec_dot[3] = 0;
  ip_dec_dot[2] = 0;
  ip_dec_dot[1] = 0;
  do{
    printf("Inserisci il numero di sottoreti (MAX %ld): ", pow(2, 7));
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
    ip.range[1] = ip_dec_dot[3] - 1;
    printf("%d.%d.%d.%d\t", ip.ip_gateway[0], ip.ip_gateway[1], ip.ip_gateway[2], ip.range[0]);
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip.range[1]);
    conversione_decimale_binario_semplice(cont + 1, ip.numero_sottorete_bin);
    j = 0;
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
  indirizzi ip;
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
  ip_dec_dot[3] = 0;
  ip_dec_dot[2] = 0;
  do{
    printf("Inserisci il numero di sottoreti (MAX %ld): ", pow(2, 14));
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
  printf("Ecco l'ordine delle reti:\n");
  for(i = 0; i < num_sottoreti; i++){
    printf("%d) %d Host, Potenza di 2 piu' vicina: 2^%d\n", i + 1, host_sottorete[i] - 2, bit_host[i]);
  }
  printf("\tNETWORK ID\tGATEWAY\t\tBROADCAST\tPRIMO HOST\tULTIMO HOST\n");
  cont_bit = 0;
  cont_pot = 16 - bit_host[cont_bit];
  conversione_decimale_binario(ip_dec_dot, ip.ip_bin_dot);
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
    ip.range[1] = ip_dec_dot[3] - 1;
    printf("%d.%d.%d.%d\t", ip.ip_gateway[0], ip.ip_gateway[1], ip.ip_gateway[2], ip.range[0]);
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip.range[1]);
    conversione_decimale_binario_semplice(cont + 1, ip.numero_sottorete_bin);
    j = 0;
    k = 31;
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
  indirizzi ip;
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
  ip_dec_dot[3] = 0;
  do{
    printf("Inserisci il numero di sottoreti (MAX %ld): ", pow(2, 21));
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
  printf("Ecco l'ordine delle reti:\n");
  for(i = 0; i < num_sottoreti; i++){
    printf("%d) %d Host, Potenza di 2 piu' vicina: 2^%d\n", i + 1, host_sottorete[i] - 2, bit_host[i]);
  }
  printf("\tNETWORK ID\tGATEWAY\t\tBROADCAST\tPRIMO HOST\tULTIMO HOST\n");
  cont_bit = 0;
  cont_pot = 8 - bit_host[cont_bit];
  conversione_decimale_binario(ip_dec_dot, ip.ip_bin_dot);
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
    ip.range[1] = ip_dec_dot[3] - 1;
    printf("%d.%d.%d.%d\t", ip.ip_gateway[0], ip.ip_gateway[1], ip.ip_gateway[2], ip.range[0]);
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip.range[1]);
    conversione_decimale_binario_semplice(cont + 1, ip.numero_sottorete_bin);
    j = 0;
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
