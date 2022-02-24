#include <iostream>
using namespace std;

int calcola_it(int x, int y){
    int res = 0;
    while(x>=y){
        x = x-y;
        res++;
    }
    return res;
}

int calcola_rec(int x, int y){
    int res = 0;
    if(x<y){
    }else{
        res = 1 + calcola_rec(x-y, y);
    }
    return res;
}

int main(){

    cout << "Inserisci numeri da input: ";
    int a, b;
    cin >> a >> b;
    cout << "Calcola Iterativa: "<< calcola_it(a, b) << endl;
    cout << "Calcola Ricorsiva: "<< calcola_rec(a, b) << endl;

    return 0;
}