#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNOME 60

//definição da estrutura aluno
typedef struct aluno
{

    int codigoAl;
    char nome[MAXNOME];
    char cpf[12];
    int numeroDeDisciplinas;
	int* listaCodigosDis;
	
} aluno;

//definição da estrutura disciplina
typedef struct disciplina
{

    int codigoDis;
    char nome[MAXNOME];
    char professor[MAXNOME];
    int quantidadeCreditos;
    
} disciplina;

//definicao da estrutura periodo
typedef struct periodo {
	
	int nomePeriodo;
	int numeroDeAlunos;
	int numeroDeDisciplinas;
	aluno* baseAlunos;
	disciplina* baseDisciplinas;
	
}periodo;

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

void printAluno(aluno *a)
{
	int i;
	printf("Nome: %s\nCodigo: %d\nCPF: %s\n", a->nome, a->codigoAl, a->cpf);
	for(i = 0; i < a->numeroDeDisciplinas; ++i)
	{
		printf("Disciplinas em que o aluno esta inscrito\n");
		printf("%d\t", a->listaCodigosDis[i]);
	}
}

int buscaPeriodo(periodo *basePeriodo, int numeroDePeriodos, int nomePeriodo)
{
	int i;
	for(i = 0; i < numeroDePeriodos; ++i){
		if(basePeriodo[i].nomePeriodo == nomePeriodo)
		{
			return i;
		}
	}
	return -1;
}

