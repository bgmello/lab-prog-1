#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNOME 60

#include "estrutura.h"
#include "menu.h"
#include "validacao.h"

periodo *basePeriodo = NULL;
int numeroDePeriodos = 0;



int buscaPeriodo(int nomePeriodo) // ok
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

int adicionaPeriodo(int nomePeriodo) // ok
{
	
	if(buscaPeriodo(nomePeriodo) != -1)
	{
		return -1;
	}
	
	basePeriodo = (periodo*)realloc(basePeriodo, (numeroDePeriodos+1)*sizeof(periodo));
	basePeriodo[numeroDePeriodos].nomePeriodo = nomePeriodo;
	basePeriodo[numeroDePeriodos].numeroDeAlunos = 0;
	basePeriodo[numeroDePeriodos].baseAlunos = NULL;
	basePeriodo[numeroDePeriodos].numeroDeDisciplinas = 0;
	basePeriodo[numeroDePeriodos].baseDisciplinas = NULL;
	numeroDePeriodos+=1;

	return 0;
}

void adicionaPeriodoMenu() //ok
{
	int ok;
	int nomePeriodo;
	
	while(1)
	{	
		printf("Digite o periodo desejado (por exemplo: 20201): ");
		scanf("%d", &nomePeriodo);
		if(nomePeriodo >= 1000000 || nomePeriodo <= 9999)
		{
			printf("Periodo invalido, tente novamente\n\n");
		}
		else
		{
			break;
		}
	}
	ok = adicionaPeriodo(nomePeriodo);
	if(ok == -1)
	{
		printf("Periodo ja existente\n\n");
		return;
	}
	printf("Novo periodo adicionado com sucesso!\n\n");
	return;
	
}	

int adicionaAluno(int nomePeriodo, int codigoAl, int numeroDeDisciplinas, char cpf[], char nome[], int listaCodigosDis[]) //ok
{
	int i, posicaoPeriodo, posicaoAluno;
	
	posicaoPeriodo = buscaPeriodo(nomePeriodo);
	
	for(i = 0; i < basePeriodo[posicaoPeriodo].numeroDeAlunos; ++i)
	{
		if(basePeriodo[posicaoPeriodo].baseAlunos[i].codigoAl == codigoAl)
		{
			return 1;
		}
	}
	
	basePeriodo[posicaoPeriodo].baseAlunos = (aluno*)realloc(basePeriodo[posicaoPeriodo].baseAlunos, (basePeriodo[posicaoPeriodo].numeroDeAlunos + 1)*sizeof(aluno));
	posicaoAluno = basePeriodo[posicaoPeriodo].numeroDeAlunos++;
	strcpy(basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].nome, nome);
	strcpy(basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].cpf, cpf);
	basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].codigoAl = codigoAl;
	basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].numeroDeDisciplinas = numeroDeDisciplinas;
	basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].listaCodigosDis = (int*)malloc(numeroDeDisciplinas*sizeof(int));
	for(i = 0; i < numeroDeDisciplinas; ++i)
	{
		basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].listaCodigosDis[i] = listaCodigosDis[i];
	}
	
	return 0;
}

