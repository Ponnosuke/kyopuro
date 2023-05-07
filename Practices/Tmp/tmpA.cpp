#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int A, B, C, D, E, F, X;
    cin >> A >> B >> C >> D >> E >> F >> X;

    int ACnt = 0, DCnt = 0;
    int tmpX = X;
    while(tmpX > 0){
        ACnt += min(tmpX, A);
        tmpX -= A;
        tmpX -= C;
    }
    tmpX = X;
    while(tmpX > 0){
        DCnt += min(tmpX, D);
        tmpX -= D;
        tmpX -= F;
    }

    int tDist, aDist;
    tDist = B * ACnt;
    aDist = E * DCnt;

    if(tDist > aDist){
        cout << "Takahashi" << endl;
    }
    else if(tDist < aDist){
        cout << "Aoki" << endl;
    }
    else{
        cout << "Draw" << endl;
    }
}