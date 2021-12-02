void output_ip_dec(int *ip_dec){
  int i;
	for(i = 0; i < 4; i++){
        if(i == 3){
            printf("%d", ip_dec[i]);
        }
        else{
            printf("%d.", ip_dec[i]);
        }
    }	
}

void output_ip_bin(int *ip_bin){
	int i;
    for(i = 0; i < 32; i++){
      if(i % 8 == 0 && i != 0){
        printf(".");
      }
      printf("%d", ip_bin[i]);
    }	
}

void output_ip_bin_sottorete_c(int *ip_bin, int intervallo){
	int i;
    for(i = 0; i < 32; i++){
      if(i % 8 == 0 && i != 0){
        printf(".");
      }
      if(i == 24 + intervallo){
        printf("|");
        printf("%d", ip_bin[i]);
      }
      else{
        printf("%d", ip_bin[i]);
      }
    }	
}

void output_ip_bin_sottorete_b(int *ip_bin, int intervallo){
	int i;
    for(i = 0; i < 32; i++){
      if(i % 8 == 0 && i != 0){
        printf(".");
      }
      if(i == 16 + intervallo){
        printf("|");
        printf("%d", ip_bin[i]);
      }
      else{
        printf("%d", ip_bin[i]);
      }
    }	
}

