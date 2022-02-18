void creatore_sottoreti_supernetting_c_file(int *ip_dec_supernetting);
void creatore_sottoreti_supernetting_b_file(int *ip_dec_supernetting);
void creatore_sottoreti_supernetting_a_file(int *ip_dec_supernetting);

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
  int diff_supernet[8];
}indirizzi_supernet_file;

void creatore_sottoreti_supernetting_c_file(int *ip_dec){
  indirizzi_supernet_file ip;
  FILE *fp;
  char *buffer;
  long size;
  int scelta;
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
  int temp_controllo_addizione;
  int cont_pot;
  int cont_bit;
  int cont_host;
  int max_sottoreti;
  int percentuale;
  max_sottoreti = pow(2, 22);
  somma_host = 0;
  int pot2_controllo_possibile_esponente;
  int pot2_controllo_possibile;
  int max_pot2;
  max_pot2 = 256; //Calcolo spazio massimo
  max_sottoreti = pow(2, 22); //Calcono numero sottoreti massime
  for(i = 0; i < 32; i++){ //Calcolo subnet mask
    if(i < 8){
      ip.subnet_mask_bin[i] = 1;
    }
    else{
      ip.subnet_mask_bin[i] = 0;
    }
  }
  do{ //Input numero sottoreti
    printf("Inserisci il numero di sottoreti (MAX %d): ", max_sottoreti);
    scanf("%d", &num_sottoreti);
  }while(num_sottoreti > max_sottoreti || num_sottoreti <= 1);
  host_sottorete = (int*) malloc(num_sottoreti * sizeof(int));

  for(i = 0; i < num_sottoreti; i++){ //Input numero host con controlli
    do{
      printf("Inserisci il numero di host della sottorete numero %d: ", i + 1);
      scanf("%d", &host_sottorete[i]);
    }while(host_sottorete[i] <= 0);
  }
  for(i = 0; i < num_sottoreti; i++){ //Ordinamento reti
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
  for(i = 0; i < num_sottoreti; i++){ //Calcolo bit host
    bit_host[i] = log2(host_sottorete[i]) + 1;
  }
  j = 0;
  cont_host = 0;
  fp = fopen("latest_supernet.txt", "w");
  fprintf(fp, "Ecco l'ordine delle reti:\n");
  for(i = 0; i < num_sottoreti; i++){
    fprintf(fp, "%d) %d Host, Potenza di 2 piu' vicina: 2^%d\n", i + 1, host_sottorete[i] - 2, bit_host[i]);
  }
  fprintf(fp, "\tNETWORK ID\tGATEWAY\t\tBROADCAST\tPRIMO HOST\tULTIMO HOST\tSUBNET MASK\n");
  cont_bit = 0;
  cont_pot = 24 - bit_host[cont_bit];

  conversione_decimale_binario(ip_dec, ip.ip_bin);  
  //INIZIO CALCOLO RETE
  for(cont = 0; cont < num_sottoreti; cont++){
    cont_pot = 24 - bit_host[cont_bit]; //calcola posizione dei bit della rete/host
    for(i = 0; i < 32; i++){ //Clone ip
      ip_temp[i] = ip.ip_bin[i];
    }
    for(i = (31 - bit_host[cont_bit]) + 1; i < 32; i++){ //Calcolo net id
      ip_temp[i] = 0;
    }
    conversione_binario_decimale(ip_dec, ip_temp);
    fprintf(fp, "%d)\t", cont + 1);
    fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]); //Output ned id
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin[i];
    }
    ip_temp[31] = 1; //Calcolo gateway
    conversione_binario_decimale(ip_dec, ip_temp);
    ip.range[0] = ip_dec[3] + 1;
    fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]); //Output gateway
    ip.ip_gateway[0] = ip_dec[0];
    ip.ip_gateway[1] = ip_dec[1];
    ip.ip_gateway[2] = ip_dec[2];
    ip.ip_gateway[3] = ip_dec[3];
    for(i = 0; i < 32; i++){ //Clone ip
      ip_temp[i] = ip.ip_bin[i];
    }
    for(i = (31 - bit_host[cont_bit]) + 1; i < 32; i++){ //Calcolo broadcast
      ip_temp[i] = 1;
    }  
    conversione_binario_decimale(ip_dec, ip_temp);
    fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]); //Output broadcast
    conversione_decimale_binario_semplice((host_sottorete[cont_host] - 3), ip.numero_sottorete_bin);
    for(i = 31; i > 31 - bit_host[cont_bit]; i--){
      ip_temp[i] = ip.numero_sottorete_bin[i];
    }
    cont_host++;
    conversione_binario_decimale(ip_dec, ip_temp);
    fprintf(fp, "%03d.%03d.%03d.%03d\t", ip.ip_gateway[0], ip.ip_gateway[1], ip.ip_gateway[2], ip.range[0]); //Output range
    fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]);
    for(i = 8; i <= 31 - bit_host[cont_bit]; i++){
      ip.subnet_mask_bin[i] = 1;
    }
    conversione_binario_decimale(ip.subnet_mask_dec, ip.subnet_mask_bin);
    fprintf(fp, "%03d.%03d.%03d.%03d\t", ip.subnet_mask_dec[0], ip.subnet_mask_dec[1], ip.subnet_mask_dec[2], ip.subnet_mask_dec[3]);
    conversione_decimale_binario_semplice(cont + 1, ip.numero_sottorete_bin);
    
    k = 31;
    fprintf(fp, "\n\n");
    cont_bit++;
    resto = 0;
    somma = 1;
    for(i = 31 - bit_host[cont_bit]; i >= 8; i = i - 2){
      resto = ip.ip_bin[i] * somma;
      ip.ip_bin[i] = ip.ip_bin[i] ^ somma;
      temp_controllo_addizione = ip.ip_bin[i - 1];
      ip.ip_bin[i - 1] = ip.ip_bin[i - 1] ^ resto;
      if(ip.ip_bin[i - 1] == 0 && temp_controllo_addizione == 1){
        somma = resto;
      }
      else{
        i = 7;
      }
    }
  }
  printf("Il file si trova nella cartella del programma e si chiama 'latest_supernet.txt'\n");
  fclose(fp);
  fp = fopen("latest_supernet.txt", "r");
  fseek(fp, 0, SEEK_END);
  size = ftell(fp);
  rewind(fp);
  buffer = (char *) calloc(size, sizeof(char));
  fread(buffer, sizeof(char), size, fp);
  printf(buffer);
  free(buffer);
  fclose(fp);
  do{
    printf("Vuoi salvare il file? (1 = si; 0 = no): ");
    scanf("%d", &scelta);
    if(scelta == 0){
      remove("latest_supernet.txt");
    }
  }while(scelta < 0 || scelta > 1);

}

