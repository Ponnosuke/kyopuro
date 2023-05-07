#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const int MODHOUR = 24;
const int MODMIN = 60;

bool isOK(int hour, int minute){
    int A, B, C, D;
    A = hour / 10;
    B = hour % 10;
    C = minute / 10;
    D = minute % 10;

    swap(B, C);
    hour = A*10 + B;
    minute = C*10 + D;

    bool OK1 = false, OK2 = false;
    if(0 <= hour && hour < 24){
        OK1 = true;
    }
    if(0 <= minute && minute < 60){
        OK2 = true;
    }

    return OK1 && OK2;
}

pair<int, int> solve1(int H, int M){
    if(isOK(H, M)){
        return make_pair(H, M);
    }

    for(int i = 0; i < 24; i++){
        H++;
        H %= MODHOUR;
        for(int j = 0; j < 60; j++){
            M++;
            M %= MODMIN;

            if(isOK(H, M)){
                return make_pair(H, M);
            }
        }
    }

    return make_pair(-3390, -3390);
}

bool isOK2(int h, int m){
    
}

pair<int, int> solve2(int H, int M){

}

int main() {
}