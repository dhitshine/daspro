#include <stdio.h>

void get_rate_drop_factor(double* rate, double* drop_factor){
    printf("Enter rate in ml/hr=> ");
    scanf("%lf", rate);
    printf("Enter tubing's drop factor(drops/ml)=> ");
    scanf("%lf", drop_factor);
}

void get_kg_rate_conc(double* rate, double* weight, double* concentration){
    printf("Enter rate in mg/kg/hr=> ");
    scanf("%lf", rate);
    printf("Enter patient weight in kg=> ");
    scanf("%lf", weight);
    printf("Enter concentration in mg/ml=> ");
    scanf("%lf", concentration);
}

void get_units_conc(double* rate, double* concentration){
    printf("Enter rate in units/hr=> ");
    scanf("%lf", rate);
    printf("Enter concentration in units/ml=> ");
    scanf("%lf", concentration);
}

int fig_drops_min(double rate, double drop_factor){
    rate /= 60;
    return (rate * drop_factor) + 0.5;
}

int fig_ml_hr(double hours){
    return (1000 / hours) + 0.5;
}

int by_weight(double rate, double weight, double concentration){
    return ((rate * weight) / concentration) + 0.5;
}

int by_units(double rate, double concentration){
    return  (rate / concentration) + 0.5;
}

void get_problem(int* problem){ 
    printf("INTRAVENOUS RATE ASSISTANT\n\n");
    printf("Enter the number of the problem you wish to solve.\n");
    printf("\tGIVEN A MEDICAL ORDER IN\t\tCALCULATE RATE IN\n");
    printf("(1) ml/hr & tubing drop factor\t\t\tdrops / min\n");
    printf("(2) 1 L for n hr\t\t\t\tml / hr\n");
    printf("(3) mg/kg/hr & concentration in mg/ml\t\tml / hr\n");
    printf("(4) units/hr & concentration in units/ml\tml / hr\n");
    printf("(5) QUIT\n\n");
    printf("Problem> ");
    scanf("%d", problem);
}

int main(){
    int problem;
    get_problem(&problem);
    while(problem != 5){
        if(problem == 1){
            double rate, drop_factor;
            get_rate_drop_factor(&rate, &drop_factor);
            int drop_rate = fig_drops_min(rate, drop_factor);
            printf("The drop rate per minute is %d.\n\n", drop_rate);
        }else if(problem == 2){
            int hours;
            printf("Enter number of hours=> ");
            scanf("%d", &hours);
            int ml_rate = fig_ml_hr(hours);
            printf("The rate in milliliters per hour is %d.\n\n", ml_rate);
        }else if(problem == 3){
            double rate, weight, concentration;
            get_kg_rate_conc(&rate, &weight, &concentration);
            int ml_rate = by_weight(rate, weight, concentration);
            printf("The rate in milliliters per hour is %d.\n\n", ml_rate);
        }else if(problem == 4){
            double rate, concentration;
            get_units_conc(&rate, &concentration);
            int ml_rate = by_units(rate, concentration);
            printf("The rate in milliliters per hour is %d.\n\n", ml_rate);
        }
        get_problem(&problem);
    }
    return 0;
}

/*
isi var problem adalah memori address dari si input <-> int* problem = &input
artinya problem -> memori address dan *problem (deferences) adalah value dari si input
*/ 
