#include <iostream>
#include <fstream>
#include "albero.h"
using namespace std;

int main(int argc, char * argv[]){

  if(argc!=2){
    cout << "Usage ./main <input.txt>" << endl;
    return 0;
  }

  fstream input;
  input.open(argv[1], ios::in);

  if(input.fail()){
    cout << "Errore nell'apertura del file" << endl;
    return 0;
  }

  char stringa[50];
  albero a;
  init(a);
  while(input>>stringa){
    int n = atoi(stringa);
    creaAlbero(a, n);
  }

  stampaAlbero(a);

  cout << "ALBERO STAMPATO IN ORDINE CRESCENTE:" << endl;
  print(a);
  cout << endl;

  cout << "Percorso per arrivare a 5: " <<search(a, 5);

  

  deinit(a);
  
  input.close();
  
  return 0;
}
