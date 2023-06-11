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

void dfs(i64 now, i64 hp, vector<i64> &h, vector<bool> &isExisted, vector<bool> &visited, vector<vector<i64>> &G){

    debugVL(now);

    if(hp <= 0){{
        return;
    }}

    for(i64 nxt : G.at(now)){
        if(visited.at(nxt)){
            continue;
        }

        visited.at(nxt) = true;

        debugVL(nxt);

        if(isExisted.at(nxt)){

            debugP();

            if(hp - 1 > h.at(nxt)){
                dfs(nxt, hp - 1, h, isExisted, visited, G);
            }
            else{
                dfs(nxt, h.at(nxt), h, isExisted, visited, G);
            }
        }
        else{

            debugP();

            dfs(nxt, hp - 1, h, isExisted, visited, G);
        }
    }

    return;
}

int main() {
    i64 N, M, K;
    cin >> N >> M >> K;
    vector<vector<i64>> G(N);
    for(int i = 0; i < M; i++){
        i64 a, b;
        cin >> a >> b;
        a--;
        b--;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }
    vector<i64> p(K), h(K);
    vector<bool> isExisted(N, false);
    vector<i64> p_hp(N, -1);
    for(int i = 0; i < K; i++){
        cin >> p.at(i) >> h.at(i);
        p.at(i)--;
        isExisted.at(p.at(i)) = true;
        p_hp.at(p.at(i)) = h.at(i);
    }

    debugP();

    vector<bool> visited(N, false);
    for(int i = 0; i < K; i++){
        if(visited.at(p.at(i))){
            continue;
        }
        visited.at(p.at(i)) = true;

        dfs(p.at(i), h.at(i), p_hp, isExisted, visited, G);
    }


    debugP();

    i64 ans_G = 0;
    vector<i64> ans_v;
    for(int i = 0; i < N; i++){
        if(visited.at(i)){
            ans_G++;
            ans_v.push_back(i+1);
        }
    }

    debugP();

    cout << ans_G << '\n';
    for(int i = 0; i < ans_v.size(); i++){
        cout << ans_v.at(i);

        if(i < N-1){
            cout << " ";
        }
    }
    cout << '\n';

    return 0;
}