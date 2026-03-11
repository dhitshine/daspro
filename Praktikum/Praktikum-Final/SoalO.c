#include <stdio.h>

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int n;
    scanf("%d", &n);
    if(n % 6 == 0){
      printf("Y\n");
    }else{
      printf("N\n");
    }
  }
}
