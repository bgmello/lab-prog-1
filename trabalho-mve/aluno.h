
void createAluno(int nomePeriodo, int codigoAl, char cpf[], char nome[])
{
	/**
	 * Cria um aluno com uma lista vazia de disciplinas
	 * @param int nomePeríodo Nome do periodo em que o aluno vai ser criado
     * @param int codigoAl Codigo do aluno a ser criado
     * @param char cpf[] CPF do aluno a ser criado, obrigatoriamente tem 11 digitos
     * @param char nome[] Nome do aluno a ser criado
	 */

    int i, posicaoPeriodo, posicaoAluno;

    posicaoPeriodo = buscaPeriodo(nomePeriodo);

    for(i = 0; i < basePeriodo[posicaoPeriodo].numeroDeAlunos; ++i)
    {
        if(basePeriodo[posicaoPeriodo].baseAlunos[i].codigoAl == codigoAl)
        {
            return;
        }
    }

    basePeriodo[posicaoPeriodo].baseAlunos = (aluno *)realloc(basePeriodo[posicaoPeriodo].baseAlunos, (basePeriodo[posicaoPeriodo].numeroDeAlunos + 1) * sizeof(aluno));
    posicaoAluno = basePeriodo[posicaoPeriodo].numeroDeAlunos++;
    strcpy(basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].nome, nome);
    strcpy(basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].cpf, cpf);
    basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].codigoAl = codigoAl;
    basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].numeroDeDisciplinas = 0;
    basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].listaCodigosDis = (int *)malloc(0 * sizeof(int));
    return;

}

void addDisciplinaInAluno(int nomePeriodo, int codigoAl, int codigoDis)
{
	/**
	 * Adiciona uma disciplina a um aluno
	 * @param int nomePeriodo Nome do periodo a que a disciplina sera adiconada ao aluno
     * @param int codigoAl Codigo do aluno em que a displina sera adiconada
     * @param int codigoDis Codigo da disciplina
	 */
	 
    int i, posicaoPeriodo, posicaoAluno;

    posicaoPeriodo = buscaPeriodo(nomePeriodo);

    for(i = 0; i < basePeriodo[posicaoPeriodo].numeroDeAlunos; ++i)
    {
        if(basePeriodo[posicaoPeriodo].baseAlunos[i].codigoAl == codigoAl)
        {
            posicaoAluno = i;
            basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].numeroDeDisciplinas++;
            basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].listaCodigosDis = (int *)realloc(basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].listaCodigosDis, basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].numeroDeDisciplinas * sizeof(int));
            basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].listaCodigosDis[basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].numeroDeDisciplinas-1] = codigoDis;
            break;
        }
    }

    return;
}


int adicionaAluno(int nomePeriodo, int codigoAl, int numeroDeDisciplinas, char cpf[], char nome[], int listaCodigosDis[])
{
	/**
	 * Função que adiciona um aluno a base
	 * @param int nome do período, int código do aluno, int quantidade de créditos, char cpf
	 * @return 1 caso o aluno já existe, 0 caso seja adicionado
	 */
	 
    int i, posicaoPeriodo, posicaoAluno;

    posicaoPeriodo = buscaPeriodo(nomePeriodo);

    for(i = 0; i < basePeriodo[posicaoPeriodo].numeroDeAlunos; ++i)
    {
        if(basePeriodo[posicaoPeriodo].baseAlunos[i].codigoAl == codigoAl)
        {
            return 1;
        }
    }

    basePeriodo[posicaoPeriodo].baseAlunos = (aluno *)realloc(basePeriodo[posicaoPeriodo].baseAlunos, (basePeriodo[posicaoPeriodo].numeroDeAlunos + 1) * sizeof(aluno));
    posicaoAluno = basePeriodo[posicaoPeriodo].numeroDeAlunos++;
    strcpy(basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].nome, nome);
    strcpy(basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].cpf, cpf);
    basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].codigoAl = codigoAl;
    basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].numeroDeDisciplinas = numeroDeDisciplinas;
    basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].listaCodigosDis = (int *)malloc(numeroDeDisciplinas * sizeof(int));
    for(i = 0; i < numeroDeDisciplinas; ++i)
    {
        basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno].listaCodigosDis[i] = listaCodigosDis[i];
    }

    return 0;
}

