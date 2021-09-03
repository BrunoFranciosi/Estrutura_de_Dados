/***********************************************************************************
    Autor:    Bruno Franciosi
    Programa: Lista Estatica Ordenada Encadeada.
            Arquivo com as definições dos tipos e os procedimentos de funções
************************************************************************************/

#define maxNome 50
#define maxLista 100
#define terra -1

typedef struct tipoDN{
    int dia, mes, ano;
}tipoDN;

typedef struct tipoDado{
    char nome[maxNome];
    tipoDN dnasc;
    int rg;
}tipoDado;

typedef struct tipoElem{
    tipoDado dado;
    int prox;
}tipoElem;

typedef struct tipoLista{
    tipoElem lista[maxLista];
    int quant, ocupado, livre;
}tipoLista;

void criaLista(tipoLista *l);

int listaCheia(tipoLista l);

int listaVazia(tipoLista l);

int quantLista(tipoLista l);

int insereLista(tipoLista *l, tipoDado dado);

int consultaPorNome(tipoLista l, tipoDado *dado);

int consultaPorPosicao(tipoLista l, int pos, tipoDado *dado);

int removeLista(tipoLista *l, tipoDado *dado);