#include <stdio.h>
#include <string.h>
typedef struct {
  char nama[101];
  int harga;
  int stok;
} Barang;

void swap(Barang *a1, Barang *a2){
  Barang temp = *a1;
  *a1 = *a2;
  *a2 = temp;
}

void sort(Barang *barang, int n){
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
      if(barang[i].harga > barang[j].harga){
        swap(&barang[i], &barang[j]);
      }
    }
  }
}

int main(){
  int n;
  scanf("%d", &n);
  Barang barang[n];
  for(int i = 0; i < n; i++){
    scanf("%s %d %d", barang[i].nama, &barang[i].harga, &barang[i].stok);
  }
  int m;
  scanf("%d", &m);
  while(m--){
    char cmd[20];
    scanf("%s", cmd);
    if(!strcmp(cmd, "SORT")){
      sort(barang, n);
    }else if(!strcmp(cmd, "PRINT")){
      for(int i = 0; i < n; i++){
        printf("%s %d %d\n", barang[i].nama, barang[i].harga, barang[i].stok);
      }
    }else if(!strcmp(cmd, "MAXSTOCK")){
      int idx = 0;
      for(int i = 1; i < n; i++){
        if(barang[i].stok > barang[idx].stok){
          idx = i;
        }
      }
      printf("%s %d %d\n", barang[idx].nama, barang[idx].harga, barang[idx].stok);
    }else if(!strcmp(cmd, "SWAP")){
      int a, b;
      scanf("%d %d", &a, &b);
      swap(&barang[a], &barang[b]);
    }else if(!strcmp(cmd, "UPDATE")){
      int idx, new_price, new_stock;
      scanf("%d %d %d", &idx, &new_price, &new_stock);
      barang[idx].harga = new_price;
      barang[idx].stok = new_stock;
    }
  }
}
