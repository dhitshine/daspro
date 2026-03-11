#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int r, c, x, cmdlen;
  char cmd[101];
} Blob;

void change(int *x){
  if((*x) & 1){
    *x = 3*(*x) + 1;
  }else{
    *x /= 2;
  }
}

int main(){
  int n, r, c;
  scanf("%d %d %d", &n, &r, &c);
  int **grid = (int**)malloc(r * sizeof(int*));
  for(int i = 0; i < r; i++){
    grid[i] = (int*)calloc(c, sizeof(int));
  }
  Blob *blob = (Blob*)malloc(n * sizeof(Blob));
  for(int i = 0; i < n; i++){
    scanf("%d %d %d %d %s", &blob[i].r, &blob[i].c, &blob[i].x, &blob[i].cmdlen, blob[i].cmd);
    int x = blob[i].r;
    int y = blob[i].c;
    int val = blob[i].x;
    grid[x][y] += val;
  }
  int query;
  scanf("%d", &query);
  for(int i = 0; i < query; i++){
    int q;
    scanf("%d", &q);
    int len = blob[q].cmdlen;
    int nowx = blob[q].r, nowy = blob[q].c;
    for(int j = 0; j < len; j++){
      char cmd = blob[q].cmd[j];
      if(cmd == 'W'){
        nowx--;
      }else if(cmd == 'S'){
        nowx++;
      }else if(cmd == 'A'){
        nowy--;
      }else if(cmd == 'D'){
        nowy++;
      }
      change(&blob[q].x);
      if(nowx >= 0 && nowx < r && nowy >= 0 && nowy < c){
        grid[nowx][nowy] += blob[q].x;
      }
    }
    blob[q].r = nowx;
    blob[q].c = nowy;
  }
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
  for(int i = 0; i < r; i++){
    free(grid[i]);
  }
  free(blob);
  free(grid);
	return 0;
}
