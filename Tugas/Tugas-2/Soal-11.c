#include <stdio.h>

int within_x_percent(double ref, double data, double x){
    if(data >= (ref - (x / 100.0) * ref) && data <= (ref + (x / 100.0) * ref)){
        return 1;    
    }else{
        return 0;
    }
}

int main(){
    double temp;
    printf("Enter the observed boiling point in °C: ");
    scanf("%lf", &temp);
    if(within_x_percent(100.0, temp, 5.0)) {
        printf("Substance: Water\n");
    }else if(within_x_percent(357.0, temp, 5.0)){
        printf("Substance: Mercury\n");
    }else if(within_x_percent(1187.0, temp, 5.0)){
        printf("Substance: Copper\n");
    }else if(within_x_percent(2193.0, temp, 5.0)){
        printf("Substance: Silver\n");
    }else if(within_x_percent(2660.0, temp, 5.0)){
        printf("Substance: Gold\n");
    }else{
        printf("Substance unknown\n");
    }
}