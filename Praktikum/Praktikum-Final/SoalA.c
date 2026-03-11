#include <stdio.h>
#include <math.h>

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    long long d, m, n;
    scanf("%lld %lld %lld", &d, &m, &n);
    if(d < 0){
      printf("NO\n");
    }else if(d == 0){
      printf("YES\n");
    }else{
      long long ans = (long long)(round(pow(d, 0.25)));
      if(n - m >= ans && (long long)(ans * ans * ans * ans) == d){
        printf("YES\n");
      }else{
        printf("NO\n");
      }
    }
  }
}
/*
(x - y)^4 = D 
misal D = d^1/4

d harus kuadrat sempurna


maksimum x - y adalah saat x = M dan y = N, sehingga 
|x - y| pasti maksimum,
*/
