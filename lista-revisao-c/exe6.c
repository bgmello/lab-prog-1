#include<stdio.h>


int main(){

  int n, a=0, b=1, c=1, tmp;

  printf("Entre com o número: ");
  scanf("%d", &n);
  
  if(n==0){
    printf("0\n");
    return 0;
  }

  if(n==1 || n==2){
    printf("1\n");
    return 0;
  }

  while(n--){
    int tmp = c+b;
    a = b;
    b = c;
    c = tmp;
  }

  printf("%d\n", a);

  return 0;
}
