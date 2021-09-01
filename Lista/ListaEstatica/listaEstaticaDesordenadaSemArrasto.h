/***********************************************************************************
    Autor:    Bruno Franciosi
    Programa: Lista Estatica Desordenada Sem Arrasto.
            Arquivo com as definições dos tipos e os procedimentos de funções
************************************************************************************/

#include <stdio.h>
#include <string.h>

#define maxNome 50
#define maxLista 100

typedef struct tipoDN{
    int dia, mes, ano;
}tipoDN;

typedef struct tipoDado{
    char nome[maxNome];
    tipoDN dnasc;
    int rg;
    char genero;
}tipoDado;

typedef struct tipoElem{
    tipoDado dado;
    int status;                 //1 = ocupado, 0 = livre
}tipoElem;

typedef struct tipoLista{
    tipoElem lista[maxLista];
    int quant;
}tipoLista;

void criaLista(tipoLista *l);

int listaCheia(tipoLista l);

int listaVazia(tipoLista l);

int quantLista(tipoLista l);

int consultaPorNome(tipoLista l, tipoDado *dado);

int consultaPorPosicao(tipoLista l, int pos, tipoDado *dado);

int insereLista(tipoLista *l, tipoDado dado);

int removeLista(tipoLista *l, tipoDado *dado);

int atualizar(tipoLista *l, tipoDado dado);


//int input(char *str, int size);