#include <stdio.h>
#include <string.h>

void replace_first_x(char *str, char *ans, int now, int len){
  if(now == len){
    printf("%s\n", ans);
    return;
  }
  if(str[now] == 'x'){
    ans[now] = '1';
    replace_first_x(str, ans, now + 1, len);
    ans[now] = '0';
    replace_first_x(str, ans, now + 1, len);
  }else{
    ans[now] = str[now];
    replace_first_x(str, ans, now + 1, len);
  }
}

int main(){
  char str[100], ans[100];
  printf("Enter the string> ");
  scanf("%s", str);
  int len = strlen(str);
  replace_first_x(str, ans, 0, len);
}
