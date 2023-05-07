// This is WA.

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

// O(N^2) ?
// この書き方だと調べきれてないケースが出てくる感じになってそう

int main() {
    i64 N, P, Q, R;
    cin >> N >> P >> Q >> R;

    vector<i64> A(N);
    for(auto &x : A)  cin >> x;

    // 累積和テーブル
    vector<i64> S(N+1);
    for(int i = 0; i < N; i++){
        S.at(i+1) = S.at(i) + A.at(i);
    }

    bool OK1 = false, OK2 = false, OK3 = false;
    int x = 0, y, z, w;
    for(x; x < N-2; x++){
        for(y = x + 1; y < N-1; y++){
            OK1 = ((S.at(y) - S.at(x)) == P);

            if(OK1)  break;
        }

        if(OK1) break;
    }

    for(y; y < N-1; y++){
        for(z = y+1; z < N; z++){
            OK2 = ((S.at(z) - S.at(y)) == Q);

            if(OK2) break;
        }

        if(OK2) break;
    }

    for(z; z < N; z++){
        for(w = z+1; w <= N; w++){
            OK3 = ((S.at(w) - S.at(z)) == R);

            if(OK3) break;
        }

        if(OK3) break;
    }

    bool isPerfect = OK1 && OK2 && OK3;
    cout << (isPerfect ? "Yes" : "No") << endl;
}