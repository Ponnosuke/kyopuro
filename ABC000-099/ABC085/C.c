#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int N, Y;
    scanf("%d %d", &N, &Y);

    int ansX = -1, ansY = -1, ansZ = -1;
    bool OK = false;
    for(int i = 0; i <= N; i++){
        for(int j = 0; i + j <= N; j++){
            int k = N - i - j;

            if(10000*i + 5000*j + 1000*k == Y){
                ansX = i;
                ansY = j;
                ansZ = k;

                OK = true;
                break;
            }
        }

        if(OK){
            break;
        }
    }

    printf("%d %d %d", ansX, ansY, ansZ);
    puts("");

    return 0;
}