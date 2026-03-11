#include <stdio.h>
#include <math.h>
const double pi = M_PI;

int main(){
  double radius, slant_height;
  printf("Enter radius of cone: ");
  scanf("%lf", &radius);
  printf("Enter slant height: ");
  scanf("%lf", &slant_height);
  double surface_area = pi*radius*(radius + slant_height);
  printf("Total surface area of right circular cone: %0.2lf", surface_area);
}
