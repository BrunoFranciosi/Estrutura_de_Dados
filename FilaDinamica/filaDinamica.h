/***********************************************************************************
    Autor:    Bruno Franciosi
    Programa: Fila Dinâmica..
            Arquivo com as definições dos tipos e os procedimentos de funções
************************************************************************************/

typedef struct tipoElem{
    int dado;
    struct tipoElem *prox;
}tipoElem;

typedef tipoElem *tipoFila;

void criaFila(tipoFila *f);

int filaCheia(tipoFila f);

int filaVazia(tipoFila f);

int primeiroFila(tipoFila f, int *dado);

int inserir(tipoFila *f, int dado);

int remover(tipoFila *f, int *dado);