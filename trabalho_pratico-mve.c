#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAXNOME 60

//definição da estrutura aluno
typedef struct aluno
{

    char codigo[5];
    char nome[MAXNOME];
    char cpf[11];
    char periodo[6];

} aluno;

//definição da estrutura disciplina
typedef struct disciplina
{

    char codigo[4];
    char nome[MAXNOME];
    int quantiadeCreditos;
    char periodo[6];

} disciplina;

int verificaCPF(char *cpf)
{

    int j, k, t, digito1 = 0, digito2 = 0;
    char numIguais[11], i;

    if(strlen(cpf) != 11)
        return 0;

    //cpf com todos os digitos iguais é falso
    for(i = '0'; i <= '9'; ++i)
    {

        for(j = 0; j <= 11; ++j)
        {
            numIguais[j] = i;
        }

        if(strcmp(cpf, numIguais) == 0)
        {
            return 0;
        }

    }

    for(k = 0, t = 10; k < strlen(cpf) - 2; k++, t--)
    {
        digito1 += (cpf[k] - 48) * t;
    }

    digito1 %= 11;

    if(digito1 < 2)
    {
        digito1 = 0;
    }

    else
    {
        digito1 = 11 - digito1;
    }

    if((cpf[9] - 48) != digito1)
    {
        return 0;
    }

    else
    {

        for(k = 0, t = 11; i < strlen(cpf) - 1; k++, t--)
        {
            digito2 += (cpf[k] - 48) * t;
        }

        digito2 %= 11;

        if(digito2 < 2)
        {
            digito2 = 0;
        }

        else
        {
            digito2 = 11 - digito2;
        }

        if((cpf[10] - 48) != digito2)
        {
            return 0;
        }

    }

    return 1;
}

int isNumeric(char *c)
{

    for(int i = 0; i < strlen(c); i++)
    {

        if(c[i] < '0' || c[i] > '9')
        {
            return 0;
        }
    }

    return 1;
}

void adicionaAluno(aluno *baseAlunos, int *numeroAlunos)
{

	aluno novoAluno;
    
    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", novoAluno.nome);

    printf("\nDigite o codigo do aluno: ");
    scanf("%s", novoAluno.codigo);

    printf("\nDigite o cpf do aluno: ");
    scanf("%s", novoAluno.cpf);

    printf("\nDigite o periodo do aluno: ");
    scanf("%s", novoAluno.periodo);

    *numeroAlunos += 1;

    aluno *novosAlunos = (aluno *)realloc(baseAlunos, *numeroAlunos * sizeof(aluno));

    if(novosAlunos != NULL)
    {
        baseAlunos = novosAlunos;
        baseAlunos[*numeroAlunos - 1] = novoAluno;
        printf("\nNovo aluno adicionado com sucesso!\n\n");
    }

    else
    {
        printf("\nErro ao adicionar aluno na base de dados\n\n");
    }

}

void adicionaDisciplina(disciplina *baseDisciplina, int *numeroDisciplinas)
{

	disciplina novaDisciplina;
    printf("Digite o nome da disciplina: ");
    scanf(" %[^\n]", novaDisciplina.nome);

    printf("\nDigite o codigo da disciplina: ");
    scanf("%s", novaDisciplina.codigo);

    printf("\nDigite a quantidade de creditos da disciplina: ");
    scanf("%d", &novaDisciplina.quantiadeCreditos);

    printf("\nDigite o periodo da disciplina: ");
    scanf("%s", novaDisciplina.periodo);

	*numeroDisciplinas += 1;
	
    disciplina *novasDisciplinas = (disciplina *)realloc(baseDisciplina, *numeroDisciplinas * sizeof(disciplina));

    if(novasDisciplinas != NULL)
    {
        baseDisciplina = novasDisciplinas;
        baseDisciplina[*numeroDisciplinas - 1] = novaDisciplina;
        printf("\nNova disciplina adicionada com sucesso!\n\n");
    }

    else
    {
        printf("\nErro ao adicionar disciplina na base de dados\n\n");
    }
}

int main()
{

    setlocale(LC_ALL, "Portuguese");

    int opcaoMenu = 1, opcaoObjeto = 1, numeroAlunos = 0, numeroDisciplinas = 0;

    aluno *baseAlunos = NULL;
    disciplina *baseDisciplina = NULL;

    printf("SISTEMA DE CONTROLE DE DISCIPLINAS E ALUNOS\n\n");

    do
    {
        printf("Digite (1) para consultar (2) para adicionar (3) para remover ou outro número para sair: ");
        scanf("%d", &opcaoMenu);

        // se a opcao nao e invalida
        if ((opcaoMenu == 1) || (opcaoMenu == 2) || (opcaoMenu == 3))
        {

            printf("Digite (1) para aluno (2) para disciplina ou outro para voltar: ");
            scanf("%d", &opcaoObjeto);
            printf("\n\n");

            // se o objeto nao e invalido
            if((opcaoObjeto == 1) || (opcaoObjeto == 2))
            {

            	// consultar
                if(opcaoMenu == 1)
                {
                }

                // adicionar
                else if(opcaoMenu == 2)
                {
                	// aluno
                    if(opcaoObjeto == 1)
                    {
                        adicionaAluno(baseAlunos, &numeroAlunos);
                    }

                    // disciplina
                    else
                    {
                        adicionaDisciplina(baseDisciplina, &numeroDisciplinas);
                    }

                }

                // remover
                else if(opcaoMenu == 3)
                {

                }
            }
        }
    }
    while((opcaoMenu == 1) || (opcaoMenu == 2) || (opcaoMenu == 3));

    printf("Aplicação terminada\n");

    return 0;
}
