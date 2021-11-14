void creatore_sottoreti_c(int *ip_dec_dot);
void creatore_sottoreti_b(int *ip_dec_dot);
void creatore_sottoreti_a(int *ip_dec_dot);

void creatore_sottoreti_a(int *ip_dec_dot){
  int ip_bin_dot[32];
  long num_sottoreti;
  int pot2;
  int net_id;
  int cont_pot;
  int cont;
  
  int intervallo_pot;
  int intervallo;
  int broadcast;
  int gateway;
  int range[2];
  pot2 = 0;
  cont_pot = 0;
  net_id = 0;
  do{
    printf("Digita il numero di sottoreti da creare: ");
    scanf("%ld", &num_sottoreti);
		if(num_sottoreti <= 0 || num_sottoreti >= pow(2, 24)){
      printf("Non e' possibile soddisfare la tua richiesta\n");
    }
  }while(num_sottoreti <= 0 || num_sottoreti >= pow(2, 24));
  do{
    pot2 = pow(2,cont_pot);
    cont_pot++;
  }while(pot2 < num_sottoreti);
  intervallo = 256 / pot2;
  
  printf("\tNETWORK ID\tBROADCAST\tGATEWAY\t\tPRIMO HOST\tULTIMO HOST\n");
  for(cont = 0; cont < num_sottoreti; cont++){
    broadcast = net_id + intervallo - 1;
    gateway = net_id + 1;
    range[0] = gateway + 1;
    range[1] = broadcast - 1;
		printf("%d)\t%d.%d.0.0", cont + 1, ip_dec_dot[0], net_id);
		printf("\t%d.%d.255.255", ip_dec_dot[0], broadcast);
		printf("\t%d.%d.255.254", ip_dec_dot[0], gateway);
		printf("\t%d.%d.0.1", ip_dec_dot[0], net_id);
		printf("\t%d.%d.255.253\n", ip_dec_dot[0], gateway);		
    printf("\t");
    net_id = net_id + intervallo;
    ip_dec_dot[1] = net_id;

    printf("\n\n");
  }

}

void creatore_sottoreti_b(int *ip_dec_dot){
  int ip_bin_dot[32];
  int clone_ip_dec_dot[4];
  int num_sottoreti;
  int pot2;
  int net_id;
  int j;
  int i;
  int cont_pot;
  int cont;
  int intervallo_pot;
  int intervallo;
  int broadcast;
  int ip_temp[32];
  int gateway;
  int range[2];
  pot2 = 0;
  cont_pot = 0;
  net_id = 0;
  do{
    printf("Digita il numero di sottoreti da creare: ");
    scanf("%d", &num_sottoreti);
		if(num_sottoreti <= 0 || num_sottoreti >= pow(2, 16)){
      printf("Non e' possibile soddisfare la tua richiesta\n");
    }
  }while(num_sottoreti <= 0 || num_sottoreti >= pow(2, 16));
  do{
    pot2 = pow(2,cont_pot);
    cont_pot++;
  }while(pot2 < num_sottoreti);
  intervallo = 256 / pot2;
  
  printf("\tNETWORK ID\tGATEWAY\tBROADCAST\t\tPRIMO HOST\tULTIMO HOST\n");
  
  for(cont = 0; cont < num_sottoreti; cont++){
    for(i = 0; i < 4; i++){
      clone_ip_dec_dot[i] = ip_dec_dot[i];
    }
    conversione_decimale_binario(ip_dec_dot, ip_bin_dot);
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip_bin_dot[i];
    }
    for(i = 15 + cont_pot; i < 32; i++){
      ip_temp[i] = 0;
    }
    conversione_binario_decimale(ip_dec_dot, ip_bin_dot);
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip_dec_dot[3]);
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip_bin_dot[i];
    }
    ip_temp[31] = 1;
    conversione_binario_decimale(ip_dec_dot, ip_temp);
    range[0] = ip_dec_dot[3] + 1;
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip_dec_dot[3]);
    for(i = 0; i < 32; i++){
      ip_temp[i] = ip_bin_dot[i];
    }
    for(i = 15 + cont_pot; i < 32; i++){
      ip_temp[i] = 1;
    }  
    conversione_binario_decimale(ip_dec_dot, ip_temp);
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip_dec_dot[3]);
    range[1] = ip_dec_dot[3] - 1;
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], range[0]);
    printf("%d.%d.%d.%d\t", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], range[1]);
    for(i = 0; i < 4; i++){
      ip_dec_dot[i] = clone_ip_dec_dot[i];
    }
    ip_dec_dot[2] = ip_dec_dot[2] + intervallo;
    printf("\n\n");
  }

}


void creatore_sottoreti_c(int *ip_dec_dot){
    int pot2;
    int num_sottoreti;
    int net_id;
    int broadcast;
    int gateway;
    int range[2];
    int ip_bin_dot[32];
    int clone_ip_dec_dot[4];
    int cont_pot;
    int cont;
    int cont2;
    int intervallo;
    int intervallo_pot;

    pot2 = 0;
    num_sottoreti =0 ;
    net_id = 0;
    broadcast = 0;
    gateway = 0;
    range[0] = 0;
    range[1] = 0;
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

    net_id = 0;
    printf("\tNETWORK ID\tBROADCAST\tGATEWAY\t\tPRIMO HOST\tULTIMO HOST\n");
    for(cont = 0; cont < num_sottoreti; cont++){
        broadcast = net_id + intervallo - 1;
        gateway = net_id + 1;
        range[0] = gateway + 1;
        range[1] = broadcast - 1;
		    printf("%d)\t%d.%d.%d.%03d", cont + 1, ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip_dec_dot[3]);
		    printf("\t%d.%d.%d.%03d", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], broadcast);
		    printf("\t%d.%d.%d.%03d", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], gateway);
		    printf("\t%d.%d.%d.%03d", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], range[0]);
		    printf("\t%d.%d.%d.%03d\n", ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], range[1]);		
        printf("\t");
        conversione_decimale_binario(ip_dec_dot, ip_bin_dot);
        output_ip_bin_sottorete_c(ip_bin_dot, (8 - intervallo_pot));
        net_id = net_id + intervallo;
        ip_dec_dot[3] = net_id;
        for(cont2 = 0; cont2 < 3; cont2++){
            ip_dec_dot[cont2] = clone_ip_dec_dot[cont2];
        }

        printf("\n\n");
    }
}
