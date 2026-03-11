#include <stdio.h>

int recurse(int num){
  if(num <= 0){
    return 0;
  }
  return recurse(num - 1) + 2;
}

int main(){
  int x;
  scanf("%d", &x);
  for(int i = 0; i <= x; i++){
    printf("f(%d) = %d\n", i, recurse(i));
  }
}
