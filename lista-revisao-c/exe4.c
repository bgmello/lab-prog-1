#include<stdio.h>

int main(){

  FILE *fp;

  char sexo;
  float a, somaM=0, quantM=0, somaF=0, quantF=0;
  char c[30];

  printf("Digite o nome do arquivo de entrada: ");

  scanf("%[^\n]s", c);

  fp = fopen(c, "r");

  if(!fp){
    printf("Arquivo nao encontrado\n");
    return 0;
  }
  while(1!=2){
    if(fscanf(fp, "%c %f ", &sexo, &a)==EOF)break;
    if(sexo=='M'){
      somaM+=a;
      quantM++;
    }
    else{
      somaF+=a;
      quantF++;
    }
  }

  if(quantM==0){
    printf("Média do sexo Masculino: 0\n");
  }
  else{
    printf("Média do sexo Masculino: %.2f\n", somaM/quantM);
  }

  if(quantF==0){
    printf("Média do sexo Feminino: 0\n");
  }
  else{
    printf("Média do sexo Feminino: %.2f\n", somaF/quantF);
  }

  fclose(fp);

  return 0;
}
