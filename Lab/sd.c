#include <stdio.h>

int main(){
  unsigned long long mod = 1000000000;
  unsigned long long n;
  scanf("%llu", &n);
  unsigned long long res = 1, a = 4;
  a %= mod;
  while(n){
    if(n & 1){
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    n >>= 1;
  }
  printf("%llu", res);
}
