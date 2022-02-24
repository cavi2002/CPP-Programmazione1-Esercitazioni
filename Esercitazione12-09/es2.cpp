#include <iostream>
using namespace std;

void stampaVettore(char v[], int dim = 5){
    for(int i = 0; i < dim; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void ruotaVettore(char v[], int j, int dim = 5){
    int appoggio;
    for(int i = 0; i < j; i++){
        appoggio = v[0];
        for(int k = 0; k < dim-1; k++){
            v[k] = v[k+1];
        }
        v[dim-1] = appoggio;
    }    
}

int main(int argc, char * argv[]){

    if(argc!=6){
        cout << "Usage ./es2 elemento1 elemento2 ... elemento5";
    }

    char v[5];
    for(int i = 0, j = 1; i<5; i++, j++){
        v[i] = argv[j][0];
    }

    cout << "Vettore di partenza: " << endl;
    stampaVettore(v);
    int j;
    cout << "N rotazioni: ";
    cin >> j;
    ruotaVettore(v, j);
    cout << "Nuovo vettore: " << endl;
    stampaVettore(v);

    return 0;
}