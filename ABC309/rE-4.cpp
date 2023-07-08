/*
    ABC309 E

    トポロジカルソートをして有向グラフ的に保証されている順番にする (今回は p の制約でやる必要はない)
    その順番ごとにDP値を更新していく
*/

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

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> p(N, 0);
    vector<vector<int>> children(N);
    vector<int> in_dig(N, 0);
    for(int i = 1; i < N; i++){
        cin >> p.at(i);
        p.at(i)--;
        children.at(p.at(i)).push_back(i);
        in_dig.at(i)++;
    }
    vector<int> x(M), y(M);
    vector<int> dp(N, -1);
    for(int i = 0; i < M; i++){
        cin >> x.at(i) >> y.at(i);
        x.at(i)--;

        dp.at(x.at(i)) = max(dp.at(x.at(i)), y.at(i));
    }

    queue<int> Q;
    for(int i = 0; i < N; i++){
        if(in_dig.at(i) == 0){
            Q.push(i);
        }
    }

    debugP();

    vector<int> target;
    while(!Q.empty()){
        int v = Q.front();
        target.push_back(v);
        Q.pop();

        for(int nv : children.at(v)){
            in_dig.at(nv)--;
            if(in_dig.at(nv) == 0){
                Q.push(nv);
            }
        }
    }

    debugP();

    for(int idx = 0; idx < N; idx++){
        int now = target.at(idx);

        dp.at(now) = max(dp.at(now), dp.at(p.at(now)) - 1);
    }

    debugP();

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(dp.at(i) >= 0){
            ans++;
        }
    }

    cout << ans << endl;
}