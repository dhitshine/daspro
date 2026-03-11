#include <stdio.h>

int main(){
    unsigned long long  e, s;
    scanf("%llu %llu", &e, &s);
    if((e & s) == 0){
        printf("hop on roblox!");
    }else{
        printf("we'll try again tomorrow :(");
    }
}