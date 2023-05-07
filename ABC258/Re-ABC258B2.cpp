#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

vector<int> dx = {0,1,1,1,0,-1,-1,-1};
vector<int> dy = {1,1,0,-1,-1,-1,0,1};

int main() {
    i64 N;
    cin >> N;
    
    vector<vector<i64>> A(N, vector<i64>(N));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            char c;
            cin >> c;
            A.at(i).at(j) = c - '0';  // キャストしなくてオッケー
        }
    }

    i64 ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < 8 ; k++){
                i64 now = 0;
                int x = j, y = i;
                for(int m = 0; m < N; m++){
                    now *= 10;
                    now += A.at(y).at(x);

                    x += dx.at(k);
                    y += dy.at(k);
                    x = (x + N) % N;
                    y = (y + N) % N;
                }

                ans = max(ans, now);
            }
        }
    }

    cout << ans << endl;


}