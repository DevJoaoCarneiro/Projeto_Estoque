/*Autor............Luan Araujo Mello
  Data Modificacao.13/06/25
  Funcao...........Edita Produtos
*/

#include "funcoes.h"
#include "interface.h"
#include <string.h>

void editaProduto(Lista *L)
{
  if (L->primeiro == NULL)
  {
    limpar();
    gotoxy(20, 12);
    printf("A LISTA ESTA VAZIA. Nao ha produtos para editar.");
    return;
  }

  int codigo_para_editar;
  int resp_confirmacao;
  PonteiroProduto p;
  int encontrado = 0;

  limpar();
  gotoxy(30, 6);
  printf("** EDICAO DE PRODUTO **");

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
      gotoxy(30, 6);
      printf("** EDICAO DE PRODUTO **");
      gotoxy(2, 8);
      printf("Produtos Cadastrados (continuacao):");
      linha_atual = 10;
    }
  }

  gotoxy(1, 21);
  printf("Digite o codigo do produto que deseja editar: ");
  scanf("%d", &codigo_para_editar);

  p = L->primeiro;
  while (p != NULL)
  {
    if (p->conteudo.codigoProduto == codigo_para_editar)
    {
      encontrado = 1;
      break;
    }
    p = p->proximo;
  }

  if (encontrado)
  {
    mostraProduto(p);

    gotoxy(1, 21);
    printf("Deseja editar este produto? (1-Sim / 2-Nao): ");
    scanf("%d", &resp_confirmacao);

    if (resp_confirmacao == 1)
    {
      int opcao_campo;
      do
      {
        limpar();
        gotoxy(25, 6);
        printf("* EDITANDO PRODUTO: %d - %s *", p->conteudo.codigoProduto, p->conteudo.nomeProduto);

        gotoxy(22, 9);
        printf("Qual campo deseja editar?");
        gotoxy(22, 11);
        printf("1- Nome do Produto");
        gotoxy(22, 12);
        printf("2- Unidade de Medida");
        gotoxy(22, 13);
        printf("3- Data de Validade");
        gotoxy(22, 14);
        printf("4- Editar Todos os Campos");
        gotoxy(22, 15);
        printf("5- Voltar");
        gotoxy(1, 21);
        printf("Digite sua opcao: ");
        scanf("%d", &opcao_campo);

        switch (opcao_campo)
        {
        case 1:
          limpar();
          gotoxy(8, 10);
          printf("Digite o NOVO NOME: ");
          fflush(stdin);
          fgets(p->conteudo.nomeProduto, 50, stdin);
          p->conteudo.nomeProduto[strcspn(p->conteudo.nomeProduto, "\n")] = 0;
          gotoxy(1, 21);;
          printf("Nome alterado com sucesso!");
          getch();
          break;
        case 2:
          limpar();
          gotoxy(8, 10);
          printf("Digite a NOVA UNIDADE DE MEDIDA: ");
          fflush(stdin);
          fgets(p->conteudo.unidadeMedida, 10, stdin);
          p->conteudo.unidadeMedida[strcspn(p->conteudo.unidadeMedida, "\n")] = 0;
          gotoxy(1, 21);
          printf("Unidade de medida alterada com sucesso!");
          getch();
          break;
        case 3:
          limpar();
          gotoxy(8, 10);
          printf("Digite a NOVA DATA DE VALIDADE: ");
          fflush(stdin);
          fgets(p->conteudo.dataValidade, 11, stdin);
          p->conteudo.dataValidade[strcspn(p->conteudo.dataValidade, "\n")] = 0;
          gotoxy(1, 21);
          printf("Data de validade alterada com sucesso!");
          getch();
          break;
        case 4:
          limpar();
          gotoxy(8, 8);
          printf("Novo Nome........: ");
          fflush(stdin);
          fgets(p->conteudo.nomeProduto, 50, stdin);
          p->conteudo.nomeProduto[strcspn(p->conteudo.nomeProduto, "\n")] = 0;

          gotoxy(8, 10);
          printf("Nova Un. Medida..: ");
          fflush(stdin);
          fgets(p->conteudo.unidadeMedida, 10, stdin);
          p->conteudo.unidadeMedida[strcspn(p->conteudo.unidadeMedida, "\n")] = 0;

          gotoxy(8, 12);
          printf("Nova Data Validade: ");
          fflush(stdin);
          fgets(p->conteudo.dataValidade, 11, stdin);
          p->conteudo.dataValidade[strcspn(p->conteudo.dataValidade, "\n")] = 0;

          gotoxy(1, 21);
          printf("Todos os campos foram alterados!");
          getch();
          break;
        case 5:
          break;
        default:
          gotoxy(20, 15);
          printf("Opcao invalida!");
          getch();
          break;
        }
      } while (opcao_campo != 5);
    }
  }
  else
  {
    limpar();
    gotoxy(24, 12);
    printf("* PRODUTO COM CODIGO %d NAO ENCONTRADO *", codigo_para_editar);
    getch();
  }
}