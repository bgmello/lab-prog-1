
int buscaPeriodo(int nomePeriodo)
{
	/**
	 * Função que procura a posição do período dentro da base
	 * @param int nome do período
	 * @return a posição do período dentro da base caso ele exista, -1 caso contrário
	 */
	 
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

int adicionaPeriodo(int nomePeriodo)
{
	/**
	 * Função que adiciona um novo período
	 * @param int nome do período
	 * @return 0 caso o período seja adicionado, -1 caso contrário
	 */

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

void adicionaPeriodoMenu()
{
	/**
	 * Função respónsavel por ler o nome do período para que este seja adicionado
	 */
	 
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
