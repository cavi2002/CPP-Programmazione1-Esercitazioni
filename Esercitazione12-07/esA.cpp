#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[]){

    if(argc!=3){
        cout << "Usage ./a input.txt output.txt" << endl;
        return 0;
    }

    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);

    if(input.fail()){
        cout << "Errore nell'apertura del file di input" << endl;
        if(output.fail()){
            cout << "Errore nell'apertura del file di output" << endl;
        }else{
            output.close();
        }
        return 0;
    }

    char buffer[256];


    input >> buffer;
    if(buffer[0]>='a'&&buffer[0]<='z'){
        buffer[0] -= 'a'-'A';
    }

    while(!input.eof()){
        for(int i = 0; buffer[i]!='\0'; i++){
            if((buffer[i]=='?')||(buffer[i]=='.')||(buffer[i]=='!')){
                output << buffer;
                output << " ";
                input >> buffer;
                if(buffer[0]>='a'&&buffer[0]<='z'){
                    buffer[0] -= 'a'-'A';
                    i = 1;
                }else{
                    i = 1;
                }
            }
        }
        output << buffer;
        output << " ";
        input >> buffer;
    }

    input.close();
    output.close();
}