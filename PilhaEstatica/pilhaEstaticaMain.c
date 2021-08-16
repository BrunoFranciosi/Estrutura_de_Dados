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

    printf("\n\nMenu de Opcoes");
    printf("\n<1> Criar Pilha");
    printf("\n<2> Empilhar");
    printf("\n<3> Desempilhar");
    printf("\n<4> Mostar Topo");
    printf("\n<5> Listar Pilha");
    printf("\n<6> Sair");
    printf("\n\nEscolha a opcao: ");
    scanf("%d", &op);

    system("cls");
    return (op);
}

void trataOpcao(int op){
    int dado;

    switch(op){
        case 1:
            criaPilha(&PILHA);
            break;
        case 2:
            if(pilhaCheia(PILHA))
                printf("\nPilha Cheia! Dado nao inserido!\n");
            else{
                printf("\nDigite o dado a ser empilhado: ");
                scanf("%d", &dado);
                empilha(&PILHA, dado);
            }
            break;
        case 3:
            if(pilhaVazia(PILHA))
                printf("\nPilha Vazia! Dado nao removido!\n");
            else{
                desempilha(&PILHA, &dado);
                printf("\nDado Desempilhado: %d", dado);
            }
            break;
        case 4:
            if(pilhaVazia(PILHA))
                printf("\nPilha Vazia! Topo nao pode ser mostrado\n");
            else
                printf("\nTopo: %d", topoPilha(PILHA));
            break;
        case 5:
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

int main(void){
    int opcao;

    printf("--------------------------\n");
    printf("APLICACAO DE MANIPULACAO DE PILHA\n");
    printf("--------------------------\n");

    do{
        opcao = menuOpcao();
        trataOpcao(opcao);
    }while(opcao != 6);
}