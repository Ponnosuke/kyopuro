#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << #X << " = " << X << ", "
    #define debugL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugP(Z) std::cerr << #Z << '\n'
#else
    #define debug(X) 3389
    #define debugL(Y) 3390
    #define debugP(Z) 3391
#endif

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<int> dp(N, 0);
    dp.at(0) = X;
    dp.at(1) = Y;
    for(int i = 2; i < N; i++){
        dp.at(i) = (dp.at(i-1) + dp.at(i-2)) % 100;
    }

    cout << dp.at(N-1) << endl;
}