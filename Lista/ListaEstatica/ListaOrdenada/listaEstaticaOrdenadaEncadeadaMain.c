/***********************************************************************************
    Autor:    Bruno Franciosi
    Programa: Lista Estatica Ordenada Encadeada.
            Aplicação
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "listaEstaticaOrdenadaEncadeada.h"

tipoLista LISTA;

int menuOpcao(){
    int op;

    printf("\n\nMenu de Opcoes");
    printf("\n<1> Inserir");
    printf("\n<2> Remover");
    printf("\n<3> Consultar por Nome");
    printf("\n<4> Consultar por Posicao");
    printf("\n<5> Quantidade de Elementos");
    printf("\n<6> Mostrar Lista");
    printf("\n<7> Sair");
    printf("\n\nEscolha a opcao: ");
    scanf("%d", &op);

    system("cls");
    return (op);
}

void trataOpcao(int op){
    tipoDado dado;
    int posicao, quant;

    switch(op){
        case 1:
            if (listaCheia(LISTA))
                printf("\nLista Cheia! Dado nao inserido!\n");
            else{
                printf("\nDigite o dado a ser inserido > \n");
                printf("\nNome: ");
                gets(dado.nome);
                gets(dado.nome);   /* fgets(dado.nome, 50, stdin) */
                printf("\nDia de Nascimento: ");
                scanf("%d", &(dado.dnasc.dia));
                printf("\nMes de Nascimento: ");
                scanf("%d", &(dado.dnasc.mes));
                printf("\nAno de Nascimento: ");
                scanf("%d", &(dado.dnasc.ano));
                printf("\nRegistro Geral: ");
                scanf("%d", &(dado.rg));

                insereLista(&LISTA, dado);

                printf("\nRegistro Inserido\n");
            }
            break;
        case 2:
            if (listaVazia(LISTA))
                printf("\nLista Vazia! Dado nao removido!\n");
            else{
                printf("\nDigite o nome a ser removido > \n");
                printf("\nNome: ");
                gets(dado.nome);
                gets(dado.nome);   /* fgets(dado.nome, 50, stdin) */
                if (removeLista(&LISTA, &dado)){
                    printf("\nRegistro Removido: \n");
                    printf("\nNome: %s", dado.nome);
                    printf("\nDia de Nascimento: %d", dado.dnasc.dia);
                    printf("\nMes de Nascimento: %d", dado.dnasc.mes);
                    printf("\nAno de Nascimento: %d", dado.dnasc.ano);
                    printf("\nRegistro Geral: %d\n", dado.rg);
                }
                else
                    printf("\nRegistro Inexistente!");
            }
            break;
        case 3:
            if (listaVazia(LISTA))
                printf("\nLista Vazia! Dado nao pode ser consultado!\n");
            else{
                printf("\nDigite o nome a ser consultado > \n");
                printf("\nNome: ");
                gets(dado.nome);
                gets(dado.nome);   /* fgets(dado.nome, 50, stdin) */
                if (consultaPorNome(LISTA, &dado)){
                    printf("\nRegistro Consultado: \n");
                    printf("\nNome: %s", dado.nome);
                    printf("\nDia de Nascimento: %d", dado.dnasc.dia);
                    printf("\nMes de Nascimento: %d", dado.dnasc.mes);
                    printf("\nAno de Nascimento: %d", dado.dnasc.ano);
                    printf("\nRegistro Geral: %d\n", dado.rg);
                }
                else
                    printf("\nRegistro Inexistente!\n");
            }
            break;
        case 4:
            if (listaVazia(LISTA))
                printf("\nLista Vazia! Dado nao pode ser consultado!\n");
            else{
                printf("\nDigite a posicao (ordem) do registro a ser consultado > \n");
                printf("\nPosicao: ");
                scanf("%d", &posicao);
                if (consultaPorPosicao(LISTA, posicao, &dado)){
                    printf("\nRegistro Consultado: \n");
                    printf("\nPosicao: %d", posicao);
                    printf("\nNome: %s", dado.nome);
                    printf("\nDia de Nascimento: %d", dado.dnasc.dia);
                    printf("\nMes de Nascimento: %d", dado.dnasc.mes);
                    printf("\nAno de Nascimento: %d", dado.dnasc.ano);
                    printf("\nRegistro Geral: %d\n", dado.rg);
                }
                else
                    printf("\nPosicao de Registro Inexistente!\n");
            }
            break;
        case 5:
            printf("\nQuantidade de Elementos na Lista = %d\n", quantLista(LISTA));
            break;
        case 6:
            if (listaVazia(LISTA))
                printf("\nLista Vazia!!!\n");
            else{
                printf("\nElementos da Lista:\n");
                quant = quantLista(LISTA);
                for (posicao = 1; posicao <= quant; posicao++){
                    consultaPorPosicao(LISTA, posicao, &dado);
                    printf("\nRegistro Nro %d:", posicao);
                    printf("\nNome: %s", dado.nome);
                    printf("\nDia de Nascimento: %d", dado.dnasc.dia);
                    printf("\nMes de Nascimento: %d", dado.dnasc.mes);
                    printf("\nAno de Nascimento: %d", dado.dnasc.ano);
                    printf("\nRegistro Geral: %d\n", dado.rg);
                }
            }
            break;
    }
}

int main(){
    int opcao;

    criaLista(&LISTA);

    printf("--------------------------\n");
    printf("APLICACAO DE MANIPULACAO DE LISTA\n");
    printf("--------------------------\n");

    do{
        opcao = menuOpcao();
        trataOpcao(opcao);
    } while (opcao != 7);

    return 0;
}