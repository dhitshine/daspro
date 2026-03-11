#include <stdio.h>
#include <math.h>

double compute_acceleration(double initial_velocity, double final_velocity, double time){
  return (double)(final_velocity - initial_velocity) / time;
}
``

int main(){
  double initial_velocity = 200;
  double final_velocity = 150;
  double time = (double)1 / 60; // convert from minute to hour
  double acceleration = compute_acceleration(initial_velocity, final_velocity, time);
  double stop_time = (double)(0 - initial_velocity) / acceleration;
  printf("Acceleration: %.1lf mi/hr^2\nEnd Time: %.lf minutes", acceleration, stop_time * 60);
}
