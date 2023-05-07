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

void dfs(int N, vector<vector<int>> &A, int &ans, vector<bool> &used, int now){

    // debugVL(now);

    int si = -1;
    for(int i = 0; i < 2*N; i++){
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

    for(int j = 0; j < 2*N; j++){
        if(!used.at(j) && si != j){
            used.at(j) = true;
            
            // debugV(si);
            // debugVL(j);

            if(A.at(si).at(j) < 0){
                debugV(si);
                debugVL(j);
            }
            assert(A.at(si).at(j) >= 0);

            dfs(N, A, ans, used, now ^ A.at(si).at(j));
            used.at(j) = false;
        }
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

    vector<bool> used(2*N, false);
    int now = 0;
    int ans = 0;
    dfs(N, A, ans, used, now);

    cout << ans << endl;

    return 0;
}