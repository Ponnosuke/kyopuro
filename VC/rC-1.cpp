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

const string TABLE = "atcoder";

int main() {
    string S;
    cin >> S;
    vector<int> num(TABLE.size(), 0);
    for(int i = 0; i < S.size(); i++){
        char now = S.at(i);
        for(int j = 0; j < TABLE.size(); j++){
            if(now == TABLE.at(j)){
                num.at(i) = j;
            }
        }
    }

    int N = S.size();

    // debug
    for(int d = 0; d < N; d++){
        debug(num.at(d));
    }
    debugWL();

    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N-1-i; j++){
            string debug_str = "NOT_CHANGE";
            if(num.at(j) > num.at(j+1)){
                swap(num.at(j+1), num.at(j));
                debug_str = "CHANGE";
                cnt++;
            }
            // debug
            for(int d = 0; d < N; d++){
                debug(num.at(d));
            }
            debug(debug_str);
            debugWL();
        }
    }

    cout << cnt << '\n';
}