#include <iostream>
#include "module2.h"
using namespace std;

const int MAX_DIM = 80;

int main(){


  char * stringa = new char[MAX_DIM];
  cout << "Inserire stringa: ";
  cin >> stringa;

  char * stringaF = new char[MAX_DIM];
  stringaF = estrai(stringa);


  cout << "La stringa finale è: " << stringaF << endl;

  delete[] stringa;
  delete[] stringaF;
  return 0;
}
