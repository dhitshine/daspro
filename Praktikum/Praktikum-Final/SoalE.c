#include <stdio.h>

int pref[10][1000005];

int get(int x){
  while(x >= 10){
    int cur = 1;
    while(x > 0){
      if(x % 10 == 0){
        x /= 10;
        continue;
      }
      cur *= (x % 10);
      x /= 10;
    }
    x = cur;
  }
  return x;
}

int main(){
  for(int x = 1; x < 1000005; x++){
    int k = get(x);
    for(int j = 1; j <= 9; j++){ // tambahin counter ke previous x
      if(k == j){ 
        pref[j][x] = 1 + pref[j][x - 1]; 
      }else{      
        pref[j][x] = pref[j][x - 1];
      }
    }
  }
  int t;
  scanf("%d", &t);
  while(t--){
    int c, g, k;
    scanf("%d %d %d", &c, &g, &k);
    printf("%d\n", pref[k][g] - pref[k][c - 1]); // banyak cara rentang [L,R] = [1, R] - [1, L - 1]
  }
}
/*
pref[k][g] banyak x yang hasilnya f(x) = k
*/
