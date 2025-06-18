#include "funcoes.h"
#include "interface.h"

void salvarDadosProduto(Lista *L)
{
    FILE *fp = fopen("funcionarios.dat", "wb");
    if (fp == NULL)
    {
        limpar();
        gotoxy(27, 12);
        printf("Erro ao abrir o arquivo para escrita!");
        Sleep(2000);
        return;
    }

    PonteiroProduto atual = L->primeiro;

    if (atual == NULL)
    {
        gotoxy(27, 12);
        printf("Lista vazia, nada a salvar.");
        Sleep(2000);
    }

    while (atual != NULL)
    {
        fwrite(&atual->conteudo, sizeof(reg_produto), 1, fp);
        atual = atual->proximo;
    }

    fclose(fp);
}

void carregarArquivoProduto(Lista *L)
{
    FILE *fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL)
    {
        return;
    }

    reg_produto temp;

    while (fread(&temp, sizeof(reg_produto), 1, fp) == 1)
    {
        PonteiroProduto novo = (PonteiroProduto)malloc(sizeof(TipoItem));
        if (novo == NULL)
        {
            printf("Erro de alocação de memória.\n");
            fclose(fp);
            return;
        }

        novo->conteudo = temp;
        novo->proximo = NULL;
        
        if (L->ultimo != NULL)
        {
            L->ultimo->proximo = novo;
        }
        else
        {
            L->primeiro = novo;
        }

        L->ultimo = novo;
        L->tamanho++;
    }

    fclose(fp);
}
