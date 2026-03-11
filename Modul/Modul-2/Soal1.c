#include <stdio.h>

int main(){
  int input;
  while(scanf("%d", &input) != EOF){
    printf((input & 1) ? "Ganjil\n" : "Genap\n");
  }
}
