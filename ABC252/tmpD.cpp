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

i64 nC3(i64 N){
    return N*(N-1)*(N-2)/6;
}
i64 nC2(i64 N){
    return N*(N-1)/2;
}

int main() {
    int N;
    cin >> N;
    vector<i64> A(N, 0);
    map<i64, i64> allMp;
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
        allMp[A.at(i)]++;
    }

    map<i64, i64> now;
    i64 ans = 0;
    for(int i = 0; i < N; i++){
        int rest = N - i - 1;
        now[A.at(i)]++;
        rest -= (allMp[A.at(i)] - now[A.at(i)]);
        ans += nC2(rest);
        
    }

    cout << ans << '\n';
}