
int verificaCPF(char *cpf) //ok
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

int isNumeric(char *c) //ok
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