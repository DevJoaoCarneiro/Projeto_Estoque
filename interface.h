#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y);
void tela();
void limpar();
int telaPrincipal();
void telaCadastroProduto();
int opcaoCadastro();
void telaMovimentacao();

#endif