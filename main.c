#include <stdio.h>
#include "funcoes.h"
#include "interface.h"

int main(){
    int resp;
    Lista L;
    inicializaLista(&L);
    tela();
    resp = telaPrincipal();
    
    switch(resp){
        case 1:
            cadastroProduto(&L);
            break;
        case 2:
            printf("Teste");
            break;
        case 3:
            return 0;
            break;

    }
    

    gotoxy(01,24);
    return 0;
}