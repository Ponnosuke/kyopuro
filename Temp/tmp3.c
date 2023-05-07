#include<stdio.h>

int main(){
    int water = 198, milk = 138;
    double tax = 1.05;
    int change = 1000 - water*tax - milk*2*tax;
    printf("Change: %d\n", change);
    return 0;
}