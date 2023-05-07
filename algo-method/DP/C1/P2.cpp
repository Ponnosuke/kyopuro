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

const int INF = (1 << 30);

int main() {
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    vector<int> dp(N, INF);
    dp.at(0) = 0;
    for(int i = 0; i < N; i++){
        if(i+1 < N){
            dp.at(i+1) = min(dp.at(i+1), dp.at(i) + A.at(i+1));
        }
        if(i+2 < N){
            dp.at(i+2) = min(dp.at(i+2), dp.at(i) + 2*A.at(i+2));
        }
    }

    cout << dp.at(N-1) << endl;
}