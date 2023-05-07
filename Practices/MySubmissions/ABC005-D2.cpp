// TLE

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

const int INF = 1e8;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> D(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> D.at(i).at(j);
        }
    }
    int Q;
    cin >> Q;
    vector<int> P(Q);
    for(auto &x : P)  cin >> x;

    // 累積和
    vector<vector<int>> S(N+1, vector<int>(N+1));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            S.at(i+1).at(j+1) = S.at(i).at(j+1) + S.at(i+1).at(j) - S.at(i).at(j) + D.at(i).at(j);
        }
    }

    for(int index = 0; index < Q; index++){
        int k = P.at(index);
        int ans = -INF;
        
        for(int kX = 1; kX <= k; kX++){
            for(int kY = 1; kY*kX <= k; kY++){
                for(int i = 0; i + kX <= N; i++){
                    for(int j = 0; j + kY <= N; j++){
                        int tmp = S.at(i+kX).at(j+kY) - S.at(i).at(j+kY) - S.at(i+kX).at(j) + S.at(i).at(j);
                        ans = max(ans, tmp);
                    }
                }
            }
        }
        
        cout << ans << endl;
    }
}