int buscarAlunoMenu()
{
	
	int opcao;
	
	printf ("\t\t SELECIONE COMO DESEJA FAZER A BUSCA   \n");
    printf ("\t\t\t================================\n");
    printf ("\t\t\t|\t                       |\n");
    printf("\t\t\t|    1 - CPF                   |\n");
    printf("\t\t\t|    2 - Codigo                |\n");
    printf("\t\t\t|    3 - Nome                  |\n");
    printf ("\t\t\t|                              |\n");
    printf ("\t\t\t================================\n");
    printf ("\n\n");
    printf("\t\t\tPor favor, selecione uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
    
}

int buscarAluno(periodo *basePeriodo, int numeroDePeriodos, int nomePeriodo, int semMenu, int codigoAl)
{

    int i, posicaoPeriodo, opcao, nomePeriodoMenu, codigoAlMenu;
    char cpf[11], nome[MAXNOME];
    aluno *a;
    
	if(semMenu == 1)
	{
		posicaoPeriodo = buscaPeriodo(basePeriodo, numeroDePeriodos, nomePeriodo);
		for(i = 0; i < basePeriodo[posicaoPeriodo].numeroDeAlunos; ++i)
		{
			if(basePeriodo[posicaoPeriodo].baseAlunos[i].codigoAl == codigoAl)
			{
				return 1;
			}
		}
	}
	else
	{
		opcao = buscarAlunoMenu();
		printf("Digite o periodo do aluno: ");
		scanf("%d", &nomePeriodoMenu);
		posicaoPeriodo = buscaPeriodo(basePeriodo, numeroDePeriodos, nomePeriodoMenu);
		if(opcao == 1){
		
			printf ("Digite o CPF do aluno: ");
			scanf(" %s", cpf);

			for(i = 0; i < basePeriodo[posicaoPeriodo].numeroDeAlunos; ++i)
			{
				
				if(strcmp(basePeriodo[posicaoPeriodo].baseAlunos[i].cpf, cpf) == 0)
				{
					printf("Aluno encontrado!\n");
					a = &basePeriodo[posicaoPeriodo].baseAlunos[i];
					printAluno(a);
					return 0;
				}
			}
		}
		
		if(opcao == 2){
		
			printf ("Digite o codigo do aluno: ");
			scanf("%d", &codigoAlMenu);

			for(i = 0; i < basePeriodo[posicaoPeriodo].numeroDeAlunos; ++i)
			{
				
				if(basePeriodo[posicaoPeriodo].baseAlunos[i].codigoAl == codigoAlMenu)
				{
					printf("Aluno encontrado!\n");
					a = &basePeriodo[posicaoPeriodo].baseAlunos[i];
					printAluno(a);
					return 0;
				}
			}
		}
		
		if(opcao == 3){
		
			printf ("Digite o nome do aluno: ");
			scanf(" %s", nome);

			for(i = 0; i < basePeriodo[posicaoPeriodo].numeroDeAlunos; ++i)
			{
				
				if(strcmp(basePeriodo[posicaoPeriodo].baseAlunos[i].nome, nome) == 0)
				{
					printf("Aluno encontrado!\n");
					a = &basePeriodo[posicaoPeriodo].baseAlunos[i];
					printAluno(a);
					return 0;
				}
			}
		}
    }
    printf("Aluno nao encontrado");
	return 0;
}

void adicionaPeriodo(periodo *basePeriodo, int numeroDePeriodos)
{
	
	int nomePeriodo;
	
	while(1){	
		printf("Digite o periodo desejado (por exemplo: 20201): ");
		scanf("%d", &nomePeriodo);
		if(buscaPeriodo(basePeriodo, numeroDePeriodos, nomePeriodo) != -1)
		{
			printf("Periodo ja registrado");
		}
		else if(nomePeriodo >= 1000000 || nomePeriodo <= 9999)
		{
			printf("Periodo invalido, tente novamente\n");
		}
		else
		{	
			break;
		}
	}
	printf("\n");
	basePeriodo = (periodo*)realloc(basePeriodo, (numeroDePeriodos+1)*sizeof(periodo));
	basePeriodo[numeroDePeriodos].nomePeriodo = nomePeriodo;
	basePeriodo[numeroDePeriodos].numeroDeAlunos = 0;
	basePeriodo[numeroDePeriodos].baseAlunos = NULL;
	basePeriodo[numeroDePeriodos].numeroDeDisciplinas = 0;
	basePeriodo[numeroDePeriodos].baseDisciplinas = NULL;
	numeroDePeriodos+=1;
	printf("Novo periodo adicionado com sucesso!\n\n");
	return;
}
	
void adicionaAluno(periodo *basePeriodo, int numeroDePeriodos)
{
	
	int i, codigoAl, nomePeriodo, posicaoPeriodo, posicaoAluno, numeroDeDisciplinas;
	char nome[MAXNOME], cpf[11];
	
	while(1){
		printf("Digite o periodo em que o aluno se encontra: ");
		scanf("%d", &nomePeriodo);
		posicaoPeriodo = buscaPeriodo(basePeriodo, numeroDePeriodos, nomePeriodo);
		if(posicaoPeriodo == -1)
		{
			printf("Periodo nao encontrado\n\n");
		}
		else
		{
			break;
		}
	}
		
    // adiciona codigo do aluno 
    while(1){

        printf("\nDigite o codigo do aluno: "); 
        scanf("%d", &codigoAl);
        if(codigoAl >= 1000000 || codigoAl <= 9999)
        {
            printf("Codigo invalido, o codigo possui 5 digitos\n");
        }
        else if(buscarAluno(basePeriodo, numeroDePeriodos, nomePeriodo, 1, codigoAl) == 1)
        {
			printf("Aluno ja existe na base de dados");
		}
        else
        {
            break;
        }
    }
    
    // adiciona cpf do aluno
    while(1){

        printf("\nDigite o CPF do aluno: ");
        scanf(" %s", cpf);
        //fazer funcao para ver se o aluno já existe.
        if(verificaCPF(cpf) == 0)
        {
            printf("CPF invalido\n");
        }
        else
        {
            break;
        }
    }

    // adiciona nome do aluno
    printf("\nDigite o nome do aluno: ");
    scanf(" %[^\n]", nome);
    
    //numero de disciplinas do aluno
    printf("Digite a quantidade de disciplinas em que o aluno esta inscrito: ");
    scanf("%d", &numeroDeDisciplinas);
	printf("\n");
	basePeriodo[posicaoPeriodo].baseAlunos = (aluno*)realloc(basePeriodo[posicaoPeriodo].baseAlunos, (basePeriodo[posicaoPeriodo].numeroDeAlunos + 1)*sizeof(aluno));
	posicaoAluno = basePeriodo[posicaoPeriodo].numeroDeAlunos++;
	strcpy(basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].nome, nome);
	strcpy(basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].cpf, cpf);
	basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].codigoAl = codigoAl;
	basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].listaCodigosDis = (int*)malloc(numeroDeDisciplinas*sizeof(int));
	
	for(i = 0; i < numeroDeDisciplinas; ++i)
	{
		printf("Digite os codigos das disciplinas: ");
		scanf("%d", &basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].listaCodigosDis[i]);
	}
	
	printf("Aluno cadastrado com sucesso");
	return;
}

