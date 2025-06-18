/*Autor............Joao Victor Carneiro
  Data Modificacao.17/06/25
  Funcao...........Exclui Produto*/

#include "funcoes.h"
#include "interface.h"

void excluiProduto(Lista *L)
{
    int resp, confirmacao;
    int i;

    if (L->primeiro == NULL)
    {
        limpar();
        gotoxy(20, 12);
        printf("A lista esta vazia! Nao ha o que excluir.");
        return;
    }

    ordemCodigo(L);
    gotoxy(1, 22);
    printf("Insira qualquer tecla para continuar");
    gotoxy(01, 21);

    do
    {
        gotoxy(01, 21);
        printf("Digite o codigo do produto que deseja excluir:");
        gotoxy(49, 21);
        scanf("%d", &resp);
        if (resp <= 0 || resp > L->tamanho)
        {
            limpar();
            gotoxy(24, 12);
            printf("Posicao invalida!");
        }
    } while (resp <= 0 || resp > L->tamanho);

    PonteiroProduto atual = L->primeiro;
    PonteiroProduto anterior = NULL;

    while (atual != NULL && atual->conteudo.codigoProduto != resp)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL)
    {
        gotoxy(24, 12);
        printf("Produto com codigo %d nao encontrado.", resp);
        getch();
        return;
    }

    mostraProduto(atual);

    gotoxy(01, 21);
    printf("Deseja confirmar a exclusao (1-Sim 2-Nao)..:");
    gotoxy(46, 21);
    scanf("%d", &confirmacao);

    if (confirmacao != 1)
    {
        limpar();
        gotoxy(24, 12);
        printf("Operação cancelada pelo usuário.");
        getch();
        return;
    }

     if (anterior == NULL)
    {
        L->primeiro = atual->proximo;
        if (L->primeiro == NULL)
            L->ultimo = NULL;
    }
    else
    {
        anterior->proximo = atual->proximo;
        if (atual == L->ultimo)
            L->ultimo = anterior;
    }

    free(atual);
    L->tamanho--;

    salvarDadosProduto(L); 

    limpar();
    gotoxy(24, 12);
    printf("Produto excluido com sucesso!");
    getch();
}