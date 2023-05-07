#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<bool>> flag(N, vector<bool>(N, false));
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        flag.at(u).at(v) = true;
        flag.at(v).at(u) = true;
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            for(int k = j + 1; k < N; k++){
                bool flag1 = flag.at(i).at(j), flag2 = flag.at(j).at(k), flag3 = flag.at(k).at(i);

                if(flag1 && flag2 && flag3)  ans++;
            }
        }
    }

    cout << ans << endl;
}