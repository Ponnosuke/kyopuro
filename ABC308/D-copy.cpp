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

const string TARGET_STR = "snuke";

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S;
    for(int i = 0; i < H; i++){
        cin >> S.at(i);
    }

    vector<vector<bool>> dp(H, vector<bool>(W, false));
    if(S.at(0).at(0) != 's'){
        cout << "No" << endl;

        return 0;
    }

    dp.at(0).at(0) = true;
    for(int i = 0; )
}