

void input_ip(int *ip_dec_dot){
	int i;
    for(i = 0; i < 4; i++){
      do{
          printf("Inserisci la cifra numero %d dell'indirizzo ipv4 in decimale: ", i + 1);
          scanf("%d", &ip_dec_dot[i]);
      }while(ip_dec_dot[i] < 0 || ip_dec_dot[i] > 255);
    }	
}
