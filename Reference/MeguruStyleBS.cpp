/*
* 参照問題: 
* https://atcoder.jp/contests/typical-algorithm/tasks/typical_algorithm_a
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N, K;
    cin >> N >> K;
    vector<i64> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    // めぐる式二分探索の場合、初期値に注意
    i64 right = A.size(); // 常に条件を満たす
    i64 left = -1;   // 常に条件を満たさない
    while(right - left > 1){
        i64 mid = left + (right - left) / 2;
        if(A.at(mid) >= K){
            right = mid;
        }
        else{
            left = mid;
        }
    }

    if(right == A.size()){
        cout << -1 << "\n";
    }
    else{
        cout << right << "\n";
    }

    return 0;
}