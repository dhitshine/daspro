#include <stdio.h>
#define tax 0.03625

int main(){
  int employees;
  double total_salary = 0, avg_salary;

  printf("Enter number of employees> ");
  scanf("%d", &employees);

  for(int i = 0; i < employees; i++){
    int id;
    double wage_rate, hours_worked, net_salary;
    printf("\nEnter identification number> ");
    scanf("%d", &id);
    printf("Enter hourly wage rate> ");
    scanf("%lf", &wage_rate);
    printf("Enter hours worked> ");
    scanf("%lf", &hours_worked);

    if(hours_worked <= 40){
      net_salary = wage_rate * hours_worked;
    }else{
      double overtime = (hours_worked - 40) * wage_rate * 1.5;
      net_salary = (wage_rate * 40) + overtime;
    }

    net_salary -= net_salary * tax;
    printf("\nEmployees ID: %d\n", id);
    printf("Net Salary: %.2lf\n", net_salary);
    total_salary += net_salary;
  }
  avg_salary = total_salary / employees;

  printf("\nTotal Payroll: %.2lf\n", total_salary);
  printf("Average amount: %.2lf", avg_salary);
}
