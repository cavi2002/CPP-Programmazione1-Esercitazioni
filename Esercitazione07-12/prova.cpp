#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv[]){

    cout << argc << endl;
    /*for(int i = 0; i <= argc; i++){
        cout << argv[i] << endl;
    }*/

    ifstream input;
    input.open(argv[1], ios::in);

    char stringa[100];
    while(input >> stringa){
        cout << stringa << endl;
    }

    input.close();

    return 0;
}