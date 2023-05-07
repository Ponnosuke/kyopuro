#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    // 右に C が存在する A の位置をメモしたフラグ
    vector<int> isAC(N, 0);  // 1 true, 0 false
    for(int i = 0; i < N-1; i++){
        if((S.at(i) == 'A') && (S.at(i+1) == 'C'))  isAC.at(i) = 1;
    }
    

    // 累積和
    vector<int> SC(N+1, 0);  // [0, i) に右に C がある A が何回出現したか
    for(int i = 0; i < N; i++){
        SC.at(i+1) = SC.at(i) + isAC.at(i);
    }

    // CGA|CAGCAA|CCAA  のようなときの A をカウントしないように [l, r) (0-indexed) で考える
    for(int i = 0; i < Q; i++){
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << SC.at(r) - SC.at(l) << endl;
    }

    return 0;
}