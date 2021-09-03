/***********************************************************************************
    Autor:    Bruno Franciosi
    Programa: Lista Estatica Ordenada Encadeada.
            Funções
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaEstaticaOrdenadaEncadeada.h"

void criaLista(tipoLista *l){
    l->quant = 0;
    l->ocupado = terra;
    l->livre = 0;
    for (int i = 0; i < maxLista-1; i++)
        l->lista[i].prox = i + 1;
    l->lista[maxLista-1].prox = terra;
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

/*
   A função buscaLista é uma função auxiliar, de uso interno, que não é
   disponibilizada para a aplicação. Essa função pode ser usada por outras
   funções, como, por exemplo, o consultaLista(), insereLista() e o removeLista()

Prototipo: int buscaLista(tipoLista l, char nome[], int *pos_ant)

        - o parâmetro "l" indica a lista na qual um registro será buscado
        - o parâmetro "nome" informa o campo chave do registro a ser buscado, ou
          seja, o registro buscado deve ter o mesmo nome no dado que armazena.
        - o parâmetro "*pos_ant" deverá retornar a posição do registro anterior
          ao registro encontrado ou a posição anterior da posição de inserção.
        - o nome da função, "buscaLista", deverá retornar verdadeiro (1) ou
          falso(0) se o registro com o nome buscado foi encontrado ou não foi
          encontrado, respectivamente.

Funcionamento:

   Dado uma lista e uma chave de busca (nome), a função buscaLista() percorre a
   lista para encontrar a posição onde um registro com esse nome esteja inserido
   ou a posição onde um registro com esse nome poderia ser inserido. Ela retorna
   a posição do registro anterior ao local onde o registro está ou poderia estar.

   As seguintes convenções são adotadas:

   1) A função retorna terra no parâmetro "*pos_ant" quando o nome buscado é
   menor ou igual a todos os nomes da lista. Essa situação pode ocorrer nas
   seguintes situações:

        - No caso da lista estar vazia. Nesse caso, a função também retorna falso
          no nome da função, pois não existe um registro com o nome buscado

        - No caso da lista não estar vazia e o nome buscado ser igual ao nome do
          registro da primeira posição da lista. Nesse caso, a função também
          retorna verdadeiro no nome da função, pois um registro com esse nome
          foi encontrado.

        - No caso da lista não estar vazia e o nome ser menor do que o nome do
          registro da primeira posição da lista. Nesse caso, a função também
          retorna falso no nome da função, pois nenhum registro com esse nome
          foi encontrado.

   2) A função retorna algum índice diferente de terra no parâmetro "*pos_ant"
   quando a lista não está vazia e o nome procurado é maior que o nome do primeiro
   registro da lista. Nesse caso, a função caminha pela lista para tentar encontrar
   a posição anterior ao registro com o mesmo nome ou a posição anterior a posição
   de inserção. Antes de iniciar esse caminhamento, o parâmetro "*pos_ant" é marcado
   com a posição do primeiro elemento da lista. Observe que o primeiro elemento
   da lista é identificado pelo campo "ocupado" da lista.
*/

int buscaLista(tipoLista l, char nome[], int *pos_ant){
    int pos_prox, tem_mais;

    *pos_ant = terra;
    pos_prox = l.ocupado;
    if (listaVazia(l))
        return 0;
    else{
        tem_mais = (l.lista[pos_prox].prox != terra);

        while ((strcmp(l.lista[pos_prox].dado.nome, nome) == -1) && (tem_mais)){
            *pos_ant = pos_prox;
            pos_prox = l.lista[pos_prox].prox;
            tem_mais = (l.lista[pos_prox].prox != terra);
        }

        if (strcmp(l.lista[pos_prox].dado.nome, nome) == 0)
            return 1;
        else if (strcmp(l.lista[pos_prox].dado.nome, nome) == +1)
            return 0;
            else{
                *pos_ant = pos_prox;
                return 0;
            }
    }
}

int insereLista(tipoLista *l, tipoDado dado){
    int pos_ant, aux, prox;

    if (listaCheia(*l))
        return 0;
    else{
        if (buscaLista(*l, dado.nome, &pos_ant))
            return 0;
        else{
            aux = l->livre;
            l->livre = l->lista[aux].prox;
            l->lista[aux].dado = dado;

            if (pos_ant == terra){
                l->lista[aux].prox = l->ocupado;
                l->ocupado = aux;
            }
            else{
                prox = l->lista[pos_ant].prox;
                l->lista[aux].prox = prox;
                l->lista[pos_ant].prox = aux;
            }

            l->quant++;
            return 1;
        }
    }
}

int consultaPorNome(tipoLista l, tipoDado *dado){
    int pos_ant, prox;

    if (listaVazia(l))
        return 0;
    else{
        if (buscaLista(l, dado->nome, &pos_ant)){
            if (pos_ant == terra)
                *dado = l.lista[l.ocupado].dado;
            else{
                prox = l.lista[pos_ant].prox;
                *dado = l.lista[prox].dado;
            }
            return 1;
        }
        else
            return 0;
    }
}

int consultaPorPosicao(tipoLista l, int pos, tipoDado *dado){
    int count, posaux;
    if (listaVazia(l) || (pos > l.quant))
        return 0;
    else{
        count = 1;
        posaux = l.ocupado;
        while (pos != count){
            count++;
            posaux = l.lista[posaux].prox;
        }

        *dado = l.lista[posaux].dado;
        return 1;
    }
}

int removeLista(tipoLista *l, tipoDado *dado){
    int pos_ant, prox;

    if (listaVazia(*l))
        return 0;
    else{
        if (buscaLista(*l, dado->nome, &pos_ant)){
            if (pos_ant == terra){
                prox = l->ocupado;
                *dado = l->lista[prox].dado;
                l->ocupado = l->lista[prox].prox;
            }
            else{
                prox = l->lista[pos_ant].prox;
                *dado = l->lista[prox].dado;
                l->lista[pos_ant].prox = l->lista[prox].prox;
            }

            l->lista[prox].prox = l->livre;
            l->livre = prox;
            l->quant--;

            return 1;
        }
        else return 0;
    }
}