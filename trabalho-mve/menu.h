
void explicacaoInicial(){
	/**
	 * Função que mostra orientações ao usuario
	 */
	 
	printf("\t\tBem vindo ao sistema de controle de disciplinas e alunos!\n");
	printf("\t\tAqui podemos guardar informacoes dos alunos e disciplinas em diversos periodos diferentes\n");
	printf("\t\tNosso sistema e composto de 3 partes principais: os alunos, as disciplinas e os periodos\n");
	printf("\t\tCada aluno em um determinado periodo deve ter um codigo de 5 digitos, um cpf valido, um nome e uma lista de disciplinas em que esta inscrito\n");
	printf("\t\tCada disciplina em um determinado periodo deve ter um codigo de 4 digitos, um nome, um nome do professor e a quantidade de creditos\n");
	printf("\t\tPara consultar as informacoes de uma disciplina e os alunos inscritos, basta ir ao menu de consultar e digitar o periodo e o codigo da disciplina\n");
	printf("\t\tPara consultar as informacoes de um aluno e as disciplinas que ele esta inscrito, basta ir ao menu consultar e digitar o periodo e o codigo do aluno\n");
	printf("\t\tE importante notar que cada disciplina e cada aluno estao dentro de um periodo, logo podemos criar varias disciplinas e varios alunos iguais mas em periodos diferentes!\n");
	printf("\t\tSe for necessario adicionar um aluno ou uma disciplina em um periodo que ainda nao foi criado, e nececessario cria-lo antes\n");
	printf("\t\tO periodo deve ser inserido da forma XXXXX, por exemplo, o periodo 2020.1 deve ser inserido como 20201\n");
	printf("\n\n");
}

int menuInicial () 
{
	/**
	 * Função que mostra as opções iniciais do programa ao usuario
	 * @return a opção escolhida
	 */

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
	/**
	 * Função que mostra as opções de consulta ao usuario
	 * @return a opção escolhida
	 */
	
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
	/**
	 * Função que mostra as opções de que podem ser adicionadas ao usuario
	 * @return a opção escolhida
	 */
	
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
	/**
	 * Função que mostra as opções para vincular e desvincular disciplina ao usuario
	 * @return a opção escolhida
	 */
	
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

void printAluno(aluno a)
{
	/**
	 * Função que printa as informações de um aluno
	 * @param struct aluno a ser printado
	 */
	
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
