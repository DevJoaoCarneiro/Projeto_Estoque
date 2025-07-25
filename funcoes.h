#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

typedef struct
{
    int codigoProduto;
    char nomeProduto[50];
    char unidadeMedida[10];
    char dataValidade[11];
    float quantidadeEstoque;
    float custoMedio;
    double valorTotal;
} reg_produto;

typedef struct TipoItem *PonteiroProduto;

typedef struct TipoItem
{
    reg_produto conteudo;
    PonteiroProduto proximo;
} TipoItem;

typedef struct
{
    PonteiroProduto primeiro;
    PonteiroProduto ultimo;
    int tamanho;
    int proxCodigoProduto;
} Lista;

typedef struct
{
    char dataMovimentacao[11];
    int codigo_produto;
    char tipoMovimentacao;
    float qtdeMovimentacao;
    float valor_unitario;
    float valor_total;
} reg_movimentacao;

typedef struct TipoItem_Mov *Ponteiro_Mov;

typedef struct TipoItem_Mov
{
    reg_movimentacao movimentacao;
    Ponteiro_Mov proximo;
    Ponteiro_Mov anterior;
} TipoItem_Mov;

typedef struct
{
    Ponteiro_Mov primeiro;
    Ponteiro_Mov ultimo;
} Lista_Movimentacao;

void inicializaLista(Lista *L);

void inicializaListaMovimentacao(Lista_Movimentacao *L);

void cadastroProduto(Lista *L);

void consultaCodigo(Lista *L);

void ordenaCodigo(Lista *L);

void ordenaNome(Lista *L);

void ordemCodigo(Lista *L);

void consultaProduto(Lista *L);

void mostraProduto(PonteiroProduto p);

void editaProduto(Lista *L);

void excluiProduto(Lista *L);

void cadastrarMovimentacao(Lista *L, Lista_Movimentacao *X);

void listarMovimentacao(Lista *L, Lista_Movimentacao *X);

void salvarDadosProduto(Lista *L);

void salvarDadosMovimentacao(Lista_Movimentacao *X);

void carregarArquivoProduto(Lista *L);

void carregarMovimentacao(Lista_Movimentacao *L);

#endif