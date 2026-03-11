#include <stdio.h>
#include <string.h>
int main(){
  int t;
  scanf("%d", &t);
  for(int i = 1; i <= t; i++){
    int n, m;
    char dir[10];
    scanf("%d %d %s", &n, &m, dir);
    printf("Tangga %d:\n", i);
    for(int i = 0; i < m; i++){
      int pagar = (n - 1)/2;
      int dot = n - 2*pagar;
      if(!strcmp(dir, "right")){
        for(int j = 0; j < i; j++){
          printf(" ");
        }
        for(int j = 0; j < pagar; j++){
          printf("#");
        }
        for(int j = 0; j < dot; j++){
          printf(".");
        }
        for(int j = 0; j < pagar; j++){
          printf("#");
        }
        printf("\n");
      }else{
        for(int j = m - i - 1; j >= 0; j--){
          printf(" ");
        }
        for(int j = 0; j < pagar; j++){
          printf("#");
        }
        for(int j = 0; j < dot; j++){
          printf(".");
        }
        for(int j = 0; j < pagar; j++){
          printf("#");
        }
        printf("\n");
      }
    }
  }
}
