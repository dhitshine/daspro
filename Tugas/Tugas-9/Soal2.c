#include <stdio.h>

int main(){
  FILE *file1 = fopen("src/soal2/file1.txt", "r");
  FILE *file2 = fopen("src/soal2/file2.txt", "r");
  FILE *merged = fopen("src/soal2/merged.txt", "w");
  if(file1 == NULL || file2 == NULL || merged == NULL){
    fprintf(stderr, "Error Opening File.");
    return 1;
  }
  char buffers[256];
  while(fgets(buffers, sizeof(buffers), file2) != NULL){
    fputs(buffers, merged);
  }
  while(fgets(buffers, sizeof(buffers), file1) != NULL){
    fputs(buffers, merged);
  }
  fclose(merged);
  fclose(file2);
  fclose(file1);
  return 0;
}
