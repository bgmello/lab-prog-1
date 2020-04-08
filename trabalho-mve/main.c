#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNOME 60

#include "estrutura.h"

// variaveis globais
periodo *basePeriodo = NULL;
int numeroDePeriodos = 0;

#include "menu.h"
#include "periodo.h"
#include "validacao.h"
#include "aluno.h"
#include "disciplina.h"

int main()
{

    int opcaoMenu, opcaoObjeto = 1;

    printf("\n\n");
    do
    {
        opcaoMenu = menuInicial();

        // se a opcao nao e invalida
        if (opcaoMenu == 1)
        {
            opcaoObjeto = menuConsultar();
            switch(opcaoObjeto)
            {
            case 1:
                buscaAluno();
                break;
            case 2:
                buscarDisciplina();
                break;
            }
        }
        if(opcaoMenu == 2)
        {
            opcaoObjeto = menuAdicionar();
            switch(opcaoObjeto)
            {
            case 1:
                adicionaAlunoMenu();
                break;
            case 2:
                adicionaDisciplinaMenu();
                break;
            case 3:
                adicionaPeriodoMenu();
                break;

            }
        }

        if(opcaoMenu == 3)
        {
            opcaoObjeto = menuConsultar();
            switch(opcaoObjeto)
            {
            case 1:
                removeAlunoMenu();
                break;
            case 2:
                removeDisciplinaMenu();
                break;
            }
        }

        if(opcaoMenu == 4)
        {
            opcaoObjeto = menuVincularDesvincular();
            switch(opcaoObjeto)
            {
            case 1:
                vinculaAlunoMenu();
                break;
            case 2:
                desvinculaAlunoMenu();
                break;
            }
        }

    }
    while((opcaoMenu == 1) || (opcaoMenu == 2) || (opcaoMenu == 3) || (opcaoMenu == 4));

    printf("Aplicacao terminada\n");

    return 0;
}
