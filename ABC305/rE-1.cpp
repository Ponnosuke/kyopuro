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
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    vector<int> d(N, -1);
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < K; i++){
        int p, h;
        cin >> p >> h;
        p--;
        d.at(p) = h;
        pq.emplace(h, p);
    }

    while(!pq.empty()){
        auto [h, p] = pq.top();
        pq.pop();

        if(d.at(p) != h){
            continue;
        }

        for(int nv : G.at(p)){
            if(d.at(nv) >= h-1){
                continue;
            }

            d.at(nv) = h-1;
            pq.emplace(h-1, nv);
        }
    }

    vector<int> ans;
    for(int i = 0; i < N; i++){
        if(d.at(i) >= 0){
            ans.push_back(i+1);
        }
    }

    cout << (int)ans.size() << '\n';
    for(int i = 0; i < (int)ans.size(); i++){
        cout << ans.at(i);

        if(i < (int)ans.size() - 1){
            cout << " ";
        }
    }
    cout << '\n';
}