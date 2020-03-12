#include<stdio.h>

int main(){

  FILE *fp;

  int somaImp = 0, prodPar = 1, a;
  
  char c[30];

  printf("Digite o nome do arquivo de entrada: ");

  scanf("%s", c);

  fp = fopen(c, "r");

  if(!fp){
    printf("Arquivo nao encontrado\n");
    return 0;
  }

  while(1!=2){
    if(fscanf(fp, "%d", &a)==EOF)break;
    if(a%2==0)prodPar*=a;
    else somaImp+=a;
  }

  printf("Produtório dos números pares: %d\n", prodPar);
  printf("Somatório dos números ímpares: %d\n", somaImp);
  
  fclose(fp);

  return 0;
}