void adicionaAlunoMenu() //ok
{
	/**
	 * Função lê os dados necessários para que um aluno seja adicionado
	 */
	
    int i, nomePeriodo, codigoAl, numeroDeDisciplinas, codigoDis, ok;
    int *listaCodigosDis;
    char cpf[12], nome[MAXNOME];

    nomePeriodo = getPeriodoAluno();

    if(nomePeriodo==0){
        return;
    }

    codigoAl = getCodigoAluno();

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
    while ((getchar()) != '\n');
    scanf(" %[^\n]", nome);

    printf("\nDigite a quantidade de disciplinas em que o aluno esta inscrito: ");
    while ((getchar()) != '\n');
    scanf("%d", &numeroDeDisciplinas);

    listaCodigosDis = (int *)malloc(numeroDeDisciplinas * sizeof(int));
    for(i = 0; i < numeroDeDisciplinas; ++i)
    {
        printf("Digite o codigo da %d disciplina: ", i + 1);
        while ((getchar()) != '\n');
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

void buscaAluno()
{
	/**
	 * Função que busca um aluno na base de dados e printa suas informações caso ele seja encontrado
	 */
	 
    int i, codigoAl, nomePeriodo, posicaoPeriodo;
    aluno Al;
    Al.codigoAl = 0;

    nomePeriodo = getPeriodoAluno();

    if(nomePeriodo==0){
        return;
    }

    posicaoPeriodo = buscaPeriodo(nomePeriodo);

    codigoAl = getCodigoAluno();

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

void removeAlunoMenu()
{
	
	/**
	 * Função responsável por remover um aluno da base de dados
	 */
	 
    int i, codigoAl, nomePeriodo, posicaoPeriodo, posUltimoAl, posRemovido;

    aluno seraRemovido, ultimoAl;

    seraRemovido.codigoAl = 0;

    nomePeriodo = getPeriodoAluno();

    if(nomePeriodo==0){
        return;
    }

    posicaoPeriodo = buscaPeriodo(nomePeriodo);

    codigoAl = getCodigoAluno();

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
    basePeriodo[posicaoPeriodo].baseAlunos = (aluno *)realloc(basePeriodo[posicaoPeriodo].baseAlunos, (basePeriodo[posicaoPeriodo].numeroDeAlunos - 1) * sizeof(aluno));
    basePeriodo[posicaoPeriodo].numeroDeAlunos--;

    printf("Aluno removido com sucesso!\n\n");
    return;
}

void vinculaAlunoMenu()
{
	/**
	 * Função responsável por vincular um aluno a uma disciplina
	 */
	
    int i, nomePeriodo, codigoAl, codigoDis, posicaoPeriodo, posicaoAluno;
    aluno Al;
    Al.codigoAl = 0;
    disciplina Dis;
    Dis.codigoDis = 0;

    nomePeriodo = getPeriodoAluno();

    if(nomePeriodo==0){
        return;
    }

    posicaoPeriodo = buscaPeriodo(nomePeriodo);

    codigoAl = getCodigoAluno();

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

    codigoDis = getCodigoDisciplina();

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

    Al.listaCodigosDis = (int *)realloc(Al.listaCodigosDis, (Al.numeroDeDisciplinas + 1) * sizeof(int));
    Al.listaCodigosDis[Al.numeroDeDisciplinas] = Dis.codigoDis;
    Al.numeroDeDisciplinas++;
    basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno] = Al;
    printf("Aluno vinculado à disciplina com sucesso\n\n");
    return;
}

void desvinculaAlunoMenu()
{
	/**
	 * Função responsável por desvincular um aluno a uma disciplina
	 */
	
    int i, nomePeriodo, codigoAl, codigoDis, posicaoPeriodo, posicaoAluno, posicaoDisciplina = - 1, posUltimaDis;
    aluno Al;
    Al.codigoAl = 0;

    nomePeriodo = getPeriodoAluno();

    if(nomePeriodo==0){
        return;
    }

    posicaoPeriodo = buscaPeriodo(nomePeriodo);

    codigoAl = getCodigoAluno();

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

    codigoDis = getCodigoDisciplina();

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
    Al.listaCodigosDis = (int *)realloc(Al.listaCodigosDis, (Al.numeroDeDisciplinas) * sizeof(int));
    basePeriodo[posicaoPeriodo].baseAlunos[posicaoAluno] = Al;
    printf("Aluno desvinculado à disciplina com sucesso\n\n");
    return;
}
