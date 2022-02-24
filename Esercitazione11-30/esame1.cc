#include <iostream>
#include <fstream>
using namespace std;

const int MAX_DIM = 11;

int main(int argc, char * argv[]){

  if(argc!=2){
    cout << "Usage ./a.out <input.txt>" << endl;
    return 0;
  }

  fstream input, output;

  input.open(argv[1], ios::in);
  output.open(argv[1], ios::app);

  if(input.fail()){
    cout << "Errore nella lettura del file" << endl;
    return 0;
  }

  char stringa[MAX_DIM];
  int somma = 0, n = 1;
  float media;
  while(input >> stringa){
    int i = 0;
    while(stringa[i]!='\0'){
      i++;
    }
    somma = somma + i + 1;
    n++;
  }

  float resto = (somma%n)*0.1;
  media = ((float)somma/(float)n)-resto;
  cout << "La media dei numeri è: " << (int)media << endl;

  for(int i = 0; i < (int)media; i++){
    output << "*";
  }

  output << endl;
  
  input.close();
  output.close();
  return 0;
}
