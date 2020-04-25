#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAXNOME 60
#define MAXLINE 200

#include "estrutura.h"

// variaveis globais
FILE *fpAlunoRead, *fpAlunoWrite, *fpDisciplinaRead, *fpDisciplinaWrite;
periodo *basePeriodo = NULL;
int numeroDePeriodos = 0;

#include "menu.h"
#include "periodo.h"
#include "validacao.h"
#include "aluno.h"
#include "disciplina.h"
#include "arquivo.h"


int main()
{

    int opcaoMenu, opcaoObjeto = 1;

    explicacaoInicial();
    
    // Se os arquivos existem
    if(access("baseAluno.csv", F_OK)!=-1 && access("baseDisciplina.csv", F_OK)!=-1){
        fpAlunoRead = fopen("baseAluno.csv", "r");
        fpDisciplinaRead = fopen("baseDisciplina.csv", "r");

        if(fpAlunoRead==NULL || fpDisciplinaRead==NULL){
            printf("Erro ao abrir arquivos");
            return 0;
        }
        readBaseAluno();
        readBaseDisciplina();

    }
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


    if(access("baseAluno.csv", F_OK)!=-1 && access("baseDisciplina.csv", F_OK)!=-1){
        fclose(fpAlunoRead);
        fclose(fpDisciplinaRead);
    }   

    fpAlunoWrite = fopen("baseAluno.csv", "w");
    fpDisciplinaWrite = fopen("baseDisciplina.csv", "w");

    writeBase();

    fclose(fpAlunoWrite);
    fclose(fpDisciplinaWrite);

    printf("Aplicacao terminada, dados escritos com sucesso!\n");

    
    
    return 0;
}
