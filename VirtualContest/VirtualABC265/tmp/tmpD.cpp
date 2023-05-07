// This is TLE.

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

// O(N^4) ?

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

    bool isPerfect = false;
    for(int x = 0; x < N-2; x++){
        for(int y = x + 1; y < N-1; y++){
            for(int z = y + 1; z < N; z++){
                for(int w = z + 1; w <= N; w++){
                    bool OK1, OK2, OK3;
                    OK1 = (S.at(y) - S.at(x) == P);
                    OK2 = (S.at(z) - S.at(y) == Q);
                    OK3 = (S.at(w) - S.at(z) == R);

                    if(OK1 && OK2 && OK3){
                        isPerfect = true;
                        break;
                    }
                }
                
                if(isPerfect)  break;
            }

            if(isPerfect)  break;
        }

        if(isPerfect)  break;
    }

    cout << (isPerfect ? "Yes" : "No") << endl;
}