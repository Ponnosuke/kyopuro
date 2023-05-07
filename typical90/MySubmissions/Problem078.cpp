#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

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

    int ans = 0;
    for(auto [v, s] : vertex){
        auto itr = s.lower_bound(v);
        int d = distance(s.begin(), itr);

        if(d == 2){
            ans++;
        }
    }

    cout << ans << endl;
}