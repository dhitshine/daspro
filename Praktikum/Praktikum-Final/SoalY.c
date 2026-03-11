#include <stdio.h>
int main(){
  long long n;
  scanf("%lld", &n);
  long long arr[n];
  scanf("%lld", &arr[0]);
  long long mx_sum = arr[0], curr_sum = arr[0];
  long long curr_start = 0, start = 0, end = 0;
  for(long long i = 1; i < n; i++){
    scanf("%lld", &arr[i]);
    if(curr_sum + arr[i] > arr[i]){
      curr_sum += arr[i];
    }else{
      curr_sum = arr[i];
      curr_start = i;
    }
    if(curr_sum > mx_sum){
      mx_sum = curr_sum;
      start = curr_start;
      end = i;
    }
  }
  if(mx_sum > 0){
    printf("Peak energy resonance at %lld! Clearance granted, Dombest archives unlocked!\n", mx_sum);
    printf("CODE: ");
    for(long long i = start; i <= end; i++){
      printf("%lld ", arr[i]);
    }
  }else if(mx_sum == 0){
    printf("No usable signal detected! The fragment dissolves into pure static!\n");
    printf("CODE: ");
    for(long long i = start; i <= end; i++){
      printf("%lld ", arr[i]);
    }
  }else{
    printf("Critical instability detected with energy drain of %lld! The Dombest fragment is collapsing!\n", -mx_sum);
    printf("CODE: ");
    for(long long i = start; i <= end; i++){
      printf("%lld ", arr[i]);
    }
  }
}

/*
8
-2 -3 4 -1 -2 1 6 -3

start -> -2
start -> -3 
antara start new subarray, atau lanjutin subarray sebelumnya

saat -3, kita akan memilih sum yang miminum antara start subarray baru atau lanjutin sebelumnya

-3 + -2 atau start -3 (mendin start dari -3) mx_sum = -2
4 + -3 atau start 4 (mending start dari 4) mx_sum = 4
4 + -1 atau start -1 (mending lanjutin dari 4) mx_sum = 3
3 + -2 atau start -2 (mending lanjutin dari 3) mx_sum = 1
1 + 1 atau start 1 (mending lanjutin dari 1) mx_sum = 2
2 + 6 atau start 6 (mending lanjutin dari 2) mx_sum = 8
8 + -3 atau start -3 (mending lanjutin dari 8 (end)) mx_sum = 8

inti algo kadane's :
untuk setiap elemen pada array, pertimbangkan 2 kondisi
1. lanjutin subarray sebelumnya
2. mulai subarray baru dari elemen sekarang
untuk setiap subarray yang berakhir pada indeks ke-i, ambil maksimum sum
*/
