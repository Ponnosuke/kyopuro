/*
    bitDP

    Q. 白黒に塗り分ける (2) | アルゴ式 
    https://algo-method.com/tasks/1117 

    右シフトを使う方法
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

    // 0 := white, 1 := black
    vector<bool> isNG(1 << M, false);
    for(int p = 0; p < (1 << M); p++){
        for(int i = 0; i < M-1; i++){
            if(!((p >> i) & 1) && !((p >> (i+1)) & 1)){
                isNG.at(p) = true;
                break;
            }
        }
    }

    vector<vector<int>> sumColumn(N, vector<int>(1 << M, 0));
    for(int i = 0; i < N; i++){
        for(int p = 0; p < (1 << M); p++){
            if(isNG.at(p)){
                continue;
            }

            for(int j = 0; j < M; j++){
                if((p >> j) & 1){
                    sumColumn.at(i).at(p) += A.at(j).at(i);
                }
            }
        }
    }

    debugP();

    vector<vector<int>> dp(N+1, vector<int>(1 << M, INF));
    int full = (1 << M) - 1;
    dp.at(0).at(full) = 0;
    for(int i = 0; i < N; i++){
        debugVL(i);
        for(int p = 0; p < (1 << M); p++){
            if(isNG.at(p)){
                continue;
            }

            debugV(p);

            for(int q = 0; q < (1 << M); q++){
                if(isNG.at(q)){
                    continue;
                }

                debugVL(q);

                if((p|q) == full){
                    dp.at(i+1).at(p) = min(dp.at(i+1).at(p), dp.at(i).at(q) + sumColumn.at(i).at(p));
                }
            }
        }
    }

    debugP();

    int ans = *min_element(dp.at(N).begin(), dp.at(N).end());

    cout << ans << endl;
}