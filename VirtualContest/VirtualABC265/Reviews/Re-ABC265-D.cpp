#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

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

    // A[i] > 0 より、S は単調増加であることに注意する
    set<i64> st;
    for(int i = 0; i <= N; i++){
        st.insert(S.at(i));
    }

    bool OK = false;
    for(int i = 0; i <= N; i++){
        if(st.count(S.at(i) + P) && st.count(S.at(i) + P + Q) && st.count(S.at(i) + P + Q + R))  OK = true;
    }

    cout << (OK ? "Yes" : "No") << endl;
}