void creatore_sottoreti_supernetting_b_file(int *ip_dec){
  indirizzi_supernet_file ip;
  FILE *fp;
  char *buffer;
  long size;
  int scelta;
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
  int temp_controllo_addizione;
  int cont_pot;
  int cont_bit;
  int cont_host;
  int max_sottoreti;
  int percentuale;
  max_sottoreti = pow(2, 22);
  somma_host = 0;
  int pot2_controllo_possibile_esponente;
  int pot2_controllo_possibile;
  int max_pot2;
  max_pot2 = 256 * 256; //Calcolo spazio massimo
  max_sottoreti = pow(2, 22); //Calcono numero sottoreti massime
  for(i = 0; i < 32; i++){ //Calcolo subnet mask
    if(i < 8){
      ip.subnet_mask_bin[i] = 1;
    }
    else{
      ip.subnet_mask_bin[i] = 0;
    }
  }
  do{ //Input numero sottoreti
    printf("Inserisci il numero di sottoreti (MAX %d): ", max_sottoreti);
    scanf("%d", &num_sottoreti);
  }while(num_sottoreti > max_sottoreti || num_sottoreti <= 1);
  host_sottorete = (int*) malloc(num_sottoreti * sizeof(int));

  for(i = 0; i < num_sottoreti; i++){ //Input numero host con controlli
    do{
      printf("Inserisci il numero di host della sottorete numero %d: ", i + 1);
      scanf("%d", &host_sottorete[i]);
    }while(host_sottorete[i] <= 0);
  }
  for(i = 0; i < num_sottoreti; i++){ //Ordinamento reti
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
  for(i = 0; i < num_sottoreti; i++){ //Calcolo bit host
    bit_host[i] = log2(host_sottorete[i]) + 1;
  }
  j = 0;
  cont_host = 0;
  fp = fopen("latest_supernet.txt", "w");
  fprintf(fp, "Ecco l'ordine delle reti:\n");
  for(i = 0; i < num_sottoreti; i++){
    fprintf(fp, "%d) %d Host, Potenza di 2 piu' vicina: 2^%d\n", i + 1, host_sottorete[i] - 2, bit_host[i]);
  }
  fprintf(fp, "\tNETWORK ID\tGATEWAY\t\tBROADCAST\tPRIMO HOST\tULTIMO HOST\tSUBNET MASK\n");
  cont_bit = 0;
  cont_pot = 16 - bit_host[cont_bit];

  conversione_decimale_binario(ip_dec, ip.ip_bin);  
  //INIZIO CALCOLO RETE
  for(cont = 0; cont < num_sottoreti; cont++){
    cont_pot = 24 - bit_host[cont_bit]; //calcola posizione dei bit della rete/host
    for(i = 0; i < 32; i++){ //Clone ip
      ip_temp[i] = ip.ip_bin[i];
    }
    for(i = (31 - bit_host[cont_bit]) + 1; i < 32; i++){ //Calcolo net id
      ip_temp[i] = 0;
    }
    conversione_binario_decimale(ip_dec, ip_temp);
    fprintf(fp, "%d)\t", cont + 1);
    fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]); //Output ned id
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin[i];
    }
    ip_temp[31] = 1; //Calcolo gateway
    conversione_binario_decimale(ip_dec, ip_temp);
    ip.range[0] = ip_dec[3] + 1;
    fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]); //Output gateway
    ip.ip_gateway[0] = ip_dec[0];
    ip.ip_gateway[1] = ip_dec[1];
    ip.ip_gateway[2] = ip_dec[2];
    ip.ip_gateway[3] = ip_dec[3];
    for(i = 0; i < 32; i++){ //Clone ip
      ip_temp[i] = ip.ip_bin[i];
    }
    for(i = (31 - bit_host[cont_bit]) + 1; i < 32; i++){ //Calcolo broadcast
      ip_temp[i] = 1;
    }  
    conversione_binario_decimale(ip_dec, ip_temp);
    fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]); //Output broadcast
    conversione_decimale_binario_semplice((host_sottorete[cont_host] - 3), ip.numero_sottorete_bin);
    for(i = 31; i > 31 - bit_host[cont_bit]; i--){
      ip_temp[i] = ip.numero_sottorete_bin[i];
    }
    cont_host++;
    conversione_binario_decimale(ip_dec, ip_temp);
    fprintf(fp, "%03d.%03d.%03d.%03d\t", ip.ip_gateway[0], ip.ip_gateway[1], ip.ip_gateway[2], ip.range[0]); //Output range
    fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]);
    for(i = 8; i <= 31 - bit_host[cont_bit]; i++){
      ip.subnet_mask_bin[i] = 1;
    }
    conversione_binario_decimale(ip.subnet_mask_dec, ip.subnet_mask_bin);
    fprintf(fp, "%03d.%03d.%03d.%03d\t", ip.subnet_mask_dec[0], ip.subnet_mask_dec[1], ip.subnet_mask_dec[2], ip.subnet_mask_dec[3]);
    conversione_decimale_binario_semplice(cont + 1, ip.numero_sottorete_bin);
    
    k = 31;
    fprintf(fp, "\n\n");
    cont_bit++;
    resto = 0;
    somma = 1;
    for(i = 31 - bit_host[cont_bit]; i >= 8; i = i - 2){
      resto = ip.ip_bin[i] * somma;
      ip.ip_bin[i] = ip.ip_bin[i] ^ somma;
      temp_controllo_addizione = ip.ip_bin[i - 1];
      ip.ip_bin[i - 1] = ip.ip_bin[i - 1] ^ resto;
      if(ip.ip_bin[i - 1] == 0 && temp_controllo_addizione == 1){
        somma = resto;
      }
      else{
        i = 7;
      }
    }
  }
  printf("Il file si trova nella cartella del programma e si chiama 'latest_supernet.txt'\n");
  fclose(fp);
  fp = fopen("latest_supernet.txt", "r");
  fseek(fp, 0, SEEK_END);
  size = ftell(fp);
  rewind(fp);
  buffer = (char *) calloc(size, sizeof(char));
  fread(buffer, sizeof(char), size, fp);
  printf(buffer);
  free(buffer);
  fclose(fp);
  do{
    printf("Vuoi salvare il file? (1 = si; 0 = no): ");
    scanf("%d", &scelta);
    if(scelta == 0){
      remove("latest_supernet.txt");
    }
  }while(scelta < 0 || scelta > 1);
}

