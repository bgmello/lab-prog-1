#include <stdio.h>
#include <locale.h>
#include <string.h>
#define MAXNOME 60

//definição da estrutura aluno
typedef struct aluno{

  char codigo[5];
  char nome[MAXNOME];
  char cpf[11];
  char periodo[6];
  struct aluno *proximoAluno;
  	
}aluno;

//definição da estrutura disciplina
typedef struct disciplina{

  char codigo[4];
  char nome[MAXNOME];
  int quantiadeCreditos;
  char periodo[6];
  struct disciplina *proximaDisciplina;

}disciplina;

int verificaCPF(char *cpf){
  int j, k, t, digito1 = 0, digito2 = 0;
  char numIguais[11], i;
  if(strlen(cpf) != 11)
	return 0;
  //cpf com todos os digitos iguais é falso	
  for(i = '0'; i<= '9'; ++i){	
	for(j = 0; j<= 11; ++j)
	  numIguais[j]=i;
	if(strcmp(cpf,numIguais) == 0)
	  return 0;
  }	
  for(k = 0, t = 10; k < strlen(cpf)-2; k++, t--)
    digito1 += (cpf[k]-48) * t;
  digito1 %= 11;
  if(digito1 < 2)
    digito1 = 0;
  else
    digito1 = 11 - digito1;
  if((cpf[9]-48) != digito1) 
    return 0;
  else{
    for(k = 0, t = 11; i < strlen(cpf)-1; k++, t--)
      digito2 += (cpf[k]-48) * t;
    digito2 %= 11;
    if(digito2 < 2)
      digito2 = 0;
    else
      digito2 = 11 - digito2;
    if((cpf[10]-48) != digito2)
      return 0; 
  }
  return 1;
}
int main(){
  setlocale(LC_ALL, "Portuguese");
  int opcaoMenu=1;
  printf("SISTEMA DE CONTROLE DE DISCIPLINAS E ALUNOS\n\n");
	do{
	printf("Digite (1) para consultar\n(2) para adicionar\n(3) para remover\nOu outro número para sair: ");
	scanf("%d", &opcaoMenu);
	if(opcaoMenu == 1){
		
	}
	else if(opcaoMenu == 2){
		
	}
	else if(opcaoMenu == 3){
		
	}

  }while((opcaoMenu == 1) || (opcaoMenu == 2) || (opcaoMenu == 3));
  
  printf("Aplicação terminada\n");

  return 0;
}
