#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N;
    cin >> N;
    // vector<i64> A(N, 0);
    map<i64, i64> mp;
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        mp[A]++;
    }

    // sort(A.begin(), A.end());

    // debug
    // for(auto [p, q] : mp){
    //     cout << p << " " << q << endl;
    // }

    int K = N;
    vector<i64> ans(K, 0);
    i64 tmp = mp.size() - 1;
    for(auto [key, cnt] : mp){
        ans.at(tmp) += cnt;
        tmp--;
    }

    for(int i = 0; i < K; i++){
        cout << ans.at(i) << endl;
    }
}