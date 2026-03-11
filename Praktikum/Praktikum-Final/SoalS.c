#include <stdio.h>

long long memo[51][51];

long long comb(long long n, long long k){
  if(n < k){
    return 0;
  }
  if(k == 0 || n == 0){
    return 1;
  }
  if(memo[n][k] != 0){
    return memo[n][k];
  }
  memo[n][k] = comb(n - 1, k) + comb(n - 1, k - 1);
  return memo[n][k];
}

int main(){
  for(long long i = 0; i < 51; i++){
    for(long long j = 0; j < 51; j++){
      memo[i][j] = 0;
    }
  }
  long long n;
  scanf("%lld", &n);
  long long ans = comb(n, n);
  for(long long i = 0; i <= n; i++){
    printf("%lld ", comb(n, i));
  }
}
