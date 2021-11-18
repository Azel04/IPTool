

void input_ip(int *ip_dec_dot){
	int i;
    for(i = 0; i < 4; i++){
      do{
          printf("Inserisci la cifra numero %d dell'indirizzo ipv4 in decimale: ", i + 1);
          scanf("%d", &ip_dec_dot[i]);
      }while(ip_dec_dot[i] < 0 || ip_dec_dot[i] > 255);
    }	
}
void input_subnet_mask(int *subnet_mask){
	int i;
    for(i = 0; i < 4; i++){
      do{
          printf("Inserisci la cifra numero %d della subnet mask: ", i + 1);
          scanf("%d", &subnet_mask[i]);
      }while(!(subnet_mask[i] == 255 || subnet_mask[i] == 254 || subnet_mask[i] == 252 || subnet_mask[i] == 248 || subnet_mask[i] == 240 || subnet_mask[i] == 224 || subnet_mask[i] == 192 || subnet_mask[i] == 128 || subnet_mask[i] == 0));
    }
    for(i = 0; i < 4; i++){
      if(subnet_mask[i] == 255 && subnet_mask[i + 1] != 255){
        for(i = i + 2; i < 4; i++){
          subnet_mask[i] = 0;
        }
      }
    }	
}
