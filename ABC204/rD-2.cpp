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

int main() {
    int N;
    cin >> N;
    vector<int> T(N, 0);
    int sum = 0;
    for(int i = 0; i < N; i++){
        int iT;
        cin >> iT;

        T.at(i) = iT;
        sum += iT;
    }

    vector<vector<bool>> dp(N+1, vector<bool>(sum + 1, false));
    dp.at(0).at(0) = true;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= sum; j++){
            if(dp.at(i).at(j)){
                dp.at(i+1).at(j) = true;
                dp.at(i+1).at(j+T.at(i)) = true;
            }
        }
    }

    int ans = sum;
    int lower = (sum + 1)/2;
    for(int i = lower; i <= sum; i++){
        if(dp.at(N).at(i)){
            ans = i;
            break;
        }
    }

    cout << ans << '\n';
}