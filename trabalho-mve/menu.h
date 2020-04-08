
int menuInicial () 
{
	
	int opcaoMenu;
	printf ("\t\t SISTEMA DE CONTROLE DE DISCIPLINAS E ALUNOS\n");
    printf ("\t\t\t================================\n");
    printf ("\t\t\t|\t                       |\n");
    printf("\t\t\t|    1 - Consultar             |\n");
    printf("\t\t\t|    2 - Adicionar             |\n");
    printf("\t\t\t|    3 - Remover               |\n");
    printf("\t\t\t|    4 - Vincular/Desvincular  |\n");
    printf("\t\t\t|    0 - Sair                  |\n");
    printf ("\t\t\t|                              |\n");
    printf ("\t\t\t================================\n");
    printf ("\n\n");
    printf("\t\t\tPor favor, selecione uma opcao: ");
    scanf("%d", &opcaoMenu);
    printf ("\n\n");
    return opcaoMenu;
}

int menuConsultar ()
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

int menuAdicionar ()
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

int menuVincularDesvincular()
{
	int opcaoObjeto;
	
	printf ("\t\t        SELECIONE UMA DAS OPCOES    \n");
    printf ("\t\t\t================================\n");
    printf ("\t\t\t|\t                       |\n");
    printf("\t\t\t|    1 - Vincular Disciplina   |\n");
    printf("\t\t\t|    2 - Desvincular Disciplina|\n");
    printf("\t\t\t|    3 - Voltar                |\n");
    printf ("\t\t\t|                              |\n");
    printf ("\t\t\t================================\n");
    printf ("\n\n");
    printf("\t\t\tPor favor, selecione uma opcao: ");
    scanf("%d", &opcaoObjeto);
	return opcaoObjeto;
}

void printAluno(aluno a) //ok
{
	int i;
	printf("Nome: %s\nCPF: %s\nNumero de Disciplinas: %d\n", a.nome, a.cpf, a.numeroDeDisciplinas);
	printf("Disciplinas em que o aluno esta inscrito\n");
	for(i = 0; i < a.numeroDeDisciplinas; ++i)
	{
		printf("%d\t", a.listaCodigosDis[i]);
	}
	printf("\n\n");
	return;
}
