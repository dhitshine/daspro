#include <stdio.h>

int reverse_num(int num){
  int rev = 0;
  while(num > 0){
    rev = rev * 10 + (num % 10);
    num /= 10;
  }
  return rev;
}

void is_prime(int num, int* flag){
  *flag = 1;
  if(num <= 1){
    *flag = 0;
    return;
  }
  for(int i = 2; i*i <= num; i++){
    if(num % i == 0){
      *flag = 0;
      return;
    }
  }
}

void is_palindrome(int num, int* flag){
  if(num == reverse_num(num)){
    *flag = 1;
  }else{
    *flag = 0;
  }
}

void output(int num){
  printf("Original Number: %d\n", num);
  printf("Reverse number: %d\n", reverse_num(num));
  int prime_flag;
  is_prime(num, &prime_flag);
  printf("Is %d prime? ", num);
  if(prime_flag){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  int palind_flag;
  is_palindrome(num, &palind_flag);
  printf("Is %d palindrome? ", num);
  if(palind_flag){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  printf("\n");
}

int main(){
  int num1 = 323, num2 = 12242, num3 = 9, num4 = 463, num5 = 678, num6 = 8679;
  output(num1);
  output(num2);
  output(num3);
  output(num4);
  output(num5);
  output(num6);
}

