#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 INF = 1e15;

int main() {
    i64 N, L, R;
    cin >> N >> L >> R;

    vector<i64> A(N+1);
    for(int i = 1; i <= N; i++) cin >> A.at(i);

    vector<i64> Lmin(N+1, 0), Rmin(N+1, 0);

    for(int i = 0; i < N; i++){
        Lmin.at(i+1) = min(Lmin.at(i) + A.at(i+1), L*(i+1));
        Rmin.at(i+1) = min(Rmin.at(i) + A.at(N-i), R*(i+1));
    }

    // debug
    // for(int i = 0; i <= N; i++) cout << "Lmin.at(" << i << ") = " << Lmin.at(i) << endl;
    // for(int i = 0; i <= N; i++) cout << "Rmin.at(" << i << ") = " << Rmin.at(i) << endl;

    i64 ans = INF;
    for(int i = 0; i <= N; i++) ans = min(ans, Lmin.at(i) + Rmin.at(N-i));

    // debug
    // for(int i = 0; i <= N; i++) cout << "i = " << i << ", min = " << Lmin.at(i) + Rmin.at(N-i) << endl;

    cout << ans << endl;
}