#include <iostream>
#include <fstream>

using namespace std;

const int DIM = 1000;

int main(int argc, char **argv){
  
  if(argc!=3){
    cout << "Usage : ./es2 <input.txt> <output.txt>" << endl;
    return 0;
  }

  ifstream input;
  ofstream output;

  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  if(input.fail()){
    cout << "Impossibile aprire file" << endl;
    return 0;
  }

  char stringa[DIM][DIM];
  int i = 0;
  while(input.getline(stringa[i], DIM)){
    i++;
  }

  const int N_FRASI = i;
  for(i = 0; i < N_FRASI; i++){
    //stringa[i] indice delle frasi
    for(int j = 0; stringa[i][j]!='\0'; j++){
      if(i==0 && j==0){
        if(stringa[i][j]>='a'&&stringa[i][j]<='z'){
          stringa[i][j] -= 'a'-'A'; 
        }
      }else if(stringa[i][j]=='.'||stringa[i][j]=='?'||stringa[i][j]=='!'){
        if(stringa[i][j+2]!='\0' && stringa[i][j+2]>='a' && stringa[i][j+2]<='z'){
          stringa[i][j+2] -= 'a' - 'A';
        }else if(stringa[i][j+2]=='\0' && stringa[i+1][0]>='a' && stringa[i+1][0]<='z'){
          stringa[i+1][0] -= 'a' - 'A';
        }
      }
    }
    output << stringa[i] << endl;
  }
  
  input.close();
  output.close();
  return 0;
}
