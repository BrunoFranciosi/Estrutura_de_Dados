/***********************************************************************************
    Autor:    Bruno Franciosi
    Programa: Lista Estatica Desordenada Sem Arrasto.
            Funções
************************************************************************************/

#include <stdio.h>
#include <string.h>
#include "listaEstaticaDesordenadaSemArrasto.h"

void criaLista(tipoLista *l){
    l->quant = 0;
    for (int i = 0; i < maxLista; i++)
        l->lista[i].status = 0;             //marcando todos os lugares da lista como livre(0)
}

int listaCheia(tipoLista l){
    return (l.quant == maxLista);
}

int listaVazia(tipoLista l){
    return (l.quant == 0);
}

int quantLista(tipoLista l){
    return (l.quant);
}  

int consultaPorNome(tipoLista l, tipoDado *dado){
    int i, nelem, localizei;

    if (listaVazia(l))
        return 0;
    else{
        i = 0;
        nelem = 0;
        localizei = 0;          //iniciando como falso
        while((nelem < l.quant) && (!localizei)){
            if (l.lista[i].status == 1){
                if (strcmp(l.lista[i].dado.nome, dado->nome) == 0){
                    *dado = l.lista[i].dado;
                    localizei = 1;
                }
                nelem++;
            }
            i++;
        }
        return localizei;
    }
}

int consultaPorPosicao(tipoLista l, int pos, tipoDado *dado){
    int i, nelem;

    if ((pos > l.quant) || (pos <= 0))
        return 0;
    else{
        i = 0;
        nelem = 0;

        while (nelem != pos){
            if (l.lista[i].status == 1){
                nelem++;
            }
            i++;
        }
        *dado = l.lista[i-1].dado;
        return 1;
    }
}

int insereLista(tipoLista *l, tipoDado dado){
    int i, inserido;

    if (listaCheia(*l))
        return 0;
    else{
        if (consultaPorNome(*l, &dado))
            return 0;
        else{
            i = 0;
            inserido = 0;
            do{
                if (l->lista[i].status == 0){       //andar na lista até achar uma "casinha" livre
                    l->lista[i].dado = dado;
                    l->lista[i].status = 1;         //mudando o status da "casinha" para ocupado
                    l->quant++;
                    inserido = 1;
                }
                i++;
            }while (!inserido);
            return 1;
        }
    }
}

int removeLista(tipoLista *l, tipoDado *dado){
    int i, nelem, localizei;

    if (listaVazia(*l))
        return 0;
    else{
        i = 0;
        nelem = 0;
        localizei = 0;
        while((nelem < l->quant) && (!localizei)){
            if (l->lista[i].status == 1){
                if (strcmp(l->lista[i].dado.nome, dado->nome) == 0){
                    *dado = l->lista[i].dado;
                    l->lista[i].status = 0;     //mudando o status da "casinha" para livre
                    l->quant--;                 //diminui o numero de elementos validos/ocupados
                    localizei = 1;
                }
                nelem++;
            }
            i++;
        }
        return localizei;
    }
}

int atualizar(tipoLista *l, tipoDado dado_atual){
    tipoDado dado_antigo = dado_atual;
    if (!consultaPorNome(*l, &dado_antigo))
        return 0;

    removeLista(l, &dado_antigo);
    insereLista(l, dado_atual);
    return 1;
}


/*  Criei essa função para tentar trocar
a gets(), mas acabei nao utilizando

int input(char *str, int size){
    int i = 0;
    char c = getchar();
    while (c != '\n') {
        if (i < size-1) {
            str[i] = c;
            i++;
        }
        c = getchar();
    }
    str[i] = '\0';
    return i;
}
*/