#include <stdio.h>
#include <string.h>

void reverse(int *arr, int n){
  int temp[n];
  for(int i = n - 1; i >= 0; i--){
    temp[n - i - 1] = arr[i];
  }
  memcpy(arr, temp, sizeof(temp));
}

int main(){
  int n;
  scanf("%d", &n);
  int arr[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }
  reverse(arr, n);
  for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
}
