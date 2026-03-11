#include <stdio.h>
#include <math.h>
#include <string.h>
int main(){
  char str[101];
  long long num, sum;
  scanf("%s %lld", str, &num);
  if(str[0] == 'E' && str[1] == 'l' && str[2] == 'l' && str[3] == 'i' && str[4] == 'e'){
    num /= 2;
    sum = num*(num + 1);
    printf("%lld", sum);
  }else if(str[0] == 'O' && str[1] == 'd' && str[2] == 'd' && str[3] == 'i' && str[4] == 'e'){
    num = ceil((double)num / 2);
    sum = num * num;
    printf("%lld", sum);
  }else{
    printf("Who is that?");
  }
}
