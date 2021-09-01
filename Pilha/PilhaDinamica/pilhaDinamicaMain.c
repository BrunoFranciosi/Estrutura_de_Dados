/***********************************************************************************
    Autor:    Bruno Franciosi
    Programa: Pilha Dinâmica.
            Aplicação
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "pilhaDinamica.h"

tipoPilha PILHA;

void listaPilha(tipoPilha *p);

int menuOpcao(){
    int op;

    printf("\n\nMenu de Opcoes");
    printf("\n<1> Empilhar");
    printf("\n<2> Desempilhar");
    printf("\n<3> Mostrar Topo");
    printf("\n<4> Listar Pilha");
    printf("\n<5> Sair");
    printf("\n\nEscolha a opcao: ");
    scanf("%d", &op);

    system("cls");
    return (op);
}

void trataOpcao(int op){
    int dado, topo;

    switch(op){
        case 1:
            if (pilhaCheia(PILHA))
                printf("\nPilha Cheia! Dado nao inserido!\n");
            else{
                printf("\nDigite o dado a ser empilhado > ");
                scanf("%d", &dado);
                empilha(&PILHA, dado);
            }
            break;
        case 2:
            if (pilhaVazia(PILHA))
                printf("\nPilha Vazia! Dado nao removido!\n");
            else{
                desempilha(&PILHA, &dado);
                printf("\nDado Desempilhado: %d", dado);
            }
            break;
        case 3:
            if (pilhaVazia(PILHA))
                printf("\nPilha Vazia! Topo nao pode ser mostrado!\n");
            else
                topoPilha(PILHA, &topo);
                printf("\nTopo: %d", topo);
            break;
        case 4:
            listaPilha(&PILHA);
            break;
    }
}

void listaPilha(tipoPilha *p){
    int dado;
    tipoPilha aux;
    criaPilha(&aux);

    while (*p != NULL){
        desempilha(p, &dado);
        empilha(&aux, dado);
        printf("\n%d ", dado);
    }

    while (aux != NULL){
        desempilha(&aux, &dado);
        empilha(p, dado);
    }

}

int main(){
    int opcao;

    criaPilha(&PILHA);

    printf("--------------------------\n");
    printf("APLICACAO DE MANIPULACAO DE PILHA\n");
    printf("--------------------------\n");

    do{
        opcao = menuOpcao();
        trataOpcao(opcao);
    } while(opcao != 5);

    return 0;
}