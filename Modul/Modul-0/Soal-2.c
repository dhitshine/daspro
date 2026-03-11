#include <stdio.h>

int main(){
  int p, n;
  scanf("%d %d", &p, &n);
  printf("Teman-teman mendapatkan %d potong :)\n", p / n);
  printf("Ghifari mendapatkan %d potong :(", p % n);
}
