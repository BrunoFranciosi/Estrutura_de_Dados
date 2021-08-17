/***********************************************************************************
    Autor:    Bruno Franciosi
    Programa: Pilha Dinâmica.
            Funções
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "pilhaDinamica.h"

void criaPilha(tipoPilha *p){
    *p = NULL;
}

int pilhaVazia(tipoPilha p){
    return (p == NULL);
}

int pilhaCheia(tipoPilha p){
    return 0;
}

int topoPilha(tipoPilha p, int *topo){
    if (pilhaVazia(p))
        return 0;
    else{
        *topo = p->dado;
        return 1;
    }
}

int empilha(tipoPilha *p, int dado){
    tipoElem *aux;

    aux = (tipoElem*)malloc(sizeof(tipoElem));

    aux->dado = dado;
    aux->prox = *p;
    *p = aux;

    return 1;
}

int desempilha(tipoPilha *p, int *dado){
    tipoElem *aux;

    if (pilhaVazia(*p))
        return 0;
    else{
        *dado = (*p)->dado;
        aux = *p;
        *p = aux->prox;

        free(aux);
        return 1;
    }
}