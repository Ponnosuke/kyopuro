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

void dfs(i64 N, vector<vector<i64>> &A, i64 &ans, vector<bool> &used, i64 now){

    // debugVL(now);

    i64 si = -1;
    for(i64 i = 0; i < 2*N; i++){
        if(!used.at(i)){
            si = i;
            used.at(si) = true;
            break;
        }
    }
    if(si == -1){
        ans = max(ans, now);
        debugVL(ans);
        return;
    }

    for(i64 j = 0; j < 2*N; j++){
        if(!used.at(j) && si != j){
            used.at(j) = true;
            
            debugV(si);
            debugVL(j);

            if(A.at(si).at(j) < 0){
                debugV(si);
                debugVL(j);
            }
            assert(A.at(si).at(j) >= 0);

            dfs(N, A, ans, used, now ^ A.at(si).at(j));
            used.at(j) = false;
        }
    }

    used.at(si) = false;  // ここを忘れると上手く全部を探索してくれない

    return;
}

int main() {
    i64 N;
    cin >> N;
    vector<vector<i64>> A(2*N, vector<i64>(2*N, 0));
    for(i64 i = 0; i < 2*N; i++){
        for(i64 j = i+1; j < 2*N; j++){
            cin >> A.at(i).at(j);
            A.at(j).at(i) = A.at(i).at(j);
        }
    }

    vector<bool> used(2*N, false);
    i64 now = 0;
    i64 ans = 0;
    dfs(N, A, ans, used, now);

    cout << ans << endl;

    return 0;
}