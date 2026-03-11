#include <stdio.h>

long long mxn = 1e9 + 7;

long long maxx(long long arr[], long long size){
  long long mx = -mxn;
  for(long long i = 0; i < size; i++){
    if(mx <= arr[i]){
      mx = arr[i];
    }
  }
  return mx;
}

long long minn(long long arr[], long long size){
  long long mn = mxn;
  for(long long i = 0; i < size; i++){
    if(mn >= arr[i]){
      mn = arr[i];
    }
  }
  return mn;
}

int main(){
  long long n;
  scanf("%lld", &n);
  long long arr[n];
  for(long long i = 0; i < n; i++){
    scanf("%lld", &arr[i]);
  }
  long long mx = maxx(arr, n);
  long long mn = minn(arr, n);
  printf("max: %lld\nmin: %lld", mx, mn);
}
