#include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);
  int arr[n];
  for(int i = 0; i < n; i++){
    int num;
    scanf("%d", &num);
    arr[n - i - 1] = num;
  }
  for(int i = 0; i < n; i++){
    printf("%d\n", arr[i]);
  }
}
