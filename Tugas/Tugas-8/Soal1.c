#include <stdio.h>

typedef struct {
  double capacity;
  double current;
} tank_t;

typedef struct {
  int month;
  int day;
  int year;
} date_t;

typedef struct {
  char make[50];
  char model[50];
  int odometer;
  date_t manufact;
  date_t purchase;
  tank_t tank;
} auto_t;

int scan_tank(tank_t *tank){
  int res;
  res = scanf("%lf %lf", &tank->capacity, &tank->current);
  if(res == EOF){
    return EOF;
  }
  if(res != 2){
    return 0;
  }
  return 1;
}

int scan_date(date_t *date){
  int res;
  res = scanf("%d %d %d", &date->month, &date->day, &date->year);
  if(res == EOF){
    return EOF;
  }
  if(res != 3){
    return 0;
  }
  return 1;
}
int scan_auto(auto_t *automobile){
  int res;
  res = scanf("%s %s %d", automobile->make, automobile->model, &automobile->odometer);
  if(res == EOF){
    return EOF;
  }
  if(res != 3){
    return 0;
  }

  res = scan_date(&automobile->manufact);
  if(res == EOF){
    return EOF;
  }
  if(res != 1){ // if input is not valid
    return 0;
  }

  res = scan_date(&automobile->purchase);
  if(res == EOF){
    return EOF;
  }
  if(res != 1){
    return 0;
  }

  res = scan_tank(&automobile->tank);
  return res;
}

void print_tank(tank_t tank){
  printf("Total capacity: %.2lf\n", tank.capacity);
  printf("Current capacity: %.2lf\n", tank.current);
}

void print_date(date_t date){
  printf("%d %d %d\n", date.month, date.day, date.year);
}

void print_auto(auto_t automobile){
  printf("Make: %s\n", automobile.make);
  printf("Model: %s\n", automobile.model);
  printf("Odometer: %d\n", automobile.odometer);
  printf("Manufactured Date (MM DD YY): ");
  print_date(automobile.manufact);
  printf("Purchased Date (MM DD YY): ");
  print_date(automobile.purchase);
  print_tank(automobile.tank);
}

int main(){
  auto_t automobile;
  while(1){
    int status = scan_auto(&automobile);
    if(status == EOF){
      break;
    }
    if(status == 1){
      print_auto(automobile);
      printf("\n");
    }
  }
  return 0;
}
