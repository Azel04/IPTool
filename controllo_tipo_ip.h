
void controllo_tipo_ip(int *ip_dec_dot);
int controllo_tipo_ip_sottorete(int *ip_dec_dot);

void controllo_tipo_ip(int *ip_dec_dot){
    switch(ip_dec_dot[0]){
      case 10:
        printf("L'indirizzo inserito e' un indirizzo privato di classe A\n");
        break;
      case 172:
        if(ip_dec_dot[1] >= 16 && ip_dec_dot[1] <= 31){
          printf("L'indirizzo inserito e' un indirizzo privato di classe B\n");
        }
        else{
          printf("L'indirizzo inserito e' un indirizzo pubblico di classe B\n");
        }
      case 192:
        if(ip_dec_dot[1] == 168){
          printf("L'indirizzo inserito e' un indirizzo privato di classe C\n");
        }
        else{
          printf("L'indirizzo inserito e' un indirizzo pubblico di classe C\n");
        }
    }	
}

int controllo_tipo_ip_sottorete(int *ip_dec_dot){
  if(ip_dec_dot[0] >= 1 && ip_dec_dot[0] <= 127){
    return 0;
  }
    if(ip_dec_dot[0] >= 128 && ip_dec_dot[0] <= 191){
    return 1;
  }
    if(ip_dec_dot[0] >= 192 && ip_dec_dot[0] <= 223){
    return 2;
  }
}
