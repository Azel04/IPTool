void conversione_binario_decimale(int *ip_dec_dot, int *ip_bin_dot){
  int ottetto1;
  int ottetto2;
  int ottetto3;
  int ottetto4;
  int i;
  int contpow;
  contpow = 0;
  ottetto1 = 0;
  ottetto2 = 0;
  ottetto3 = 0;
  ottetto4 = 0;
  for(i = 7; i >= 0; i--){
    ottetto1 = ottetto1 + pow(2, contpow) * ip_bin_dot[i];
    contpow++;
  }
  contpow = 0;
  for(i = 15; i >= 8; i--){
    ottetto2 = ottetto2 + pow(2, contpow) * ip_bin_dot[i];
    contpow++;
  }
  contpow = 0;
  for(i = 23; i >= 16; i--){
    ottetto3 = ottetto3 + pow(2, contpow) * ip_bin_dot[i];
    contpow++;
  }
  contpow = 0;
  for(i = 31; i >= 24; i--){
    ottetto4 = ottetto4 + pow(2, contpow) * ip_bin_dot[i];
    contpow++;
  }
  contpow = 0;
  ip_dec_dot[0] = ottetto1; 
  ip_dec_dot[1] = ottetto2; 
  ip_dec_dot[2] = ottetto3; 
  ip_dec_dot[3] = ottetto4; 
}
