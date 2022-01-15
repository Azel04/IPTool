void creatore_sottoreti_c(int *ip_dec);
void creatore_sottoreti_b(int *ip_dec);
void creatore_sottoreti_a(int *ip_dec);

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
}indirizzi;

void creatore_sottoreti_a(int *ip_dec){
  indirizzi ip;
  int clone_ip_dec[4];  
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
  ip_dec[1] = 0;
  ip_dec[2] = 0;
  ip_dec[3] = 0;
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
    clone_ip_dec[i] = ip_dec[i];
  }
  printf("\tNETWORK ID\tGATEWAY\t\tBROADCAST\tPRIMO HOST\tULTIMO HOST\n");
  conversione_decimale_binario(ip_dec, ip.ip_bin);
  for(cont = 0; cont < num_sottoreti; cont++){
    
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin[i];
    }
    for(i = 7 + cont_pot; i < 32; i++){
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
    for(i = 7 + cont_pot; i < 32; i++){
      ip_temp[i] = 1;
    }  
    conversione_binario_decimale(ip_dec, ip_temp);
    printf("%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]);
    ip.range[1] = ip_dec[3] - 1;
    printf("%03d.%03d.%03d.%03d\t", ip.ip_gateway[0], ip.ip_gateway[1], ip.ip_gateway[2], ip.range[0]);
    printf("%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip.range[1]);
    conversione_decimale_binario_semplice(cont + 1, ip.numero_sottorete_bin);
    j = 0;
    k = 31;
    for(i = 7 + cont_pot - 1; j < cont_pot - 1; j++){
      ip.ip_bin[i] = ip.numero_sottorete_bin[k];
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
  printf("INDIRIZZO IP CON CIDR: %d.0.0.0/%d\nHost per sottorete: %d\nSubnet mask: %d.%d.%d.%d\n", clone_ip_dec[0], 8 + (cont_pot - 1), ip.host_per_sottorete, ip.subnet_mask_dec[0], ip.subnet_mask_dec[1], ip.subnet_mask_dec[2], ip.subnet_mask_dec[3]);

}

void creatore_sottoreti_b(int *ip_dec){
  indirizzi ip;
  int clone_ip_dec[4];
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
  ip_dec[2] = 0;
  ip_dec[3] = 0;
  for(i = 0; i < 4; i++){
    clone_ip_dec[i] = ip_dec[i];
  }
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
  conversione_decimale_binario(ip_dec, ip.ip_bin);
  for(cont = 0; cont < num_sottoreti; cont++){

    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin[i];
    }
    for(i = 15 + cont_pot; i < 32; i++){
      ip_temp[i] = 0;
    }
    conversione_binario_decimale(ip_dec, ip.ip_bin);
    printf("%d)\t", cont + 1);
    printf("%d.%d.%d.%d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]);
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin[i];
    }
    ip_temp[31] = 1;
    conversione_binario_decimale(ip_dec, ip_temp);
    ip.range[0] = ip_dec[3] + 1;
    printf("%d.%d.%d.%d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]);
    ip.ip_gateway[0] = ip_dec[0];
    ip.ip_gateway[1] = ip_dec[1];
    ip.ip_gateway[2] = ip_dec[2];
    ip.ip_gateway[3] = ip_dec[3];
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin[i];
    }
    for(i = 15 + cont_pot; i < 32; i++){
      ip_temp[i] = 1;
    }  
    conversione_binario_decimale(ip_dec, ip_temp);
    printf("%d.%d.%d.%d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]);
    ip.range[1] = ip_dec[3] - 1;
    printf("%d.%d.%d.%d\t", ip.ip_gateway[0], ip.ip_gateway[1], ip.ip_gateway[2], ip.range[0]);
    printf("%d.%d.%d.%d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip.range[1]);
    conversione_decimale_binario_semplice(cont + 1, ip.numero_sottorete_bin);
    j = 0;
    k = 31;
    for(i = 15 + cont_pot - 1; j < cont_pot - 1; j++){
      ip.ip_bin[i] = ip.numero_sottorete_bin[k];
      k--;
      i--;
    }
    printf("\n\n");
  }
  ip.host_per_sottorete = 0;
  ip.host_per_sottorete = pow(2, (32 - (16 + (cont_pot - 1)))) - 2;
  for(i = 0; i < 16 + (cont_pot - 1); i++){
    ip.subnet_mask_bin[i] = 1;
  }
  conversione_binario_decimale(ip.subnet_mask_dec, ip.subnet_mask_bin);
  printf("INDIRIZZO IP CON CIDR: %d.%d.0.0/%d\nHost per sottorete: %d\nSubnet mask: %d.%d.%d.%d\n", clone_ip_dec[0], clone_ip_dec[1], 16 + (cont_pot - 1), ip.host_per_sottorete, ip.subnet_mask_dec[0], ip.subnet_mask_dec[1], ip.subnet_mask_dec[2], ip.subnet_mask_dec[3]);
}


void creatore_sottoreti_c(int *ip_dec){
  indirizzi ip;
  int clone_ip_dec[4];
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
  ip_dec[3] = 0;

  for(cont = 0; cont < 4; cont++){
    clone_ip_dec[cont] = ip_dec[cont];
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
    
  printf("\tNETWORK ID\tGATEWAY\t\tBROADCAST\tPRIMO HOST\tULTIMO HOST\n");
  for(cont = 0; cont < num_sottoreti; cont++){
    ip.broadcast = ip.net_id + intervallo - 1;
    ip.gateway = ip.net_id + 1;
    ip.range[0] = ip.gateway + 1;
    ip.range[1] = ip.broadcast - 1;
		printf("%d)\t%d.%d.%d.%03d", cont + 1, ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]);
    printf("\t%d.%d.%d.%03d", ip_dec[0], ip_dec[1], ip_dec[2], ip.gateway);
		printf("\t%d.%d.%d.%03d", ip_dec[0], ip_dec[1], ip_dec[2], ip.broadcast);
		printf("\t%d.%d.%d.%03d", ip_dec[0], ip_dec[1], ip_dec[2], ip.range[0]);
		printf("\t%d.%d.%d.%03d\n", ip_dec[0], ip_dec[1], ip_dec[2], ip.range[1]);		
    printf("\t");
    conversione_decimale_binario(ip_dec, ip.ip_bin);
    output_ip_bin_sottorete_c(ip.ip_bin, (8 - intervallo_pot));
    ip.net_id = ip.net_id + intervallo;
    ip_dec[3] = ip.net_id;
    for(cont2 = 0; cont2 < 3; cont2++){
      ip_dec[cont2] = clone_ip_dec[cont2];
    }

    printf("\n\n");
    }
  ip.host_per_sottorete = 0;

  ip.host_per_sottorete = pow(2, (32 - (24 + (cont_pot - 1)))) - 1;
  for(i = 0; i < 24 + (cont_pot - 1); i++){
    ip.subnet_mask_bin[i] = 1;
  }
  conversione_binario_decimale(ip.subnet_mask_dec, ip.subnet_mask_bin);
  printf("INDIRIZZO IP CON CIDR: %d.%d.%d.%d/%d\nNumero Host per sottorete: %d\nSubnet mask: %d.%d.%d.%d\n", clone_ip_dec[0], clone_ip_dec[1], clone_ip_dec[2], clone_ip_dec[3], 24 + (cont_pot - 1), ip.host_per_sottorete, ip.subnet_mask_dec[0], ip.subnet_mask_dec[1], ip.subnet_mask_dec[2], ip.subnet_mask_dec[3]);

}
