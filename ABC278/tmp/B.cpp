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

    // debug
    // cerr << "AB CD" << '\n';
    // cerr << A << B << " " << C << D << '\n';

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

int main() {
    int H, M;
    cin >> H >> M;

    if(isOK(H, M)){
        cout << H << " " << M << '\n';

        return 0;
    }


    while(true){
        M++;
        if(M >= 60){
            M = 0;
            H++;
        }
        if(H >= 24){
            H = 0;
        }

        if(isOK(H, M)){
            cout << H << " " << M << '\n';

            return 0;
        }
    }

    return 0;
}