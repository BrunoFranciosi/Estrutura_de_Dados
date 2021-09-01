/***********************************************************************************
    Autor:    Bruno Franciosi
    Programa: Pilha Estatica.
            Funções
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "pilhaEstatica.h"

void criaPilha(tipoPilha *p){
    p->topo = terra;                //OU    (*p).topo = terra;
}

int pilhaCheia(tipoPilha p){
    return (p.topo == maxPilha-1);
}

int pilhaVazia(tipoPilha p){
    return (p.topo == terra);
}

int topoPilha(tipoPilha p){
    return (p.pilha[p.topo]);
}

int empilha(tipoPilha *p, int dado){
    if(pilhaCheia(*p))
        return 0;
    else{
        p->topo++;                  //Avancei o topo para cima
        p->pilha[p->topo] = dado;   //Coloco na pilha na posicao do topo o dado
        return 1;                   //Retorno o sucesso da operacao
    }
}

int desempilha(tipoPilha *p, int *dado){
    if(pilhaVazia(*p))
        return 0;
    else{
        *dado = p->pilha[p->topo];  //Pegamos o dado da posicao do topo
        p->topo--;                  //Diminuo o topo
        return 1;                   //Retorno o sucesso da operacao
    }
}