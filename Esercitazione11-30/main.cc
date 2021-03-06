#include <iostream>
#include "coda.h"
#include "pila.h"
using namespace std;

const int MAX_DIM = 101;

void invertiPila(){
  int n;
  while(pila_top(n)){
    coda_enqueue(n);
    pila_pop();
  }
  while(coda_first(n)){
    pila_push(n);
    coda_dequeue();
  }
}

bool palindroma(){
  bool verifica = true;;
  int n1, n2;
  while(pila_top(n1)&&coda_first(n2)){
    if(!(n1 == n2)){
      verifica = false;
    }
    pila_pop();
    coda_dequeue();
  }
  return verifica;
}

int main(){
  pila_init();
  coda_init();

  
  char stringa[MAX_DIM];
  cout << "Inserisci stringa: ";
  cin >> stringa;
  for(int i = 0; stringa[i]!='\0'; i++){
    pila_push(stringa[i]);
    coda_enqueue(stringa[i]);
  }

  if(palindroma()){
    cout << "La parola è palindroma" << endl;
  }else{
    cout << "La parola non è palindroma" << endl;
  }
  
  pila_deinit();
  coda_deinit();
}
