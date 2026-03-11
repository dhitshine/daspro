#include <stdio.h>

const int mod = 1e9 + 7;

int max(int a, int b){
  if(a < b){
    return b;
  }
  return a;
}

int mul(int a, int b){
  return ((a % mod) * (b % mod)) % mod;
}

int binexp(int a, int b){
  a %= mod;
  int res = 1;
  while(b){
    if(b & 1){
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

int invers(int a){
  return binexp(a, mod - 2);
}

void precompute(int *inv, int *fact, int n){
  fact[0] = 1;
  for(int i = 1; i < 2 * n; i++){
    fact[i] = fact[i - 1] * i;
    fact[i] %= mod;
  }
  inv[n] = invers(fact[n]);
  for(int i = n; i >= 1; i--){
    inv[i - 1] = inv[i] * i;
  }
}

int main(){
  int n, k, p;
  scanf("%d %d %d", &n, &k, &p);
  int A[n + 1], B[n + 1];
  for(int i = 1; i <= n; i++){
    scanf("%d %d", &A[i], &B[i]);
  }
  int dp[n + 1][k + 1]; // maksimum value jika pertimbangan -> ga ambil (skip), atau ambil dengan mempertimbangkan barang sebelumnya (1-n)
  for(int i = 0; i <= n; i++){
    dp[i][0] = 0; // kalo kapasitas = 0
  }
  for(int i = 0; i <= k; i++){
    dp[0][i] = 0; // kalo gada barang (barang hanya dari 1 - n);
  }
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= A[i]; j++){ // stok
      for(int k = )
    }
  }
  for(int i = 0; i <= n; i++){
    for(int w = 0; w <= k; w++){
      printf("%d ", dp[i][w]);
    }
    printf("\n");
  }
}
