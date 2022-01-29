void creatore_sottoreti_supernetting_c_file(int *ip_dec_supernetting);
void creatore_sottoreti_supernetting_b_file(int *ip_dec_supernetting);
void creatore_sottoreti_supernetting_a_file(int *ip_dec_supernetting);

typedef struct{
  int ip_bin[32];
  int ip_gateway[4];
  int subnet_mask_bin[32];
  int subnet_mask_dec[4];
  //int numero_sottorete_bin[32];
  int gateway;
  int range[2];
  int host_per_sottorete;
  int broadcast;
  int net_id;
  int host;
  int diff_supernet[8];
}indirizzi_supernet_file;

void creatore_sottoreti_supernetting_c_file(int *ip_dec_supernetting){
  indirizzi_supernet_file ip;
  FILE *fp;
  int num_host;
  int bit_sottr_supernet;
  int somma;
  somma = 0;
  bit_sottr_supernet = 0;
  int i;
  i = 0;
  do{
    printf("Inserire il numero di host: ");
    scanf("%d", &num_host);
  }while(num_host <= 0 || num_host > pow(2, 24));
  ip_dec_supernetting[3] = 0;
  
  
  do{
    somma = somma + pow(2, i);
    i++;
  }while(somma < num_host);
  if(i > 8){
  	bit_sottr_supernet = i - 8;
  }
  if(i > 16){
  	bit_sottr_supernet = i - 16;
  }
  if(i > 24){
  	bit_sottr_supernet = i - 24;
  }
  
  for(i = 0; i < 32; i++){
   if(i < 24 - bit_sottr_supernet){
     ip.subnet_mask_bin[i] = 1;
   }
   else{
     ip.subnet_mask_bin[i] = 0;
   }
  }
  ip.gateway =  ip_dec_supernetting[3] + 1;
  ip.broadcast = ip_dec_supernetting[2] + (pow(2, bit_sottr_supernet)) - 1;
  ip.range[0] = ip.gateway + 1;
  ip.range[1] = ip.broadcast - 1;
  fp = fopen("latest_flsm_supernet.txt", "w");
  fprintf(fp, "NETWORK ID\tGATEWAY\t\tBROADCAST\tPRIMO HOST\tULTIMO HOST\n");
  fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec_supernetting[0], ip_dec_supernetting[1], ip_dec_supernetting[2], ip_dec_supernetting[3]);
  fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec_supernetting[0], ip_dec_supernetting[1], ip_dec_supernetting[2], ip.gateway);
  fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec_supernetting[0], ip_dec_supernetting[1], ip.broadcast - 1, 255);
  fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec_supernetting[0], ip_dec_supernetting[1], ip_dec_supernetting[2], ip.range[0]);
  fprintf(fp, "%03d.%03d.%03d.%03d\n", ip_dec_supernetting[0], ip_dec_supernetting[1], ip.broadcast - 1, 254);
  fclose(fp);
}

void creatore_sottoreti_supernetting_b_file(int *ip_dec_supernetting){
  indirizzi_supernet_file ip;
  FILE *fp;
  int num_host;
  int bit_sottr_supernet;
  int somma;
  somma = 0;
  bit_sottr_supernet = 0;
  int i;
  i = 0;
  do{
    printf("Inserire il numero di host: ");
    scanf("%d", &num_host);
  }while(num_host <= 0 || num_host > pow(2, 16));
  ip_dec_supernetting[3] = 0;
  
  
  do{
    somma = somma + pow(2, i);
    i++;
  }while(somma < num_host);
  if(i > 8){
  	bit_sottr_supernet = i - 8;
  }
  if(i > 16){
  	bit_sottr_supernet = i - 16;
  }
  if(i > 24){
  	bit_sottr_supernet = i - 24;
  }
  
  for(i = 0; i < 32; i++){
   if(i < 16 - bit_sottr_supernet){
     ip.subnet_mask_bin[i] = 1;
   }
   else{
     ip.subnet_mask_bin[i] = 0;
   }
  }
  ip.gateway =  ip_dec_supernetting[3] + 1;
  ip.broadcast = ip_dec_supernetting[1] + (pow(2, bit_sottr_supernet)) - 1;
  ip.range[0] = ip.gateway + 1;
  ip.range[1] = ip.broadcast - 1;
  fp = fopen("latest_flsm_supernet.txt", "w");
  fprintf(fp, "NETWORK ID\tGATEWAY\t\tBROADCAST\tPRIMO HOST\tULTIMO HOST\n");
  fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec_supernetting[0], ip_dec_supernetting[1], ip_dec_supernetting[2], ip_dec_supernetting[3]);
  fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec_supernetting[0], ip_dec_supernetting[1], ip_dec_supernetting[2], ip.gateway);
  fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec_supernetting[0], ip_dec_supernetting[1], ip.broadcast - 1, 255);
  fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec_supernetting[0], ip_dec_supernetting[1], ip_dec_supernetting[2], ip.range[0]);
  fprintf(fp, "%03d.%03d.%03d.%03d\n", ip_dec_supernetting[0], ip_dec_supernetting[1], ip.broadcast - 1, 254);
  fclose(fp);
}

void creatore_sottoreti_supernetting_a_file(int *ip_dec_supernetting){
  indirizzi_supernet_file ip;
  FILE *fp;
  int num_host;
  int bit_sottr_supernet;
  int somma;
  somma = 0;
  bit_sottr_supernet = 0;
  int i;
  i = 0;
  do{
    printf("Inserire il numero di host: ");
    scanf("%d", &num_host);
  }while(num_host <= 0 || num_host > pow(2, 8));
  ip_dec_supernetting[3] = 0;

  do{
    somma = somma + pow(2, i);
    i++;
  }while(somma < num_host);
  i--;
  if(i > 8){
  	bit_sottr_supernet = i - 8;
  }
  if(i > 16){
  	bit_sottr_supernet = i - 16;
  }
  if(i > 24){
  	bit_sottr_supernet = i - 24;
  }
  	
  
  for(i = 0; i < 32; i++){
   if(i < 8 - bit_sottr_supernet){
     ip.subnet_mask_bin[i] = 1;
   }
   else{
     ip.subnet_mask_bin[i] = 0;
   }
  }
  ip.gateway =  ip_dec_supernetting[3] + 1;
  ip.broadcast = ip_dec_supernetting[0] + (pow(2, bit_sottr_supernet));
  ip.range[0] = ip.gateway + 1;
  ip.range[1] = ip.broadcast - 1;
  fp = fopen("latest_flsm_supernet.txt", "w");
  fprintf(fp, "NETWORK ID\tGATEWAY\t\tBROADCAST\tPRIMO HOST\tULTIMO HOST\n");
  fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec_supernetting[0], ip_dec_supernetting[1], ip_dec_supernetting[2], ip_dec_supernetting[3]);
  fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec_supernetting[0], ip_dec_supernetting[1], ip_dec_supernetting[2], ip.gateway);
  fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec_supernetting[0], ip_dec_supernetting[1], ip.broadcast - 1, 255);
  fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec_supernetting[0], ip_dec_supernetting[1], ip_dec_supernetting[2], ip.range[0]);
  fprintf(fp, "%03d.%03d.%03d.%03d\n", ip_dec_supernetting[0], ip_dec_supernetting[1], ip.broadcast - 1, 254);
  fclose(fp);
}


