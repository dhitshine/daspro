#include <bits/stdc++.h>
#define debug(x) cerr << #x << " --> " << x << endl;
using namespace std;

unsigned long long fun(unsigned long long a, unsigned long long b){
  unsigned long long res = 1;
  while(b){
    if(b & 1){
      res = res * a;
    }
    a *= a;
    b >>= 1;
  }
  return res;
}

int main(){
  unsigned long long n;  
  cin >> n;
  for(unsigned long long i = 1; i <= n; i++){
    unsigned long long ans = fun(4, i);
    printf("%llu -> %llu\n", i, ans);
  }
}
