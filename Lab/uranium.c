#include <stdio.h>

int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  int grid[n][m];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf("%d", &grid[i][j]);
    }
  }
  int temp = n;
  n = m;
  m = temp;
  int k;
  scanf("%d", &k);
  for(int i = 0; i < k; i++){
    int row, col;
    scanf("%d %d", &row, &col);
    int sum = (sum != 0) ? 1 : 0;
    int maxx = grid[row][col];
    //kanan
    if(col + 1 < m){
      int val = grid[row][col + 1];
      sum += (val != 0) ? 1 : 0;
      if(val > maxx){
        maxx = val;
      }
    }
    if(row + 1 < n && col + 1 < m){
      int val = grid[row + 1][col + 1];
      sum += (val != 0) ? 1 : 0;
      if(val > maxx){
        maxx = val;
      }
    }
    if(row + 1 < n){
      int val = grid[row + 1][col];
      sum += (val != 0) ? 1 : 0;
      if(val > maxx){
        maxx = val;
      }
    }
    if(row + 1 < n && col - 1 >= 0){
      int val = grid[row + 1][col - 1];
      sum += (val != 0) ? 1 : 0;
      if(val > maxx){
        maxx = val;
      }
    }
    if(col - 1 >= 0){
      int val = grid[row][col - 1];
      sum += (val != 0) ? 1 : 0;
      if(val > maxx){
        maxx = val;
      }
    }
    if(row - 1 >= 0 && col - 1 >= 0){
      int val = grid[row - 1][col - 1];
      sum += (val != 0) ? 1 : 0;
      if(val > maxx){
        maxx = val;
      }
    }
    if(row - 1 >= 0){
      int val = grid[row - 1][col];
      sum += (val != 0) ? 1 : 0;
      if(val > maxx){
        maxx = val;
      }
    }
    if(row - 1 >= 0 && col + 1){
      int val = grid[row - 1][col + 1];
      sum += (val != 0) ? 1 : 0;
      if(val > maxx){
        maxx = val;
      }
    }
    printf("Nilai sum: %d dan nilai maxx: %d\n", sum, maxx);
  }
}
