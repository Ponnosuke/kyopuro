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
    vector<i64> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    // O(N * log_2(max(A_i)))  log_2(10^13) は 43 くらい
    i64 G = A.at(0);
    for(int i = 1; i < N; i++){
        G = gcd(G, A.at(i));
    }

    i64 cnt = 0;
    for(i64 i = 1; i*i <= G; i++){
        if(G % i != 0){
            continue;
        }

        cnt++;
        if(G/i != i){
            cnt++;
        }
    }

    cout << cnt << endl;
}