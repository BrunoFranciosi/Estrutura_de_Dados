/***********************************************************************************
    Autor:    Bruno Franciosi
    Programa: Pilha Estatica.
            Arquivo com as definições dos tipos e os procedimentos de funções
************************************************************************************/

#define maxPilha 100
#define terra -1

typedef struct tPilha{
    int pilha[maxPilha];
    int topo;
}tipoPilha;

void criaPilha(tipoPilha *p);

int pilhaCheia(tipoPilha p);

int pilhaVazia(tipoPilha p);

int topoPilha(tipoPilha p);

int empilha(tipoPilha *p, int dado);

int desempilha(tipoPilha *p, int *dado);