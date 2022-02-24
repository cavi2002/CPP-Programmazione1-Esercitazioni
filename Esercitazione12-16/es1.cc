#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv[]){

    char carattere_seguente;
    if(argc!=2){
        cout << "Usage ./a.out input.txt" << endl;
        return 0;
    }
    fstream input;
    input.open(argv[1], ios::in);
    if(input.fail()){
        cout << "Errore nell'apertura del file di input" << endl;
        return 0;
    }
    char stringa[17];
    int i = 0;
    int n_stringhe = 0;
    while(input.get(carattere_seguente)){
        if(carattere_seguente>='0'&&carattere_seguente<='9'){
            stringa[i] = carattere_seguente;
            i++;
        }else if(carattere_seguente!=' '){
            i = 0;
        }
        if(i == 16){
            n_stringhe++;
            i = 0;
        }
    }
    cout << "Numero di carte di credito: " << n_stringhe << endl;

    return 0;
}