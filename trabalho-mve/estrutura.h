
//definição da estrutura aluno
typedef struct aluno
{

    int codigoAl;
    char nome[MAXNOME];
    char cpf[12];
    int numeroDeDisciplinas;
	int* listaCodigosDis;
	
} aluno;

//definição da estrutura disciplina
typedef struct disciplina
{

    int codigoDis;
    char nome[MAXNOME];
    char professor[MAXNOME];
    int quantidadeCreditos;
    
} disciplina;

//definicao da estrutura periodo
typedef struct periodo {
	
	int nomePeriodo;
	int numeroDeAlunos;
	int numeroDeDisciplinas;
	aluno* baseAlunos;
	disciplina* baseDisciplinas;
	
}periodo;