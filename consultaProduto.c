/*Autor............Luan Araujo Mello
  Data Modificacao.13/06/25
  Funcao...........Consulta Produtos
*/

#include "funcoes.h"
#include "interface.h"
#include <string.h>

void mostraProduto(PonteiroProduto p)
{
    // Remove a quebra de linha que o fgets pode deixar no final da string
    p->conteudo.nomeProduto[strcspn(p->conteudo.nomeProduto, "\n")] = 0;
    p->conteudo.dataValidade[strcspn(p->conteudo.dataValidade, "\n")] = 0;

    limpar();
    gotoxy(25, 8);
    printf("--- DADOS DO PRODUTO ---");
    gotoxy(6, 11);
    printf("Codigo............: %d", p->conteudo.codigoProduto);
    gotoxy(6, 12);
    printf("Nome..............: %s", p->conteudo.nomeProduto);
    gotoxy(6, 13);
    printf("Unidade de Medida.: %s", p->conteudo.unidadeMedida);
    gotoxy(6, 14);
    printf("Data de Validade..: %s", p->conteudo.dataValidade);
    gotoxy(6, 15);
    printf("Quantidade Estoque: %.2f", p->conteudo.quantidadeEstoque);
    gotoxy(6, 16);
    printf("Custo Medio.......: R$ %.2f", p->conteudo.custoMedio);
    gotoxy(6, 17);
    printf("Valor Total.......: R$ %.2f", p->conteudo.valorTotal);
}

void consultaCodigo(Lista *L)
{
    if (L->primeiro == NULL)
    {
        limpar();
        gotoxy(27, 12);
        printf("A LISTA ESTA VAZIA. Nao ha produtos para consultar.");
        getch();
        return;
    }

    int codigo;
    PonteiroProduto p;

    limpar();
    gotoxy(24, 6);
    printf("** CONSULTA POR CODIGO **");

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
            printf("** CONSULTA POR CODIGO **");
            gotoxy(2, 8);
            printf("Produtos Cadastrados (continuacao):");
            linha_atual = 10;
        }
    }

    gotoxy(1, 21);
    printf("Digite o codigo que deseja consultar em detalhes: ");
    scanf("%d", &codigo);

    p = L->primeiro;
    while (p != NULL)
    {
        if (codigo == p->conteudo.codigoProduto)
        {
            mostraProduto(p);
            gotoxy(1, 21);
            printf("Pressione qualquer tecla para voltar ao menu...");
            getch();
            return;
        }
        p = p->proximo;
    }

    limpar();
    gotoxy(24, 12);
    printf("*PRODUTO COM CODIGO %d NAO ENCONTRADO*", codigo);
    getch();
    return;
}

void ordenaCodigo(Lista *L)
{
    if (L->primeiro == NULL || L->primeiro->proximo == NULL)
    {
        return;
    }
    int trocou;
    PonteiroProduto p;
    reg_produto temp;
    do
    {
        trocou = 0;
        p = L->primeiro;
        while (p->proximo != NULL)
        {
            if (p->conteudo.codigoProduto > p->proximo->conteudo.codigoProduto)
            {
                temp = p->conteudo;
                p->conteudo = p->proximo->conteudo;
                p->proximo->conteudo = temp;
                trocou = 1;
            }
            p = p->proximo;
        }
    } while (trocou);
}

void ordenaNome(Lista *L)
{
    if (L->primeiro == NULL || L->primeiro->proximo == NULL)
    {
        return;
    }
    int trocou;
    PonteiroProduto p;
    reg_produto temp;
    do
    {
        trocou = 0;
        p = L->primeiro;
        while (p->proximo != NULL)
        {
            if (strcmp(p->conteudo.nomeProduto, p->proximo->conteudo.nomeProduto) > 0)
            {
                temp = p->conteudo;
                p->conteudo = p->proximo->conteudo;
                p->proximo->conteudo = temp;
                trocou = 1;
            }
            p = p->proximo;
        }
    } while (trocou);
}

void ordemCodigo(Lista *L)
{
    PonteiroProduto p = L->primeiro;
    int contador = 1;
    limpar();
    gotoxy(1, 6);
    printf("|Codigo |Nome Produto      |Data Valid|Qtde Est.|Custo Med |Vlr Total");

    while (p != NULL)
    {
        gotoxy(1, 6 + contador);
        p->conteudo.nomeProduto[strcspn(p->conteudo.nomeProduto, "\n")] = 0;
        p->conteudo.dataValidade[strcspn(p->conteudo.dataValidade, "\n")] = 0;

        printf("|%-7d|%-18s|%-10s|%-9.2f|R$ %-7.2f|R$ %.2f",
               p->conteudo.codigoProduto,
               p->conteudo.nomeProduto,
               p->conteudo.dataValidade,
               p->conteudo.quantidadeEstoque,
               p->conteudo.custoMedio,
               p->conteudo.valorTotal);

        p = p->proximo;
        contador++;
        if (contador >= 14)
        {
            gotoxy(1, 21);
            printf("Pressione ENTER para a proxima pagina");
            getch();
            contador = 1;
            limpar();
            gotoxy(1, 6);
            printf("|Codigo |Nome Produto      |Data Valid|Qtde Est.|Custo Med |Vlr Total");
        }
    }
    gotoxy(1, 22);
    printf("Fim da lista. Pressione qualquer tecla para voltar.");
    getch();
}

void consultaProduto(Lista *L)
{
    int resp;
    limpar();
    if (L->primeiro == NULL)
    {
        limpar();
        gotoxy(27, 12);
        printf("A LISTA ESTA VAZIA");
        getch();
        return;
    }
    gotoxy(25, 6);
    printf("*MENU CONSULTA*");
    gotoxy(22, 8);
    printf("1-Consultar por codigo");
    gotoxy(22, 10);
    printf("2-Ordem alfabetica");
    gotoxy(22, 12);
    printf("3-Ordem de codigo");
    gotoxy(1, 21);
    printf("Insira sua resposta....           ");
    gotoxy(25, 21);
    scanf("%d", &resp);

    switch (resp)
    {
    case 1:
        consultaCodigo(L);
        break;
    case 2:
        ordenaNome(L);
        ordemCodigo(L);
        break;
    case 3:
        ordenaCodigo(L);
        ordemCodigo(L);
        break;
    }
}