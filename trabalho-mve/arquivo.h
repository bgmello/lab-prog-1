
int isEmpty(FILE *file){
	
	/**
	 * Função que checa se o arquivo está vazio
	 * @param FILE file a ser verificado
	 * @return 1 se o arquivo está vazio e 0 caso contrário
	 */
	
    long savedOffset = ftell(file);
    fseek(file, 0, SEEK_END);

    if (ftell(file) == 0){
        return 1;
    }

    fseek(file, savedOffset, SEEK_SET);
    return 0;
}

void writeBase(){
	
	/**
	 * Função que escreve as informações nos arquivos
	 */
	
    int i,j,r;

    if(isEmpty(fpAluno)){
        fprintf(fpAluno, "periodo,codigoAluno,nomeAluno,cpf,codigoDisciplina\n");
    }

    if(isEmpty(fpDisciplina)){
        fprintf(fpDisciplina, "periodo,codigoDisciplina,nomeDisciplina,nomeProfessor,quantidadeCreditos\n");
    }

    for(i=0;i<numeroDePeriodos;i++){
        for(j=0;j<basePeriodo[i].numeroDeAlunos;j++){
            for(r=0;r<basePeriodo[i].baseAlunos[j].numeroDeDisciplinas;r++){
                fprintf(fpAluno, "%d,%d,%s,%s,%d\n", basePeriodo[i].nomePeriodo, basePeriodo[i].baseAlunos[j].codigoAl, basePeriodo[i].baseAlunos[j].nome, basePeriodo[i].baseAlunos[j].cpf, basePeriodo[i].baseAlunos[j].listaCodigosDis[r]);
            }
        }
    }

    for(i=0;i<numeroDePeriodos;i++){
        for(j=0;j<basePeriodo[i].numeroDeDisciplinas;j++){
            fprintf(fpDisciplina, "%d,%d,%s,%s,%d\n", basePeriodo[i].nomePeriodo, basePeriodo[i].baseDisciplinas[j].codigoDis, basePeriodo[i].baseDisciplinas[j].nome, basePeriodo[i].baseDisciplinas[j].professor, basePeriodo[i].baseDisciplinas[j].quantidadeCreditos);
        }
    }
}

void readBaseAluno(){
	
	/**
	 * Função que lê as informações dos alunos no arquivo
	 */

    char line[MAXLINE];
    char seps[] = ",";
    char *token;
    int nomePeriodo, posicaoPeriodo;
    int codigoDisciplina;
    aluno novoAluno;

    if(!isEmpty(fpAluno)){

        //le o cabecalho
        fgets(line, sizeof(line), fpAluno);

        while (fgets(line, sizeof(line), fpAluno)) {

            token = strtok(line, seps);
            sscanf (token, "%d", &nomePeriodo);
            token = strtok (NULL, seps);
            sscanf (token, "%d", &novoAluno.codigoAl);
            token = strtok (NULL, seps);
            sscanf (token, "%[^,]", novoAluno.nome);
            token = strtok (NULL, seps);
            sscanf (token, "%s", novoAluno.cpf);
            token = strtok (NULL, seps);
            sscanf (token, "%d", &codigoDisciplina);

    
            adicionaPeriodo(nomePeriodo);

            createAluno(nomePeriodo, novoAluno.codigoAl, novoAluno.cpf, novoAluno.nome);
            addDisciplinaInAluno(nomePeriodo, novoAluno.codigoAl, codigoDisciplina);
        }

    }
}

void readBaseDisciplina(){
	
	/**
	 * Função que lê as informações das disciplinas no arquivo
	 */
	 
    char line[MAXLINE];
    char seps[] = ",";
    char *token;
    int nomePeriodo, posicaoPeriodo;
    int codigoDisciplina;
    disciplina novaDisciplina;

    if(!isEmpty(fpDisciplina)){

        //le o cabecalho
        fgets(line, sizeof(line), fpDisciplina);

        while (fgets(line, sizeof(line), fpDisciplina)) {

            token = strtok(line, seps);
            sscanf (token, "%d", &nomePeriodo);
            token = strtok (NULL, seps);
            sscanf (token, "%d", &novaDisciplina.codigoDis);
            token = strtok (NULL, seps);
            sscanf (token, "%[^,]", novaDisciplina.nome);
            token = strtok (NULL, seps);
            sscanf (token, "%s", novaDisciplina.professor);
            token = strtok (NULL, seps);
            sscanf (token, "%d", &novaDisciplina.quantidadeCreditos);

    
            adicionaPeriodo(nomePeriodo);

            adicionaDisciplina(nomePeriodo, novaDisciplina.codigoDis, novaDisciplina.quantidadeCreditos, novaDisciplina.nome, novaDisciplina.professor);
        }

    }
}
