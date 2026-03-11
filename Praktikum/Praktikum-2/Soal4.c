#include <stdio.h>
int main(){
  int t;
  scanf("%d", &t);
  char first[t];
  for(int i = 0; i < t; i++){
    char str[105];
    scanf(" %[^\n]s", str);
    first[i] = str[0];
    printf("%s telah hilang...\n", str);
  }
  int bisa = 1;
  for(int i = 1; i < t; i++){
    if((int)first[i] <= (int)first[i - 1]){
      bisa = 0;
      break;
    }
  }
  if(!bisa){
    printf("\nApakah Juumonji melakukan kesalahan?");
    return 0;
  }
  int hilang = 0;
  int cnt = 0;
  char ans[100];
  for(int i = 1; i < t; i++){
    int idx = 1;
    if((int)first[i] != (int)(first[i - 1] + 1)){
      hilang = 1;
      while((int)first[i] != (int)(first[i - 1] + idx)){
        ans[cnt] = (char)(first[i - 1] + idx);
        cnt++;
        idx++;
      }
    }
  }
  if(hilang){
    printf("\nMasih ada barang dengan huruf ");
    for(int i = 0; i < cnt; i++){
      printf("%c", ans[i]);
    }
    printf(" yang hilang!");
  }else{
    if(first[t - 1] == 'Z'){
      printf("Juumonji mungkin akan mencuri barang dengan huruf A\n");
    }else{
      printf("Juumonji mungkin akan mencuri barang dengan huruf %c", (char)(first[t - 1] + 1));
    }
  }
}
/*
B, C, D, J
E F G H I
*/
