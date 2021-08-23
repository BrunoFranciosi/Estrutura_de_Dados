/***********************************************************************************
    Autor:    Bruno Franciosi
    Programa: Fila Dinâmica..
            Funções
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.h"

void criaFila(tipoFila *f){
    *f = NULL;
}

int filaCheia(tipoFila f){
    return 0;
}

int filaVazia(tipoFila f){
    return f == NULL;
}

int primeiroFila(tipoFila f, int *dado){
    tipoElem *pri;

    if (filaVazia(f))
        return 0;
    else{
        pri = f;

        while (pri->prox != NULL){
            pri = pri->prox;
        }

        *dado = pri->dado;

        return 1;
    }
}

int inserir(tipoFila *f, int dado){
    tipoElem *aux;

    if(filaCheia(*f))
        return 0;
    else{
        aux = (tipoElem*)malloc(sizeof(tipoElem));
        aux->dado = dado;
        aux->prox = *f;
        *f = aux;
        return 1;
    }
}

int remover(tipoFila *f, int *dado){
    tipoElem *pri, *seg;

    if (filaVazia(*f)){
        return 0;
    }
    else{
        pri = *f;
        seg = NULL;

        while (pri->prox != NULL){
            seg = pri;
            pri = pri->prox;
        }

        *dado = pri->dado;

        if (seg == NULL){
            *f = NULL;
        }
        else
            seg->prox = NULL;

        free(pri);

        return 1;
    }
}