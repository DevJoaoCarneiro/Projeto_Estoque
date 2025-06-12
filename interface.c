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
  printf("TELA CADASTRO");
  gotoxy(01, 01);
  printf("Autor.......Joao Carneiro");
  gotoxy(01, 02);
  printf("Faculdade...UNICV");
  gotoxy(01, 03);
  printf("Ano.........2024");
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

int telaPrincipal(){
    int resp;
    limpar();
    gotoxy(20,12);
    printf("1- Menu Cadastro do Produto");
    gotoxy(20,14);
    printf("2- Menu movimentacao de Estoque");
    gotoxy(20,16);
    printf("3- Finalizar o programa");
    gotoxy(01,21);
    printf("Digite sua resposta....");
    scanf("%d", &resp);

    return resp;
}

void telaCadastroProduto(){
    limpar();
    gotoxy(6,10);
    printf("1- Descricao do produto..:");
    gotoxy(6,12);
    printf("2- Unidade de medida.....:");
    gotoxy(6,14);
    printf("3- Data de validade......:");
   
}
