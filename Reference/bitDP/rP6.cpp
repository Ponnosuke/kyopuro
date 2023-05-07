/*
    bitDP

    Q. 白黒に塗り分ける (2) | アルゴ式 
    https://algo-method.com/tasks/1117 

    bitset を使った実装
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
    #define debugP() std::cerr << "Line:" << __LINE__ << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
    #define debugP()
#endif

const int BIT_MAX = 8;
const int INF = (1 << 30);

int main() {
    int M, N;
    cin >> M >> N;
    vector<vector<int>> A(M, vector<int>(N, 0));
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> A.at(i).at(j);
        }
    }

    // 0 := white,  1  :=  black
    vector<bool> isNG(1 << M, false);
    for(int i = 0; i < (1 << M); i++){
        bitset<BIT_MAX> bit(i);
        for(int j = 0; j < M-1; j++){
            if(!bit.test(j) && !bit.test(j+1)){
                isNG.at(i) = true;
            }
        }
    }

    vector<vector<int>> sumColumn(N, vector<int>(1 << M, 0));
    for(int i = 0; i < N; i++){
        for(int p = 0; p < (1 << M); p++){
            if(isNG.at(p)){
                continue;
            }

            bitset<BIT_MAX> bit(p);
            for(int j = 0; j < M; j++){
                if(bit.test(j)){
                    sumColumn.at(i).at(p) += A.at(j).at(i);
                }
            }
        }
    }

    vector<vector<int>> dp(N+1, vector<int>(1 << M, INF));
    int full = (1 << M) - 1;
    dp.at(0).at(full) = 0;
    for(int i = 0; i < N; i++){
        for(int p = 0; p < (1 << M); p++){
            if(isNG.at(p)){
                continue;
            }
            for(int q = 0; q < (1 << M); q++){
                if(isNG.at(q)){
                    continue;
                }
                bitset<BIT_MAX> bitP(p);
                bitset<BIT_MAX> bitQ(q);
                bitset<BIT_MAX> bitPQ = (bitP | bitQ);
                // debugV(p);
                // debugVL(q);
                if((int)bitPQ.count() == M){
                    debugV(p);
                    debugVL(q);
                    dp.at(i+1).at(p) = min(dp.at(i+1).at(p), dp.at(i).at(q) + sumColumn.at(i).at(p));
                }

            }
        }
    }

    int ans = INF;
    for(int p = 0; p < (1 << M); p++){
        ans = min(ans, dp.at(N).at(p));
        debugV(p);
        debugVL(dp.at(N).at(p));
    }

    cout << ans << endl;
}