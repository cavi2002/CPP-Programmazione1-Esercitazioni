#include <iostream>
#include <fstream>
#include "pila.h"
using namespace std;

int main(int argc, char * argv[]){

  if(argc!=3){
    cout << "Usage: ./es1 <input.txt> <output.txt>" << endl;
    return 0;
  }

  fstream input, output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::app);
  init();
  char stringa[20];
  int n;
  while(input >> stringa){
    n = atoi(stringa);
    push(n);
  }
  while(top(n)){
    output << n << endl;
    pop();
  }

  input.close();
  output.close();
  
  return 0;
}
