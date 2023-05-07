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

void dfs(i64 v, vector<vector<i64>> &G, i64 cnt, i64 &N, bool &stop, vector<i64> &path){
    debugVL(v);

    if(stop){
        return;
    }
    
    cnt++;
    if(cnt == N){
        stop = true;
        return;
    }


    for(i64 nv : G.at(v)){
        path.at(v) = nv;

        debugVL(path.at(v));

        dfs(nv, G, cnt, N, stop, path);
    }

    return;
}

int main(){
    i64 N, M;
    cin >> N >> M;
    vector<vector<i64>> G(N);
    // [i][j]  :=  i -> j
    i64 iniV = -1;
    map<i64, set<i64>> mp;
    for(int i = 0; i < M; i++){
        i64 X, Y;
        cin >> X >> Y;

        X--;
        Y--;

        if(!mp[X].count(Y)){
            G.at(X).push_back(Y);
            mp[X].insert(Y);
        }
        if(iniV == -1 || iniV == Y){
            iniV = X;
        }
    }

    debugVL(iniV);
    debugP();

    vector<i64> path(N, -1);
    i64 cnt = 0;
    bool stop = false;
    dfs(iniV, G, cnt, N, stop, path);

    debugP();

    if(!stop){
        cout << "No" << '\n';
    }
    else{
        vector<i64> ans(N, 0);
        ans.at(iniV) = 1;
        i64 nowV = iniV;
        i64 num = 2;
        debugP();
        for(int i = 0; i < N-1; i++){
            debugV(nowV + 1);
            debugVL(path.at(nowV) + 1);
            nowV = path.at(nowV);
            ans.at(nowV) = num;
            num++;
        }

        cout << "Yes" << '\n';

        for(int i = 0; i < N; i++){
            cout << ans.at(i);
            if(i < N-1){
                cout << " ";
            }
        }
        cout << '\n';
    }
}