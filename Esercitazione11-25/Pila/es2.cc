#include <iostream>
#include "pila.h"
using namespace std;

int main(int argc, char * argv[]){

  init();
  if(argc!=2){
    cout << "Usage ./es2 <input.txt>" << endl;
    return 0;
  }

  fstream input;
  input.open(argv[1], ios::in);
  
  if(input.fail()){
    cout << "Errore nell'apertura del file" << endl;
    return 0;
  }

  char carattere;
  while(input >> carattere){
    push(carattere);
  }

  int n = carattere;
  int n_chiuse = 0;
  bool verifica = true;
  while(top(n)){
    if(n=='(' && n_chiuse==0){
      verifica = false;
    }else if(n==')'){
      n_chiuse++;
    }
    pop();
  }

  if(verifica){
    cout << "BILANCIATE" << endl;
  }else{
    cout << "NON BILANCIATE" << endl;
  }

  
  input.close();
  return 0;
}
