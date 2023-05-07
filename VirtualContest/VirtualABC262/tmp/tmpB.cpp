#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> S;
    for(int i = 0 ; i < M; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        S.insert(make_pair(u, v));
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            for(int k = j + 1; k < N; k++){
                pair<int, int> p1 = make_pair(i, j), p2 = make_pair(j, k), p3 = make_pair(i, k);

                if(S.count(p1) && S.count(p2) && S.count(p3))  ans++;
                
                // debug
                // cout << i << j << k << endl;
            }
        }
    }

    cout << ans << endl;
}