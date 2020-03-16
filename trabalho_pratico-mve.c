#include <stdio.h>
#define MAXNOME 60

//definicao da estrutura aluno
typedef struct aluno{

  char codigo[5];
  char nome[MAXNOME];
  char cpf[11];
  char periodo[6];

}aluno;

//definicao da estrutura disciplina
typedef struct disciplina{

  char codigo[4];
  char nome[MAXNOME];
  int quantiadeCreditos;
  char periodo[6];

}disciplina;

int main(){

  int opcaoMatricula=1;

  printf("SISTEMA DE MATRICULAS\n\n");

  do{
  printf("Digite (1) para aluno, (2) para disciplina ou outro numero para sair: ");
  scanf("%d", &opcaoMatricula);
  
  //aluno
  if(opcaoMatricula==1){

  }

  else if(opcaoMatricula==2){

  }

  }while((opcaoMatricula==1) || (opcaoMatricula==2));
  
  printf("Aplicacao terminada\n");

  return 0;
}
