#include <stdio.h>
#include <math.h>

double monthly_payment(double interest_rate, int duration, double amount_loan){
  interest_rate = interest_rate / (12 * 100);
  duration *= 12;
  return (interest_rate * amount_loan) / (1.0 - 1.0 / (pow(1 + interest_rate, duration)));
}

int main(){
  FILE *out = fopen("src/soal6/output.txt", "w");
  if(out == NULL){
    fprintf(stderr, "Error Opening File");
    return 1;
  }
  double amount_loan, min_interest, max_interest;
  printf("Enter amount of the loan> ");
  scanf("%lf", &amount_loan);
  printf("Enter the minimum interest rate> ");
  scanf("%lf", &min_interest);
  printf("Enter the maximum interest rate> ");
  scanf("%lf", &max_interest);
  fprintf(out, "Loan Amount: %.2lf\n", amount_loan);
  fputs("---------------------------------------------------------------------------\n", out);
  fputs("Interest Rate\t\t\tDuration (years)\t\t\tMonthly Payment\t\t\tTotal Payment\n", out);
  int idx = 0;
  int duration[3] = {20, 25, 30};
  while(min_interest <= max_interest){
    double payment = monthly_payment(min_interest, duration[idx], amount_loan);
    payment = round(payment * 100) / 100;
    double total_payment = payment * duration[idx] * 12;
    fprintf(out, "%9.2lf %17d %23.2lf %20.2lf\n", min_interest, duration[idx], payment, total_payment);
    idx++;
    if(idx == 3){
      min_interest += 0.25;
      idx = 0;
    }
  }
  fclose(out);
  return 0;
}
