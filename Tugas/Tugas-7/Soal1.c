#include <stdio.h>

int visited[101][101];

int isvalid(int x, int y, int n, int m){
  return x >= 0 && x < n && y >= 0 && y < m;
}

int blob_check(int x, int y, int n, int m, int grid[n][m]){
  if(!isvalid(x, y, n, m) || visited[x][y] || grid[x][y] == 0){
    return 0;
  }
  visited[x][y] = 1;
  int count = 1;
  count += blob_check(x + 1, y, n, m, grid);
  count += blob_check(x - 1, y, n, m, grid);
  count += blob_check(x, y + 1, n, m, grid);
  count += blob_check(x, y - 1, n, m, grid);
  count += blob_check(x + 1, y + 1, n, m, grid);
  count += blob_check(x + 1, y - 1, n, m, grid);
  count += blob_check(x - 1, y + 1, n, m, grid);
  count += blob_check(x - 1, y - 1, n, m, grid);

  return count;
}

int main(){
  int n, m;
  printf("Enter the number of rows and column (n m)> \n");
  scanf("%d %d", &n, &m);
  int grid[n][m];
  printf("Enter the grid with n rows and m column> \n");
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf("%d", &grid[i][j]);
      visited[i][j] = 0;
    }
  }
  int x, y;
  printf("Enter the coordinate (x y)> \n");
  scanf("%d %d", &x, &y);
  int ans = blob_check(x, y, n, m, grid);
  if(ans != 0){
    printf("Cell (%d, %d) is filled with size: %d", x, y, ans);
  }else{
    printf("Cell (%d, %d) is empty", x, y);
  }
}
