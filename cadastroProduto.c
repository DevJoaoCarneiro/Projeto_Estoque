/*Autor............Joao Victor Carneiro
  Data Modificacao.11/06/25
  Funcao...........Cadastro produto*/

#include "funcoes.h"
#include "interface.h"

void cadastroProduto(Lista *L)
{
    reg_produto produto;
    int resp, reinicio, opcao, contador = 0, i;

    do
    {
        telaCadastroProduto();

        produto.codigoProduto = L->proxCodigoProduto;

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

        produto.quantidadeEstoque = 0;
        produto.custoMedio = 0;
        produto.valorTotal = 0;

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
                L->tamanho++;
            }
            else
            {
                limpar();
                gotoxy(25, 8);
                printf("1- Cadastrar no inicio");
                gotoxy(25, 10);
                printf("2- Cadastrar no meio");
                gotoxy(25, 12);
                printf("3- Cadastrar no final");
                gotoxy(01, 21);
                printf("Insira onde deseja cadastrar o produto...");
                gotoxy(43, 21);
                scanf("%d", &opcao);

                switch (opcao)
                {
                case 1:
                    p->proximo = L->primeiro;
                    L->primeiro = p;
                    break;

                case 2:

                    do
                    {
                        gotoxy(01, 21);
                        printf("Em qual posicao deseja cadastrar? (Max %d)...", L->tamanho);
                        gotoxy(47, 21);
                        scanf("%d", &resp);
                        if (resp <= 0 || resp > L->tamanho)
                        {
                            limpar();
                            gotoxy(24, 12);
                            printf("Posicao invalida!");
                        }

                    } while (resp <= 1 || resp > L->tamanho);

                    if (resp == L->tamanho) 
                    {
                        L->ultimo->proximo = p;
                        L->ultimo = p;
                        p->proximo = NULL;
                    }
                    else
                    {
                        PonteiroProduto atual = L->primeiro;
                        for (i = 0; i < resp - 1; i++)
                        {
                            atual = atual->proximo;
                        }
                        p->proximo = atual->proximo;
                        atual->proximo = p;
                    }
                    break;

                case 3:
                    L->ultimo->proximo = p;
                    L->ultimo = p;
                    p->proximo = NULL;
                    break;
                }
            }

            limpar();
            gotoxy(24, 12);
            printf("Cadastrado com sucesso!!");
            L->proxCodigoProduto++;
            L->tamanho++;
        }

        gotoxy(01, 21);
        printf("Deseja cadastrar um novo produto? (1-Sim 2-Nao)..:");
        gotoxy(52, 21);
        scanf("%d", &reinicio);

    } while (reinicio == 1);
}