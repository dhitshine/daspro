#include <stdio.h>
int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a > b){
        int temp = a;
        a = b;
        b = temp;
    }
    if(a > c){
        int temp = a;
        a = c;
        c = temp;
    }
    if(b > c){
        int temp = b;
        b = c;
        c = temp;
    }
    if((long long)a*a + (long long)b*b <= (long long)c*c){
        printf("Yatta, aku bisa membentuk segitiga!");
    }else{
        printf("Gomenasai, segitiga tidak dapat dibuat.");
    }
    return 0;
}