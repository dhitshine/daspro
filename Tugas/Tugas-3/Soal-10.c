#include <stdio.h>
#define R_constant 0.08206
#define b_constant 0.0427
#define a_constant 3.592
#define mL_to_L 0.001

int main(){
  printf("Please enter at the prompts the number of moles of carbon dioxide, the absolute temperature, the initial volume in milliliters, the final volume, and the increment volume between lines of the table.\n\n");
  double moles, temp, v_initial, v_final, v_inc;

  printf("Quantity of carbon dioxide (moles) > ");
  scanf("%lf", &moles);
  printf("Temperature (kelvin) > ");
  scanf("%lf", &temp);
  printf("Initial volume (milliliters) > ");
  scanf("%lf", &v_initial);
  printf("Final volume (milliliters) > ");
  scanf("%lf", &v_final);
  printf("Volume increment (milliliters) > ");
  scanf("%lf", &v_inc);

  printf("\n%.4lf moles of carbon dioxide at %.lf kelvin\n\n", moles, temp);
  printf("Volume (ml) \t Pressure (atm)\n\n");

  while(v_initial <= v_final){
    double pressure = (moles * R_constant * temp) / (v_initial * mL_to_L - b_constant * moles);
    pressure -= (a_constant * moles * moles) / (v_initial * mL_to_L * v_initial * mL_to_L);
    printf("    %.lf \t     %.4lf\n", v_initial, pressure);
    v_initial += v_inc;
  }
}
