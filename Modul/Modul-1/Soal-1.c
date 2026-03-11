#include <stdio.h>
#include <math.h>
int main(){
  int x;
  scanf("%d", &x);
  int ratusan = x / 100;
  int puluhan = (x % 100) / 10;
  int satuan = x % 10;
  if(x >= 0 && x < 10){
    printf("Merupakan Bilangan Armstrong");
  }else if(x >= 10 && x < 100){
    long long arm = pow(ratusan, 2) + pow(puluhan, 2) + pow(satuan, 2);
    if(arm == x){
      printf("Merupakan Bilangan Armstrong");
    }else{
      printf("Bukan Merupakan Bilangan Armstrong");
    }
  }else if(x >= 100 && x <= 999){
    long long arm = pow(ratusan, 3) + pow(puluhan, 3) + pow(satuan, 3);
    if(arm == x){
      printf("Merupakan Bilangan Armstrong");
    }else{
      printf("Bukan Merupakan Bilangan Armstrong");
    }
  }
}
