#include <iostream>
#include <fstream>
#include "module3.h"
using namespace std;

const int MAX_DIM = 50;

int main(int argc, char * argv[]){
  
  if(argc!=2){
    cout << "Usage ./check_email <input.txt>" << endl;
    return 0;
  }

  fstream input;
  input.open(argv[1], ios::in);

  if(input.fail()){
    cout << "ERRORE NELL'APERTURA DEL FILE" << endl;
    return 0;
  }

  char stringa[MAX_DIM];
  while(input>>stringa){
    if(check_email(stringa)){
      cout << "La stringa " << stringa << " potrebbe essere un email" << endl;
    }else{
      cout << "La stringa " << stringa << " non potrebbe essere un email" << endl;
    }
  }
  
  return 0;
}
