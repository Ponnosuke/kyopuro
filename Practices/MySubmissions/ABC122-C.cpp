#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    vector<int> isAC(N, 0);  // 1 true, 0 false
    for(int i = 1; i < N; i++){
        if((S.at(i) == 'C') && (S.at(i-1) == 'A'))  isAC.at(i) = 1;
    }
    // 左に A が存在する C の番号をメモしたフラグ

    // 累積和
    vector<int> SC(N+1, 0);  // [0, i) に 左に A がある C の出現回数
    for(int i = 0; i < N; i++){
        SC.at(i+1) = SC.at(i) + isAC.at(i);
    }

    // debug
    // for(int i = 0; i < N; i++)  cout << "isAC[" << i << "] = " << isAC.at(i) << endl;
    // for(int i = 0; i < N+1; i++) cout << "SC[" << i << "] = " << SC.at(i) << endl;

    // CGA|CAGCAC|CCAA  のようなときの C をカウントしないように [l+1, r+1) (0-indexed) で考える
    for(int i = 0; i < Q; i++){
        int l, r;
        cin >> l >> r;
        cout << SC.at(r) - SC.at(l) << endl;
    }

    return 0;
}