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

    int r = 0;
    vector<int> dist1(N, -1);
    queue<int> Q;
    dist1.at(r) = 0;
    Q.push(r);
    debugL(r);
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int nv : G.at(v)){
            if(dist1.at(nv) != -1){
                continue;
            }

            dist1.at(nv) = dist1.at(v) + 1;
            Q.push(nv);
        }
    }

    r = distance(dist1.begin(), max_element(dist1.begin(), dist1.end()));
    debugL(r);
    vector<int> dist2(N, -1);
    dist2.at(r) = 0;
    Q.push(r);
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int nv : G.at(v)){
            if(dist2.at(nv) != -1){
                continue;
            }

            dist2.at(nv) = dist2.at(v) + 1;
            Q.push(nv);
        }
    }

    int ans = *max_element(dist2.begin(), dist2.end());
    cout << ans << endl;
}