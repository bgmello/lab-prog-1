
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
    basePeriodo[posicaoPeriodo].baseDisciplinas = (disciplina *)realloc(basePeriodo[posicaoPeriodo].baseDisciplinas, (basePeriodo[posicaoPeriodo].numeroDeDisciplinas + 1) * sizeof(disciplina));
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
        while ((getchar()) != '\n');
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
    while ((getchar()) != '\n');
    scanf(" %[^\n]", nome);

    printf("\nDigite o nome do professor da disciplina: ");
    while ((getchar()) != '\n');
    scanf(" %[^\n]", professor);

    codigoDis = getCodigoDisciplina();

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

void buscarDisciplina() //ok
{
    int i, j, codigoDis, nomePeriodo, posicaoPeriodo;
    disciplina Dis;
    Dis.codigoDis = 0;
    aluno Al;

    while(1)
    {
        printf("Digite o periodo: ");
        while ((getchar()) != '\n');
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

    codigoDis = getCodigoDisciplina();

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

    codigoDis = getCodigoDisciplina();

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
    basePeriodo[posicaoPeriodo].baseDisciplinas = (disciplina *)realloc(basePeriodo[posicaoPeriodo].baseDisciplinas, (basePeriodo[posicaoPeriodo].numeroDeDisciplinas - 1) * sizeof(disciplina));
    basePeriodo[posicaoPeriodo].numeroDeDisciplinas--;

    printf("Disciplina removida com sucesso\n\n");
    return;
}