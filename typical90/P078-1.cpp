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
    int N, M;
    cin >> N >> M;
    map<int, set<int>> vertex;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        vertex[a].insert(b);
        vertex[b].insert(a);
    }
 
    for(auto &[p,q] : vertex){
        q.insert(0);
        q.insert(N+1);
    }
 
    // debug
    for(auto [p, q] : vertex){
        debug(p);
        debugP("ele = ");
        for(auto ele : q){
            debug(ele);
        }
        debugP();
    }
 
    int ans = 0;
    for(auto [v, s] : vertex){
        auto itr = s.lower_bound(v);
        int d = distance(s.begin(), itr);
 
        // debug
        debug(v);
        debugL(d);
 
        if(d == 2){
            ans++;
        }
    }
 
    cout << ans << endl;
}