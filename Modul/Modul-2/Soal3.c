// checking num prime using check divisible from 2 - n 

#include <stdio.h>

int main(){
  int prime[1000];
  int n;
  scanf("%d", &n);
  prime[0] = prime[1] = 0;
  for(int i = 2; i <= n; i++){
    prime[i] = 1;
    for(int j = 2; j < i; j++){
      if(i % j  == 0){
        prime[i] = 0;
        break;
      }
    }
    if(prime[i]){
      printf("* ");
    }else{
      printf("%d ", i);
    }
  }
}
