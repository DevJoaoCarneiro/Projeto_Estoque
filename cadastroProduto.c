/*Autor............Joao Victor Carneiro
  Data Modificacao.11/06/25
  Funcao...........Cadastro produto*/

#include "funcoes.h"
#include "interface.h"

void cadastroProduto(Lista *L)
{
    reg_produto produto;
    int resp, reinicio;

    do
    {
        telaCadastroProduto();

        if (L->primeiro == NULL)
        {
            produto.codigoProduto = 1;
        }
        else
        {
            produto.codigoProduto = L->ultimo->conteudo.codigoProduto + 1;
        }

        gotoxy(8, 6);
        printf("Id produto......:%d", produto.codigoProduto);

        gotoxy(34, 8);
        fflush(stdin);
        fgets(produto.nomeProduto, 50, stdin);

        gotoxy(34, 10);
        fflush(stdin);
        fgets(produto.unidadeMedida, 10, stdin);

        gotoxy(34, 12);
        fflush(stdin);
        fgets(produto.dataValidade, 11, stdin);

        gotoxy(01, 21);
        printf("Deseja cadastrar o produto (1-Sim 2-Nao)..:");
        scanf("%d", &resp);

        if (resp == 1)
        {
            PonteiroProduto p = (PonteiroProduto)malloc(sizeof(TipoItem));
            p->conteudo = produto;

            if (L->primeiro == NULL)
            {
                L->primeiro = p;
                L->ultimo = p;
                p->proximo = NULL;
            }
            else
            {
                L->ultimo->proximo = p;
                L->ultimo = p;
                p->proximo = NULL;
            }

            limpar();
            gotoxy(24, 12);
            printf("Cadastrado com sucesso!!");
        }

        gotoxy(01, 21);
        printf("Deseja cadastrar um novo produto? (1-Sim 2-Nao)..:");
        gotoxy(52, 21);
        scanf("%d", &reinicio);
        
    } while (reinicio == 1);
}