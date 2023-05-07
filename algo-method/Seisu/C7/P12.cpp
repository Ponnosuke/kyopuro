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
    vector<i64> diffA;
    for(int i = 0; i < N; i++){
        cin >> A.at(i);

        if(i >= 1){
            diffA.push_back(A.at(i) - A.at(0));
        }
    }

    i64 G = diffA.at(0);
    for(int i = 0; i < diffA.size(); i++){
        G = gcd(G, diffA.at(i));
    }

    i64 cnt = 0;
    for(i64 i = 1; i*i <= G; i++){
        if(G % i != 0){
            continue;
        }

        cnt++;
        if(i != G/i){
            cnt++;
        }
    }

    cout << cnt << endl;
}