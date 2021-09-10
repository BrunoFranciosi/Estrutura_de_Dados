/***********************************************************************************
    Autor:    Bruno Franciosi
    Programa: Lista Dinamica Encadeada Ordenada.
            Arquivo com as definições dos tipos e os procedimentos de funções
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxChar 75

typedef struct tipoDataNasc{
    int dia, mes, ano;
} tipoDataNasc;

typedef struct tipoDado{
    char nome[maxChar], profissao[maxChar];
    tipoDataNasc dnasc;
    int rg;
    float salario;
} tipoDado;

typedef struct tipoElem{
    tipoDado dado;
    struct tipoElem *prox;
} tipoElem;

typedef tipoElem *tipoPonteiro;

typedef struct tipoLista{
    tipoPonteiro lista;
    int quant;
} tipoLista;

void criaLista(tipoLista *l);

int listaCheia(tipoLista l);

int listaVazia(tipoLista l);

int quantLista(tipoLista l);

int insereLista(tipoLista *l, tipoDado dado);

int consultaListaPorNome(tipoLista l, tipoDado *dado);

int consultaListaPorPosicao(tipoLista l, int pos, tipoDado *dado);

int removeLista(tipoLista *l, tipoDado *dado);

int atualizaLista(tipoLista *l, tipoDado dado);