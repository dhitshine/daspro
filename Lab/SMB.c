#include <stdio.h>

int main(){
  //sieve of erathothenes
  int prime[1000002];
  for(int i = 2; i < 1000002; i++){
    prime[i] = 1;
  }
  prime[0] = 0;
  prime[1] = 0;
  for(int i = 2; i*i < 1000002; i++){ //kita ngemark i^2 biar optimize (alias ga ngemark dua kali)   
    if(prime[i]){
      for(int j = i*i; j < 1000002; j+=i){ //mark i^2 dan kelipatannya 
        prime[j] = 0;
      }
    }
  }
  int t;
  scanf("%d", &t);
  int sum = 0, count = 0;
  while(t--){
    int n;
    scanf("%d", &n);
    count += n;
    while(n--){
      int num;
      scanf("%d", &num);
      if(prime[num]){
        sum++;
      }
    }
  }
  if(sum == count){
    printf("Cici senang, bot Mr. Biti berhasil ngirim semua buku");
  }else if(sum > 0 && sum < count){
    printf("Cici kecewa, bot Mr. Biti cuman kirim %d dari %d buku", sum, count);
  }else{
    printf("Cici sedih, bot Mr. Biti gak ngirim apa apa");
  }
}
