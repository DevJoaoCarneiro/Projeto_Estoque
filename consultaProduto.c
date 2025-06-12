#include "funcoes.h"
#include "interface.h"
#include <string.h>

static void mostraProduto(PonteiroProduto p)
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

    gotoxy(1, 21);
    printf("Pressione qualquer tecla para continuar...");
    getch();
}

void consultaCodigo(Lista *L)
{
    int codigo;
    PonteiroProduto p = L->primeiro;
    limpar();
    gotoxy(24, 12);
    printf("**CONSULTA POR CODIGO**");
    gotoxy(01, 21);
    printf("Digite o codigo que deseja consultar...");
    gotoxy(41, 21);
    scanf("%d", &codigo);

    while (p != NULL)
    {
        if (codigo == p->conteudo.codigoProduto)
        {
            mostraProduto(p);
            return;
        }
        p = p->proximo;
    }
    limpar();
    gotoxy(24, 12);
    printf("*CODIGO NAO ENCONTRADO*");
    return;
}

void ordenaCodigo(Lista *L)
{
    if (L->primeiro == NULL)
    {
        return;
    }

    PonteiroProduto p;
    PonteiroProduto q;
    reg_produto temp;

    p = L->primeiro;

    while (p->proximo != NULL)
    {
        q = p->proximo;
        if (p->conteudo.codigoProduto > q->conteudo.codigoProduto)
        {
            temp = p->conteudo;
            p->conteudo = q->conteudo;
            q->conteudo = temp;
        }
        p = p->proximo;
    }
}

void ordenaNome(Lista *L)
{
    if (L->primeiro == NULL)
    {
        return;
    }

    PonteiroProduto p;
    PonteiroProduto q;
    reg_produto func;

    p = L->primeiro;

    while (p->proximo != NULL)
    {
        q = p->proximo;
        if (strcmp(p->conteudo.nomeProduto, q->conteudo.nomeProduto) > 0)
        {
            func = p->conteudo;
            p->conteudo = q->conteudo;
            q->conteudo = func;
        }
        p = p->proximo;
    }
}

void ordemCodigo(Lista *L)
{

    PonteiroProduto p = L->primeiro;
    int contador = 1;
    limpar();
    gotoxy(01, 06);
    printf("|Codigo    |Nome Produto                                 |Data Validade          ");

    while (p != NULL)
    {
        gotoxy(01, 06 + contador);
        printf("|%-10d|%-45s|%-8s", p->conteudo.codigoProduto, p->conteudo.nomeProduto, p->conteudo.dataValidade);
        p = p->proximo;
        contador++;
        if (contador >= 14)
        {
            gotoxy(01, 21);
            printf("Pressione ENTER para a proxima pagina");
            getch();

            contador = 0;
            limpar();
            gotoxy(01, 06);
            printf("|Codigo    |Nome Produto                                 |Data Validade          ");
        }
    }
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
        return;
    }

    gotoxy(25, 06);
    printf("*MENU OPCOES*");
    gotoxy(22, 8);
    printf("1-Consultar por codigo");
    gotoxy(22, 10);
    printf("2-Ordem alfabeticar");
    gotoxy(22, 12);
    printf("3-Ordem de codigo");
    gotoxy(01, 21);
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