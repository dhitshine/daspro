#include <stdio.h>

int fun1(){
    char input;
    printf("Enter 'T' for true or 'F' for false: ");
    scanf(" %c", &input);
    if(input == 'T'){
        return 1;
    }else{
        return 0;
    }
}

int fun2(){
    printf("fun2 executed\n");
    return 1;
}

int main(){
    printf("Testing &&\n");
    if(fun1() && fun2()){
        printf("Test of && complete\n");
    }
    
    printf("Testing ||\n");
    if(fun1() || fun2()){
        printf("Test of || complete\n");
    }
}