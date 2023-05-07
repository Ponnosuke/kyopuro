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
    int T;
    cin >> T;
    
    while(T--){
        int N, M;
        cin >> N >> M;
        vector<int> C(N);
        for(int i = 0; i < N; i++){
            cin >> C[i];
        }

        if(C[0] == C[N-1]){
            cout << -1 << '\n';
            continue;
        }

        vector<int> u(M), v(M);
        for(int i = 0; i < M; i++){
            cin >> u[i] >> v[i];
            u[i]--;
            v[i]--;
        }

        
    }
}