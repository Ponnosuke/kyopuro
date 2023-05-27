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

const i64 INF = (1LL << 60);

int main() {
    i64 X, Y, Z;
    cin >> X >> Y >> Z;
    string S;
    cin >> S;

    i64 N = S.size();
    vector<vector<i64>> dp(N+1, vector<i64>(2, INF));  // [j] :=  1:ON, 0:OFF

    dp.at(0).at(0) = 0;
    for(int i = 0; i < N; i++){
        if(dp.at(i).at(0) < dp.at(i).at(1)){
            dp.at(i).at(1) = min(dp.at(i).at(1), dp.at(i).at(0) + Z);
        }
        else{
            dp.at(i).at(0) = min(dp.at(i).at(0), dp.at(i).at(1) + Z);
        }

        for(int j = 0; j < 2; j++){
            char nowS = S.at(i);
            if(j == 0){
                if(nowS == 'A'){
                    dp.at(i+1).at(j) = min(dp.at(i+1).at(j), dp.at(i).at(j) + Y);
                }
                else{  // a
                    dp.at(i+1).at(j) = min(dp.at(i+1).at(j), dp.at(i).at(j) + X);
                }
            }
            else{  // 1 : ON
                if(nowS == 'A'){
                    dp.at(i+1).at(j) = min(dp.at(i+1).at(j), dp.at(i).at(j) + X);
                }
                else{  // a
                    dp.at(i+1).at(j) = min(dp.at(i+1).at(j), dp.at(i).at(j) + Y);
                }
            }
        }

    }

    i64 ans = min(dp.at(N).at(0), dp.at(N).at(1));
    cout << ans << '\n';

    return 0;
}