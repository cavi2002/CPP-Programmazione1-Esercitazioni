#include <iostream>
#include <fstream>
using namespace std;

const int DIM = 30;

struct nodo{

  int value;
  nodo * next;
  
};

//inserimento elemento UNO DOPO L'ALTRO SENZA ORDINE
void insert_element(nodo *& lista, int n){
  nodo * nuovoNodo = new nodo;
  nuovoNodo->value = n;
  nuovoNodo->next = NULL;
  if(lista!=NULL){
    nodo *nodoCorrente = lista;
    while(nodoCorrente->next!=NULL){
      nodoCorrente = nodoCorrente->next;
    }
    nodoCorrente->next = nuovoNodo;
  }else{
    lista = nuovoNodo;
  }
}

void print(nodo * lista){
  while(lista!=NULL){
    cout << lista->value << endl;
    lista = lista->next;
  }
}

void reverse_print(nodo * lista){
  /*
  nodo * t;
  nodo * y = x;
  nodo * r = NULL;
  while(y!=NULL){
    t = y->next;
    y->next = r;
    r = y;
    y = t;
  }
  print(r);
  */
  if(lista->next!=NULL){
    reverse_print(lista->next);
  }
  cout << lista->value;
}


void deinit(nodo *& lista){
  while(lista!=NULL){
    nodo * t = lista;
    lista = lista->next;
    delete[] t;
  }
}

int main(int argc, char * argv[]){

  if(argc!=2){
    cout << "Usage ./es1 <input.txt>" << endl;
    return 0;
  }

  ifstream input;
  input.open(argv[1], ios::in);

  if(input.fail()){
    cout << "Errore nell'apertura del file" << endl;
    return 0;
  }

  nodo * lista;

  char stringa[DIM];
  while(input>>stringa){
    int n = atoi(stringa);
    insert_element(lista, n);
  }

  print(lista);
  reverse_print(lista);
  deinit(lista);

  input.close();
  return 0;
}
