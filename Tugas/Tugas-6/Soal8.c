#include <stdio.h>
#include <string.h>

int isalphabet(char c){
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int isvowels(char c){
  return c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' || c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O';

}

int main(){
  char str[100];
  printf("Enter the string> ");
  fgets(str, sizeof(str), stdin);
  int len = strlen(str);
  int vowels = 0, consonants = 0;
  for(int i = 0; i < len; i++){
    if(isalphabet(str[i])){
      if(isvowels(str[i])){
        vowels++;
      }else{
        consonants++;
      }
    }
  }
  printf("The number of vowels is: %d\n", vowels);
  printf("The number of consonants is: %d", consonants);
}
