#include <stdio.h>
#define rho 1.23

void drag_force(double* F, double cd, double A, int v){
  *F = 0.5 * cd * A * rho * v*v;
}

int main(){a\
  double area, coeff, force;
  int velocity;
  printf("Enter projected area (m^2) => ");
  scanf("%lf", &area);
  printf("Enter drag coefficient => ");
  scanf("%lf", &coeff);

  printf("Velocity (m/s)\t\tDrag Force (N)\n");
  for(velocity = 0; velocity <= 40; velocity += 5){
    drag_force(&force, coeff, area, velocity);
    printf("   %d\t\t\t%.2lf\n", velocity, force);
  }
}
