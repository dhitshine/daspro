#include <stdio.h>
#include <string.h>
int main(){
  long long n, cnt = 0;
  scanf("%lld", &n);
  long long grid[n][n];
  for(long long i = 0; i < n; i++){
    for(long long j = 0; j < n; j++){
      scanf("%lld", &grid[i][j]);
    }
  }
  char str[10];
  while(scanf("%[^\n]s",str)){
    cnt++;
    cnt %= 4;
    if(!strcmp(str, "quit")){
      break;
    }
  }
  long long ans[n][n];
  for(long long i = 0; i < cnt; i++){
    for(long long j = 0; j < n; j++){
      for(long long k = 0; k < n; k++){
        ans[k][n - i - 1] = grid[j][k];
      }
    }
    for(long long j = 0; j < n; j++){
      for(long long k = 0; k < n; k++){
        grid[i][j] = ans[i][j];
      }
    }
  }
  for(long long j = 0; j < n; j++){
    for(long long k = 0; k < n; k++){
      printf("%lld ", ans[j][k]);
    }
    printf("\n");
  }
}
