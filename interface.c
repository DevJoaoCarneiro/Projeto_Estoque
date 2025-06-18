/*Autor............Joao Victor Carneiro
  Data Modificacao.11/06/25
  Funcao...........Interfaces e telas*/

#include "interface.h"

void gotoxy(int x, int y)

{
  COORD coord;
  coord.X = (short)x;
  coord.Y = (short)y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void tela()

{
  int i;
  system("cls");
  printf("===============================================================================\n");
  for (i = 0; i < 22; i++)
  {
    printf("|                                                                             |\n");
  }
  printf("===============================================================================\n");
  gotoxy(30, 02);
  printf("Sistema de Estoque");
  gotoxy(01, 01);
  printf("Autor.......Joao Carneiro");
  gotoxy(01, 02);
  printf("Autor.......Luan Araujo");
  gotoxy(01, 03);
  printf("Ano.........2025");
  gotoxy(00, 04);
  printf("===============================================================================\n");
  gotoxy(00, 20);
  printf("===============================================================================\n");
}

void limpar()
{
  int i;
  for (i = 0; i < 15; i++)
  {
    gotoxy(1, 05 + i);
    printf("                                                                          ");
  }
  gotoxy(01, 21);
  printf("                                                                          ");
  gotoxy(01, 22);
  printf("                                                                          ");
}

int telaPrincipal()
{
  int resp;
  limpar();
  gotoxy(22, 8);
  printf("1- Menu Cadastro do Produto");
  gotoxy(22, 10);
  printf("2- Menu movimentacao de Estoque");
  gotoxy(22, 12);
  printf("3- Finalizar o programa");
  gotoxy(01, 21);
  printf("Digite sua resposta....");
  scanf("%d", &resp);

  return resp;
}

void telaCadastroProduto()
{
  limpar();
  gotoxy(8, 8);
  printf("1- Descricao do produto..:");
  gotoxy(8, 10);
  printf("2- Unidade de medida.....:");
  gotoxy(8, 12);
  printf("3- Data de validade......:");

  gotoxy(06, 13);
  printf("+----------------------------------------------------------------+");
  gotoxy(06, 14);
  printf("|    QUANTIDADE     |      CUSTO MEDIO     |      VALOR TOTAL    |");
  gotoxy(06, 15);
  printf("+----------------------------------------------------------------+");
  gotoxy(06, 16);
  printf("|                   |                      |                     |");
  gotoxy(06, 17);
  printf("|                   |                      |                     |");
  gotoxy(06, 18);
  printf("+----------------------------------------------------------------+");
}

int opcaoCadastro()
{
  int resp;
  limpar();
  gotoxy(25, 8);
  printf("1- Cadastrar Produto.:");
  gotoxy(25, 10);
  printf("2- Consultar Produto.:");
  gotoxy(25, 12);
  printf("3- Editar Produto....:");
  gotoxy(25, 14);
  printf("4- Excluir Produto...:");
  gotoxy(25, 16);
  printf("5- Voltar ao Menu....:");
  gotoxy(01, 21);
  printf("Digite sua resposta..:                             ");
  gotoxy(24, 21);
  scanf("%d", &resp);

  return resp;
}

void telaMovimentacao()
{
  limpar();
  gotoxy(06, 06);
  printf("Codigo do Produto.......:");
  gotoxy(06, 07);
  printf("Nome do Produto.........:");
  gotoxy(06, 8);
  printf("Data Da Movimentacao....:");
  gotoxy(06, 9);
  printf("Tipo de Movimentacao....:");
  gotoxy(06, 10);
  printf("Quantidade..............:");
  gotoxy(06, 11);
  printf("Valor Unitario..........:");
  gotoxy(06, 12);
  printf("Valor Total.............:");

  gotoxy(06, 13);
  printf("+----------------------------------------------------------------+");
  gotoxy(06, 14);
  printf("|    QUANTIDADE     |      CUSTO MEDIO     |      VALOR TOTAL    |");
  gotoxy(06, 15);
  printf("+----------------------------------------------------------------+");
  gotoxy(06, 16);
  printf("|                   |                      |                     |");
  gotoxy(06, 17);
  printf("|                   |                      |                     |");
  gotoxy(06, 18);
  printf("+----------------------------------------------------------------+");
}

int opcaoMovimentacao()
{
  int resp;

  limpar();

  gotoxy(22, 8);
  printf("1- Cadastra Movimentacao de Estoque");
  gotoxy(22, 10);
  printf("2- Lista Movimentacao de Estoque");
  gotoxy(22, 12);
  printf("3- Retornar ao Menu Principal");

  gotoxy(01, 21);
  printf("Digite sua opcao..: ");
  scanf("%d", &resp);

  return resp;
}