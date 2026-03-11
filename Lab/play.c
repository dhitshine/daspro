#include <stdio.h>

int main(){
  int arr[9] = {3,2,3,3,3,2,2,4,4};
  int freq[100];
  for(int i = 0; i < 100; i++){
    freq[i] = 0;
  }
  for(int i = 0; i < 9; i++){
    freq[arr[i]]++;
  }
  int mod = freq[arr[0]], num = arr[0];
  for(int i = 1; i < 9; i++){
    if(mod < freq[arr[i]]){
      mod = freq[arr[i]];
      num = arr[i];
    }
  }
  printf("Num %d", num);
}
