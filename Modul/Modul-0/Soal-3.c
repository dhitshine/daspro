#include <stdio.h>

int main(){
  double a, b, c;
  scanf("%lf %lf %lf", &a, &b, &c);
  if(c == 0){
    return 0;
  }
  double ans = (a + b) / c;
  printf("%.2lf", ans);
}
