#include<stdio.h>

enum{
    IS_HELD,
    ISNT_HELD,
};

int isHeld(int year){
    if(year < 2000){
        return ISNT_HELD;
    }
    else{
        if(year % 2 == 0){
            return IS_HELD;
        }
        else{
            return ISNT_HELD;
        }
    }
}

int main(){
    int year = -1;
    printf("Year? : ");
    scanf("%d", &year);

    int flag = isHeld(year);
    if(flag == IS_HELD){
        printf("%d is the year that Olympic is held!!\n", year);
    }
    else{
        printf("%d is the year that Olympic isn't held!!\n", year);
    }

    return 0;
}