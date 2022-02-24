#include "module2.h"

void aux_estrai(char * parola, char * ritorno, int i, int j){
  if(parola[i]=='\0'){
    ritorno[j] == '\0';
  }else{
    if(parola[i]>='A'&&parola[i]<='Z'){
      ritorno[j] = parola[i];
      aux_estrai(parola, ritorno, i+1, j+1);
    }else{
      aux_estrai(parola, ritorno, i+1, j);
    }
  }
}


char * estrai(char * parola){
  char * ritorno = new char[80];
  aux_estrai(parola, ritorno, 0, 0);
  return ritorno;
}
