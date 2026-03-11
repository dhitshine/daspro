#include <stdio.h>

long long memo[100001] = {0};

long long fun(long long n){
  if(n == 1) return 1;

  if(memo[n] != 0){
      return memo[n];
  }
  memo[n] = fun(n - 1) + n*n;
  return memo[n];
}

int main(){
  long long n;
  scanf("%lld", &n);
  printf("%lld\n", (long long)fun(n));
}
/*
#include <stdio.h>

long long memo[100001] = {0};

long long fun(long long n){
  if(n == 1) return 1;

  if(memo[n] != 0){
      return memo[n];
  }
  memo[n] = fun(n - 1) + n*n;
  return memo[n];
}

int main(){
  long long n;
  scanf("%lld", &n);
  printf("%lld\n", (long long)fun(n));
}
*/
