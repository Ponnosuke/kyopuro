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

void dfs(i64 &N, i64 i, vector<vector<i64>> &a, i64 &X, i64 &ans, i64 now){
    if(i == N){
        if(now == X){
            ans++;
        }

        return;
    }

    for(i64 ele : a.at(i)){
        if(now > X/ele){
            continue;
        }

        dfs(N, i+1, a, X, ans, now*ele);
    }

    return;
}

int main() {
    i64 N, X;
    cin >> N >> X;
    vector<vector<i64>> a(N);
    for(i64 i = 0; i < N; i++){
        i64 L;
        cin >> L;
        for(i64 j = 0; j < L; j++){
            i64 ia;
            cin >> ia;
            a.at(i).push_back(ia);
        }
    }

    i64 ans = 0;
    dfs(N, 0, a, X, ans, 1);
    cout << ans << endl;

    return 0;
}