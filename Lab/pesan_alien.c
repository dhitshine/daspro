#include <stdio.h>
#include <string.h>

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    char m;
    int k;
    scanf(" %c %d ", &m, &k);
    char str[1001];
    gets(str);
    int len = strlen(str);
    if(m == '*'){
      for(int i = 0; i < len; i++){
        if((str[i] >= 'a' && str[i] <= 'z')){
          char ans = (char)(((str[i] - k - 97 + 26) % 26) + 97); // handle kasus negatif
          printf("%c", ans);
        }else if(str[i] >= 'A' && str[i] <= 'Z'){
          char ans = (char)(((str[i] - k - 65 + 26) % 26) + 65);
          printf("%c", ans);
        }else{
          printf("%c", str[i]);
        }
      }
    }else if(m == '#'){
      for(int i = 0; i < len; i++){
        if((str[i] >= 'a' && str[i] <= 'z')){
          char ans = (char)(((str[i] + k - 97 + 26) % 26) + 97);
          printf("%c", ans);
        }else if(str[i] >= 'A' && str[i] <= 'Z'){
          char ans = (char)(((str[i] + k - 65 + 26) % 26) + 65);
          printf("%c", ans);
        }else{
          printf("%c", str[i]);
        }
      }
    }
    printf("\n");
  }
}
