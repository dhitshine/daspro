#include <stdio.h>
#include <math.h>

int visited[]

typedef struct {
  int x, y;
} data;

data q[101];
int front, back;

int gcd(int a, int b){
  if(b == 0){
    return a;
  }
  return gcd(b, a % b);
}

void push(int x, int y){
  q[back] = (data){x, y};
  back++;
}

int cnt;

void bfs(int a, int b, int x){
  if(a == x || b == x){
    return;
  }
  push(0, 0);

}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int a, b, x;
    scanf("%d %d %d", &a, &b, &x);
    bfs(a, b, x);
  }
}
