#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int ** inizializzaMatrice(int dim1, int dim2){
    int **m = new int*[dim1];
    for(int i = 0; i < dim1; i++){
        m[i] = new int[dim2];
    }
    for(int i = 0; i < dim1; i++){
        for(int j = 0; j < dim2; j++){
            m[i][j] = rand()%10;
        }
    }
    return m;
}

void stampaSottoMatrice(int **m, int dim1, int dim2, int x, int y, int dimSub1, int dimSub2){
    dimSub1 += x;
    dimSub2 += y;
    if(dimSub1>dim1){
        dimSub1 = dim1;
    }
    if(dimSub2>dim2){
        dimSub2 = dim2;
    }
    for(int i = x; i < dimSub1; i++){
        for(int j = y; j < dimSub2; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void deinizializzaSottoMatrice(int **m, int dim1){
    for(int i = 0; i < dim1; i++){
        delete[] m[i];
    }
    delete[] m;
}


int main(){
    
    srand(time(NULL));

    int dim1, dim2;
    cout << "Inserire numero righe e colonne: ";
    cin >> dim1 >> dim2;
    int **m = inizializzaMatrice(dim1, dim2);
    cout << "Matrice di partenza: " << endl;
    stampaSottoMatrice(m, dim1, dim2, 0, 0, dim1, dim2);
    int x, y, dimSub1, dimSub2;
    cout << "Inserisci coordinate di partenza (x, y, nrighe, ncolonne) della sottomatrice: ";
    cin >> x >> y >> dimSub1 >> dimSub2;
    cout << "Sottomatrice: " << endl;
    stampaSottoMatrice(m, dim1, dim2, x, y, dimSub1, dimSub2);
    deinizializzaSottoMatrice(m, dim1);

    return 0;
}