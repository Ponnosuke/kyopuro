/*
    ABC309 E

    配るDPの解法
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
    for(int i = 1; i < N; i++){
        cin >> p.at(i);
        p.at(i)--;
        children.at(p.at(i)).push_back(i);
    }
    vector<int> x(M), y(M);
    vector<int> dp(N, -1);
    for(int i = 0; i < M; i++){
        cin >> x.at(i) >> y.at(i);
        x.at(i)--;

        dp.at(x.at(i)) = max(dp.at(x.at(i)), y.at(i));
    }

    // 配るDP
    for(int i = 0; i < N; i++){
        for(int nxt : children.at(i)){
            dp.at(nxt) = max(dp.at(nxt), dp.at(i) - 1);
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(dp.at(i) >= 0){
            ans++;
        }
    }

    cout << ans << endl;
}