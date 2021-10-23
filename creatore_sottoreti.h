void creatore_sottoreti_c(int *ip_dec_dot);
void creatore_sottoreti_b(int *ip_dec_dot);

void creatore_sottoreti_b(int *ip_dec_dot){
  int ip_bin_dot[32];
  int num_sottoreti;
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
    scanf("%d", &num_sottoreti);
		if(num_sottoreti <= 0 || num_sottoreti >= pow(2, 16)){
      printf("Non e' possibile soddisfare la tua richiesta\n");
    }
  }while(num_sottoreti <= 0 || num_sottoreti >= pow(2, 16));
  do{
    pot2 = pow(2,cont_pot);
    cont_pot++;
  }while(pot2 < num_sottoreti);
  intervallo_pot = 8 - (cont_pot - 1);
  intervallo = pow(2, intervallo_pot);
  
  printf("\tNETWORK ID\tBROADCAST\tGATEWAY\t\tPRIMO HOST\tULTIMO HOST\n");
  for(cont = 0; cont < num_sottoreti; cont++){
    broadcast = net_id + intervallo - 1;
    gateway = broadcast - 1;
    range[0] = net_id + 1;
    range[1] = gateway - 1;
		printf("%d)\t%d.%d.%d.0", cont + 1, ip_dec_dot[0], ip_dec_dot[1], net_id);
		printf("\t%d.%d.%d.255", ip_dec_dot[0], ip_dec_dot[1], broadcast);
		printf("\t%d.%d.%d.254", ip_dec_dot[0], ip_dec_dot[1], gateway);
		printf("\t%d.%d.%d.1", ip_dec_dot[0], ip_dec_dot[1], net_id);
		printf("\t%d.%d.%d.253\n", ip_dec_dot[0], ip_dec_dot[1], range[1]);		
    printf("\t");
    net_id = net_id + intervallo;
    ip_dec_dot[2] = net_id;

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
    intervallo = 256 / (cont_pot - 1);

    net_id = 0;
    printf("\tNETWORK ID\tBROADCAST\tGATEWAY\t\tPRIMO HOST\tULTIMO HOST\n");
    for(cont = 0; cont < num_sottoreti; cont++){
        broadcast = net_id + intervallo - 1;
        gateway = broadcast - 1;
        range[0] = net_id + 1;
        range[1] = gateway - 1;
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
