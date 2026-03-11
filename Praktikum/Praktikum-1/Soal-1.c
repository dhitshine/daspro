#include <stdio.h>
#include <math.h>
#define pi M_PI
int main(){
    double x1, y1, x2, y2, theta1;
    scanf("%lf %lf %lf %lf %lf", &x1, &y1, &theta1, &x2, &y2);
    double theta2 = atan2(y2 - y1, x2 - x1);
    if(x1 == x2 && y1 == y2){
        printf("Halo, Dan, aku Iel.");
        return 0;
    }
    double atan_funct = atan(INFINITY);
    printf("theta2: %lf\n", atan_funct);
    double angle = fabs(theta1 - theta2);
    if(angle > pi){
        angle = 2 * pi - angle; //periodik
    }
    if(angle < 0.01){
        printf("Aku akan berjalan lurus ke Dan!");
    }else{
        printf("Aku akan berputar ke arah tujuan!");
    }
    return 0;
}
