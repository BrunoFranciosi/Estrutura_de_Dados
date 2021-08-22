/***********************************************************************************
    Autor:    Bruno Franciosi
    Programa: Fila Estatica Circular.
            Aplicação
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "filaEstatica.h"

tipoFila FILA;

void listaFila(tipoFila *f);

int menuOpcao(){
    int op;

    printf("\n\nMenu de Opcoes");
    printf("\n<1> Inserir Fila");
    printf("\n<2> Remover Fila");
    printf("\n<3> Mostrar Primeiro");
    printf("\n<4> Listar Fila");
    printf("\n<5> Sair");
    printf("\n\nEscolha a opcao: ");
    scanf("%d", &op);

    system("cls");
    return (op);
}

void trataOpcao(int op){
    int dado;

    switch (op){
        case 1:
            if (filaCheia(FILA))
                printf("\nFila Cheia! Dado nao inserido!\n");
            else{
                printf("\nDigite o dado a ser enfileirado > ");
                scanf("%d", &dado);
                inserir(&FILA, dado);
            }
            break;
        case 2:
            if (filaVazia(FILA))
                printf("\nFila Vazia! Dado nao removido!\n");
            else{
                remover(&FILA, &dado);
                printf("\nDado Desenfileirado: %d", dado);
            }
            break;
        case 3:
            if (filaVazia(FILA))
                printf("\nFila Vazia!\n");
            else
                primeiroFila(FILA, &dado);

            printf("\nPrimeiro: %d", dado);
            break;
        case 4:
            listaFila(&FILA);
            break;
    }
}

void listaFila(tipoFila *f){
    int dado;
    int size = f->quant;
    tipoFila aux;
    criaFila(&aux);

    for(int i = 0; i < size; i++){
        remover(f, &dado);
        inserir(&aux, dado);
    }

    printf("\n");

    for(int i = 0; i < size; i++){
        remover(&aux, &dado);
        printf("%d ", dado);
        inserir(f, dado);
    }
    printf("\n");
}

int main(){
    int opcao;

    criaFila(&FILA);

    printf("--------------------------\n");
    printf("APLICACAO DE MANIPULACAO DE FILA\n");
    printf("--------------------------\n");

    do{
        opcao = menuOpcao();
        trataOpcao(opcao);
    }while (opcao != 5);

    return 0;
}