#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct contact {
  char name[100];
  char phoneNumber[100];
  struct contact *closeFriend;
} contact;

void swap(contact *k1, contact *k2){
  contact temp = *k1;
  *k1 = *k2;
  *k2 = temp;
}

int get_sum(char *c){
  int sum = 0;
  int len = strlen(c);
  for(int i = 0; i < len; i++){
    if(c[i] >= '0' && c[i] <= '9'){
      sum += (int)(c[i] - '0');
    }
  }
  return sum;
}

void sort(contact *kontak, int n){
  int swapped;
  for(int i = 0; i < n - 1; i++){
    swapped = 0;
    for(int j = 0; j < n - i - 1; j++){
      int sumA = get_sum(kontak[j].phoneNumber);
      int sumB = get_sum(kontak[j + 1].phoneNumber);
      int shouldSwap = 0;
      if(sumB < sumA){
        shouldSwap = 1;
      }
      if(sumA == sumB && kontak[j].closeFriend != NULL && kontak[j + 1].closeFriend != NULL){
        int sumA_close = get_sum(kontak[j].closeFriend->phoneNumber);
        int sumB_close = get_sum(kontak[j + 1].closeFriend->phoneNumber);
        if(sumB_close < sumA_close){
          shouldSwap = 1;
        }
      }
      if(shouldSwap){
        swap(&kontak[j], &kontak[j + 1]);
        swapped = 1;
      }
    }
    if(swapped == 0){
      break; 
    }
  }
}

int search(contact *kontak, char *find, int n){
  for(int i = 0; i < n; i++){
    if(strcmp(kontak[i].name, find) == 0){
      return i;
    }
  }
  return -1;
}

int main(){
  int n;
  scanf("%d", &n);
  contact kontak[n];
  for(int i = 0; i < n; i++){
    scanf("%s %s", kontak[i].name, kontak[i].phoneNumber);
    kontak[i].closeFriend = NULL;
  }
  int c;
  scanf("%d", &c); 
  for(int i = 0; i < c; i++){
    char find[101], close[101];
    scanf("%s %s", find, close);
    int idx = search(kontak, find, n);
    int idxclose = search(kontak, close, n);
    if(idx != -1 && idxclose != -1){
      kontak[idx].closeFriend = &kontak[idxclose];
      kontak[idxclose].closeFriend = &kontak[idx];
    }
  }
  sort(kontak, n);
  for(int i = 0; i < n; i++){
    printf("Contact #%d\n\n", i + 1);
    printf("Name : %s\n", kontak[i].name);
    printf("Phone Number : %s\n", kontak[i].phoneNumber);
    printf("-------------------------\n\n");
  }
  return 0;
}
