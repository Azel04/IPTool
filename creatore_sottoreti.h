void creatore_sottoreti(int *ip_dec_dot){
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
    }while(num_sottoreti <= 0 || num_sottoreti >= 32);
    do{
        pot2 = pow(2,cont_pot);
        cont_pot++;
    }while(pot2 <= num_sottoreti);
    intervallo_pot = 8 - (cont_pot - 1);
    intervallo = pow(2, intervallo_pot);

    net_id = 0;
    printf("\tNETWORK ID:\tBROADCAST\tGATEWAY\tRANGE\n");
    for(cont = 0; cont < num_sottoreti; cont++){
        broadcast = net_id + intervallo - 1;
        gateway = broadcast - 1;
        range[0] = net_id + 1;
        range[1] = gateway - 1;
        //Lo so che il printf qua sotto fa cagare, mi faccio schifo da solo
        printf("%d)\t%d.%d.%d.%d\t%d.%d.%d.%d\t%d.%d.%d.%d\t%d-%d\n", cont + 1, ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], ip_dec_dot[3], ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], broadcast, ip_dec_dot[0], ip_dec_dot[1], ip_dec_dot[2], gateway, range[0], range[1]);
        printf("\t");
        conversione_decimale_binario(ip_dec_dot, ip_bin_dot);
        output_ip_bin_sottorete(ip_bin_dot, (8 - intervallo_pot));
        net_id = net_id + intervallo;
        ip_dec_dot[3] = net_id;
        for(cont2 = 0; cont2 < 3; cont2++){
            ip_dec_dot[cont2] = clone_ip_dec_dot[cont2];
        }
        printf("\n\n");
    }
}
