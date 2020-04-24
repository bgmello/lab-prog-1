
int verificaCPF(char *cpf) //ok
{	
	/**
	 * Função que checa se o CPF é válido
	 * @param char cpf a ser verificado
	 * @return 1 se o CPF é válido, 0 caso contrário
	 */

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

int getCodigoAluno(){

	 /**
	 * Função que lê o código do aluno e verifica se ele tem 5 digitos
	 * @return Código do aluno
	 */	
	 
	int codigo;

	 while(1)
    {

        printf("\nDigite o codigo do aluno: ");
        while ((getchar()) != '\n');
        scanf("%d", &codigo);
        if(codigo >= 1000000 || codigo <= 9999)
        {
            printf("Codigo invalido, o codigo possui 5 digitos\n");
        }
        else
        {
            break;
        }
    }

    return codigo;
}

int getPeriodoAluno(){
	
	 /**
	 * Função que lê o periodo e verifica se ele já existe
	 * @return Nome do período
	 */	

	int nomePeriodo, posicaoPeriodo;

	while(1)
	{
	    printf("\nDigite o periodo em que o aluno se encontra: ");
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

	return nomePeriodo;
}

int getCodigoDisciplina(){
	
	 /**
	 * Função que lê o código da disciplina e verifica se ela tem 4 digitos
	 * @return Código da disciplina
	 */	

	int codigoDis;

	while(1)
    {
        printf("\nDigite o codigo da disciplina: ");
        while ((getchar()) != '\n');
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

    return codigoDis;
}
