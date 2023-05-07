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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    for(int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        graph.at(A).push_back(B);
        graph.at(B).push_back(A);
    }

    vector<int> dist(N, -1);
    queue<int> Q;
    Q.push(0);
    dist.at(0) = 0;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int nv : graph.at(v)){
            if(dist.at(nv) != -1){
                continue;
            }

            Q.push(nv);
            dist.at(nv) = dist.at(v) + 1;
        }
    }

    int ans = -1;
    for(int i = 0; i < N; i++){
        ans = max(ans, dist.at(i));
    }

    cout << ans << endl;
}