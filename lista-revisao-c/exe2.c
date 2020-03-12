#include<stdio.h>

void imprimirNumero(int i, int n){
  if(i>=n) return;
  printf("%d ", i);
  return imprimirNumero(i+2, n);
}

int main(){

  int n;

  printf("Digite o numero n: ");

  scanf("%d", &n);

  printf("Todos os numeros pares 0 < i < %d: ", n);

  imprimirNumero(2, n);
  
  printf("\n");

  return 0;
}