void creatore_sottoreti_supernetting_a_file(int *ip_dec){
  indirizzi_supernet_file ip;
  FILE *fp;
  char *buffer;
  long size;
  int scelta;
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
  int temp_controllo_addizione;
  int cont_pot;
  int cont_bit;
  int cont_host;
  int max_sottoreti;
  int percentuale;
  max_sottoreti = pow(2, 22);
  somma_host = 0;
  int pot2_controllo_possibile_esponente;
  int pot2_controllo_possibile;
  int max_pot2;
  max_pot2 = 256 * 256 * 256; //Calcolo spazio massimo
  max_sottoreti = pow(2, 22); //Calcono numero sottoreti massime
  for(i = 0; i < 32; i++){ //Calcolo subnet mask
    if(i < 8){
      ip.subnet_mask_bin[i] = 1;
    }
    else{
      ip.subnet_mask_bin[i] = 0;
    }
  }
  do{ //Input numero sottoreti
    printf("Inserisci il numero di sottoreti (MAX %d): ", max_sottoreti);
    scanf("%d", &num_sottoreti);
  }while(num_sottoreti > max_sottoreti || num_sottoreti <= 1);
  host_sottorete = (int*) malloc(num_sottoreti * sizeof(int));

  for(i = 0; i < num_sottoreti; i++){ //Input numero host con controlli
    do{
      printf("Inserisci il numero di host della sottorete numero %d: ", i + 1);
      scanf("%d", &host_sottorete[i]);
    }while(host_sottorete[i] <= 0);
  }
  for(i = 0; i < num_sottoreti; i++){ //Ordinamento reti
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
  for(i = 0; i < num_sottoreti; i++){ //Calcolo bit host
    bit_host[i] = log2(host_sottorete[i]) + 1;
  }
  j = 0;
  cont_host = 0;
  fp = fopen("latest_flsm.txt", "w");
  fprintf(fp, "Ecco l'ordine delle reti:\n");
  for(i = 0; i < num_sottoreti; i++){
    fprintf(fp, "%d) %d Host, Potenza di 2 piu' vicina: 2^%d\n", i + 1, host_sottorete[i] - 2, bit_host[i]);
  }
  fprintf(fp, "\tNETWORK ID\tGATEWAY\t\tBROADCAST\tPRIMO HOST\tULTIMO HOST\tSUBNET MASK\n");
  cont_bit = 0;
  cont_pot = 8 - bit_host[cont_bit];

  conversione_decimale_binario(ip_dec, ip.ip_bin);  
  //INIZIO CALCOLO RETE
  for(cont = 0; cont < num_sottoreti; cont++){
    cont_pot = 24 - bit_host[cont_bit]; //calcola posizione dei bit della rete/host
    for(i = 0; i < 32; i++){ //Clone ip
      ip_temp[i] = ip.ip_bin[i];
    }
    for(i = (31 - bit_host[cont_bit]) + 1; i < 32; i++){ //Calcolo net id
      ip_temp[i] = 0;
    }
    conversione_binario_decimale(ip_dec, ip_temp);
    fprintf(fp, "%d)\t", cont + 1);
    fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]); //Output ned id
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip.ip_bin[i];
    }
    ip_temp[31] = 1; //Calcolo gateway
    conversione_binario_decimale(ip_dec, ip_temp);
    ip.range[0] = ip_dec[3] + 1;
    fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]); //Output gateway
    ip.ip_gateway[0] = ip_dec[0];
    ip.ip_gateway[1] = ip_dec[1];
    ip.ip_gateway[2] = ip_dec[2];
    ip.ip_gateway[3] = ip_dec[3];
    for(i = 0; i < 32; i++){ //Clone ip
      ip_temp[i] = ip.ip_bin[i];
    }
    for(i = (31 - bit_host[cont_bit]) + 1; i < 32; i++){ //Calcolo broadcast
      ip_temp[i] = 1;
    }  
    conversione_binario_decimale(ip_dec, ip_temp);
    fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]); //Output broadcast
    conversione_decimale_binario_semplice((host_sottorete[cont_host] - 3), ip.numero_sottorete_bin);
    for(i = 31; i > 31 - bit_host[cont_bit]; i--){
      ip_temp[i] = ip.numero_sottorete_bin[i];
    }
    cont_host++;
    conversione_binario_decimale(ip_dec, ip_temp);
    fprintf(fp, "%03d.%03d.%03d.%03d\t", ip.ip_gateway[0], ip.ip_gateway[1], ip.ip_gateway[2], ip.range[0]); //Output range
    fprintf(fp, "%03d.%03d.%03d.%03d\t", ip_dec[0], ip_dec[1], ip_dec[2], ip_dec[3]);
    for(i = 8; i <= 31 - bit_host[cont_bit]; i++){
      ip.subnet_mask_bin[i] = 1;
    }
    conversione_binario_decimale(ip.subnet_mask_dec, ip.subnet_mask_bin);
    fprintf(fp, "%03d.%03d.%03d.%03d\t", ip.subnet_mask_dec[0], ip.subnet_mask_dec[1], ip.subnet_mask_dec[2], ip.subnet_mask_dec[3]);
    conversione_decimale_binario_semplice(cont + 1, ip.numero_sottorete_bin);
    
    k = 31;
    fprintf(fp, "\n\n");
    cont_bit++;
    resto = 0;
    somma = 1;
    for(i = 31 - bit_host[cont_bit]; i >= 8; i = i - 2){
      resto = ip.ip_bin[i] * somma;
      ip.ip_bin[i] = ip.ip_bin[i] ^ somma;
      temp_controllo_addizione = ip.ip_bin[i - 1];
      ip.ip_bin[i - 1] = ip.ip_bin[i - 1] ^ resto;
      if(ip.ip_bin[i - 1] == 0 && temp_controllo_addizione == 1){
        somma = resto;
      }
      else{
        i = 7;
      }
    }
  }
  printf("Il file si trova nella cartella del programma e si chiama 'latest_supernet.txt'\n");
  fclose(fp);
  fp = fopen("latest_supernet.txt", "r");
  fseek(fp, 0, SEEK_END);
  size = ftell(fp);
  rewind(fp);
  buffer = (char *) calloc(size, sizeof(char));
  fread(buffer, sizeof(char), size, fp);
  printf(buffer);
  free(buffer);
  fclose(fp);
  do{
    printf("Vuoi salvare il file? (1 = si; 0 = no): ");
    scanf("%d", &scelta);
    if(scelta == 0){
      remove("latest_supernet.txt");
    }
  }while(scelta < 0 || scelta > 1);
}


