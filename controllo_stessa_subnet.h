void controllo_stessa_subnet(){
    int ip1[4];
    int ip2[4];
    int net_id1[4];
    int net_id2[4];
    int subnet_mask[4];
    int subnet_mask_bin[32];
    int tipo1;
    int tipo2;
    int i;
    int cont;
    cont = 0;
    printf("PRIMO IP\n");
    input_ip(ip1);
    printf("SECONDO IP\n");
    input_ip(ip2);
    tipo1 = controllo_tipo_ip_sottorete(ip1);
    tipo2 = controllo_tipo_ip_sottorete(ip2);
    if(tipo1 != tipo2){
        printf("I 2 indirizzi sono di classi diverse\n");
        exit(0);
    }
    input_subnet_mask(subnet_mask);
    for(i = 0; i < 4; i++){
        net_id1[i] = ip1[i] & subnet_mask[i];
        net_id2[i] = ip2[i] & subnet_mask[i];
    }
    for(i = 0; i < 4; i++) {
        if(net_id1[i] == net_id2[i]){
            cont++;
        }
    }
    if(cont == 4){
        printf("I 2 indirizzi ip appartengono alla stessa sottorete\n");
    }
    else{
        printf("I 2 indirizzi ip NON appartengono alla stessa sottorete\n");
    }
}