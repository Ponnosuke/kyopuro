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
        cin >> A.at(i);
    }
    int M;
    cin >> M;
    set<int> B;
    for(int i = 0; i < M; i++){
        int iB;
        cin >> iB;
        B.insert(iB);
    }
    int X;
    cin >> X;

    vector<bool> dp(X+1, false);
    dp.at(0) = true;
    int Bindex = 0;
    for(int i = 0; i < X; i++){
        for(int j = 0; j < N; j++){
            if(dp[i]){
                if(B.count(i + A[j])){
                    continue;
                }

                if(i + A[j] <= X){
                    dp[i + A[j]] = true;
                }
            }
        }
    }

    if(dp.at(X)){
        cout << "Yes" << '\n';
    }
    else{
        cout << "No" << '\n';
    }
}