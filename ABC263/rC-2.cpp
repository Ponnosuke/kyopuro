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

void dfs(int N, int M, vector<int> &A, int now){
    if((int)A.size() == N){
        for(int i = 0; i < N; i++){
            cout << A.at(i);

            if(i < N-1){
                cout << " ";
            }
        }
        cout << '\n';

        return;
    }

    for(int nxt = now + 1; nxt <= M; nxt++){
        A.push_back(nxt);
        dfs(N, M, A, nxt);
        A.pop_back();
    }

    return;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A;
    dfs(N, M, A, 0);

    return 0;
}