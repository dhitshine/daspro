#include <stdio.h>
#include <string.h>

int main(){
  char str[1000];
  scanf("%s", str);
  for(int i = 0; i < (int)strlen(str); i++){
    if(str[i] >= 'A' && str[i] <= 'Z' && str[i - 1] != '_'){
      str[i] = (char)(str[i] + 32);
    }
    if(str[i] == '_'){
      if(str[i + 1] >= 'a' && str[i + 1] <= 'z'){
        str[i + 1] = (char)(str[i + 1] - 32);

      }
    }
  }
  for(int i = 0; i < (int)strlen(str); i++){
    if(str[i] != '_'){
      printf("%c", str[i]);
    }
  }
}
