#include <stdio.h>
void magician(long long *a1, long long *a2, long long *x, long long *ans){
  if(*x == 1){
    *ans = *a1;
    return;
  }
  if(*x == 2){
    *ans = *a2;
    return;
  }
  long long next;
  for(int i = 3; i <= *x; i++){
    next = *a1 + *a2;
    *a1 = *a2;
    *a2 = next;
  }
  *ans = next;
}
int main() {
  long long t;
  scanf("%lld", &t);
  while(t--){
    long long a1, a2, x;
    scanf("%lld %lld %lld", &a1, &a2, &x);
    long long ans;
    magician(&a1, &a2, &x, &ans);
    printf("%lld\n", ans);
  }
  return 0;
}
