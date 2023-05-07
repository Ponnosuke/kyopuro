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
    map<i64, i64> cnt;
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        cnt[A]++;
    }

    i64 sum = 0;
    // p := num, q := count
    for(auto [p1, q1] : cnt){
        for(auto [p2, q2] : cnt){
            sum += (p1 - p2)*(p1 - p2) * q1 * q2;
        }
    }

    sum /= 2;
    cout << sum << endl;
}