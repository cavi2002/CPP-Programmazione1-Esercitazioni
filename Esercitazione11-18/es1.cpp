#include <iostream>
#include <fstream>
#include "module1.h"
using namespace std;

const int MAX_DIM = 256;

int main(int argc, char * argv[]){

  if(argc!=4){
    cout << "Usage ./cifrario <input.txt> <output.txt> key" << endl;
    return 0;
  }

  fstream input, output;
  input.open(argv[1],ios::in);
  output.open(argv[2],ios::app);
  int key = atoi(argv[3]);

  if(input.fail()){
    cout << "FILE INESISTENTE" << endl;
    return 0;
  }

  char stringa[MAX_DIM];
  cout << "Vuoi criptare o decriptare? (1:criptare/2:decriptare) ";
  int risposta;
  cin >> risposta;
  if(risposta==1){ 
    while(input>>stringa){
      crypt(stringa, key);
      output << stringa << " ";
    }
  }else if(risposta == 2){
    while(input>>stringa){
      decrypt(stringa, key);
      output << stringa << " ";
    }
  }else{
    cout << "RISPOSTA SBAGLIATA!" << endl;
  }

  input.close();
  output.close();
  
  return 0;
}
