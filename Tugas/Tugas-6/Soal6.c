#include <stdio.h>
#include <string.h>

void sort(int len_row, int len_col, char lastnames[len_row][len_col], char firstnames[len_row][len_col], int *ages){
  for(int i = 0; i < len_row - 1; i++){
    int min_j = i;
    for(int j = i + 1; j < len_row; j++){
      int checkLast = strcmp(lastnames[j], lastnames[min_j]);
      if(checkLast < 0){           
        min_j = j;
      }else if(checkLast == 0){      // if both are match, then check firstnames
        int checkFirst = strcmp(firstnames[j], firstnames[min_j]);
        if(checkFirst < 0){
          min_j = j;
        }
      }
    }
    char temp1[len_col], temp2[len_col];
    strcpy(temp1, lastnames[i]);
    strcpy(lastnames[i], lastnames[min_j]);
    strcpy(lastnames[min_j], temp1);
    strcpy(temp2, firstnames[i]);
    strcpy(firstnames[i], firstnames[min_j]);
    strcpy(firstnames[min_j], temp2);
    int temp = ages[i];
    ages[i] = ages[min_j];
    ages[min_j] = temp;
  }
}

int main(){
  int n;
  printf("Enter number of data> ");
  scanf("%d", &n);
  char lastnames[n][100], firstnames[n][100];
  int ages[n];
  printf("Original list:\n");
  for(int i = 0; i < n; i++){
    scanf("%s %s %d", lastnames[i], firstnames[i], &ages[i]);
  }
  sort(n, 100, lastnames, firstnames, ages);
  printf("\nAlphabetized list:\n");
  for(int i = 0; i < n; i++){
    printf("%s %s %d\n", lastnames[i], firstnames[i], ages[i]);
  }
}
