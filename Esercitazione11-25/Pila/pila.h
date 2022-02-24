#ifndef PILA_H
#define PILA_H

#include <fstream>
struct nodo {
    int value;
    nodo* next;
};
typedef nodo* lista;
 
void init();
bool push(int);
bool top(int &);
bool pop();
void deinit();
 
#endif
