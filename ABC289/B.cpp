#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(M);
    for(int i = 0; i < M; i++){
        cin >> a.at(i);
        a.at(i)--;
    }

    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        G.at(a.at(i)).push_back(a.at(i) + 1);
        G.at(a.at(i) + 1).push_back(a.at(i));
    }

    queue<int> Q;
    vector<bool> seen(N, false);
    for(int i = 0; i < N; i++){
        if(seen.at(i)){
            continue;
        }

        Q.push(i);
        vector<int> order;
        while(!Q.empty()){
            int v = Q.front();
            Q.pop();

            seen.at(v) = true;
            order.push_back(v);
            for(int nv : G.at(v)){
                if(seen.at(nv)){
                    continue;
                }

                Q.push(nv);
            }
        }

        reverse(order.begin(), order.end());

        for(int j = 0; j < order.size(); j++){
            cout << order.at(j) + 1 << " ";
        }
    }
    cout << '\n';
}