#include <stdio.h>
#include "funcoes.h"
#include "interface.h"

int main()
{
    int resp, reiniciar;
    Lista L;
    inicializaLista(&L);

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
            default:
                gotoxy(22, 12);
                printf("Opcao Invalida!");
                break;
            }
            break;
        case 2:
            gotoxy(22, 12);
            printf("Opcao Invalida!");
            break;
        case 3:
            return 0;
            break;
        }

        gotoxy(01, 21);
        printf("Voltar ao menu (1-Sim 2-Nao)..:                        ");
        gotoxy(33, 21);
        scanf("%d", &reiniciar);
    } while (reiniciar == 1);
    gotoxy(01, 24);
    return 0;
}