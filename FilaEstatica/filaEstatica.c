/***********************************************************************************
    Autor:    Bruno Franciosi
    Programa: Fila Estatica Circular.
            Funções
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "filaEstatica.h"

void criaFila(tipoFila *f){
    f->quant = 0;
    f->ultimo = -1;
    f->primeiro = 0;
}

int filaVazia(tipoFila f){
    return f.quant == 0;
}

int filaCheia(tipoFila f){
    return f.quant == maxFila;
}

int primeiroFila(tipoFila f, int *dado){
    if (filaVazia(f))
        return 0;
    else{
        *dado = f.fila[f.primeiro];
        return 1;
    }
}

int inserir(tipoFila *f, int dado){

    if (filaCheia(*f))
        return 0;
    else{
        if (f->ultimo == maxFila-1)
            f->ultimo = 0;
        else
            f->ultimo++;

        //ou f->ultimo = (f->ultimo + 1) % maxFila;

        f->fila[f->ultimo] = dado;
        f->quant++;
        return 1;
    }
}

int remover(tipoFila *f, int *dado){


    if (filaVazia(*f))
        return 0;
    else{
        *dado = f->fila[f->primeiro];

        if (f->primeiro == maxFila-1)
            f->primeiro = 0;
        else
            f->primeiro++;

        //ou f->primeiro = (f->primeiro + 1) % maxFila;

        f->quant--;
        return 1;
    }
}