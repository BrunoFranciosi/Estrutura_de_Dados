/***********************************************************************************
    Autor:    Bruno Franciosi
    Programa: Lista Dinamica Encadeada Ordenada.
            Aplicação
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "listaDinamicaEncadeadaOrdenada.h"

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
    printf("\n<7> Atualizar");
    printf("\n<8> Sair");
    printf("\n\nEscolha a opcao: ");
    scanf("%d", &op);

    system("cls");
    return (op);

}

void trataOpcao(int op){
    tipoDado dado;
    int posicao;

    switch (op){
        case 1:
            if (listaCheia(LISTA))
                printf("\nLista Cheia! Dado nao pode ser inserido!\n");
            else{
                printf("\nInserir na Lista!\n");
                printf("\nNome: ");
                gets(dado.nome);
                gets(dado.nome);
                printf("\nDia de Nascimento: ");
                scanf("%d", &(dado.dnasc.dia));
                printf("\nMes de Nascimento: ");
                scanf("%d", &(dado.dnasc.mes));
                printf("\nAno de Nascimento: ");
                scanf("%d", &(dado.dnasc.ano));
                printf("\nRegistro Geral: ");
                scanf("%d", &(dado.rg));
                printf("\nProfissao: ");
                gets(dado.profissao);
                gets(dado.profissao);
                printf("\nSalario: ");
                scanf("%f", &(dado.salario));

                insereLista(&LISTA, dado);

                printf("\nRegistro Inserido!\n");
            }
            break;
        case 2:
            if (listaVazia(LISTA))
                printf("\nLista Vazia! Dado nao pode ser removido!\n");
            else{
                printf("\nDigite o nome a ser removido > \n");
                printf("\nNome: ");
                gets(dado.nome);
                gets(dado.nome);
                if (removeLista(&LISTA, &dado)){
                    printf("\nRegistro Removido: \n");
                    printf("\nNome: %s", dado.nome);
                    printf("\nDia de Nascimento: %d", dado.dnasc.dia);
                    printf("\nMes de Nascimento: %d", dado.dnasc.mes);
                    printf("\nAno de Nascimento: %d", dado.dnasc.ano);
                    printf("\nRegistro Geral: %d\n", dado.rg);
                    printf("\nProfissao: %s\n", dado.profissao);
                    printf("\nSalario: %.2f\n", dado.salario);
                }
                else
                    printf("\nRegistro nao Existente!\n");
            }
            break;
        case 3:
            if (listaVazia(LISTA))
                printf("\nLista Vazia! Dado nao pode ser consultado!\n");
            else{
                printf("\nDigite o nome a ser consultado > \n");
                printf("\nNome: ");
                gets(dado.nome);
                gets(dado.nome);
                if (consultaListaPorNome(LISTA, &dado)){
                    printf("\nRegistro Consultado: \n");
                    printf("\nNome: %s", dado.nome);
                    printf("\nDia de Nascimento: %d", dado.dnasc.dia);
                    printf("\nMes de Nascimento: %d", dado.dnasc.mes);
                    printf("\nAno de Nascimento: %d", dado.dnasc.ano);
                    printf("\nRegistro Geral: %d\n", dado.rg);
                    printf("\nProfissao: %s\n", dado.profissao);
                    printf("\nSalario: %.2f\n", dado.salario);
                }
                else
                    printf("\nRegistro nao Existente!\n");
            }
            break;
        case 4:
            if (listaVazia(LISTA))
                printf("\nLista Vazia! Dado nao pode ser consultado!\n");
            else{
                printf("\nDigite a posicao (ordem) do registro a ser consultado > \n");
                printf("\nPosicao: ");
                scanf("%d", &posicao);
                if (consultaListaPorPosicao(LISTA, posicao, &dado)){
                    printf("\nRegistro Consultado: \n");
                    printf("\nPosicao: %d", posicao);
                    printf("\nNome: %s", dado.nome);
                    printf("\nDia de Nascimento: %d", dado.dnasc.dia);
                    printf("\nMes de Nascimento: %d", dado.dnasc.mes);
                    printf("\nAno de Nascimento: %d", dado.dnasc.ano);
                    printf("\nRegistro Geral: %d\n", dado.rg);
                    printf("\nProfissao: %s\n", dado.profissao);
                    printf("\nSalario: %.2f\n", dado.salario);
                }
                else
                    printf("\nPosicao de Registro nao Existente!\n");
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
                for (posicao = 1; posicao <= quantLista(LISTA); posicao++){
                    consultaListaPorPosicao(LISTA,posicao, &dado);
                    printf("\nRegistro Nro %d:", posicao);
                    printf("\nNome: %s", dado.nome);
                    printf("\nDia de Nascimento: %d", dado.dnasc.dia);
                    printf("\nMes de Nascimento: %d", dado.dnasc.mes);
                    printf("\nAno de Nascimento: %d", dado.dnasc.ano);
                    printf("\nRegistro Geral: %d\n", dado.rg);
                    printf("\nProfissao: %s\n", dado.profissao);
                    printf("\nSalario: %.2f\n", dado.salario);
                }
            }
            break;
        case 7:
            printf("Atualizar lista:\n");
            tipoDado dado;

            printf("\nQuem voce deseja alterar?\n");
            printf("\nNome: ");
            gets(dado.nome);
            gets(dado.nome);
            printf("\nDia de Nascimento: ");
            scanf("%d", &(dado.dnasc.dia));
            printf("\nMes de Nascimento: ");
            scanf("%d", &(dado.dnasc.mes));
            printf("\nAno de Nascimento: ");
            scanf("%d", &(dado.dnasc.ano));
            printf("\nRegistro Geral: ");
            scanf("%d", &(dado.rg));
            printf("\nProfissao: ");
            gets(dado.profissao);
            gets(dado.profissao);
            printf("\nSalario: ");
            scanf("%f", &(dado.salario));

            if (atualizaLista(&LISTA, dado) != 1)
                printf("\nNome nao encontrado!\n");
            else
                printf("\nAtualizado!\n");

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
    } while(opcao != 8);

    return 0;
}