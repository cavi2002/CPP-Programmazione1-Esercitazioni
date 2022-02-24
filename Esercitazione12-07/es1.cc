#include <iostream>
#include <cstdlib>
using namespace std;

void generate_array(int v[], int dim){
  for(int i = 0; i < dim; i++){
    v[i] = rand()%10;
  }
}
void print_array(int v[], int dim){
  cout << "[ ";
  for(int i = 0; i < dim; i++){
    cout << v[i] << " ";
  }
  cout << "]" << endl;
}

bool is_sub_array(int v1[], int v2[], int dim1, int dim2){
  bool ritorno = false;
  for(int i = 0; i < dim1-dim2; i++){
    for(int j = 0, s = i; j < dim2; j++, s++){
      if(!(v2[j]==v1[s])){
	ritorno = false;
	j = dim2;
      }else{
	ritorno = true;
      }
    }
    if(ritorno == true){
      i = dim1 - dim2;
    }
  }
  return ritorno;
}

int main(){

  srand(time(NULL));

  int dim1, dim2;

  do{
    cout << "INSERIRE DIMENSIONE TESTO: ";
    cin >> dim1;
  }while(dim1<=0||dim1>100);

  do{
    cout << "INSERIRE DIMENSIONE PATTERN: ";
    cin >> dim2;
  }while(dim2<0||dim2>100);

  int testo[dim1];
  int pattern[dim2];

  generate_array(testo, dim1);
  generate_array(pattern, dim2);
  cout << "ARRAY TESTO: ";
  print_array(testo, dim1);
  cout << "ARRAY PATTERN: ";
  print_array(pattern, dim2);
  if(is_sub_array(testo, pattern, dim1, dim2)){
    cout << "L'array pattern è un sottoarray" << endl;
  }else{
    cout << "L'array pattern non è un sottoarray" << endl;
  }
  
  return 0;
}
