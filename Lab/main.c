#include <stdio.h>

int main(){
  int* ptr; // definisikan variabel pointer dengan nama num
  int num = 42;
  ptr = &num; // ngambil alamat dari num
  printf("Alamat num: %p\nNilai num: %d\n", ptr, *ptr);
  int* ptr2;
  ptr2 = ptr;
  printf("Alamat baru %p\nNilai baru %d", ptr2, *ptr2);
}
