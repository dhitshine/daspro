#include <stdio.h>
#include <string.h>

int main(){
  char arr[100];
	gets(arr);
  int cnt_a = 0, cnt_i = 0, cnt_u = 0, cnt_e = 0, cnt_o = 0;
  int len = strlen(arr);
  for(int i = 0; i < len; i++){
    if(arr[i] == 'A' || arr[i] == 'a'){
      cnt_a++;
    }else if(arr[i] == 'I' || arr[i] == 'i'){
      cnt_i++;
    }else if(arr[i] == 'U' || arr[i] == 'u'){
      cnt_u++;
    }else if(arr[i] == 'E' || arr[i] == 'e'){
      cnt_e++;
    }else if(arr[i] == 'O' || arr[i] == 'o'){
      cnt_o++;
    }
  }
  printf("A/a : %d\n", cnt_a);
  printf("I/i : %d\n", cnt_i);
  printf("U/u : %d\n", cnt_u);
  printf("E/e : %d\n", cnt_e);
  printf("O/o : %d\n", cnt_o);
}
