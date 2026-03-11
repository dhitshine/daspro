#include <stdio.h>
#include <math.h>

int cases(int day){
  return (40000 / (1 + 39999*exp(-0.24681*day)));
}

int main(){
  int day, total_cases;
  printf("Enter day number>> ");
  scanf("%d", &day);
  total_cases = cases(day);
  printf("By day %d, model predicts %d cases total\n\n", day, total_cases);

  printf("Enter day number>> ");
  scanf("%d", &day);
  total_cases = cases(day);
  printf("By day %d, model predicts %d cases total\n\n", day, total_cases);

  printf("Enter day number>> ");
  scanf("%d", &day);
  total_cases = cases(day);
  printf("By day %d, model predicts %d cases total\n\n", day, total_cases);

  return 0;
}
