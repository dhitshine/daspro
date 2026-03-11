#include <stdio.h>
#include <math.h>
#include <string.h>

int search(char COLOR_CODES[][7], int size, char *target){
  int ans = -1;
  for(int i = 0; i < size; i++){
    if(strcmp(COLOR_CODES[i], target) == 0){
      ans = i;
    }
  }
  return ans;
}

int main(){
  char COLOR_CODES[10][7] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white"};
  char band1[20], band2[20], band3[20];
  
  while(1){
    printf("Enter the colors of the resistor's three bands, beginning with the band nearest the end.\nType the colors in lowercase letters only, NO CAPS.\n\n");
    printf("Band 1 => ");
    scanf("%s", band1);
    printf("Band 2 => ");
    scanf("%s", band2);
    printf("Band 3 => ");
    scanf("%s", band3);
    int size = sizeof(COLOR_CODES) / sizeof(COLOR_CODES[0]);
    int band1Value = search(COLOR_CODES, size, band1);
    int band2Value = search(COLOR_CODES, size, band2);
    int band3Value = search(COLOR_CODES, size, band3);
    int valid = band1Value != -1 && band2Value != -1 && band3Value != -1;
    if(valid){
      double res = ((band1Value * 10 + band2Value) * pow(10, band3Value)) / 1000;
      char answer;
      printf("Resistance value: %.2lf kilo-ohms\n", res);
      printf("Do you want to decode another resistor?\n");
      printf("=> ");
      scanf(" %c", &answer);
      if(answer == 'n' || answer == 'N'){
        return 0;
      }
    }else{
      char answer;
      printf("Invalid colors: ");
      if(band1Value == -1){
        printf("%s ",band1);
      }
      if(band2Value == -1){
        printf("%s ",band2);
      }
      if(band3Value == -1){
        printf("%s ",band3);
      }
      printf("\nDo you want to decode another resistor?\n");
      printf("=> ");
      scanf(" %c", &answer);
      if(answer == 'n' || answer == 'N'){
        return 0;
      }
    }
    printf("\n");
  }
}

