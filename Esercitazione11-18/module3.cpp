#include "module3.h"
#include <cstring>

const int MAX_DIM = 50;

bool check_email(char stringa[]){
  bool ritorno = true;
  char dominio[MAX_DIM];
  char utente[MAX_DIM];
  bool chiocciola = false;
  int i = 0, j = 0,  n_chiocciole = 0, pos_chiocciola;
  while(stringa[i]!='\0'){
    if(stringa[i] == '@'){
      chiocciola = true;
      n_chiocciole += 1;
      pos_chiocciola = i;
      j = 0;
    }
    if(chiocciola){
      dominio[j] = stringa[i];
    }else{
      utente[j] = stringa[i];
    }
    j++;
    i++;
  }

  if(n_chiocciole!=1){
    ritorno = false;
  }else{
    if(strlen(dominio)<1&&strlen(utente)<1){
      ritorno  = false;
    }
  }

  i = 0;
  
  while(utente[i]!='\0'){
    if(i==0&&utente[i]=='.'){
      ritorno = false;
    }else if(utente[i+1]=='\0'&&utente[i]=='.'){
      ritorno = false;
    }else if(utente[i]<'a'&&utente[i]>'z'&&utente[i]<'A'&&utente[i]>'Z'&&utente[i]!='.'&&utente[i]!='_'&&utente[i]&&utente[i]<0&&utente[i]>9){
      ritorno = false;
    }
    i++;
  }


    i = 0;
  
    while(dominio[i]!='\0'){
      if(i==0&&dominio[i]=='.'){
	ritorno = false;
      }else if(dominio[i+1]=='\0'&&dominio[i]=='.'){
	ritorno = false;
      }else if(dominio[i]<'a'&&dominio[i]>'z'&&dominio[i]<'A'&&dominio[i]>'Z'&&dominio[i]!='.'&&dominio[i]!='_'&&dominio[i]&&dominio[i]<0&&dominio[i]>9){
	ritorno = false;
      }
      i++;
    }
  return ritorno;
}
