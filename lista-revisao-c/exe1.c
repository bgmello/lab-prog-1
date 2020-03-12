#include<stdio.h>

int main(){

  int i,n;
  
  printf("Digite o numero n: ");

  scanf("%d", &n);

  printf("Numeros pares 0 < i < %d: ", n);

  for(i=2;i<n;i+=2){
    printf("%d ", i);
  }

  printf("\n");

  return 0;
}

