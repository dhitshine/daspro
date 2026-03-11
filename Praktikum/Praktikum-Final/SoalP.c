#include <stdio.h>

int is_popped[605];

void reset(int *arr, int n){
  for(int i = 0; i < n; i++){
    arr[i] = 0;
  }
}

int is_prime(int n){
  if(n < 2){
    return 0;
  }
  for(int i = 2; i * i <= n; i++){
    if(n % i == 0){
      return 0;
    }
  }
  return 1;
}

int gcd(int a, int b){
  if(b == 0){
    return a;
  }
  return gcd(b, a % b);
}

int findleft(int *arr, int idx){
  for(int i = idx - 1; i >= 0; i--){
    if(!is_popped[i]){
      return arr[i];
    }
  }
  return 1;
}

int findright(int *arr, int idx, int size){
  for(int i = idx + 1; i < size; i++){
    if(!is_popped[i]){
      return arr[i];
    }
  }
  return 1;
}

int skor(int *arr, int n, int i){
  int left = findleft(arr, i);
  int right = findright(arr, i, n);
  if(is_prime(arr[i])){
    return arr[i] * 2 * gcd(left, right);
  }
  return left * arr[i] * right;
}

int max(int a, int b){
  if(a < b){
    return b; 
  }
  return a;
}

int pop(int *arr, int popped, int size){
  if(popped == size){
    return 0;
  }
  int mx = 0;
  for(int i = 0; i < size; i++){
    if(is_popped[i]) continue;
    is_popped[i] = 1;
    int skor_balon = skor(arr, size, i);
    int total = skor_balon + pop(arr, popped + 1, size);
    mx = max(mx, total);
    is_popped[i] = 0;
  }
  return mx;
}

int main(){
  int n, m;
  scanf("%d", &n);
  int A[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  scanf("%d", &m);
  int B[m];
  for(int i = 0; i < m; i++){
    scanf("%d", &B[i]);
  }
  reset(is_popped, n);
  int ans1 = pop(A, 0, n);
  reset(is_popped, m);
  int ans2 = pop(B, 0, m);
  if(ans1 > ans2){
    printf("Pop: %d > %d", ans1, ans2);
  }else if(ans1 < ans2){
    printf("Flop: %d < %d", ans1, ans2);
  }else{
    printf("Draw: %d = %d", ans1, ans2);
  }
  return 0;
}
