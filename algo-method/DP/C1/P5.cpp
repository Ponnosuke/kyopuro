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
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    vector<int> dp(N, INF);
    dp.at(0) = 0;
    for(int i = 1; i < N; i++){
        for(int j = 1; j <= M; j++){
            if(i-j < 0){
                break;
            }

            dp.at(i) = min(dp.at(i), dp.at(i-j) + j*A.at(i));
        }
    }

    cout << dp.at(N-1) << endl;
}