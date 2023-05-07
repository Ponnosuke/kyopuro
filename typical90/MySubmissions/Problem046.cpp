#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const int MOD = 46;

int main() {
    i64 N;
    cin >> N;
    vector<i64> A(N), B(N), C(N);
    for(auto &x : A)  cin >> x;
    for(auto &x : B)  cin >> x;
    for(auto &x : C)  cin >> x;

    vector<i64> cntA(MOD, 0), cntB(MOD, 0), cntC(MOD, 0);
    for(i64 i = 0; i < N; i++){
        cntA.at(A.at(i) % MOD)++;
        cntB.at(B.at(i) % MOD)++;
        cntC.at(C.at(i) % MOD)++;
    }

    i64 ans = 0;
    for(i64 i = 0; i <= 45; i++){
        for(i64 j = 0; j <= 45; j++){
            for(i64 k = 0; k <= 45; k++){
                if((i + j + k) % MOD == 0){
                    ans += cntA.at(i) * cntB.at(j) * cntC.at(k);
                }
            }
        }
    }

    cout << ans << endl;
}