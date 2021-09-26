void creatore_sottoreti(){
    int pot2;
    int num_sottoreti;
    int net_id;
    int broadcast;
    int gateway;
    int range[2];
    int cont_pot;
    int cont;
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
        printf("%d)\t192.168.10.%d\t192.168.10.%d\t192.168.10.%d\t%d-%d\n", cont + 1, net_id, broadcast, gateway, range[0], range[1]);
        net_id = net_id + intervallo;
    }
}