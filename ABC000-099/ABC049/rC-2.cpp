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

vector<string> TABLE = {"dream", "dreamer", "erase", "eraser"};

int main() {
    string S;
    cin >> S;
    
    int N = S.size();
    vector<bool> dp(N+1, false);
    dp.at(0) = true;
    for(int i = 0; i < N; i++){
        if(dp.at(i)){
            for(int t = 0; t < 4; t++){
                string nowStr = TABLE.at(t);
                int tSize = nowStr.size();
                if(i + tSize <= N){
                    if(S.substr(i, tSize) == nowStr){
                        dp.at(i + tSize) = true;
                    }
                }
            }
        }
    }

    if(dp.at(N)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}