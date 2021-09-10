/***********************************************************************************
    Autor:    Bruno Franciosi
    Programa: Lista Dinamica Encadeada Ordenada.
            Funções
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaDinamicaEncadeadaOrdenada.h"

void criaLista(tipoLista *l){
    l->quant = 0;
    l->lista = NULL;
}

int listaCheia(tipoLista l){
    return 0;
}

int listaVazia(tipoLista l){
    return l.quant==0;
}

int quantLista(tipoLista l){
    return l.quant;
}

int buscaLista(tipoLista l, char nome[], tipoPonteiro *pos_ant){
    tipoPonteiro pos_prox;
    int tem_mais;

    *pos_ant = NULL;

    if (listaVazia(l))
        return 0;
    else{
        pos_prox = l.lista;

        tem_mais = (pos_prox->prox != NULL);

        while ((strcmp(pos_prox->dado.nome, nome) == -1) && (tem_mais)){
            *pos_ant = pos_prox;
            pos_prox = pos_prox->prox;
            tem_mais = pos_prox->prox != NULL;
        }

        if (strcmp(pos_prox->dado.nome, nome) == 0)
            return 1;
        else if (strcmp(pos_prox->dado.nome, nome) == +1)
            return 0;
            else{
                *pos_ant = pos_prox;
                return 0;
            }
    }
}

int insereLista(tipoLista *l, tipoDado dado){
    tipoPonteiro pos_ant, aux, prox;

    if (listaCheia(*l))
        return 0;
    else{
        if (buscaLista(*l, dado.nome, &pos_ant))
            return 0;
        else{
            aux = (tipoElem*)malloc(sizeof(tipoElem));
            aux->dado = dado;

            if (pos_ant == NULL){
                aux->prox = l->lista;
                l->lista = aux;
            }
            else{
                prox = pos_ant->prox;
                aux->prox = prox;
                pos_ant->prox = aux;
            }

            l->quant++;
            return 1;
        }
    }
}

int consultaListaPorNome(tipoLista l, tipoDado *dado){
    tipoPonteiro pos_ant, prox;

    if (listaVazia(l))
        return 0;
    else{
        if (buscaLista(l, dado->nome, &pos_ant)){
            if (pos_ant == NULL)
                *dado = l.lista->dado;
            else{
                prox = pos_ant->prox;
                *dado = prox->dado;
            }
            return 1;
        }
        else
            return 0;
    }
}

int consultaListaPorPosicao(tipoLista l, int pos, tipoDado *dado){
    tipoPonteiro endaux;
    int count;

    if ((listaVazia(l)) || (pos>l.quant))
        return 0;
    else{
        count = 1;
        endaux = l.lista;
        while (pos != count){
            count++;
            endaux = endaux->prox;
        }

        *dado = endaux->dado;
        return 1;
    }
}

int removeLista(tipoLista *l, tipoDado *dado){
    tipoPonteiro pos_ant, prox;

    if (listaVazia(*l))
        return 0;
    else{
        if (buscaLista(*l, dado->nome, &pos_ant)){
            if (pos_ant == NULL){
                prox = l->lista;
                *dado = prox->dado;
                l->lista = prox->prox;
            }
            else{
                prox = pos_ant->prox;
                *dado = prox->dado;
                pos_ant->prox = prox->prox;
            }

            free(prox);
            l->quant--;

            return 1;
        }
        else
            return 0;
    }
}

int atualizaLista(tipoLista *l, tipoDado novo_dado){
    tipoDado dado_antigo = novo_dado;

    if(consultaListaPorNome(*l, &dado_antigo) != 1)
        return 0;

    removeLista(l, &dado_antigo);
    insereLista(l, novo_dado);

    return 1;
}