#include "module1.h"
void crypt(char parola[], int chiave){
  int i = 0;
  while(parola[i]!='\0'){
    parola[i] += chiave;
    if(parola[i]>'z'){
      parola[i] = parola[i] - 'z' + 'a' - 1;
    }
    i++;
  }
}

void decrypt(char parola[], int chiave){
  int i = 0;
  while(parola[i]!='\0'){
    parola[i] -= chiave;
    if(parola[i]<'a'){
      parola[i] = parola[i] + 'z' - 'a' + 1;
    }
    i++;
  }
}
