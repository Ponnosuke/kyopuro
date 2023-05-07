#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
    #define debugP() std::cerr << "Line:" << __LINE__ << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
    #define debugP()
#endif

const int INF = (1 << 30);

int main() {
    int N;
    cin >> N;
    vector<int> A(N-1);
    for(int i = 0; i < N-1; i++){
        cin >> A.at(i);
    }
    vector<int> B(N-2);
    for(int i = 0; i < N-2; i++){
        cin >> B.at(i);
    }

    vector<int> dp(N, INF);
    dp.at(0) = 0;
    for(int i = 0; i < N; i++){

        debugVL(i);

        if(i+1 < N){
            dp.at(i+1) = min(dp.at(i+1), dp.at(i) + A.at(i));
        }
        if(i+2 < N){
            dp.at(i+2) = min(dp.at(i+2), dp.at(i) + B.at(i));
        }
    }

    cout << dp.at(N-1) << endl;
}