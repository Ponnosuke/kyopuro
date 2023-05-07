#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 maxA = 200;

int main() {
    i64 N;
    cin >> N;

    vector<i64> cnt(401, 0);
    for(i64 i = 0; i < N; i++){
        i64 tmpA;
        cin >> tmpA;
        
        tmpA += maxA;

        cnt.at(tmpA)++;
    }

    i64 ans = 0;
    for(i64 i = 0; i <= 400; i++){
        for(i64 j = i + 1; j <= 400; j++){
            i64 ai = i - maxA, aj = j - maxA;
            ans += (ai - aj)*(ai - aj) * cnt.at(i) * cnt.at(j);
        }
    }

    cout << ans << endl;
}