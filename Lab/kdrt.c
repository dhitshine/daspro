#include <stdio.h>

int main(){
  int n, m, k, t;
  scanf("%d %d %d %d", &n, &m, &k, &t);
  int grid[n][m];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf("%d", &grid[i][j]);
    }
  }
  int aman[k + 1];
  for(int i = 1; i <= k; i++){
    aman[i] = 1;
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(grid[i][j] == -1){
        int row = i, col = j;
        for(int p = 0; p < n; p++){
          int val = grid[p][col];
          if(val != -1){
            aman[val] = 0;
          }
        }
        for(int p = 0; p < m; p++){
          int val = grid[row][p];
          if(val != -1){
            aman[val] = 0;
          }
        }
      }
    }
  }
  for(int i = 1; i <= k; i++){
    if(!aman[i]){
      printf("%d\n", i);
    }
  }
}
