#include <stdio.h>

int main(){
  int x, y, z;
  scanf("%d %d %d", &x, &y, &z);
  int height[x];
  for(int i = 0; i < x; i++){
    scanf("%d", &height[i]);
  }
  int ans = 0;
  for(int i = 0; i < z - 1; i++){
    for(int j = 0; j < x; j++){
      height[j]++;
      if(height[j] == y){
        ans++;
        height[j]--;
      }
    }
    for(int j = 0; j < x; j++){
      printf("%d ", height[i]);
    }
    printf("\n");
  }
  printf("%d", ans);
}
