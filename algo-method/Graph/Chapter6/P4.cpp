#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
  #define debug(X) std::cerr << #X << " = " << X << ", "
  #define debugL(Y) std::cerr << #Y << " = " << Y << '\n'
  #define debugP(Z) std::cerr << #Z << '\n'
#else
  #define debug(X) 3389
  #define debugL(Y) 3390
  #define debugP(Z) 3391
#endif

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    int ans = -2;
    for(int root = 0; root < N; root++){
        vector<int> dist(N, -1);
        queue<int> Q;
        dist.at(root) = 0;
        Q.push(root);
        while(!Q.empty()){
            int v = Q.front();
            Q.pop();
            for(int nv : G.at(v)){
                if(dist.at(nv) != -1){
                    continue;
                }

                dist.at(nv) = dist.at(v) + 1;
                Q.push(nv);
            }
        }

        ans = max(ans, *max_element(dist.begin(), dist.end()));
    }

    cout << ans << endl;
}