void adicionaAlunoMenu() //ok
{
	int i, nomePeriodo, posicaoPeriodo, codigoAl, numeroDeDisciplinas, codigoDis, ok;
	int* listaCodigosDis;
	char cpf[12], nome[MAXNOME];
	 
	while(1)
	{
		printf("Digite o periodo em que o aluno se encontra: ");
		scanf("%d", &nomePeriodo);
		posicaoPeriodo = buscaPeriodo(nomePeriodo);
		if(posicaoPeriodo == -1)
		{
			printf("Periodo nao encontrado\n\n");
		}
		else
		{
			break;
		}
	 }
	
	 while(1)
	 {

        printf("\nDigite o codigo do aluno: "); 
        scanf("%d", &codigoAl);
        if(codigoAl >= 1000000 || codigoAl <= 9999)
        {
            printf("Codigo invalido, o codigo possui 5 digitos\n");
        }
        else
        {
            break;
        }
	 }
    
     while(1)
     {

        printf("\nDigite o CPF do aluno: ");
        scanf(" %s", cpf);
        if(verificaCPF(cpf) == 0)
        {
            printf("CPF invalido\n");
        }
        else
        {
            break;
        }
     }
     
     printf("\nDigite o nome do aluno: ");
     scanf(" %[^\n]", nome);
     
     printf("\nDigite a quantidade de disciplinas em que o aluno esta inscrito: ");
     scanf("%d", &numeroDeDisciplinas);
     
     listaCodigosDis = (int*)malloc(numeroDeDisciplinas*sizeof(int));
     for(i = 0; i < numeroDeDisciplinas; ++i)
    {
		printf("Digite os codigo da %d disciplina: ", i+1);
		scanf("%d", &codigoDis);
		listaCodigosDis[i] = codigoDis;
		printf("\n");
	}
	
	ok = adicionaAluno(nomePeriodo, codigoAl, numeroDeDisciplinas, cpf, nome, listaCodigosDis);
	
	if(ok == 1)
	{
		printf("Aluno ja registrado\n\n");
		return;
	}
	
	printf("Aluno registrado com sucesso!\n\n");
	
	free(listaCodigosDis);
	
    return;
 } 
    
int adicionaDisciplina(int nomePeriodo, int codigoDis, int quantidadeCreditos, char nome[], char professor[]) //ok
{
	int i, posicaoPeriodo, posicaoDisciplina;
	
	posicaoPeriodo = buscaPeriodo(nomePeriodo);
	
	for(i = 0; i < basePeriodo[posicaoPeriodo].numeroDeDisciplinas; ++i)
	{
		if(basePeriodo[posicaoPeriodo].baseDisciplinas[i].codigoDis == codigoDis)
		{
			return 1;
		}
	}
	basePeriodo[posicaoPeriodo].baseDisciplinas = (disciplina*)realloc(basePeriodo[posicaoPeriodo].baseDisciplinas, (basePeriodo[posicaoPeriodo].numeroDeDisciplinas + 1)*sizeof(disciplina));
   	posicaoDisciplina = basePeriodo[posicaoPeriodo].numeroDeDisciplinas++;
   	basePeriodo[posicaoPeriodo].baseDisciplinas[posicaoDisciplina].codigoDis = codigoDis;
	strcpy(basePeriodo[posicaoPeriodo].baseDisciplinas[posicaoDisciplina].nome, nome);
	strcpy(basePeriodo[posicaoPeriodo].baseDisciplinas[posicaoDisciplina].professor, professor);
	basePeriodo[posicaoPeriodo].baseDisciplinas[posicaoDisciplina].quantidadeCreditos = quantidadeCreditos;
	
    return 0;
}

void adicionaDisciplinaMenu() //ok
{
	int nomePeriodo, posicaoPeriodo, quantidadeCreditos, codigoDis, ok;
	char professor[MAXNOME], nome[MAXNOME];
	
	while(1)
	{
		printf("Digite o periodo: ");
		scanf("%d", &nomePeriodo);
		posicaoPeriodo = buscaPeriodo(nomePeriodo);
		if(posicaoPeriodo == -1)
		{
			printf("Periodo nao encontrado\n\n");
		}
		else
		{
			break;
		}
	}
	
	printf("\nDigite o nome da disciplina: ");
    scanf(" %[^\n]", nome);

	printf("\nDigite o nome do professor da disciplina: ");
	scanf(" %[^\n]", professor);
	
	while(1)
	{
        printf("\nDigite o codigo da disciplina: ");
        scanf("%d", &codigoDis);
        if(codigoDis >= 100000 || codigoDis <=  999)
        {
            printf("Codigo invalido, o codigo deve ter quatro digitos\n");
        }
        else
        {
            break;
        }
    }
    
    printf("\nDigite a quantidade de creditos da disciplina: ");
    scanf("%d", &quantidadeCreditos);
    ok = adicionaDisciplina(nomePeriodo, codigoDis, quantidadeCreditos, nome, professor);
    if(ok == 1)
    {
		printf("Disciplina ja cadastrada\n\n");
	}
	
    printf("Disciplina adicionada com sucesso!\n\n");
    return;
}

