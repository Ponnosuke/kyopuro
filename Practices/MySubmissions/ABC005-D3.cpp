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

    vector<int> rectMaxs(N*N+1, -INF);  // rectMaxs.at(v)  長方形の面積が v のときの美味しさの最大値
    for(int x1 = 0; x1 < N; x1++){
        for(int x2 = x1 + 1; x2 <= N; x2++){
            for(int y1 = 0; y1 < N; y1++){
                for(int y2 = y1 + 1; y2 <= N; y2++){
                    int area = (x2 - x1) * (y2 - y1);
                    int tmp = S.at(x2).at(y2) - S.at(x1).at(y2) - S.at(x2).at(y1) + S.at(x1).at(y1);
                    rectMaxs.at(area) = max(rectMaxs.at(area), tmp);
                }
            }
        }
    }

    // rectMaxs を 長方形の面積が v 以下の時の美味しさの最大値に変更
    for(int i = 0; i < N*N; i++){
        rectMaxs.at(i+1) = max(rectMaxs.at(i), rectMaxs.at(i+1));
    }

    for(int i = 0; i < Q; i++){
        cout << rectMaxs.at(P.at(i)) << endl;
    }


}