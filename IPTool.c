
#include <stdio.h>

int main()
{
    int ip_bin_dot[32];
    int ip_dec_dot[4];
    
    int id[4] = {23, 15, 7, 0};
    int temp;
    
    int i; 
    int j;
    int k;
    
    for(i = 0; i < 4; i++){
        printf("Inserisci la cifra numero %d dell'indirizzo ipv4 in decimale: ", i + 1);
        scanf("%d", &ip_dec_dot[i]);
    }
    
    printf("L'indirizzo inserito e' il seguente: ");
    for(i = 0; i < 4; i++){
        if(i == 3){
            printf("%d", ip_dec_dot[i]);
        }
        else{
            printf("%d.", ip_dec_dot[i]);
        }
    }
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

    //INIZIO CONVERSIONE DA DEC A BIN
    i = 0;
    j = 7;
    k = 0;
    do{
        do{
            ip_bin_dot[j] = ip_dec_dot[i] % 2;
            ip_dec_dot[i] = ip_dec_dot[i] / 2;
            j--;
            k++;
        }while(k < 8);
        i++;
        j = 8 * i + 7; // Per esempio: 8 - 1 + 8 = 15
        k = 0;
    }while(i < 4);
    //INIZIO STAMPA IP BIN
    printf("\nL'indirizzo ip in binario e' il seguente: \n");
    j = 0;
    k = 8;
    for(i = 0; i < 32; i++){
      if(i % 8 == 0 && i != 0){
        printf(".");
      }
      printf("%d", ip_bin_dot[i]);
    }

    return 0;
}