void adicionaDisciplina(periodo *basePeriodo, int numeroDePeriodos)
{
    
    char nome[MAXNOME], professor[MAXNOME];
    int codigoDis, quantidadeCreditos, posicaoDisciplina, posicaoPeriodo, nomePeriodo;
    
    while(1){
		printf("Digite o periodo em que o aluno se encontra: ");
		scanf("%d", &nomePeriodo);
		posicaoPeriodo = buscaPeriodo(basePeriodo, numeroDePeriodos, nomePeriodo);
		if(posicaoPeriodo == -1)
		{
			printf("Periodo nao encontrado\n\n");
		}
		else
		{
			break;
		}
	}
    
    printf("Digite o nome da disciplina: ");
    scanf(" %[^\n]", nome);

	printf("Digite o nome do professor da disciplina: ");
	scanf(" %[^\n]", professor);
	
    while(1){

        printf("\nDigite o codigo da disciplina: ");
        scanf("%d", &codigoDis);
        if(codigoDis >= 100000 || codigoDis <=  999)
        {
			//fazer funcao que descobre se a disciplina ja existe
            printf("Codigo invalido, o codigo deve ter quatro digitos\n");
        }
        else
        {
            break;
        }
    }

    printf("\nDigite a quantidade de creditos da disciplina: ");
    scanf("%d", &quantidadeCreditos);
    printf("\n");
    
   	posicaoDisciplina = basePeriodo[posicaoPeriodo].numeroDeDisciplinas++;
	strcpy(basePeriodo[posicaoPeriodo].baseDisciplinas[posicaoDisciplina].nome, nome);
	strcpy(basePeriodo[posicaoPeriodo].baseDisciplinas[posicaoDisciplina].professor, professor);
	basePeriodo[posicaoPeriodo].baseDisciplinas[posicaoDisciplina].quantidadeCreditos = quantidadeCreditos;
	printf("Disciplina adicionada com sucesso!");
    return;
}

int menuInicial () 
{
	
	int opcaoMenu;
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
    printf("\t\t\tPor favor, selecione uma opcao: ");
    scanf("%d", &opcaoMenu);
    printf ("\n\n");
    return opcaoMenu;
}

int MenuConsultar ()
{
	int opcaoObjeto;
	
	printf ("\t\t        SELECIONE UMA DAS OPCOES    \n");
    printf ("\t\t\t================================\n");
    printf ("\t\t\t|\t                       |\n");
    printf("\t\t\t|    1 - Aluno                 |\n");
    printf("\t\t\t|    2 - Disciplina            |\n");
    printf("\t\t\t|    3 - Voltar                |\n");
    printf ("\t\t\t|                              |\n");
    printf ("\t\t\t================================\n");
    printf ("\n\n");
    printf("\t\t\tPor favor, selecione uma opcao: ");
    scanf("%d", &opcaoObjeto);
	return opcaoObjeto;
}

int MenuAdicionar ()
{
	int opcaoObjeto;
	
	printf ("\t\t        SELECIONE UMA DAS OPCOES    \n");
    printf ("\t\t\t================================\n");
    printf ("\t\t\t|\t                       |\n");
    printf("\t\t\t|    1 - Aluno                 |\n");
    printf("\t\t\t|    2 - Disciplina            |\n");
    printf("\t\t\t|    3 - Periodo               |\n");
    printf("\t\t\t|    4 - Voltar                |\n");
    printf ("\t\t\t|                              |\n");
    printf ("\t\t\t================================\n");
    printf ("\n\n");
    printf("\t\t\tPor favor, selecione uma opcao: ");
    scanf("%d", &opcaoObjeto);
	return opcaoObjeto;
}


int main()
{

    int opcaoMenu, opcaoObjeto = 1, numeroDePeriodos = 0;
    periodo* basePeriodo = NULL;
    printf("\n\n");
    do
    {
		opcaoMenu = menuInicial();
      
        // se a opcao nao e invalida
        if (opcaoMenu == 1)
        {
            opcaoObjeto = MenuConsultar();

            // se o objeto nao e invalido
            if((opcaoObjeto == 1) || (opcaoObjeto == 2))
            {

                // consultar  aluno
                if(opcaoObjeto == 1)
                {
                    buscarAluno(basePeriodo, numeroDePeriodos, 0, 0, 0);
                }
                
                else if(opcaoObjeto == 2)
                {
					//funcao buscarDisciplina
				}

			}
		}
		if(opcaoMenu == 2)
		{
			opcaoObjeto = MenuAdicionar();
			
			if((opcaoObjeto == 1) || (opcaoObjeto == 2) || (opcaoObjeto == 3))
			{
				if(opcaoObjeto == 1)
				{
					adicionaAluno(basePeriodo, numeroDePeriodos);
				}
				else if(opcaoObjeto == 2)
				{
					adicionaDisciplina(basePeriodo, numeroDePeriodos);
				}
				else if(opcaoObjeto == 3)
				{
					adicionaPeriodo(basePeriodo, numeroDePeriodos);
				}
			}
		}
		
		if(opcaoMenu == 3)
		{
			opcaoObjeto = MenuConsultar();
			
			if((opcaoObjeto == 1) || (opcaoObjeto == 2))
			{
				if(opcaoObjeto == 1)
				{
					//removeAluno(basePeriodo, numeroDePeriodos);
				}
				else if(opcaoObjeto == 2)
				{
					
					//removeDisciplina(basePeriodo, numeroDePeriodos);
				}
			}
		}
		
    }while((opcaoMenu == 1) || (opcaoMenu == 2) || (opcaoMenu == 3));
    
    printf("Aplicacao terminada\n");

    return 0;
}
