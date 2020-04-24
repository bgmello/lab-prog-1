#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNOME 60
#define MAXLINE 200

#include "estrutura.h"

// variaveis globais
FILE *fpAluno, *fpDisciplina;
periodo *basePeriodo = NULL;
int numeroDePeriodos = 0;

#include "menu.h"
#include "periodo.h"
#include "validacao.h"
#include "aluno.h"
#include "disciplina.h"

int isEmpty(FILE *file){
    long savedOffset = ftell(file);
    fseek(file, 0, SEEK_END);

    if (ftell(file) == 0){
        return 1;
    }

    fseek(file, savedOffset, SEEK_SET);
    return 0;
}

void writeBase(){

    int i,j,r;

    if(isEmpty(fpAluno)){
        fprintf(fpAluno, "periodo,codigoAluno,nomeAluno,cpf,codigoDisciplina\n");
    }

    if(isEmpty(fpDisciplina)){
        fprintf(fpDisciplina, "periodo,codigoDisciplina,nomeDisciplina,nomeProfessor,quantidadeCreditos\n");
    }

    for(i=0;i<numeroDePeriodos;i++){
        for(j=0;j<basePeriodo[i].numeroDeAlunos;j++){
            for(r=0;r<basePeriodo[i].baseAlunos[j].numeroDeDisciplinas;r++){
                fprintf(fpAluno, "%d,%d,%s,%s,%d\n", basePeriodo[i].nomePeriodo, basePeriodo[i].baseAlunos[j].codigoAl, basePeriodo[i].baseAlunos[j].nome, basePeriodo[i].baseAlunos[j].cpf, basePeriodo[i].baseAlunos[j].listaCodigosDis[r]);
            }
        }
    }

    for(i=0;i<numeroDePeriodos;i++){
        for(j=0;j<basePeriodo[i].numeroDeDisciplinas;j++){
            fprintf(fpDisciplina, "%d,%d,%s,%s,%d\n", basePeriodo[i].nomePeriodo, basePeriodo[i].baseDisciplinas[j].codigoDis, basePeriodo[i].baseDisciplinas[j].nome, basePeriodo[i].baseDisciplinas[j].professor, basePeriodo[i].baseDisciplinas[j].quantidadeCreditos);
        }
    }
}

void readBaseAluno(){

    char line[MAXLINE];
    char seps[] = ",";
    char *token;
    int nomePeriodo, posicaoPeriodo;
    int codigoDisciplina;
    aluno novoAluno;

    if(!isEmpty(fpAluno)){

        //le o cabecalho
        fgets(line, sizeof(line), fpAluno);

        while (fgets(line, sizeof(line), fpAluno)) {

            token = strtok(line, seps);
            sscanf (token, "%d", &nomePeriodo);
            token = strtok (NULL, seps);
            sscanf (token, "%d", &novoAluno.codigoAl);
            token = strtok (NULL, seps);
            sscanf (token, "%[^,]", novoAluno.nome);
            token = strtok (NULL, seps);
            sscanf (token, "%s", novoAluno.cpf);
            token = strtok (NULL, seps);
            sscanf (token, "%d", &codigoDisciplina);

    
            adicionaPeriodo(nomePeriodo);

            createAluno(nomePeriodo, novoAluno.codigoAl, novoAluno.cpf, novoAluno.nome);
            addDisciplinaInAluno(nomePeriodo, novoAluno.codigoAl, codigoDisciplina);
        }

    }
}

void readBaseDisciplina(){

    char line[MAXLINE];
    char seps[] = ",";
    char *token;
    int nomePeriodo, posicaoPeriodo;
    int codigoDisciplina;
    disciplina novaDisciplina;

    if(!isEmpty(fpDisciplina)){

        //le o cabecalho
        fgets(line, sizeof(line), fpDisciplina);

        while (fgets(line, sizeof(line), fpDisciplina)) {

            token = strtok(line, seps);
            sscanf (token, "%d", &nomePeriodo);
            token = strtok (NULL, seps);
            sscanf (token, "%d", &novaDisciplina.codigoDis);
            token = strtok (NULL, seps);
            sscanf (token, "%[^,]", novaDisciplina.nome);
            token = strtok (NULL, seps);
            sscanf (token, "%s", novaDisciplina.professor);
            token = strtok (NULL, seps);
            sscanf (token, "%d", &novaDisciplina.quantidadeCreditos);

    
            adicionaPeriodo(nomePeriodo);

            adicionaDisciplina(nomePeriodo, novaDisciplina.codigoDis, novaDisciplina.quantidadeCreditos, novaDisciplina.nome, novaDisciplina.professor);
        }

    }
}

int main()
{

    int opcaoMenu, opcaoObjeto = 1;
    fpAluno = fopen("baseAluno.csv", "a+r");
    fpDisciplina = fopen("baseDiscilina.csv", "a+r");

    if(fpAluno==NULL || fpDisciplina==NULL){
        printf("Erro ao abrir arquivos");
        return 0;
    }
    readBaseAluno();
    readBaseDisciplina();
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

    writeBase();
    fclose(fpAluno);
    fclose(fpDisciplina);

    printf("Aplicacao terminada, dados escritos com sucesso!\n");

    
    
    return 0;
}
