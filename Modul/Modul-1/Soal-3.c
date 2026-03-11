#include <stdio.h>

int main(){
  int i1, i2, i3, i4;
  scanf("%d %d %d %d", &i1, &i2, &i3, &i4);
  int decimal_form = 8*i1 + 4*i2 + 2*i3 + 1*i4;
  switch(decimal_form){
    case 0:
      printf("1 1 1 1 1 1 0");
      break;
    case 1:
      printf("0 1 1 0 0 0 0");
      break;
    case 2:
      printf("1 1 0 1 1 0 1");
      break;
    case 3:
      printf("1 1 1 1 0 0 1");
      break;
    case 4:
      printf("0 1 1 0 0 1 1");
      break;
    case 5:
      printf("1 0 1 1 0 1 1");
      break;
    case 6:
      printf("1 0 1 1 1 1 1");
      break;
    case 7:
      printf("1 1 1 0 0 0 0");
      break;
    case 8:
      printf("1 1 1 1 1 1 1");
      break;
    case 9:
      printf("1 1 1 1 0 1 1");
      break;
    default:
      printf("0 0 0 0 0 0 0");
  }
}
