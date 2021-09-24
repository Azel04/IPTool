
void controllo_tipo_ip(int *ip_dec_dot);

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