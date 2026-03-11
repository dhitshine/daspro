#include <stdio.h>
#include <math.h>

int main(){
  double amount_borrowed, annual_interest;
  int num_payment;
  printf("Enter amount borrowed ($) > ");
  scanf("%lf", &amount_borrowed);
  printf("Enter annual interest rate (%%) > ");
  scanf("%lf", &annual_interest);
  printf("Enter number of payments (months) > ");
  scanf("%d", &num_payment);

  double monthly_interest = annual_interest / (12 * 100);
  double payment = (monthly_interest * amount_borrowed) / (1 - (1 / pow(1 + monthly_interest, num_payment)));
  payment = round(payment * 100) / 100; //nearest cent
  printf("Total payment \t: $%.2lf\n", payment);
  printf("------------------------------------------------------------------\n");
  printf("Payment \t Interest \t Principal \t Principal Balance \n");
  printf("------------------------------------------------------------------\n");
  double principal_balance = amount_borrowed;
  double final_payment;
  for(int idx = 1; idx <= num_payment; idx++){
    double interest = round(monthly_interest * principal_balance * 100) / 100; //nearest cent
    double principal = payment - interest;
    if(idx == num_payment){
      principal = principal_balance;
      final_payment = principal + interest;
      principal_balance = 0;
    }else{
      principal_balance -= principal;
    }
    printf("   %d\t\t   %.2lf\t\t  %.2lf\t      %.2lf\n", idx, interest, principal, principal_balance);
  }
  printf("\nFinal payment \t: $%.2lf\n", final_payment);
  printf("------------------------------------------------------------------\n");
}
