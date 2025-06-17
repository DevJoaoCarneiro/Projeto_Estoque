/*Autor............Joao Victor Carneiro
  Data Modificacao.17/06/25
  Funcao...........Cadastro Movimentacao*/

#include "funcoes.h"
#include "interface.h"

void cadastrarMovimentacao(Lista *L, Lista_Movimentacao *X)
{
    telaMovimentacao();

    reg_movimentacao movimentacao;

    gotoxy(33, 06);
    scanf("%d", &movimentacao.codigo_produto);

    PonteiroProduto p = L->primeiro;
    while (p != NULL)
    {
        if (movimentacao.codigo_produto == p->conteudo.codigoProduto)
        {
            gotoxy(33, 07);
            printf("%s", p->conteudo.nomeProduto);

            gotoxy(18, 16);
            printf("%.2f", p->conteudo.quantidadeEstoque);

            gotoxy(38, 16);
            printf("%.2f", p->conteudo.custoMedio);

            gotoxy(58, 16);
            printf("%.2f", p->conteudo.valorTotal);
            break;
        }
        p = p->proximo;
    }

    if (p == NULL)
    {
        limpar();
        gotoxy(24, 18);
        printf("Produto nao encontrado!");
        return;
    }

    gotoxy(33, 8);
    fflush(stdin);
    fgets(movimentacao.dataMovimentacao, 11, stdin);

    gotoxy(01, 21);
    printf("Digite S = Saida ou E = Entrada");
    gotoxy(33, 9);
    scanf(" %c", &movimentacao.tipoMovimentacao);
    gotoxy(01, 21);
    printf("                                   ");

    gotoxy(33, 10);
    scanf("%f", &movimentacao.qtdeMovimentacao);

    if (movimentacao.tipoMovimentacao == 'S' || movimentacao.tipoMovimentacao == 's')
    {
        movimentacao.valor_unitario = 0;
        if (p->conteudo.quantidadeEstoque >= movimentacao.qtdeMovimentacao)
        {
            p->conteudo.quantidadeEstoque -= movimentacao.qtdeMovimentacao;
            p->conteudo.valorTotal = p->conteudo.quantidadeEstoque * p->conteudo.custoMedio;
        }
        else
        {
            limpar();
            gotoxy(24, 18);
            printf("Erro: Estoque insuficiente para retirada!");
            return;
        }
    }
    else
    {

        gotoxy(33, 11);
        scanf("%f", &movimentacao.valor_unitario);

        p->conteudo.custoMedio = ((p->conteudo.custoMedio * p->conteudo.quantidadeEstoque) + (movimentacao.valor_unitario * movimentacao.qtdeMovimentacao)) / (p->conteudo.quantidadeEstoque + movimentacao.qtdeMovimentacao);

        p->conteudo.quantidadeEstoque += movimentacao.qtdeMovimentacao;

        p->conteudo.valorTotal = p->conteudo.quantidadeEstoque * p->conteudo.custoMedio;
    }

    Ponteiro_Mov x = (Ponteiro_Mov)malloc(sizeof(TipoItem_Mov));

    x->movimentacao = movimentacao;
    x->proximo = NULL;

    if (X->primeiro == NULL)
    {
        X->primeiro = x;
        X->ultimo = x;
    }
    else
    {
        x->anterior = X->ultimo;
        X->ultimo->proximo = x;
        X->ultimo = x;
        x->proximo = NULL;
    }

    gotoxy(33, 12);
    printf("%.2f", p->conteudo.valorTotal);

    gotoxy(18, 16);
    printf("%.2f", p->conteudo.quantidadeEstoque);

    gotoxy(38, 16);
    printf("%.2f", p->conteudo.custoMedio);

    gotoxy(58, 16);
    printf("%.2f", p->conteudo.valorTotal);

    gotoxy(1, 22);
    printf("Movimentacao registrada com sucesso! Pressione qualquer tecla...");
    getch();
}