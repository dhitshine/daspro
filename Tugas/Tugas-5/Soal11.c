#include <stdio.h>

void merge(double *arr1, int size1, double *arr2, int size2, double *result, int *size_res){
  int idx = 0, i = 0, j = 0;

  while(i < size1 && j < size2){
    if(arr1[i] < arr2[j]){
      result[idx] = arr1[i];
      i++;
      idx++;
    }else if(arr1[i] > arr2[j]){
      result[idx] = arr2[j];
      j++;
      idx++;
    }else{
      result[idx] = arr1[i];
      i++;
      j++;
      idx++;
    }
  }

  while(i < size1){
    result[idx] = arr1[i];
    i++;
    idx++;
  }
  while(j < size2){
    result[idx] = arr2[j];
    j++;
    idx++;
  }
  *size_res = idx;
}

int main(){
  printf("Case 1: First array is exhausted first\n");
  double arr1[3] = {1.0, 2.0, 3.0};
  double arr2[5] = {2.5, 4.0, 5.0, 6.0, 7.0};
  double res1[8];
  int result_size1 = 0;
  merge(arr1, 3, arr2, 5, res1, &result_size1);
  for(int i = 0; i < result_size1; i++){
    printf("%.1lf ", res1[i]);
  }
  printf("\n\n");

  printf("Case 2: Second array is exhausted first\n");
  double arr3[5] = {-10.5, -1.8, 3.5, 6.3, 7.2};
  double arr4[3] = {-1.8, 3.1, 6.3};
  double res2[8];
  int result_size2 = 0;
  merge(arr3, 5, arr4, 3, res2, &result_size2);
  for(int i = 0; i < result_size2; i++){
      printf("%.1lf ", res2[i]);
    }
  printf("\n\n");

  printf("Case 3: Both array are exhausted at same time\n");
  double arr5[4] = {1.0, 3.0, 5.0, 9.0};
  double arr6[4] = {2.0, 4.0, 6.0, 9.0};
  double res3[8];
  int result_size3 = 0;
  merge(arr5, 4, arr6, 4, res3, &result_size3);
  for(int i = 0; i < result_size3; i++){
    printf("%.1lf ", res3[i]);
  }
  printf("\n");
  return 0;
}
