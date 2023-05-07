#include<stdio.h>

enum{
    OLYMPIC_NON,
    OLYMPIC_SUMMER,
    OLYMPIC_WINTER,
};

int olympic(int year){
    if(year < 2000){
        return OLYMPIC_NON;
    }

    year -= 2000;
    if(year % 4 == 0){
        return OLYMPIC_SUMMER;
    }
    else if(year % 2 == 0){
        return OLYMPIC_WINTER;
    }
    else{
        return OLYMPIC_NON;
    }
}

int main(){
    int year = -1;
    printf("Year? : ");
    scanf("%d", &year);

    int flag = olympic(year);

    switch(flag){
        case OLYMPIC_NON:
            printf("hirakarenai\n");
            break;
        case OLYMPIC_SUMMER:
            printf("SUMMER\n");
            break;
        case OLYMPIC_WINTER:
            printf("WINTER\n");
            break;
    };

    return 0;
}