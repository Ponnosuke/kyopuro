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

const i64 POW18 = 1000000000000000000LL;
//                1010101010101010101


vector<pair<i64, i64>> fact(i64 n){
    vector<pair<i64, i64>> ret;
    for(i64 i = 2; i*i <= n; i++){
        i64 cnt = 0;
        while(n % i == 0){
            cnt++;
            n /= i;
        }

        ret.emplace_back(i, cnt);
    }
    if(n != 1){
        ret.emplace_back(n, 1);
    }

    return ret;
}

int main() {
    i64 N, X;
    cin >> N >> X;
    vector<vector<i64>> a(N);
    for(i64 i = 0; i < N; i++){
        i64 L;
        cin >> L;
        for(i64 j = 0; j < L; j++){
            i64 ia;
            cin >> ia;
            a.at(i).push_back(ia);
        }
    }

    
}