void buscaAluno() //ok
{
	int i, codigoAl, nomePeriodo, posicaoPeriodo;
	aluno Al;
	Al.codigoAl = 0;
	
	while(1)
	{
		printf("\nDigite o periodo em que o aluno se encontra: ");
		scanf("%d", &nomePeriodo);
		posicaoPeriodo = buscaPeriodo(nomePeriodo);
		if(posicaoPeriodo == -1)
		{
			printf("Periodo nao encontrado\n\n");
		}
		else
		{
			break;
		}
	 }
	 
	 while(1)
	 {

        printf("\nDigite o codigo do aluno: "); 
        scanf("%d", &codigoAl);
        if(codigoAl >= 1000000 || codigoAl <= 9999)
        {
            printf("Codigo invalido, o codigo possui 5 digitos\n");
        }
        else
        {
            break;
        }
	 }
	 
	 for(i = 0; i < basePeriodo[posicaoPeriodo].numeroDeAlunos; ++i)
	 {
		if(basePeriodo[posicaoPeriodo].baseAlunos[i].codigoAl == codigoAl)
		{
			Al = basePeriodo[posicaoPeriodo].baseAlunos[i];
		}
	 }
	
	if(Al.codigoAl == 0)
	{
		printf("Aluno nao encontrado nesse periodo\n\n");
		return;
	}
	
	printf("Dados do aluno %d:\n", codigoAl);
	printAluno(Al);
	return;
}

void buscarDisciplina() //ok
{
	int i, j, codigoDis, nomePeriodo, posicaoPeriodo;
	disciplina Dis;
	Dis.codigoDis = 0;
	aluno Al;
	
	while(1)
	{
		printf("Digite o periodo: ");
		scanf("%d", &nomePeriodo);
		posicaoPeriodo = buscaPeriodo(nomePeriodo);
		if(posicaoPeriodo == -1)
		{
			printf("Periodo nao encontrado\n\n");
		}
		else
		{
			break;
		}
	 }
	 
	 while(1)
	{
        printf("\nDigite o codigo da disciplina: ");
        scanf("%d", &codigoDis);
        if(codigoDis >= 100000 || codigoDis <=  999)
        {
            printf("Codigo invalido, o codigo deve ter quatro digitos\n");
        }
        else
        {
            break;
        }
    }
    
    for(i = 0; i < basePeriodo[posicaoPeriodo].numeroDeDisciplinas; ++i)
	{
		if(basePeriodo[posicaoPeriodo].baseDisciplinas[i].codigoDis == codigoDis)
		{
			Dis = basePeriodo[posicaoPeriodo].baseDisciplinas[i];
		}
	}
	
	if(Dis.codigoDis == 0)
	{
		printf("Disciplina nao encontrada\n");
		return;
	}
	printf("Dados da disciplina %d: \n\n", codigoDis);
	printf("Nome: %s\nProfessor: %s\nCreditos: %d\n", Dis.nome, Dis.professor, Dis.quantidadeCreditos);
	printf("Os alunos matriculados nessa disciplina sao: \n");
	
	for(i = 0; i < basePeriodo[posicaoPeriodo].numeroDeAlunos; ++i)
	{	
		Al = basePeriodo[posicaoPeriodo].baseAlunos[i];
		for(j = 0; j < Al.numeroDeDisciplinas; ++j)
		{
			if(Al.listaCodigosDis[j] == codigoDis)
			{
				printf("Nome: %s\tCodigo: %d\n", Al.nome, Al.codigoAl);
			}
		}
	}
	printf("\n\n");
	return;
}

