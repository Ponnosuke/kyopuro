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
    int N, M, s, t;
    cin >> N >> M >> s >> t;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G.at(a).emplace_back(b);
    }

    vector<bool> seen(N, false);
    vector<int> prev(N, -1);
    queue<int> Q;
    Q.emplace(s);
    seen.at(s) = true;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int nv : G.at(v)){
            if(seen.at(nv)){
                continue;
            }

            seen.at(nv) = true;
            prev.at(nv) = v;
            Q.emplace(nv);
        }
    }

    stack<int> ans;
    int now = t;
    while(now != -1){
        ans.emplace(now);
        now = prev.at(now);
    }

    int ansSize = ans.size();
    cout << ansSize << '\n';
    for(int i = 0; i < ansSize; i++){
        cout << ans.top();
        ans.pop();
        if(i < ansSize - 1){
            cout << " ";
        }
    }
    cout << '\n';

    return 0;
}