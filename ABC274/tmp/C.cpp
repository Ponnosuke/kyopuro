#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    i64 N;
    cin >> N;
    vector<i64> A(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    map<i64, i64> rec;  // rec.at(i)   i の親
    rec[1] = 0;
    for(int i = 1; i <= N; i++){
        rec[2*i] = A.at(i-1);
        rec[2*i + 1] = A.at(i-1);
    }

    // debug
    // for(auto [p, q] : rec){
    //     cerr << p << " " << q << endl;
    // }
    // cerr << "pointA" << '\n';

    vector<i64> ans(2*N + 2, 0);  // ans.at(i)  アメーバi は何代
    // ans.at(1) = 0;
    for(int i = 2; i <= (2*N + 1); i++){
        ans.at(i) = ans.at(rec.at(i)) + 1;
    }

    for(int i = 1; i <= (2*N + 1); i++){
        cout << ans.at(i) << '\n';
    }
}