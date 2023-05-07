#include<stdio.h>

void getValue(int array[], int *max, int *min);

int main(){
    int array[10], max = -3, min = 1000;
    int i = 0;
    do{
        printf("%2d番目の数を入力: ", i+1);
        scanf("%d", &array[i]);
        i++;
    }while(array[i-1] != -1);

    getValue(array, &max, &min);
    printf("Max = %d, min = %d\n", max, min);

    return 0;
}

void getValue(int array[], int *max, int *min){
    int i = 0;
    while(array[i] != -1){
        if(array[i] > *max){
            *max = array[i];
        }
        if(array[i] < *min){
            *min = array[i];
        }
        i++;
    }

    return;
}