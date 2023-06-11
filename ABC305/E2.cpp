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
    vector<i64> hp_field(N, 0);
    for(int i = 0; i < K; i++){
        cin >> p.at(i) >> h.at(i);
        p.at(i)--;
        isExisted.at(p.at(i)) = true;
        hp_field.at(p.at(i)) = h.at(i);
    }

    debugP();

    // debug
    for(int i = 0; i < N; i++){
        debug(hp_field.at(i));
    }
    debugWL();

    vector<bool> visited(N, false);
    queue<i64> Q;
    
    i64 debug_cnt = 0;

    for(int i = 0; i < K; i++){
        if(visited.at(p.at(i))){
            continue;
        }
        Q.push(p.at(i));
        visited.at(p.at(i)) = true;
        while(!Q.empty()){

            debug_cnt++;
            if(debug_cnt > 100){
                exit(1);
            }

            i64 now = Q.front();

            debugVL(now);

            for(int i = 0; i < N; i++){
                debug(hp_field.at(i));
            }
            debugWL();


            Q.pop();
            for(i64 nxt : G.at(now)){
                hp_field.at(nxt) = max(hp_field.at(nxt), hp_field.at(now) - 1);
                if(hp_field.at(nxt) == 0){
                    visited.at(nxt) = true;
                    continue;
                }
                visited.at(nxt) = true;
                Q.push(nxt);
            }
        }
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