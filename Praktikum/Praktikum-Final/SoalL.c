#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b){
  return (*(int *)a) - (*(int *)b);
}

int find(int mx){
  int left = 0, right = 1005, ans;
  while(left <= right){
    int mid = left + (right - left) / 2;
    int find_x = mid * (mid + 1);
    if(find_x <= mx){
      ans = mid;
      left = mid + 1;
    }else{
      right = mid - 1;
    }
  }
  return ans;
}

int bangau(int time, int *K, int m){
  int total = 0;
  for(int i = 0; i < m; i++){
    int mx = (2 * time) / K[i];
    int x = find(mx);
    total += x;
  }
  return total;
}

int binser(int *K, int m, int n){
  int left = 0, right = 5e6, ans;
  while(left <= right){
    int mid = left + (right - left) / 2;
    int fun = bangau(mid, K, m);
    printf("saat mid = %d -> %d\n", mid, fun);
    if(bangau(mid, K, m) >= n){
      ans = mid;
      right = mid - 1;
    }else{
      left = mid + 1;
    }
  }
  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int n, m;
    scanf("%d %d", &n, &m);
    int K[m];
    for(int i = 0; i < m; i++){
      scanf("%d", &K[i]);
    }
    qsort(K, m, sizeof(int), comp);
    int ans = binser(K, m, n);
    printf("%d\n", ans);
  }
}
