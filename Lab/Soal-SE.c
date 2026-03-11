#include <stdio.h>
#include <string.h>
int main(){
  unsigned long long n;
  char str[10005];
  scanf("%llu", &n);
  scanf("%s", str);
  int len = strlen(str);
  n &= 1;
  if(n){ // n ganjil
    for(int i = 0; i < len; i++){
      str[i] = (char)(str[i] ^ len);
    }
    for(int i = len - 1; i >= 0; i--){
      printf("%c", str[i]);
    }
  }else{
    for(int i = len - 1; i >= 0; i--){
      printf("%c", str[i]);
    }
  }
}
