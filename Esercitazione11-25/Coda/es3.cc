#include <iostream>
#include <cstring>
#include "coda.h"
using namespace std;

int main(){


  init();
  cout << "- - - BENVENUTI IN POSTA - - -" << endl;
  bool esci = false;
  char input[MAX_DIM];
  
  cout << "inserisci: " << endl;
  cout << "- 'rimuovi' per rimuovere una persona" << endl;
  cout << "- 'stampa' per vedere la coda" << endl;
  cout << "- 'esci' per terminare il programma" << endl;
  cout << "- un nome per aggiungere una persona " << endl;
  
  while(!esci){

    cin >> input;
    if(strcmp(input, "rimuovi")==0){
      char * primo;
      if(first(primo)){
	dequeue();
	cout << "Abbiamo rimosso " << primo << endl;
	delete[] primo;
      }else{
	cout << "Coda vuota" << endl;;
      }
    }else if(strcmp(input, "stampa")==0){
      cout << "La coda è costituita da: " << endl;
      print();
    }else if(strcmp(input, "esci")==0){
      cout << "- - - POSTA CHIUSA - - -" << endl;
      esci = true;
    }else{
      cout << "Abbiamo inserito " << input << " nella coda" << endl;
      enqueue(input);
    }
  }

  deinit();
  
  return 0;
}
