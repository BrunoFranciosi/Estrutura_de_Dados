/***********************************************************************************
    Autor:    Bruno Franciosi
    Programa: Fila Estatica Circular.
            Arquivo com as definições dos tipos e os procedimentos de funções
************************************************************************************/

#define maxFila 100

typedef struct tipoFila{
    int fila[maxFila];
    int primeiro, ultimo, quant;
} tipoFila;

void criaFila(tipoFila *f);

int filaVazia(tipoFila f);

int filaCheia(tipoFila f);

int primeiroFila(tipoFila f, int *dado);

int inserir(tipoFila *f, int dado);

int remover(tipoFila *f, int *dado);