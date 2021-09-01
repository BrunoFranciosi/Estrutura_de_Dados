/***********************************************************************************
    Autor:    Bruno Franciosi
    Programa: Pilha Estatica.
            Aplicação
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "pilhaEstatica.h"

tipoPilha PILHA;

void listaPilha(tipoPilha p);

int menuOpcao(){
    int op;

    printf("\n\nMENU DE OPCOES");
    printf("\n<1> Empilhar");
    printf("\n<2> Desempilhar");
    printf("\n<3> Mostrar Topo");
    printf("\n<4> Listar Pilha");
    printf("\n<5> Sair");
    printf("\n\nSelecione uma opcao: ");
    scanf("%d", &op);

    system("cls");
    return (op);
}

void trataOpcao(int op){
    int dado;

    switch(op){
        case 1:
            if(pilhaCheia(PILHA))
                printf("\nPilha Cheia! Dado nao inserido!\n");
            else{
                printf("\nDigite o dado a ser empilhado: ");
                scanf("%d", &dado);
                empilha(&PILHA, dado);
            }
            break;
        case 2:
            if(pilhaVazia(PILHA))
                printf("\nPilha Vazia! Dado nao removido!\n");
            else{
                desempilha(&PILHA, &dado);
                printf("\nDado Desempilhado: %d", dado);
            }
            break;
        case 3:
            if(pilhaVazia(PILHA))
                printf("\nPilha Vazia! Topo nao pode ser mostrado\n");
            else
                printf("\nTopo: %d", topoPilha(PILHA));
            break;
        case 4:
            listaPilha(PILHA);
            break;

    }
}

void listaPilha(tipoPilha p){
    int dado;
    int tam = p.topo + 1;

    tipoPilha aux;
    criaPilha(&aux);

    for(int i = 0; i < tam; i++){
        desempilha(&p, &dado);
        printf("\n%d",dado);
        empilha(&aux, dado);
    }

    for(int i = 0; i < tam; i++){
        desempilha(&aux, &dado);
        empilha(&p, dado);
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
    }while(opcao != 5);

    return 0;
}