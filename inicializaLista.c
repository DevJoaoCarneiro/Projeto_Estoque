/*Autor............Joao Victor Carneiro
  Data Modificacao.11/06/25
  Funcao...........Cadastro produto*/
#include "funcoes.h"

void inicializaLista(Lista *L)
{
    L->primeiro = NULL;
    L->ultimo = NULL;
    L->tamanho = 0;
    L->proxCodigoProduto = 1;
}

void inicializaListaMovimentacao(Lista_Movimentacao *L)
{
    L->primeiro = NULL;
    L->ultimo = NULL;
}