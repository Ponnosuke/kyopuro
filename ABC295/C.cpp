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
    vector<i64> A(N);
    map<i64, i64> mp;
    for(int i = 0; i < N; i++){
        cin >> A.at(i);

        mp[A.at(i)]++;
    }

    // sort(A.begin(), A.end());
    i64 cnt = 0;
    for(auto [p, q] : mp){
        cnt += q/2;
    }

    cout << cnt << '\n';
}