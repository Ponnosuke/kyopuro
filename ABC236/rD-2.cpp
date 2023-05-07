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

void dfs(int N, vector<vector<int>> &A, int state, int now, int &ans){

    debugV(N);
    debugVL(now);

    if(state == (1 << (2*N)) - 1){
        ans = max(ans, now);
        return;
    }

    int si = 0;
    for(int i = 0; i < 2*N; i++){
        if((state >> i) & 1){
            continue;
        }

        si = i;
        break;
    }

    for(int j = 0; j < 2*N; j++){
        if(j == si || ((state >> j) & 1)){
            continue;
        }

        debugV(si);
        debugVL(j);

        dfs(N, A, state | (1 << si) | (1 << j), now ^ A.at(si).at(j), ans);
    }

    return;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(2*N, vector<int>(2*N, -1));
    for(int i = 0; i < 2*N; i++){
        for(int j = i+1; j < 2*N; j++){
            cin >> A.at(i).at(j);
            A.at(j).at(i) = A.at(i).at(j);
        }
    }

    int ans = 0;
    dfs(N, A, 0, 0, ans);

    cout << ans << endl;

    return 0;
}