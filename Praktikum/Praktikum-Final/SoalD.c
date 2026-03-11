#include <stdio.h>

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    long long x1, y1, x2, y2;
    scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
    long long ans = (x2 - x1) * (y2 - y1) + 1;
    printf("%lld\n", ans);
  }
}
