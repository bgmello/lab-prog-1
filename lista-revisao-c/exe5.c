#include<stdio.h>

int fib(int n){
  if(n==0)return 0;
  if(n==1)return 1;
  return fib(n-1)+fib(n-2);
}

int main(){

  int n;
  printf("Entre com o número: ");
  scanf("%d", &n);

  printf("%d\n", fib(n));

  return 0;
}
