#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    vector<i64> A(N);
    for(auto &x : A) cin >> x;

    // 累積和
    vector<i64> S(N+1, 0);
    for(int i = 0; i < N; i++){
        S.at(i+1) = S.at(i) + A.at(i);
    }

    map<i64, i64> nums;
    for(auto x : S){
        nums[x]++;
    }

    i64 ans = 0;
    for(auto mp : nums){
        i64 n = mp.second;
        ans += (n * (n-1)) / 2;
    }

    cout << ans << endl;

    return 0;
}