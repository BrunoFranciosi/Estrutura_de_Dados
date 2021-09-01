/***********************************************************************************
    Autor:    Bruno Franciosi
    Programa: Pilha Dinâmica.
            Arquivo com as definições dos tipos e os procedimentos de funções
************************************************************************************/

typedef struct tipoElem{
    int dado;
    struct tipoElem *prox;  //ponteiro que aponta para a propria estrutura que estamos definindo
} tipoElem;

typedef tipoElem *tipoPilha;

void criaPilha(tipoPilha *p);

int pilhaVazia(tipoPilha p);

int pilhaCheia(tipoPilha p);

int topoPilha(tipoPilha p, int *topo);

int empilha(tipoPilha *p, int dado);

int desempilha(tipoPilha *p, int *dado);