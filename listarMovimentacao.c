/*
  Autor............Luan Araujo Mello
  Data Modificacao.17/06/25
  Funcao...........Listar movimentação do Estoque.
*/

#include "funcoes.h"
#include "interface.h"
#include <string.h>

void liberaListaTemporaria(Lista *temp_L)
{
    PonteiroProduto atual = temp_L->primeiro;
    PonteiroProduto proximo;
    while (atual != NULL)
    {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    temp_L->primeiro = NULL;
    temp_L->ultimo = NULL;
}

void listarMovimentacao(Lista *L, Lista_Movimentacao *X)
{
    int opcao_filtro;
    int codigo_filtro = 0;
    int filtro_ativo = 0;
    PonteiroProduto p_produto_filtrado = NULL;

    limpar();

    if (X->primeiro == NULL)
    {
        gotoxy(24, 12);
        printf("Nenhuma movimentacao registrada no sistema.");
        getch();
        return;
    }

    gotoxy(15, 8);
    printf("Deseja filtrar o relatorio por um produto?");
    gotoxy(15, 10);
    printf("1 - SIM, filtrar por codigo");
    gotoxy(15, 12);
    printf("2 - NAO, mostrar todas as movimentacoes");
    gotoxy(1, 21);
    printf("Digite sua opcao..: ");
    scanf("%d", &opcao_filtro);

    if (opcao_filtro == 1)
    {
        filtro_ativo = 1;
        limpar();

        gotoxy(24, 6);
        printf("** ESCOLHA UM PRODUTO ABAIXO **");
        gotoxy(2, 8);
        printf("Produtos Cadastrados:");

        PonteiroProduto aux = L->primeiro;
        int linha_atual = 10;
        while (aux != NULL)
        {
            gotoxy(4, linha_atual);
            aux->conteudo.nomeProduto[strcspn(aux->conteudo.nomeProduto, "\n")] = 0;
            printf("Codigo: %-4d | Nome: %s", aux->conteudo.codigoProduto, aux->conteudo.nomeProduto);
            aux = aux->proximo;
            linha_atual++;

            if (linha_atual > 18)
            {
                gotoxy(1, 22);
                printf("Pressione qualquer tecla para ver mais...");
                getch();
                limpar();
                gotoxy(24, 6);
                printf("** ESCOLHA UM PRODUTO ABAIXO **");
                gotoxy(2, 8);
                printf("Produtos Cadastrados (continuacao):");
                linha_atual = 10;
            }
        }

        gotoxy(1, 21);
        printf("Digite o codigo do produto a ser filtrado: ");
        scanf("%d", &codigo_filtro);

        PonteiroProduto p_valida = L->primeiro;
        int encontrado = 0;
        while (p_valida != NULL)
        {
            if (p_valida->conteudo.codigoProduto == codigo_filtro)
            {
                encontrado = 1;
                p_produto_filtrado = p_valida;
                break;
            }
            p_valida = p_valida->proximo;
        }

        if (!encontrado)
        {
            limpar();
            gotoxy(20, 12);
            printf("ERRO: Produto com o codigo %d nao foi encontrado.", codigo_filtro);
            getch();
            return;
        }
    }

    Lista temp_L;
    inicializaLista(&temp_L);
    PonteiroProduto p_orig = L->primeiro;
    while (p_orig != NULL)
    {
        PonteiroProduto p_temp = (PonteiroProduto)malloc(sizeof(TipoItem));
        if (p_temp == NULL)
        {
            gotoxy(1, 22);
            printf("Erro de alocacao de memoria!");
            getch();
            liberaListaTemporaria(&temp_L);
            return;
        }
        p_temp->conteudo = p_orig->conteudo;
        p_temp->conteudo.quantidadeEstoque = 0;
        p_temp->conteudo.custoMedio = 0;
        p_temp->conteudo.valorTotal = 0;
        p_temp->proximo = NULL;

        if (temp_L.primeiro == NULL)
        {
            temp_L.primeiro = p_temp;
            temp_L.ultimo = p_temp;
        }
        else
        {
            temp_L.ultimo->proximo = p_temp;
            temp_L.ultimo = p_temp;
        }
        p_orig = p_orig->proximo;
    }

    Ponteiro_Mov mov_ptr_pagina = X->primeiro;
    int pagina = 1;
    int total_registros_mostrados = 0;

    do
    {
        limpar();
        gotoxy(1, 6);
        if (filtro_ativo)
        {
            char nome_prod[51];
            strcpy(nome_prod, p_produto_filtrado->conteudo.nomeProduto);
            nome_prod[strcspn(nome_prod, "\n")] = 0;
            printf("  CONSULTA DE MOVIMENTACAO - PRODUTO: %d (%s)", codigo_filtro, nome_prod);
        }
        else
        {
            printf("  SISTEMA DE CONTROLE DE ESTOQUE - CONSULTA DE MOVIMENTACAO GERAL");
        }
        gotoxy(65, 7);
        printf("Pagina %d", pagina);

        gotoxy(1, 9);
        printf("Data      |Cd|T|Qtd.Mov| Vlr Unit| Vlr Mov| Qtd Fim|C. Medio|Vlr Total");
        gotoxy(1, 10);
        printf("----------+--+-+-------+---------+--------+--------+--------+---------");

        int contador_linhas = 0;
        while (mov_ptr_pagina != NULL && contador_linhas < 8)
        {
            PonteiroProduto temp_prod_ptr = temp_L.primeiro;
            while (temp_prod_ptr != NULL && temp_prod_ptr->conteudo.codigoProduto != mov_ptr_pagina->movimentacao.codigo_produto)
            {
                temp_prod_ptr = temp_prod_ptr->proximo;
            }

            if (temp_prod_ptr != NULL)
            {
                reg_movimentacao *mov = &mov_ptr_pagina->movimentacao;
                reg_produto *prod = &temp_prod_ptr->conteudo;

                if (mov->tipoMovimentacao == 'S' || mov->tipoMovimentacao == 's')
                {
                    prod->quantidadeEstoque -= mov->qtdeMovimentacao;
                    prod->valorTotal = prod->quantidadeEstoque * prod->custoMedio;
                }
                else
                {
                    float nova_quantidade = prod->quantidadeEstoque + mov->qtdeMovimentacao;
                    if (nova_quantidade > 0)
                        prod->custoMedio = ((prod->custoMedio * prod->quantidadeEstoque) + (mov->valor_unitario * mov->qtdeMovimentacao)) / nova_quantidade;
                    prod->quantidadeEstoque = nova_quantidade;
                    prod->valorTotal = prod->quantidadeEstoque * prod->custoMedio;
                }

                if (!filtro_ativo || mov->codigo_produto == codigo_filtro)
                {
                    float vlr_unit_display, vlr_total_display;
                    if (mov->tipoMovimentacao == 'S' || mov->tipoMovimentacao == 's')
                    {
                        vlr_unit_display = prod->custoMedio;
                        vlr_total_display = mov->qtdeMovimentacao * vlr_unit_display;
                    }
                    else
                    {
                        vlr_unit_display = mov->valor_unitario;
                        vlr_total_display = mov->qtdeMovimentacao * vlr_unit_display;
                    }

                    mov->dataMovimentacao[strcspn(mov->dataMovimentacao, "\n")] = 0;
                    gotoxy(1, 11 + contador_linhas);
                    printf("%-10s|%-2d|%c|%7.2f|%9.2f|%8.2f|%8.2f|%8.2f|%9.2f",
                           mov->dataMovimentacao, mov->codigo_produto, mov->tipoMovimentacao, mov->qtdeMovimentacao,
                           vlr_unit_display, vlr_total_display,
                           prod->quantidadeEstoque, prod->custoMedio, prod->valorTotal);

                    contador_linhas++;
                    total_registros_mostrados++;
                }
            }
            mov_ptr_pagina = mov_ptr_pagina->proximo;
        }

        gotoxy(1, 22);
        if (mov_ptr_pagina != NULL)
        {
            printf("Pressione qualquer tecla para ir para a proxima pagina...");
            pagina++;
        }
        else
        {
            if (total_registros_mostrados == 0)
            {
                gotoxy(15, 15);
                printf("Nenhuma movimentacao encontrada para o produto %d.", codigo_filtro);
            }
            gotoxy(1, 22);
            printf("Fim do relatorio. Pressione qualquer tecla para voltar ao menu.");
        }
        getch();

    } while (mov_ptr_pagina != NULL);

    liberaListaTemporaria(&temp_L);
}