#include <stdio.h>

typedef struct {
  int x, y, dist;
} data;

data q[101];
int front, back;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int visited[11][11];

int is_valid(int x, int y, int n){
  return x >= 0 && x < n && y >= 0 && y < n;
}

void push(int x, int y, int val){
  q[back] = (data){x, y, val};
  back++;
}

int main(){
  int n;
  scanf("%d", &n);
  int grid[n][n];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%d", &grid[i][j]);
      visited[i][j] = 0;
    }
  }
  front = 0;
  back = 0;
  push(0, 0, 0); // push start
  visited[0][0] = 1;
  while(front < back){
    data now = q[front]; // ambil sel sekarang
    front++;
    int curr_x = now.x, curr_y = now.y, curr_dist = now.dist;
    if(curr_x == n - 1 && curr_y == n - 1){
      printf("%d menit doang", curr_dist);
      return 0;
    }
    for(int i = 0; i < 4; i++){
      int next_x = curr_x + dx[i];
      int next_y = curr_y + dy[i];
      if(is_valid(next_x, next_y, n) && !visited[next_x][next_y] && grid[next_x][next_y] == 1){
        visited[next_x][next_y] = 1;
        push(next_x, next_y, curr_dist + 1);
      }
    }
  }
  printf("Dahlah gajadi balik");
}
