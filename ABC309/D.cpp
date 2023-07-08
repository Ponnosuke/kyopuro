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
    i64 N1, N2, M;
    cin >> N1 >> N2 >> M;
    vector<vector<i64>> G(N1+N2);
    for(int i = 0; i < M; i++){
        i64 a, b;
        cin >> a >> b;
        a--;
        b--;

        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    vector<i64> dist_from_0(N1+N2, -1), dist_from_N1N2(N1+N2, -1);
    queue<i64> Q;
    Q.push(0);
    dist_from_0.at(0) = 0;
    while(!Q.empty()){
        i64 v = Q.front();
        Q.pop();

        for(i64 nv : G.at(v)){
            if(dist_from_0.at(nv) != -1){
                continue;
            }

            dist_from_0.at(nv) = dist_from_0.at(v) + 1;
            Q.push(nv);
        }
    }

    Q.push(N1+N2-1);
    dist_from_N1N2.at(N1+N2-1) = 0;
    while(!Q.empty()){
        i64 v = Q.front();
        Q.pop();

        for(i64 nv : G.at(v)){
            if(dist_from_N1N2.at(nv) != -1){
                continue;
            }

            dist_from_N1N2.at(nv) = dist_from_N1N2.at(v) + 1;
            Q.push(nv);
        }
    }

    i64 max_from_0 = -1, max_from_N1N2 = -1;
    for(int i = 0; i < N1; i++){
        max_from_0 = max(max_from_0, dist_from_0.at(i));
    }
    for(int i = N1; i < N1+N2; i++){
        max_from_N1N2 = max(max_from_N1N2, dist_from_N1N2.at(i));
    }

    cout << max_from_0 + max_from_N1N2 + 1 << endl;
}