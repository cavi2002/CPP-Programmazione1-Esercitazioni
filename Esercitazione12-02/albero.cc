#include "albero.h"
#include <iostream>
#include <cstring>
using namespace std;

void init(albero & radice){
  radice = NULL;
}

void deinit(albero & radice){
  if(radice!=NULL){
    deinit(radice->left);
    deinit(radice->right);
    delete radice;
  }
}

void creaAlbero(albero & radice, int value){
  if(radice==NULL){
    radice =  new (nothrow) nodo;
    radice->value = value;
    radice->left = NULL;
    radice->right = NULL;
  }else if(value<=radice->value){
    creaAlbero(radice->left, value);
  }else{
    creaAlbero(radice->right, value);
  }
}
 
void stampaAlbero(albero radice, int spazio){
   if (radice != NULL) {
    spazio ++;
    
    stampaAlbero(radice->right, spazio);
 
    for (int i = 1; i < spazio; i++) {
        cout<<"\t";
    }
    cout<<radice->value<<"\n";
    
    stampaAlbero(radice->left, spazio);
   }
}

void print(const albero & radice){
  if(radice!=NULL){
    print(radice->left);
    cout << radice->value << " ";
    print(radice->right);
  }
}

char * search(albero radice, int value){
  char * percorso = new char[100];
  if(radice!=NULL){
    if(value==radice->value){
      strcpy(percorso, itoa(radice->value));
    }else if(value<=radice->value){
      strcpy(percorso, ""+radice->value);
      strcat(percorso, ", sinistra");
      strcat(percorso, search(radice->left, value));
    }else{
      strcpy(percorso, ""+radice->value);
      strcat(percorso, ", destra");
      strcat(percorso, search(radice->right, value));
    }
  }
  return percorso;
}
