#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    int M;
    cin >> M;
    vector<int> B(M);
    for(int i = 0; i < M; i++){
        cin >> B[i];
    }
    int X;
    cin >> X;

    vector<bool> isOK(X+1, true);
    for(int i = 0; i < M; i++){
        isOK[B[i]] = false;
    }

    vector<bool> dp(X+1, false);
    dp[0] = true;
    for(int i = 0; i < X; i++){
        for(int j = 0; j < N; j++){
            if(dp[i]){
                if(i + A[j] <= X){
                    if(isOK[i + A[j]]){
                        dp[i + A[j]] = true;
                    }
                }
            }
        }
    }

    cout << (dp[X] ? "Yes" : "No") << endl;
}