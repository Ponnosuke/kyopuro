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
    map<string, i64> mp;
    for(int i = 0; i < N; i++){
        string S;
        cin >> S;
        sort(S.begin(), S.end());

        mp[S]++;
    }

    i64 nume = 0;
    for(auto &[str, cnt] : mp){
        nume += cnt*(cnt-1)/2;
    }
    i64 deno = N*(N-1)/2;

    cout << fixed << setprecision(19);
    cout << (double)nume / (double)deno << '\n';

    return 0;
}