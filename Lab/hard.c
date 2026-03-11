#include <stdio.h>

int main(){
  long long n;
  scanf("%lld", &n);
  long long arr[n + 1];
  arr[1] = 6;
  for(long long i = 2; i <= n; i++){
    arr[i] = arr[i - 1]*10 + 6*i;
    printf("%lld\n", arr[i]);
  }
}




