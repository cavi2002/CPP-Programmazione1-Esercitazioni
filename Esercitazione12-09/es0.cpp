#include <iostream>
using namespace std;

void elementiEsagonali(int * v, int n, int i = 0){
    if(i>=n){
        cout << "Costruzione vettore terminata" << endl;
    }else{
        v[i] = i*(2*i-1);
        elementiEsagonali(v, n, i+1);
    }
}

int * creaVettore(int n){
    int *v = new int[n];
    elementiEsagonali(v, n);
    return v;
}

void stampaVettore(int * v, int n){
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){

    int n;
    cout << "Inserisci dimensione vettore: ";
    cin >> n;
    int * v = creaVettore(n);
    cout << "Vettore di elementi esagonali: " << endl;
    stampaVettore(v, n);
    delete[] v;

    return 0;
}