#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

void debug_out() { cout << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << H << " ";
  debug_out(T...);
}

#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...) 
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
        debug("p =", p, "ele:");
        for(auto ele : q){
            debug(ele);
        }
    }

    int ans = 0;
    for(auto [v, s] : vertex){
        auto itr = s.lower_bound(v);
        int d = distance(s.begin(), itr);

        // debug
        debug("v =", v, ", d =", d);

        if(d == 2){
            ans++;
        }
    }

    cout << ans << endl;
}