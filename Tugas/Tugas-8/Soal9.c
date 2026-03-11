#include <stdio.h>

typedef struct {
  double voltage;
  double max_energy;
  double current_energy;
} battery_t;

void scan_battery(battery_t *battery){
  printf("Enter voltage (V): ");
  scanf("%lf", &battery->voltage);
  printf("Enter max energy (J): ");
  scanf("%lf", &battery->max_energy);
  printf("Enter current energy (J): ");
  scanf("%lf", &battery->current_energy);
}

void print_battery(battery_t battery){
  printf("Voltage: %.2f V\nMax Energy: %.2f J\nCurrent Energy: %.2f J\n", battery.voltage, battery.max_energy, battery.current_energy);
}

int power_device(battery_t *battery, double current, double time){
  double energy_required = battery->voltage * current * time;
  if(energy_required > battery->current_energy){
    return 0;
  }
  battery->current_energy -= energy_required;
  return 1;
}

double max_time(battery_t battery, double current){
  double power = battery.voltage * current;
  if(power == 0){
    return 0.0;
  }
  return battery.current_energy / power;
}

void recharge(battery_t *battery){
  battery->current_energy = battery->max_energy;
}

int main(void){ // no input required, using simulation on problem statement
  battery_t battery = {12.0, 5000000.0, 5000000.0};
  if(!power_device(&battery, 4.0, 900.0)) {
    printf("Insufficient energy for 4A device\n");
    return 1;
  }else{
    printf("Sufficient energy for 4A device\n");
  }
  double time_8a = max_time(battery, 8.0);
  printf("Remaining energy powers 8A device for: %.2f seconds\n", time_8a);
  recharge(&battery);
  time_8a = max_time(battery, 8.0);
  printf("After recharge, 8A device runtime: %.2f seconds\n", time_8a);
}
