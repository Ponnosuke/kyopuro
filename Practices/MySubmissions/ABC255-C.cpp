#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 X, A, D, N;
    cin >> X >> A >> D >> N;

    if(D < 0){
        X *= -1;
        A *= -1;
        D *= -1;
    }

    i64 minS = A;
    i64 maxS = D * (N - 1) + A;
    i64 ans = 0;
    if(D == 0){
        ans = abs(X - A);
    }
    else if(X < minS){
        ans = minS - X;
    }
    else if(maxS < X){
        ans = X - maxS;
    }
    else{
        i64 remN = (abs(X - A)) % D;
        ans = min(remN, D - remN);
    }

    cout << ans << endl;
}