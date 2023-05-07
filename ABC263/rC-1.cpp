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

void dfs(int now, int cnt, int N, int M, vector<int> A){
    A.push_back(now);

    if(cnt == N){
        for(int i = 0; i < N; i++){
            cout << A.at(i);

            if(i < N-1){
                cout << " ";
            }
        }
        cout << '\n';

        return;
    }

    for(int i = now + 1; i <= M; i++){
        dfs(i, cnt + 1, N, M, A);
    }

    return;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A;
    for(int now = 1; now <= M; now++){
        dfs(now, 1, N, M, A);
    }
    
    return 0;
}