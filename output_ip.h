void output_ip_dec(int *ip_dec_dot){
  int i;
	for(i = 0; i < 4; i++){
        if(i == 3){
            printf("%d", ip_dec_dot[i]);
        }
        else{
            printf("%d.", ip_dec_dot[i]);
        }
    }	
}

void output_ip_bin(int *ip_bin_dot){
	int i;
    for(i = 0; i < 32; i++){
      if(i % 8 == 0 && i != 0){
        printf(".");
      }
      printf("%d", ip_bin_dot[i]);
    }	
}

void output_ip_bin_sottorete_c(int *ip_bin_dot, int intervallo){
	int i;
    for(i = 0; i < 32; i++){
      if(i % 8 == 0 && i != 0){
        printf(".");
      }
      if(i == 24 + intervallo){
        printf("|");
        printf("%d", ip_bin_dot[i]);
      }
      else{
        printf("%d", ip_bin_dot[i]);
      }
    }	
}

void output_ip_bin_sottorete_b(int *ip_bin_dot, int intervallo){
	int i;
    for(i = 0; i < 32; i++){
      if(i % 8 == 0 && i != 0){
        printf(".");
      }
      if(i == 16 + intervallo){
        printf("|");
        printf("%d", ip_bin_dot[i]);
      }
      else{
        printf("%d", ip_bin_dot[i]);
      }
    }	
}

