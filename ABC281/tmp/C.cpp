#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N, T;
    cin >> N >> T;
    vector<i64> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    vector<i64> sA(N+1, 0);
    for(int i = 0; i < N; i++){
        sA.at(i+1) = A.at(i) + sA.at(i);
    }

    i64 sumA = sA.at(N);
    i64 nowT = (T % sumA);

    i64 index = 0, ans = 0;
    for(int i = 0; i < N; i++){
        if(sA.at(i) < nowT && nowT < sA.at(i+1)){
            index = i + 1;
            ans = nowT - sA.at(i);
        }
    }

    cout << index << " " << ans << '\n';

    // i64 sumA = 0;
    // for(auto num : A){
    //     sumA += num;
    // }

    // i64 nowT = (T % sumA);
}