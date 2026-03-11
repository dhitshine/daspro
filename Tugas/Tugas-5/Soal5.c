#include <stdio.h>

void check_digit(int *arr, int size){
  int odd_sum = 0, even_sum = 0;
  for(int i = 0; i < size - 1; i++){ // first 11 digits 
    if(i % 2 == 0){
      odd_sum += arr[i];
    }
  }
  odd_sum = 3*odd_sum;
  printf("Step 1:\n");
  printf("Result of step 1: %d\n", odd_sum);

  for(int i = 0; i < size - 1; i++){
    if(i % 2 != 0){
      even_sum += arr[i];
    }
  }
  even_sum += odd_sum;
  printf("Step 2:\n");
  printf("Result of step 2: %d\n", even_sum);

  int last_digit = (10 - (even_sum % 10)) % 10;

  if(last_digit == arr[size - 1]){ // cocok
    printf("Validated.\n");
  }else{
    printf("Error in barcode.\n");
  }
  printf("\n");
}

int main(){
  int arr1[12] = {0, 7, 9, 4, 0, 0, 8, 0, 4, 5, 0, 1};
  int arr2[12] = {0, 2, 4, 0, 0, 0, 1, 6, 2, 8, 6, 0};
  int arr3[12] = {0, 1, 1, 1, 1, 0, 8, 5, 6, 8, 0, 7};
  int arr4[12] = {0, 5, 1, 0, 0, 0, 1, 3, 8, 1, 0, 1};

  check_digit(arr1, 12);
  check_digit(arr2, 12);
  check_digit(arr3, 12);
  check_digit(arr4, 12);
  return 0;
}
