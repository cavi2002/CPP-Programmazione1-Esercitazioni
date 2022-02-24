struct nodo;

typedef nodo * albero;

struct nodo{
  int value;
  albero left;
  albero right;
};


void init(albero & radice);

void deinit(albero & radice);

void creaAlbero(albero & radice, int value);
 
void stampaAlbero(albero radice, int spazio = 0);

char * search(albero radice, int value);

void print(const albero & radice);
