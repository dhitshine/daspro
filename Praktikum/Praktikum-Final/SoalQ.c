#include <stdio.h>

int ans = 0;

int dist(int a, int b){
  int d = a - b;
  if(d < 0){
    return -d;
  }
  return d;
}

void solve(int n, int from, int via, int to){
  if(n == 0){
    return;
  }
  int cost = n * dist(to, from);
  ans += cost;
  solve(n - 1, from, to, via);
  printf("Crate %d, Zone %d -> Zone %d (Cost: %d)\n", n, from, to, cost);
  solve(n - 1, via, from, to);
}

int main(){
  int n;
  scanf("%d", &n);
  solve(n, 1, 2, 3);
  printf("%d", ans);
}