void removeAlunoMenu()
{
	int i, codigoAl, nomePeriodo, posicaoPeriodo, posUltimoAl, posRemovido;
	
	aluno seraRemovido, ultimoAl;
	
	seraRemovido.codigoAl = 0;
	
	while(1)
	{
		printf("\nDigite o periodo em que o aluno se encontra: ");
		scanf("%d", &nomePeriodo);
		posicaoPeriodo = buscaPeriodo(nomePeriodo);
		if(posicaoPeriodo == -1)
		{
			printf("Periodo nao encontrado\n\n");
		}
		else
		{
			break;
		}
	 }
	 
	 while(1)
	 {

        printf("\nDigite o codigo do aluno: "); 
        scanf("%d", &codigoAl);
        if(codigoAl >= 1000000 || codigoAl <= 9999)
        {
            printf("Codigo invalido, o codigo possui 5 digitos\n");
        }
        else
        {
            break;
        }
	 }
	 
	 for(i = 0; i < basePeriodo[posicaoPeriodo].numeroDeAlunos; ++i)
	 {
		if(basePeriodo[posicaoPeriodo].baseAlunos[i].codigoAl == codigoAl)
		{
			seraRemovido = basePeriodo[posicaoPeriodo].baseAlunos[i];
			 posRemovido = i;
		}
	 }
	 
	 if(seraRemovido.codigoAl == 0)
	 {
		 printf("Aluno nao encontrado nesse periodo\n\n");
		 return;
	 }
	 
	 posUltimoAl = basePeriodo[posicaoPeriodo].numeroDeAlunos - 1;
	 ultimoAl = basePeriodo[posicaoPeriodo].baseAlunos[posUltimoAl];
	 free(seraRemovido.listaCodigosDis);
	 
	 if(posRemovido != posUltimoAl)
	 {
		 seraRemovido = ultimoAl;
		 basePeriodo[posicaoPeriodo].baseAlunos[posRemovido] = seraRemovido;
	 }
	 basePeriodo[posicaoPeriodo].baseAlunos = (aluno*)realloc(basePeriodo[posicaoPeriodo].baseAlunos, (basePeriodo[posicaoPeriodo].numeroDeAlunos - 1)*sizeof(aluno));
	 basePeriodo[posicaoPeriodo].numeroDeAlunos--;
	 
	 printf("Aluno removido com sucesso!\n\n");
	 return; 
	 
}	 

void removeDisciplinaMenu()
{
	int i, codigoDis, nomePeriodo, posicaoPeriodo, posUltimaDis, posRemovida;
	
	disciplina seraRemovida, ultimaDis;
	
	seraRemovida.codigoDis = 0;
	
	while(1)
	{
		printf("\nDigite o periodo: ");
		scanf("%d", &nomePeriodo);
		posicaoPeriodo = buscaPeriodo(nomePeriodo);
		if(posicaoPeriodo == -1)
		{
			printf("Periodo nao encontrado\n\n");
		}
		else
		{
			break;
		}
	 }
	 
	 while(1)
	{
        printf("\nDigite o codigo da disciplina: ");
        scanf("%d", &codigoDis);
        if(codigoDis >= 100000 || codigoDis <=  999)
        {
            printf("Codigo invalido, o codigo deve ter quatro digitos\n");
        }
        else
        {
            break;
        }
    }
    for(i = 0; i < basePeriodo[posicaoPeriodo].numeroDeDisciplinas; ++i)
	{
		if(basePeriodo[posicaoPeriodo].baseDisciplinas[i].codigoDis == codigoDis)
		{
			seraRemovida = basePeriodo[posicaoPeriodo].baseDisciplinas[i];
			posRemovida = i;
		}
	}
    
	if(seraRemovida.codigoDis == 0)
	{
		printf("Disciplina nao encontrada nesse periodo\n\n");
		return;
	}
	
	posUltimaDis = basePeriodo[posicaoPeriodo].numeroDeDisciplinas - 1;
	ultimaDis = basePeriodo[posicaoPeriodo].baseDisciplinas[posUltimaDis];
	
	if(posRemovida != posUltimaDis)
	{
		seraRemovida = ultimaDis;
		basePeriodo[posicaoPeriodo].baseDisciplinas[posRemovida] = seraRemovida;
	}
	basePeriodo[posicaoPeriodo].baseDisciplinas = (disciplina*)realloc(basePeriodo[posicaoPeriodo].baseDisciplinas, (basePeriodo[posicaoPeriodo].numeroDeDisciplinas - 1)*sizeof(disciplina));
	basePeriodo[posicaoPeriodo].numeroDeDisciplinas--;
	
	printf("Disciplina removida com sucesso\n\n");
	return;
}

