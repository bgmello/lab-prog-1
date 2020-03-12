#include<stdio.h>
#include<stdlib.h>

void bubble(int v[], int size_v){
  int ok=1;
  while(ok){
    ok=0;
    for(int i=0;i+1<size_v;i++){
      if(v[i]>v[i+1]){
        int tmp = v[i];
        v[i] = v[i+1];
        v[i+1] = tmp;
        ok=1;
      }
    }
  }
}

int main(){


  int n,i;

  printf("Entre com n: ");
  scanf("%d", &n);

  int *v = (int*)calloc(n, sizeof(int));

  printf("Digite os numeros separados por espaço: ");
  for(i=0;i<n;i++)scanf("%d", &v[i]);
  
  bubble(v, n);
  
  for(i=0;i<n;i++)printf("%d ", v[i]);
  printf("\n");

  free(v);

  return 0;
}
