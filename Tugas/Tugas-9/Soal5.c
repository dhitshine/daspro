#include <stdio.h>

int is_upper(char c){
  return c >= 'A' && c <= 'Z';
}

int main(){
  FILE *input = fopen("src/soal5/input.txt", "r");
  FILE *output = fopen("src/soal5/output.txt", "w");
  if(input == NULL || output == NULL){
    fprintf(stderr, "Error Opening File.");
    return 1;
  }

  // Prints all upper case letter
  fputs("All upper case letters in input file:\n", output);
  char ch;
  while((ch = fgetc(input)) != EOF){
    if(is_upper(ch)){
      fputc(ch, output);
    }
  }
  fclose(input);

  input = fopen("src/soal5/input.txt", "r");
  if(input == NULL){
    fprintf(stderr, "Error Opening File.");
    return 1;
  }
  // Prints all line that start with letter 'A'
  fputs("\nAll lines that start with letters 'A':\n", output);
  char buffers[256];
  while(fgets(buffers, sizeof(buffers), input) != NULL){
    if(buffers[0] == 'A'){
      fputs(buffers, output);
    }
  }
  fclose(input);
  fclose(output);
  return 0;
}
