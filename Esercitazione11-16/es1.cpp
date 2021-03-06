#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_DIM = 100;

struct Studente{
  char nome[MAX_DIM];
  char cognome[MAX_DIM];
  char matricola[MAX_DIM];
  float media_ponderata;
};

void stampa_studente(const Studente & S);

Studente genera_studente(char nome[], char cognome[], char matricola[], float media_ponderata);

int genera_database(Studente * database, char file[], int dim, int elementiPresenti);

int cerca_matricola(Studente * database, char * matricola, int dim);

int cerca_nome_e_cognome(Studente * database, char * nome, char * cognome, int dim);

int studente_top_media(Studente * database, int dim);

int main(){
  
  Studente * database = new Studente[MAX_DIM];
  
  int indice, risposta, elementiPresenti=0;
  char matricola[MAX_DIM];
  char nome[MAX_DIM];
  char cognome[MAX_DIM];
  char stringa[MAX_DIM];
  float media_ponderata;
  bool verifica;
  
  do{
    cout << "1: Aggiungi utente al sistema" << endl;
    cout << "2: Ricerca utente per matricola" << endl;
    cout << "3: Ricerca utente per nome e cognome" << endl;
    cout << "4: Utente con la media ponderata più alta" << endl;
    cout << "5: Carica gli studenti da un file esterno" << endl;
    cout << "6: Chiudi programma" << endl;
    cin >> risposta;
    switch(risposta){
    case 1:
      if(elementiPresenti>=MAX_DIM){
	cout << "MASSIMO DATABASE RAGGIUNTO" << endl;
      }else{
	cout << "Inserisci nome utente: ";
	cin >> nome;
	cout << "Inserisci cognome utente: ";
	cin >> cognome;
	cout << "Inserisci matricola utente: ";
	cin >> matricola;
	cout << "Inserisci media ponderata utente: ";
	cin >> media_ponderata;
	database[elementiPresenti] = genera_studente(nome, cognome, matricola, media_ponderata);
	elementiPresenti++;
      }
      break;
    case 2:
      cout << "Inserisci matricola da cercare: ";
      cin >> matricola;
      indice = cerca_matricola(database, matricola, MAX_DIM);
      if(indice==-1){
	cout << "Matricola inesistente" << endl;
      }else{
	stampa_studente(database[indice]);
      }
      break;
    case 3:
      cout << "Inserisci nome e cognome da cercare: ";
      cin >> nome >> cognome;
      indice = cerca_nome_e_cognome(database, nome, cognome, MAX_DIM);
      if(indice==-1){
	cout << "Matricola inesistente" << endl;
      }else{
	stampa_studente(database[indice]);
      }
      break;
    case 4:
      indice = studente_top_media(database, MAX_DIM);
      stampa_studente(database[indice]);
      break;
    case 5:
      cout << "Inserisci nome file: ";
      cin >> stringa;
      elementiPresenti += genera_database(database, stringa, MAX_DIM, elementiPresenti);
      break;
    case 6:
      cout << "Fine programma" << endl;
      break;
    default:
      cout << "Risposta non contemplata" << endl;
    }
  }while(risposta != 6);
  

  

  delete[] database;
  return 0;
}

void stampa_studente(const Studente & S){
  cout << endl;
  cout << "Nome studente: " <<  S.nome << endl;
  cout << "Cognome studente:" << S.cognome << endl;
  cout << "Matricola studente: " << S.matricola << endl;
  cout << "Media ponderata studente: " << S.media_ponderata << endl << endl;
}

Studente genera_studente(char nome[], char cognome[], char matricola[], float media_ponderata){
  Studente S;
  strcpy(S.nome, nome);
  strcpy(S.cognome, cognome);
  strcpy(S.matricola, matricola);
  S.media_ponderata = media_ponderata;
  return S;
}

int genera_database(Studente * database, char file[], int dim, int elementiPresenti){
  ifstream input;
  input.open(file, ios::in);
  int i = elementiPresenti;
  char stringa[MAX_DIM];
  char nome[MAX_DIM];
  char cognome[MAX_DIM];
  char matricola[MAX_DIM];
  float media_ponderata;


  if(input.fail()){
    cout << "FILE INESISTENTE" << endl;
    return 0;
  }
  while(input>>nome&&i<dim){
      input >> cognome;
      input >> matricola;
      input >> stringa;
      media_ponderata = atof(stringa);
      database[i] = genera_studente(nome, cognome, matricola, media_ponderata);
      i++;
  }
  return i;
}

int cerca_matricola(Studente * database, char *  matricola, int dim){
  int ritorno = -1;
  for(int i=0; i<dim; i++){
    if(strcmp(database[i].matricola,matricola)==0){
      ritorno = i;
    }
  }
  return ritorno;
}

int cerca_nome_e_cognome(Studente * database, char * nome, char * cognome, int dim){
  int ritorno = -1;
  for(int i=0; i<dim; i++){
    if((strcmp(database[i].nome, nome)==0) && (strcmp(database[i].cognome, cognome)==0)){
      ritorno = i;
    }
  }
  return ritorno;
}

int studente_top_media(Studente * database, int dim){
  int ritorno = 0;
  float max = database[0].media_ponderata;
  for(int i=1; i<dim; i++){
    if(max<database[i].media_ponderata){
      max = database[i].media_ponderata;
      ritorno = i;
    }
  }
  return ritorno;
}
