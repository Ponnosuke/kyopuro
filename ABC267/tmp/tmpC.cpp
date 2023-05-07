#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const i64 INF = 1e17;

int main() {
    int N, M;
    cin >> N >> M;
    vector<i64> A(N);
    for(auto &x : A)  cin >> x;

    vector<i64>  S(N+1, 0); // 普通の累積和
    for(int i = 0; i < N; i++){
        S.at(i+1) = S.at(i) + A.at(i);
    }

    vector<i64>  U(N+1, 0);  // 添え字をかけた累積和
    for(int i = 0; i < N; i++){
        U.at(i+1) = U.at(i) + (i + 1) * A.at(i);  // A 0-indexed に注意
    }

    i64 ans = -INF;
    for(int i = 0; i <= (N - M); i++){
        i64 tmpU = U.at(i+M) - U.at(i);
        i64 tmpS = S.at(i+M) - S.at(i);
        i64 tmp = tmpU - i * tmpS;
        ans = max(ans , tmp);
    }

    // debug
    // for(auto x : S)  cout << x << endl;

    cout << ans << endl;
}