#include<stdio.h>

#define TEN 10
#define MyName "PonEnu"

#define PRINT_TEMP printf("temp = %d\n", temp);
#define PRINT_NUM(NUM) printf("%d\n", NUM);

const int TEST = 3389;

enum{
    STATE_NORMAL,
    STATE_POISON,
    STATE_NUMBLY,
    STATE_CURSE,
};

enum{
    ENUM_0,
    ENUM_1,
    ENUM_5 = 5,
    ENUM_6,
    ENUM_7,
    ENUM_9 = 9,
};

int main(){
    printf("Hello, World\n");
    printf("%d!!!!\n", TEST);

    int price;
    price = TEN;
    printf("%d\n", price);
    printf("%s\n", MyName);

    printf("%d %d %d %d %d %d\n", ENUM_0, ENUM_1,ENUM_5,ENUM_6,ENUM_7,ENUM_9);

    int temp = 100;
    PRINT_TEMP;
    temp = 500;
    PRINT_TEMP;

    int a = 100, b = 200;
    PRINT_NUM(a);
    PRINT_NUM(b);

    return 0;
}