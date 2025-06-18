#include <stdio.h>
#include "funcoes.h"
#include "interface.h"

int main()
{
    int resp, reiniciar;
    Lista L;
    Lista_Movimentacao M;
    inicializaLista(&L);
    inicializaListaMovimentacao(&M);

    carregarArquivoProduto(&L);
    carregarMovimentacao(&M);

    do
    {
        tela();
        resp = telaPrincipal();

        switch (resp)
        {
        case 1:
            switch (opcaoCadastro())
            {
            case 1:
                cadastroProduto(&L);
                break;
            case 2:
                consultaProduto(&L);
                break;
            case 3:
                editaProduto(&L);
                break;
            case 4:
                excluiProduto(&L);
                break;
            case 5:
                salvarDadosProduto(&L);
                salvarDadosMovimentacao(&M);
                break;
            default:
                gotoxy(25, 18);
                printf("Opcao Invalida!");
                break;
            }
            break;
        case 2:
        {
            int opcao_mov = opcaoMovimentacao();

            switch (opcao_mov)
            {
            case 1:
                cadastrarMovimentacao(&L, &M);
                break;
            case 2:
                listarMovimentacao(&L, &M);
                break;
            case 3:
                break;
            default:
                gotoxy(25, 12);
                printf("Opcao Invalida!");
                getch();
                break;
            }
        }
        break;
        case 3:
            salvarDadosProduto(&L);
            salvarDadosMovimentacao(&M);
            return 0;
            break;
        }

        gotoxy(01, 21);
        printf("Voltar ao menu (1-Sim 2-Nao)..:                        ");
        gotoxy(33, 21);
        scanf("%d", &reiniciar);
    } while (reiniciar == 1);
    salvarDadosProduto(&L);
    salvarDadosMovimentacao(&M);
    gotoxy(01, 24);
    return 0;
}