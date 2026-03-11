#include <stdio.h>

int main(){
  int a, b, c, d, e;
  scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
  double sum = a + b + c + d + e;
  double avg = sum / 5;
  printf("%.lf %.1lf", sum, avg);
}
