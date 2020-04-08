

int buscaPeriodo(int nomePeriodo) // ok
{
    int i;
    for(i = 0; i < numeroDePeriodos; ++i)
    {
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

    basePeriodo = (periodo *)realloc(basePeriodo, (numeroDePeriodos + 1) * sizeof(periodo));
    basePeriodo[numeroDePeriodos].nomePeriodo = nomePeriodo;
    basePeriodo[numeroDePeriodos].numeroDeAlunos = 0;
    basePeriodo[numeroDePeriodos].baseAlunos = NULL;
    basePeriodo[numeroDePeriodos].numeroDeDisciplinas = 0;
    basePeriodo[numeroDePeriodos].baseDisciplinas = NULL;
    numeroDePeriodos += 1;

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
        printf("%d", nomePeriodo);
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