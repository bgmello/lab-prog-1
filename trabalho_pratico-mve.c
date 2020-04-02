#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAXNOME 60

//definição da estrutura aluno
typedef struct aluno
{

    char codigo[6];
    char nome[MAXNOME];
    char cpf[12];
    char periodo[7];

} aluno;

//definição da estrutura disciplina
typedef struct disciplina
{

    char codigo[5];
    char nome[MAXNOME];
    int quantiadeCreditos;
    char periodo[5];

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

        for(j = 0; j < 11; ++j)
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

        for(k = 0, t = 11; k < strlen(cpf) - 1; k++, t--)
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

void adicionaAluno(aluno **baseAlunos, int *numeroAlunos)
{

    aluno novoAluno;

    // adiciona codigo do aluno 
    while(1){

        printf("\nDigite o código do aluno: "); 
        scanf("%s", novoAluno.codigo);
        if(strlen(novoAluno.codigo) != 5)
        {
            printf("Código inválido\n");
        }
        else
        {
            break;
        }
    }
    
    // adiciona cpf do aluno
    while(1){

        printf("\nDigite o CPF do aluno: ");
        scanf(" %s", novoAluno.cpf);
        if(verificaCPF(novoAluno.cpf) == 0)
        {
            printf("CPF inválido\n");
        }
        else
        {
            break;
        }
    }

    // adiciona periodo do aluno
    while(1){

        printf("\nDigite o período do aluno: ");
        scanf(" %s", novoAluno.periodo);
        if(strlen(novoAluno.periodo) != 6)
        {
            printf("Período precisa ser da forma XXXX.Y\n");
        }
        else
        {
            break;
        }
    }

    // adiciona nome do aluno
    printf("\nDigite o nome do aluno: ");
    scanf(" %[^\n]", novoAluno.nome);
    *numeroAlunos += 1;

    aluno *novosAlunos = (aluno *)realloc(*baseAlunos, *numeroAlunos * sizeof(aluno));

    if(novosAlunos != NULL)
    {
        *baseAlunos = novosAlunos;
        *baseAlunos[*numeroAlunos - 1] = novoAluno;
        printf("\nNovo aluno adicionado com sucesso!\n\n");
    }

    else
    {
        printf("\nErro ao adicionar aluno na base de dados\n\n");
    }
}

void adicionaDisciplina(disciplina **baseDisciplina, int *numeroDisciplinas)
{

    disciplina novaDisciplina;
    printf("Digite o nome da disciplina: ");
    scanf(" %[^\n]", novaDisciplina.nome);

    while(1){

        printf("\nDigite o código da disciplina: ");
        scanf("%s", novaDisciplina.codigo);
        if(strlen(novaDisciplina.codigo) != 4)
        {
            printf("Código inválido\n");
        }
        else
        {
            break;
        }
    }

    printf("\nDigite a quantidade de créditos da disciplina: ");
    scanf("%d", &novaDisciplina.quantiadeCreditos);

    while(1){

        printf("\nDigite o período da disciplina: ");
        scanf("%s", novaDisciplina.periodo);
        if(strlen(novaDisciplina.periodo) != 6)
        {
            printf("Período precisa ser da forma XXXX.Y\n");
        }
        else
        {
            break;
        }
    }

    *numeroDisciplinas += 1;

    disciplina *novasDisciplinas = (disciplina *)realloc(*baseDisciplina, *numeroDisciplinas * sizeof(disciplina));

    if(novasDisciplinas != NULL)
    {
        *baseDisciplina = novasDisciplinas;
        *baseDisciplina[*numeroDisciplinas - 1] = novaDisciplina;
        printf("\nNova disciplina adicionada com sucesso!\n\n");
    }

    else
    {
        printf("\nErro ao adicionar disciplina na base de dados\n\n");
    }
}

void printAluno (aluno *a){

    printf("%s\n%s\n%s\n", a->nome, a->cpf, a->codigo);
}

void buscarAluno(aluno *baseAlunos, int numeroAlunos)
{

    int i, opcao;
    char cpf[11], nome[60], codigo[5];
    printf ("\t\t SELECIONE COMO DESEJA FAZER A BUSCA   \n");
    printf ("\t\t\t================================\n");
    printf ("\t\t\t|\t                       |\n");
    printf("\t\t\t|    1 - CPF                   |\n");
    printf("\t\t\t|    2 - Código                |\n");
    printf("\t\t\t|    3 - Nome                  |\n");
    printf ("\t\t\t|                              |\n");
    printf ("\t\t\t================================\n");
    printf ("\n\n");
    printf("\t\t\tPor favor, selecione uma opção: ");
    scanf("%d", &opcao);

    if(opcao == 1){

        printf ("Digite o CPF do aluno: ");
        scanf("%s", cpf);

        for (i=0; i < numeroAlunos; i++)
        {
            if(strcmp(baseAlunos[i].cpf, cpf) == 0)
            {
                printAluno(&baseAlunos[i]);   
                break;
            }
        }

    }

    if(opcao == 2){

        printf ("Digite o código do aluno: ");
        scanf("%s", codigo);

        for (i=0; i < numeroAlunos; i++)
        {
            
            if(strcmp(baseAlunos[i].codigo, codigo) == 0)
            {
                printAluno(&baseAlunos[i]);   
                break;
            }
        }
    }

    if(opcao == 3){

        printf ("Digite o nome do aluno: ");
        scanf(" %[^\n]", nome);
        for (i=0; i < numeroAlunos; i++)
        {
            if(strcmp(baseAlunos[i].nome, nome) == 0)
            {
                printAluno(&baseAlunos[i]);   
                break;
            }
        }
    }
    return;
}

int main()
{

    setlocale(LC_ALL, "Portuguese");

    int opcaoMenu = 1, opcaoObjeto = 1, numeroAlunos = 0, numeroDisciplinas = 0;

    aluno *baseAlunos = NULL;
    disciplina *baseDisciplina = NULL;

    printf("\n\n");

    do
    {
        printf ("\t\t SISTEMA DE CONTROLE DE DISCIPLINAS E ALUNOS\n");
        printf ("\t\t\t================================\n");
        printf ("\t\t\t|\t                       |\n");
        printf("\t\t\t|    1 - Consultar             |\n");
        printf("\t\t\t|    2 - Adicionar             |\n");
        printf("\t\t\t|    3 - Remover               |\n");
        printf("\t\t\t|    0 - Sair                  |\n");
        printf ("\t\t\t|                              |\n");
        printf ("\t\t\t================================\n");
        printf ("\n\n");
        printf("\t\t\tPor favor, selecione uma opção: ");
        scanf("%d", &opcaoMenu);
        printf ("\n\n");
        // se a opcao nao e invalida
        if ((opcaoMenu == 1) || (opcaoMenu == 2) || (opcaoMenu == 3))
        {
            printf ("\t\t SELECIONE UMA OPÇÃO PARA ADICIONAR OU VOLTAR\n");
            printf ("\t\t\t================================\n");
            printf ("\t\t\t|\t                       |\n");
            printf("\t\t\t|    1 - Aluno                 |\n");
            printf("\t\t\t|    2 - Disciplina            |\n");
            printf("\t\t\t|    3 - Voltar                |\n");
            printf ("\t\t\t|                              |\n");
            printf ("\t\t\t================================\n");
            printf ("\n\n");
            printf("\t\t\tPor favor, selecione uma opção: ");
            scanf("%d", &opcaoObjeto);
            printf("\n\n");

            // se o objeto nao e invalido
            if((opcaoObjeto == 1) || (opcaoObjeto == 2))
            {

                // consultar
                if(opcaoMenu == 1)
                {
                    buscarAluno(baseAlunos, numeroAlunos);
                }

                // adicionar
                else if(opcaoMenu == 2)
                {
                    // aluno
                    if(opcaoObjeto == 1)
                    {
                        adicionaAluno(&baseAlunos, &numeroAlunos);
                    }

                    // disciplina
                    else
                    {
                        adicionaDisciplina(&baseDisciplina, &numeroDisciplinas);
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