void vinculaAlunoMenu()
{
	int i, nomePeriodo, codigoAl, codigoDis, posicaoPeriodo, posicaoAluno;
	aluno Al;
	Al.codigoAl = 0;
	disciplina Dis;
	Dis.codigoDis = 0;
	
	while(1)
	{
		printf("\nDigite o periodo em que o aluno se encontra: ");
		scanf("%d", &nomePeriodo);
		posicaoPeriodo = buscaPeriodo(nomePeriodo);
		if(posicaoPeriodo == -1)
		{
			printf("Periodo nao encontrado\n\n");
		}
		else
		{
			break;
		}
	 }
	 
	 while(1)
	 {

        printf("\nDigite o codigo do aluno: "); 
        scanf("%d", &codigoAl);
        if(codigoAl >= 1000000 || codigoAl <= 9999)
        {
            printf("Codigo invalido, o codigo possui 5 digitos\n");
        }
        else
        {
            break;
        }
	 }
	 
	 for(i = 0; i < basePeriodo[posicaoPeriodo].numeroDeAlunos; ++i)
	 {
		if(basePeriodo[posicaoPeriodo].baseAlunos[i].codigoAl == codigoAl)
		{
			Al = basePeriodo[posicaoPeriodo].baseAlunos[i];
			posicaoAluno = i;
		}
	 }
	 
	 if(Al.codigoAl == 0)
	 {
		printf("Aluno nao encontrado nesse periodo\n\n");
		return;
	 }
	 
	 while(1)
	 {
        printf("\nDigite o codigo da disciplina: ");
        scanf("%d", &codigoDis);
        if(codigoDis >= 100000 || codigoDis <=  999)
        {
            printf("Codigo invalido, o codigo deve ter quatro digitos\n");
        }
        else
        {
            break;
        }
     }
	 
	 for(i = 0; i < Al.numeroDeDisciplinas; ++i)
	 {
		if(basePeriodo[posicaoPeriodo].baseDisciplinas[i].codigoDis == codigoDis)
		{
			Dis = basePeriodo[posicaoPeriodo].baseDisciplinas[i];
		}
	 }
	
	if(Dis.codigoDis == 0)
	{
		printf("Disciplina nao encontrada\n");
		return;
	}
	
	Al.listaCodigosDis = (int*)realloc(Al.listaCodigosDis, (Al.numeroDeDisciplinas + 1)*sizeof(int));
	Al.listaCodigosDis[Al.numeroDeDisciplinas] = Dis.codigoDis;
	Al.numeroDeDisciplinas++;	 
	basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno] = Al;
	printf("Aluno vinculado à disciplina com sucesso\n\n");
	return;
}

