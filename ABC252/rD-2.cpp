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
    i64 N;
    cin >> N;
    vector<i64> A(N, 0);
    map<i64, i64> mp;
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
        mp[A.at(i)]++;
    }

    vector<vector<i64>> dp((int)mp.size() + 1, vector<i64>(4, 0));
    dp.at(0).at(0) = 1;
    int i = 0;

    debugP();

    for(auto [val, cnt] : mp){
        debugVL(i);
        for(int j = 0; j < 4; j++){
            debugV(i);
            debugVL(j);
            dp.at(i+1).at(j) = dp.at(i).at(j);
        }
        debugP();
        for(int j = 0; j < 3; j++){
            debugV(i);
            debugVL(j);
            dp.at(i+1).at(j+1) += dp.at(i).at(j)*cnt;
        }
        debugP();
        i++;
    }

    cout << dp.at((int)mp.size()).at(3) << endl;
}