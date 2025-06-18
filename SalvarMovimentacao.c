#include "funcoes.h"
#include "interface.h"

void salvarDadosMovimentacao(Lista_Movimentacao *L)
{
    FILE *fp = fopen("Movimentacoes.dat", "wb");
    if (fp == NULL)
    {
        limpar();
        gotoxy(27, 12);
        printf("Erro ao abrir o arquivo para escrita!");
        Sleep(2000);
        return;
    }

    Ponteiro_Mov atual = L->primeiro;

    if (atual == NULL)
    {
        gotoxy(27, 12);
        printf("Lista vazia, nada a salvar.");
        Sleep(2000);
    }

    while (atual != NULL)
    {
        fwrite(&atual->movimentacao, sizeof(reg_movimentacao), 1, fp);
        atual = atual->proximo;
    }

    fclose(fp);
}

void carregarMovimentacao(Lista_Movimentacao *L)
{
    FILE *fp = fopen("Movimentacoes.dat", "rb");
    if (fp == NULL)
    {
        return;
    }

    reg_movimentacao temp;

    while (fread(&temp, sizeof(reg_movimentacao), 1, fp) == 1)
    {
        Ponteiro_Mov novo = (Ponteiro_Mov)malloc(sizeof(TipoItem_Mov));
        if (novo == NULL)
        {
            printf("Erro de alocação de memória.\n");
            fclose(fp);
            return;
        }

        novo->movimentacao = temp;
        novo->proximo = NULL;
        novo->anterior = L->ultimo;
        
        if (L->ultimo != NULL)
        {
            L->ultimo->proximo = novo;
        }
        else
        {
            L->primeiro = novo;
        }

        L->ultimo = novo;
        
    }

    fclose(fp);
}
