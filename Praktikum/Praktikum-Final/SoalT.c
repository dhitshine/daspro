#include <stdio.h>

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

char ubah(char c){
  if(c == 'A'){
    return 'B';
  }
  if(c == 'B'){
    return 'C';
  }
  return 'A';
}

int main(){
  int n, r;
  char kode;
  char A[3] = {'C', 'A', 'B'};
  scanf("%d %d %c", &n, &r, &kode);
  int idx = kode - 'A';
  char ruangan[n + 1];
  ruangan[r] = kode;
  for(int i = 1; i <= n; i++){
    if(i != r){
      ruangan[i] = A[idx];
    }
  }
  if(n & 1){
    for(int i = 1; i <= n; i++){
      if(i % 2 == 0 && i != r){
        ruangan[i] = kode;
      }
    }
  }
  if(is_prime(r)){
    for(int i = 1; i <= n; i++){
      if(is_prime(i) && i != r){
        ruangan[i] = ubah(ruangan[i]);
      }
    }
  }
  int cnt = 0;
  for(int i = 1; i <= n; i++){
    if(ruangan[i] == kode && i != r){
      cnt++;
    }
  }
  printf("%d", cnt);
}
/*
6 1
A
Ruangan 1:
A
Ruangan 2:
C
Ruangan 3:
C
Ruangan 4:
C
Ruangan 5:
C
Ruangan 6:
C

*/
