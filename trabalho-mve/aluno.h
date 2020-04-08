
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
    int i, nomePeriodo, posicaoPeriodo, codigoAl, numeroDeDisciplinas, codigoDis, ok;
    int *listaCodigosDis;
    char cpf[12], nome[MAXNOME];

    nomePeriodo = getPeriodoAluno();
    posicaoPeriodo = buscaPeriodo(nomePeriodo);

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

void buscaAluno() //ok
{
    int i, codigoAl, nomePeriodo, posicaoPeriodo;
    aluno Al;
    Al.codigoAl = 0;

    nomePeriodo = getPeriodoAluno();
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
    int i, codigoAl, nomePeriodo, posicaoPeriodo, posUltimoAl, posRemovido;

    aluno seraRemovido, ultimoAl;

    seraRemovido.codigoAl = 0;

    nomePeriodo = getPeriodoAluno();
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
    int i, nomePeriodo, codigoAl, codigoDis, posicaoPeriodo, posicaoAluno;
    aluno Al;
    Al.codigoAl = 0;
    disciplina Dis;
    Dis.codigoDis = 0;

    nomePeriodo = getPeriodoAluno();
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
    int i, nomePeriodo, codigoAl, codigoDis, posicaoPeriodo, posicaoAluno, posicaoDisciplina = - 1, posUltimaDis;
    aluno Al;
    Al.codigoAl = 0;

    nomePeriodo = getPeriodoAluno();
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