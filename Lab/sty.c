#include <stdio.h>
#include <string.h>
int main(){
  char str[1005];
  int n, m;
  scanf("%s", str);
  scanf("%d %d", &n, &m);

  char grid[n][m];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf(" %c", &grid[i][j]);
      if(grid[i][j] >= 'A' && grid[i][j] <= 'Z'){
        grid[i][j] = (char)(grid[i][j] + 32);
      }
    }
  }
  int len = strlen(str);
  for(int i = 0; i < len; i++){
    if(str[i] >= 'A' && str[i] <= 'Z'){
      str[i] = (char)(str[i] + 32);
    }
  }
  int bisa = 0, idx = 0;
  for(int i = 0; i < m && idx < len; i++){
    for(int j = 0; j < n; j++){
      if(str[idx] == grid[j][i]){
        idx++;
        break;
      }
    }
  }
  if(idx == len){
    printf("Aman Ykik, siap dijual!");
  }else{
    printf("Salah nih Ykik, jangan dijual dulu.");
  }
}