void desvinculaAlunoMenu()
{
	int i, nomePeriodo, codigoAl, codigoDis, posicaoPeriodo, posicaoAluno, posicaoDisciplina = - 1, posUltimaDis;
	aluno Al;
	Al.codigoAl = 0;
	
	while(1)
	{
		printf("\nDigite o periodo em que o aluno se encontra: ");
		scanf("%d", &nomePeriodo);
		posicaoPeriodo = buscaPeriodo(nomePeriodo);
		if(posicaoPeriodo == -1)
		{
			printf("Periodo nao encontrado\n\n");
		}
		else
		{
			break;
		}
	 }
	 
	 while(1)
	 {

        printf("\nDigite o codigo do aluno: "); 
        scanf("%d", &codigoAl);
        if(codigoAl >= 1000000 || codigoAl <= 9999)
        {
            printf("Codigo invalido, o codigo possui 5 digitos\n");
        }
        else
        {
            break;
        }
	 }
	 
	 for(i = 0; i < basePeriodo[posicaoPeriodo].numeroDeAlunos; ++i)
	 {
		if(basePeriodo[posicaoPeriodo].baseAlunos[i].codigoAl == codigoAl)
		{
			Al = basePeriodo[posicaoPeriodo].baseAlunos[i];
			posicaoAluno = i;
		}
	 }
	 
	 if(Al.codigoAl == 0)
	 {
		printf("Aluno nao encontrado nesse periodo\n\n");
		return;
	 }
	 
	 while(1)
	 {
        printf("\nDigite o codigo da disciplina: ");
        scanf("%d", &codigoDis);
        if(codigoDis >= 100000 || codigoDis <=  999)
        {
            printf("Codigo invalido, o codigo deve ter quatro digitos\n");
        }
        else
        {
            break;
        }
     }
	 
	 for(i = 0; i < Al.numeroDeDisciplinas; ++i)
	 {
		if(Al.listaCodigosDis[i] == codigoDis)
		{
			posicaoDisciplina = i;
		}
	 }
	
	if(posicaoDisciplina == - 1)
	{
		printf("Disciplina nao vinculada ao aluno\n");
		return;
	}
	
	posUltimaDis = Al.numeroDeDisciplinas - 1;
	
	if(posicaoDisciplina != posUltimaDis)
	{
		Al.listaCodigosDis[posicaoDisciplina] = Al.listaCodigosDis[posUltimaDis];
	}
	
	Al.numeroDeDisciplinas--;
	Al.listaCodigosDis = (int*)realloc(Al.listaCodigosDis, (Al.numeroDeDisciplinas)*sizeof(int));
	basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno] = Al;
	printf("Aluno desvinculado à disciplina com sucesso\n\n");
	return;
}	

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

            // se o objeto nao e invalido
            if((opcaoObjeto == 1) || (opcaoObjeto == 2))
            {

                // consultar  aluno
                if(opcaoObjeto == 1)
                {
                    buscaAluno();
                }
                
                else if(opcaoObjeto == 2)
                {
					buscarDisciplina();
				}

			}
		}
		if(opcaoMenu == 2)
		{
			opcaoObjeto = menuAdicionar();
			
			if((opcaoObjeto == 1) || (opcaoObjeto == 2) || (opcaoObjeto == 3))
			{
				if(opcaoObjeto == 1)
				{
					adicionaAlunoMenu();
				}
				else if(opcaoObjeto == 2)
				{
					adicionaDisciplinaMenu();
				}
				else if(opcaoObjeto == 3)
				{
					adicionaPeriodoMenu();
				}
			}
		}
		
		if(opcaoMenu == 3)
		{
			opcaoObjeto = menuConsultar();
			
			if((opcaoObjeto == 1) || (opcaoObjeto == 2))
			{
				if(opcaoObjeto == 1)
				{
					removeAlunoMenu();
				}
				else if(opcaoObjeto == 2)
				{
					
					removeDisciplinaMenu();
				}
			}
		}
		
		if(opcaoMenu == 4)
		{
			opcaoObjeto = menuVincularDesvincular();
			
			if((opcaoObjeto == 1) || (opcaoObjeto == 2))
			{
				if(opcaoObjeto == 1)
				{
					vinculaAlunoMenu();
				}
				else if(opcaoObjeto == 2)
				{
					
					desvinculaAlunoMenu();
				}
			}
		}
		
    }while((opcaoMenu == 1) || (opcaoMenu == 2) || (opcaoMenu == 3) || (opcaoMenu == 4));
    
    printf("Aplicacao terminada\n");

    return 0;
}
